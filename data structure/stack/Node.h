#ifndef __NODE__
#define __NODE__



template <typename T>
struct Node {
	T  m_value;
	Node<T> * link;
};

#endif __NODE__
