#include "Node.h"
#include <iostream>
#include <cstdio>
#ifndef __LIST__
#define __LIST__


template <typename T>
class Stack {
public:
	Stack() {
		this->head = nullptr;
		this->size = 0;
	}
	void push_back(T value) {
		Node<T> * nNode = newNode(value);
		if (this->size++ == 0) {
			head = nNode;
			return;
		}
		nNode->link = head;
		head = nNode;
	}
	void print() {
		if (size <= 0) {
			throw "Out og range";
		}
		for (Node<T> * i = head; i != nullptr;i = i->link) {
			std::cout << i->m_value << " ";
		}
	}
	void pop_back() {
		if (--size <= 0) {
			throw "Out og range";
		}

		auto temp = head;
		head = head->link;
		delete temp;
	}
	int getSize() {
		return this->size;
	}
	T top() {
		if (size <= 0) {
			throw "Out og range";
		}
		return head->m_value;
	}

private:
	Node<T> * newNode(T value) {
		Node<T> * node = new Node<T>;
		node->link = nullptr;
		node->m_value = value;
		return node;
		
	}
	Node<T> * head;
	int size;

};
#endif
