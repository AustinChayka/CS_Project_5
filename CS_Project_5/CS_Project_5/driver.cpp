#include <iostream>
#include "Linked_List.hpp"
#include "util.h"

using namespace std;

int main(int argc, char argv[]) {

	int mode = -1;

	Linked_List<int> list;

	string input;
	cout << "(1) Integer\n(2) Unsigned Integer\nEnter input type choice: ";
	cin >> input;
	while(true) {
		if(!is_num(input)) {
			cout << "Error: input is not a number. Enter again: ";
			cin >> input;
		} else {
			if(stoi(input) < 1 || stoi(input) > 2) {
				cout << "Error: not a valid choice. Enter again: ";
				cin >> input;
			} else break;
		}
	}

	mode = stoi(input) - 1;

	switch(mode) {

		case 0:
			{
				//do ints
			}
			break;

		case 1:
			{
				//do uints
			}
			break;

	}

	cout << endl;
	int primes = 0;
	for(int i = 0; i < list.get_length(); i++) if(is_prime(list.get(i))) primes++;
	cout << "The list contains " << primes << " prime numbers." << endl;

	list.clear();

	return 0;

}