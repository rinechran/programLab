#include "Node.h"
#include <iostream>
#ifndef __LIST__
#define __LIST__


template <typename T>
class List {
public:
	List();
	void push_front(T value);
	void push_back(T value);
	void print();
	void pop_front();
	void pop_back();
	int getSize();
	T front();
	T back();

private:
	Node<T> * newNode(T value);
	Node<T> * head;
	Node<T> * tail;
	int size;

};
#endif

template<typename T>
inline List<T>::List() {
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

template<typename T>
inline void List<T>::push_front(T value) {
	Node<T> * node = newNode(value);
	if (!this->size)
		this->tail = this->head = node;
	else {
		this->head->m_llink = node;
		node->m_rlink = this->head;
		this->head = node;
	}
	this->size++;

}

template<typename T>
inline void List<T>::push_back(T value) {
	Node<T> * node = newNode(value);
	if (!this->size)
		this->tail = this->head = node;

	else {
		this->tail->m_rlink = node;
		node->m_llink = this->tail;
		this->tail = node;
	}
	this->size++;
}

template<typename T>
inline void List<T>::print() {
	Node<T> * ptr = this->head;
	Node<T> * end = reinterpret_cast<Node<T>*>(&this->tail);
	for (; ptr != end; ptr = ptr->m_rlink) {
		std::cout << ptr->m_value;
		std::cout << " ";
	}
}

template<typename T>
inline void List<T>::pop_front() {
	if (!this->size)
		throw "range error";


	Node<T> * temp = this->head;
	this->head = temp->m_rlink;
	this->head->m_llink = reinterpret_cast<Node<T>*>(&this->head);
	--this->size;
	delete temp;

}

template<typename T>
inline void List<T>::pop_back() {
	if (!this->size)
		throw "range error";

	Node<T> * temp = this->tail;
	this->tail = temp->m_llink;
	this->tail->m_rlink = reinterpret_cast<Node<T>*>(&this->tail);
	--this->size;
	delete temp;
}

template<typename T>
inline int List<T>::getSize() {
	return this->size;
}

template<typename T>
inline T List<T>::front() {
	if (this->size)
		return this->head->m_value;
	else
		throw "range error";
}

template<typename T>
inline T List<T>::back() {
	if (this->size)
		return this->tail->m_value;
	else
		throw "range error";
}

template<typename T>
inline Node<T>* List<T>::newNode(T value) {
	Node<T> * ptr = new Node<T>;
	if (!ptr)
		throw "Out of memory";
	ptr->m_value = value;
	ptr->m_llink = reinterpret_cast<Node<T>*>(&this->head);
	ptr->m_rlink = reinterpret_cast<Node<T>*>(&this->tail);

	return ptr;
}
