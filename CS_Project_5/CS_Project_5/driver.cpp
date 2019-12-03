#include <iostream>
#include "Linked_List.hpp"
#include "util.h"

using namespace std;

int main(int argc, char argv[]) {

	bool running = true;
	while(running) {

		int mode = get_mode();

		string input;

		switch(mode) {

			case 0:
				{
					Linked_List<int> list;
					handle_int_input(list);
					list.print();
					cout << "The list contains " << count_primes(list) << " prime numbers." << endl;
				}
				break;

			case 1:
				{
					Linked_List<unsigned int> list;
					handle_uint_input(list);
					list.print();
					cout << "The list contains " << count_primes(list) << " prime numbers." << endl;
				}
				break;

		}

		handle_restart_check(running);

	}

	return 0;

}