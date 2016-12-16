메모리 활당과 메모리 Leak 탐지는 게임에서 성능을 저하할수있습니다.

C++에서는 동적 생선에 잘알려진 함수중 dynamic (heap) memory (malloc and new) 이렇게 두가지가 있지만

이 모드는 유저 모드에서 커널모드로 context-switch(작업전환) 이 일어나기 떄문에 매우 느립니다.

그리고 메모리 Leak 탐지에 대해 제공해주지도 않습니다.

그래서 커스텀 활당자를 만들어 최적화를 할수있습니다.

Base Allocator

2 개의 가상 함수 (할당 및 할당 해제)를 선언하는 클래스 Allocator에서 파생됩니다.

Allocator.h

class Allocator{
    public:
    Allocator(size_t size , void * start){
        _start = start;
        _size = size;
        _used_memory = 0;
        _num_allocations = 0;
    }
    virtual ~Allocator(){
        ASSERT(_num_allocations == 0 && _used_memory == 0);
        _start  = nullptr;
        _size = 0 ;
    }
    virtual void* allocate(size_t size, u8 alignment = 4) = 0;
    virtual void deallocate(void* p) = 0;
    void* getStart() const
	{
		return _start;
	}

	size_t getSize() const
	{
		return _size;
	}

	size_t getUsedMemory() const
	{
		return _used_memory;
	}

	size_t getNumAllocations() const
	{
		return _num_allocations;
	}

protected:
	void*         _start;
	size_t        _size;

	size_t        _used_memory;
	size_t        _num_allocations;
};

namespace allocator
{
	template <class T> T* allocateNew(Allocator& allocator)
	{
		return new (allocator.allocate(sizeof(T), __alignof(T))) T;
	}

	template <class T> T* allocateNew(Allocator& allocator, const T& t)
	{
		return new (allocator.allocate(sizeof(T), __alignof(T))) T(t);
	}

	template<class T> void deallocateDelete(Allocator& allocator, T& object)
	{
		object.~T();
		allocator.deallocate(&object);
	}

	template<class T> T* allocateArray(Allocator& allocator, size_t length)
	{
		ASSERT(length != 0);

		u8 headerSize = sizeof(size_t)/sizeof(T);

		if(sizeof(size_t)%sizeof(T) > 0)
			headerSize += 1;

		//Allocate extra space to store array length in the bytes before the array
		T* p = ( (T*) allocator.allocate(sizeof(T)*(length + headerSize), __alignof(T)) ) + headerSize;

		*( ((size_t*)p) - 1 ) = length;

		for(size_t i = 0; i < length; i++)
			new (&p[i]) T;

		return p;
	}

	template<class T> void deallocateArray(Allocator& allocator, T* array)
	{
		ASSERT(array != nullptr);

		size_t length = *( ((size_t*)array) - 1 );

		for(size_t i = 0; i < length; i++)
			array[i].~T();

		//Calculate how much extra memory was allocated to store the length before the array
		u8 headerSize = sizeof(size_t)/sizeof(T);

		if(sizeof(size_t)%sizeof(T) > 0)
			headerSize += 1;

		allocator.deallocate(array - headerSize);
	}
};

메모리 누수 탐자

소멸자에 assert를 넣어 메모리 leak에 대해 쉽게 확인이 가능하고
오버헤드도 발생시키지도 않는다.

이방식은 어떤걸 해제를 안했는지 알아채기는 힘들겠지만 메모리 누수가 발생했다는거를
좀더 빠르게 알고 있습니다.

Aligned Allocations


프로세서는 word 사이즈 만큼 액세스합니다 그치만

정렬되지 않은 워드 사이즈는 더 많은 word-size를 액세스하게됩니다 그리고
레지스터로 부터  masking/shifting를 요청하게됩니다

Aligned data definition

메모리 주소가 primitive 사이즈의 배수이면 정렬되어있다고 말할수있습니다.

Implementation

메모리 주소 x를 n 바이트 정렬하려면 x에서 log2 (n) 최하위 비트를 마스크 처리해야합니다.

단히 비트를 마스킹하면 x 앞에 첫 번째 n 바이트 정렬 주소가 반환되므로 x 뒤에 첫 번째를 찾으려면 x에 alignment-1을 추가하고 그 주소를 마스킹해야합니다.

inline void* alignForward(void* address, u8 alignment)
{
	return (void*)( ( reinterpret_cast<uptr>(address) + static_cast<uptr>(alignment-1) ) & static_cast<uptr>(~(alignment-1)) );
}

많은 양의 바이트를 필요할지 계산하는 방법은 이방법이 가장 유용합니다.

inline u8 alignForwardAdjustment(const void* address, u8 alignment)
{
    u8 adjustment =  alignment - ( reinterpret_cast<uptr>(address) & static_cast<uptr>(alignment-1) );
    
    if(adjustment == alignment)
        return 0; //already aligned
    
    return adjustment;
}