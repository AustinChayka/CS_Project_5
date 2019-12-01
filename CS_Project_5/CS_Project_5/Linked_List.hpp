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

	static void split(Node<T>*, Node<T>**, Node<T>**);
	static Node<T>* merge(Node<T>*, Node<T>*, bool (*compare)(T, T));
	static bool greator_equal(T, T);
	static bool less_equal(T, T);

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

	void sort_ascending();
	void sort_ascending(Node<T>**);
	void sort_descending();
	void sort_descending(Node<T>**);

};

#endif

template<class T>
inline void Linked_List<T>::split(Node<T>* start, Node<T>** list_0, Node<T>** list_1) {

	Node<T>* fast = start->next;
	Node<T>* slow = start;

	while(fast != nullptr) {

		fast = fast->next;
		if(fast != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}

	}

	*list_0 = start;
	*list_1 = slow->next;
	slow->next = nullptr;

}

template<class T>
inline Node<T>* Linked_List<T>::merge(Node<T>* list_0, Node<T>* list_1, bool (*compare)(T, T)) {

	if(list_0 == nullptr) return list_1;
	if(list_1 == nullptr) return list_0;

	Node<T>* new_list;

	if((*compare)(list_0->val, list_1->val)) {
		new_list = list_0;
		new_list->next = merge(new_list->next, list_1, compare);
	} else {
		new_list = list_1;
		new_list->next = merge(list_0, new_list->next, compare);
	}

	return new_list;

}

template<class T>
inline bool Linked_List<T>::greator_equal(T val_0, T val_1) {

	return val_0 >= val_1;

}

template<class T>
inline bool Linked_List<T>::less_equal(T val_0, T val_1) {

	return val_0 <= val_1;

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

	assert(index >= 0 && index < length);

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
inline void Linked_List<T>::sort_ascending() {
	
	if(head == nullptr || head->next == nullptr) return;

	Node<T>* list_0 = nullptr, * list_1 = nullptr;

	Linked_List::split(head, &list_0, &list_1);

	sort_ascending(&list_0);
	sort_ascending(&list_1);

	head = Linked_List::merge(list_0, list_1, &Linked_List::less_equal);

}

template<class T>
inline void Linked_List<T>::sort_ascending(Node<T>** start) {
	   
	if((*start) == nullptr || (*start)->next == nullptr) return;

	Node<T>* list_0 = nullptr, * list_1 = nullptr;

	Linked_List::split(*start, &list_0, &list_1);

	sort_ascending(&list_0);
	sort_ascending(&list_1);

	*start = Linked_List::merge(list_0, list_1, &Linked_List::less_equal);

}

template<class T>
inline void Linked_List<T>::sort_descending() {

	if(head == nullptr || head->next == nullptr) return;

	Node<T>* list_0 = nullptr, * list_1 = nullptr;

	Linked_List::split(head, &list_0, &list_1);

	sort_descending(&list_0);
	sort_descending(&list_1);

	head = Linked_List::merge(list_0, list_1, &Linked_List::greator_equal);

}

template<class T>
inline void Linked_List<T>::sort_descending(Node<T>** start) {

	if((*start) == nullptr || (*start)->next == nullptr) return;

	Node<T>* list_0 = nullptr, * list_1 = nullptr;

	Linked_List::split(*start, &list_0, &list_1);

	sort_descending(&list_0);
	sort_descending(&list_1);

	*start = Linked_List::merge(list_0, list_1, &Linked_List::greator_equal);

}
