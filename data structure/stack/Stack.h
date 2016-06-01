#include "Node.h"
#include <iostream>
#include <cstdio>
#ifndef __LIST__
#define __LIST__


template <typename T>
class Stack {
public:
	Stack();
	void push_back(T value);
	void print();
	void pop_back();
	int getSize();
	T top();

private:
	Node<T> * newNode(T value);
	Node<T> * head;
	int size;

};
#endif

template<typename T>
inline Stack<T>::Stack() {
	this->head = nullptr;
	this->size = 0;
}

template<typename T>
inline void Stack<T>::push_back(T value) {
	Node<T> * nNode = newNode(value);
	if (this->size++ == 0) {
		head = nNode;
		return;
	}
	nNode->link = head;
	head = nNode;
}

template<typename T>
inline void Stack<T>::print() {
	if (size <= 0) {
		throw "Out og range";
	}
	for (Node<T> * i = head; i != nullptr;i = i->link) {
		std::cout << i->m_value << " ";
	}
}

template<typename T>
inline void Stack<T>::pop_back() {
	if (--size <= 0) {
		throw "Out og range";
	}

	auto temp = head;
	head = head->link;
	delete temp;
}

template<typename T>
inline int Stack<T>::getSize() {
	return this->size;
}

template<typename T>
inline T Stack<T>::top() {
	if (size <= 0) {
		throw "Out og range";
	}
	return head->m_value;
}

template<typename T>
inline Node<T>* Stack<T>::newNode(T value) {
	Node<T> * node = new Node<T>;
	node->link = nullptr;
	node->m_value = value;
	return node;

}
