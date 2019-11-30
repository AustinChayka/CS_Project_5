#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "Node.hpp"
#include <iostream>
#include <assert.h>

template <class T>
class Linked_List {

private:

	unsigned int length;
	Node<T>* head;

	void split(Node<T>*, Node<T>*, Node<T>*);
	Node<T>* merge(Node<T>*, Node<T>*);

public:

	Linked_List();

	~Linked_List();

	void print();
	void clear();

	unsigned int get_length();

	T get(int);

	unsigned int push_front(T);
	unsigned int push_back(T);
	unsigned int insert(T, int);

	unsigned int remove(int);

	void sort_ascending(Node<T>* = head);
	void sort_descending(Node<T>* = head);

};

#endif

template<class T>
inline void Linked_List<T>::split(Node<T>* start, Node<T>* list_0, Node<T>* list_1) {

	Node<T>* fast = start->next;
	Node<T>* slow = start;

	while(fast != nullptr) {

		fast = fast->next;
		if(fast != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}

	}

	list_0 = start;
	list_1 = slow->next;
	slow->next = nullptr;

}

template<class T>
inline Node<T>* Linked_List<T>::merge(Node<T>* list_0, Node<T>* list_1) {

	if(list_0 == nullptr) return list_1;
	if(list_1 == nullptr) return list_2;

	Node<T>* new_list;

	if(list_0->val <= list_1->val) {
		new_list = list_0;
		new_list->next = merge(new_list->next, list_1);
	} else {
		new_list = list_1;
		new_list->next = merge(list_0, new_list->next);
	}

	return new_list;

}

template<class T>
inline Linked_List<T>::Linked_List() {

	length = 0;
	head = nullptr;

}

template<class T>
inline Linked_List<T>::~Linked_List() {

	if(length > 0) clear();

}

template<class T>
inline void Linked_List<T>::print() {

	if(length == 0) {
		std::cout << "List is empty." << std::endl;
		return;
	}

	Node<T>* n = head;
	while(n != nullptr) {
		std::cout << n->val << " ";
		n = n->next;
	}
	std::cout << std::endl;

}

template<class T>
inline void Linked_List<T>::clear() {

	while(length > 0) {

		Node<T>* n = head, * temp;
		for(int i = 1; i < length; i++) {
			n = n->next;
		}
		temp = n;
		delete temp;
		--length;

	}

	head = nullptr;

}

template<class T>
inline unsigned int Linked_List<T>::get_length() {

	return length;

}

template<class T>
inline T Linked_List<T>::get(int index) {

	assert(index >= 0 && index < length);

	Node<T>* n = head;
	for(int i = 1; i < index; i++) n = n->next;

	return n->val;

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
inline unsigned int Linked_List<T>::push_back(T val) {

	if(head == nullptr) {
		Node<T>* n = new Node<T>;
		n->val = val;
		head = n;
		return ++length;
	}

	Node<T>* n = head, * new_n = new Node<T>();
	new_n->val = val;
	for(int i = 0; i < length - 1; i++) n = n->next;
	n->next = new_n;

	return ++length;

}

template<class T>
inline unsigned int Linked_List<T>::insert(T val, int index) {

	assert(index >= 0, index < length);

	if(index == 0) {
		Node<T>* n = new Node<T>;
		n->val = val;
		n->next = head;
		head = n;
		return ++length;
	}
	
	Node<T>* n = head, * new_n = new Node<T>;
	new_n->val = val;
	for(int i = 1; i < index; i++) n = n->next;
	new_n->next = n->next;
	n->next = new_n;

		return ++length;

}

template<class T>
inline unsigned int Linked_List<T>::remove(int index) {

	assert(index >= 0 && index < length);

	if(index == 0) {
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		return --length;
	}

	Node<T>* n = head, * temp;
	for(int i = 1; i < index; i++) n = n->next;
	temp = n->next;
	n->next = temp->next;
	delete temp;

	return --length;

}

template<class T>
inline void Linked_List<T>::sort_ascending(Node<T>* start) {



}

template<class T>
inline void Linked_List<T>::sort_descending(Node<T>* start) {}
