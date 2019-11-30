#include <iostream>
#include "Linked_List.hpp"
#include "util.h"

using namespace std;

int main(int argc, char argv[]) {

	Linked_List<int> list;

	for(int i = 0; i < 5; i++) list.push_back(i);
	list.print();
	cout << "List has length: " << list.get_length() << endl;

	cout << endl;
	list.push_front(5);
	list.insert(6, 2);
	list.print();
	cout << "List has length: " << list.get_length() << endl;

	cout << endl;
	list.remove(2);
	list.print();
	cout << "List has length: " << list.get_length() << endl;

	cout << endl;
	int primes = 0;
	for(int i = 0; i < list.get_length(); i++) if(is_prime(list.get(i))) primes++;
	cout << "The list contains " << primes << " prime numbers." << endl;

	list.clear();

	cout << endl;
	list.print();
	cout << "List has length: " << list.get_length() << endl;
	
	return 0;

}