template <class _Ty>
struct is_int { enum _valuelue { value = false }; };

template <>
struct is_int<int> { int a; enum _valuelue { value = true }; };


struct true_type { enum _value_ { value = true }; };
struct false_type { enum _value_ { value = false }; };

template <typename T1, typename T2>
struct is_same : false_type {};

template <typename T>
struct is_same<T, T> : true_type {};


template <typename T>
struct remove_const { using Type = T; };
template <typename T>
struct remove_const<const T> { using Type = T; };

template <typename T>
struct is_void : is_same<typename remove_const<T>::Type, void> {};

template <typename T>
struct is_null_pointer : is_same<typename remove_const<T>::Type, std::nullptr_t> {};

template <typename T>
struct is_pointer_base : false_type {};
template <typename T>
struct is_pointer_base<T*> : true_type {};

template <typename T>
struct is_pointer : is_pointer_base<typename remove_const<T>::type> {};


template <typename T>
struct is_reference : false_type {};
template <typename T>
struct is_reference<T&> : true_type {};
template <typename T>
struct is_reference<T&&> : true_type {};
