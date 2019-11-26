#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "Node.hpp"
#include <iostream>

template <class T>
class Linked_List {

private:

	unsigned int length;
	Node* head;

public:

	void print();
	void clear();

	unsigned int get_length();

	unsigned int push_front(T);
	unsigned int push_back(T);
	unsigned int insert(T, int);

	void sort_ascending();
	void sort_descending();

};

#endif

template<class T>
inline void Linked_List<T>::print() {

	Node* n = head;
	while(n != nullptr) {
		std::cout << n << " ";
		n = n.next;
	}
	std::cout << std::endl;

}

template<class T>
inline void Linked_List<T>::clear() {}

template<class T>
inline unsigned int Linked_List<T>::get_length() {

	return length;

}

template<class T>
inline unsigned int Linked_List<T>::push_front(T val) {

	Node<T>* n = new Node<T>;
	n->val = val;
	n->next = head;
	head = n;

	return ++length;

}

template<class T>
inline unsigned int Linked_List<T>::push_back(T) {
	return 0;
}

template<class T>
inline unsigned int Linked_List<T>::insert(T, int) {
	return 0;
}

template<class T>
inline void Linked_List<T>::sort_ascending() {}

template<class T>
inline void Linked_List<T>::sort_descending() {}
