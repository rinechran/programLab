#ifndef __NODE__
#define __NODE__



template <typename T>
struct Node {
	T  m_value;
	Node<T> * m_llink;
	Node<T> * m_rlink;
};

#endif __NODE__
