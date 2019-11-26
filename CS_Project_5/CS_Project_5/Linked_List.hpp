#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "Node.hpp"

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
inline void Linked_List<T>::print() {}

template<class T>
inline void Linked_List<T>::clear() {}

template<class T>
inline unsigned int Linked_List<T>::get_length() {
	return 0;
}

template<class T>
inline unsigned int Linked_List<T>::push_front(T) {
	return 0;
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
