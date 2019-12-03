#include "util.h"
#include <iostream>

bool is_prime(int n) {

	if(n < 0) return false;

	for (int i = 2; i < n - 1; i++) if (n % i == 0) return false;

	return true;

}

bool is_num(std::string s) {

	for(int i = (s[0] == '-' ? 1 : 0); s[i] != '\0'; i++) if(s[i] < '0' || s[i] > '9') return false;

	return true;

}

int get_mode() {

	std::string input;
	std::cout << "(1) Integer\n(2) Unsigned Integer\nEnter input type choice: ";
	std::cin >> input;
	while(true) {
		if(!is_num(input)) {
			std::cout << "Error: input is not a number. Enter again: ";
			std::cin >> input;
		} else {
			if(stoi(input) < 1 || stoi(input) > 2) {
				std::cout << "Error: not a valid choice. Enter again: ";
				std::cin >> input;
			} else break;
		}
	}

	return std::stoi(input) - 1;

}

int get_int_input() {

	std::string input;
	std::cout << "Enter integer: ";
	std::cin >> input;
	while(true) {
		if(!is_num(input)) {
			std::cout << "Error: input was not a number. Enter again: ";
			std::cin >> input;
		} else {
			return std::stoi(input);
		}
	}

}

unsigned int get_uint_input() {

	std::string input;
	std::cout << "Enter unsigned integer: ";
	std::cin >> input;
	while(true) {
		if(!is_num(input)) {
			std::cout << "Error: input was not a number. Enter again: ";
			std::cin >> input;
		} else if(stoi(input) < 0) {
			std::cout << "Error: input had sign. Enter again: ";
			std::cin >> input;
		} else {
			return std::stoi(input);
		}
	}

}

int count_primes(Linked_List<int>& list) {

	int primes = 0;
	for(int i = 0; i < list.get_length(); i++) if(is_prime(list.get(i))) primes++;

	return primes;

}

int count_primes(Linked_List<unsigned int>& list) {

	int primes = 0;
	for(int i = 0; i < list.get_length(); i++) if(is_prime(list.get(i))) primes++;

	return primes;

}

void handle_int_input(Linked_List<int>& list) {

	std::string input;

	while(true) {

		if(list.get_length() == 0) {
			std::cout << "Enter first number: ";
			list.push_back(get_int_input());
		} else {
			std::cout << "Do you want to enter another number? (y/n): ";
			std::cin >> input;
			if(input == "n") break;
			else if(input == "y") {
				list.push_back(get_int_input());
			} else std::cout << "Error: input not reconized." << std::endl;
		}

	}
	std::cout << "Sort list by ascending or descending? (a/d): ";
	std::cin >> input;
	while(true) {
		if(input == "a") {
			list.sort_ascending();
			break;
		} else if(input == "d") {
			list.sort_descending();
			break;
		} else {
			std::cout << "Error: input not reconized. Enter again: ";
			std::cin >> input;
		}
	}

}

void handle_uint_input(Linked_List<unsigned int>& list) {

	std::string input;

	while(true) {

		if(list.get_length() == 0) {
			std::cout << "Enter first number: ";
			list.push_back(get_uint_input());
		} else {
			std::cout << "Do you want to enter another number? (y/n): ";
			std::cin >> input;
			if(input == "n") break;
			else if(input == "y") {
				list.push_back(get_uint_input());
			} else std::cout << "Error: input not reconized." << std::endl;
		}

	}
	std::cout << "Sort list by ascending or descending? (a/d): ";
	std::cin >> input;
	while(true) {
		if(input == "a") {
			list.sort_ascending();
			break;
		} else if(input == "d") {
			list.sort_descending();
			break;
		} else {
			std::cout << "Error: input not reconized. Enter again: ";
			std::cin >> input;
		}
	}

}

void handle_restart_check(bool& running) {

	std::string input;

	std::cout << "Do you want to do this again? (y/n): ";
	std::cin >> input;
	while(true) {
		if(input == "n") {
			running = false;
			break;
		} else if(input == "y") break;
		else {
			std::cout << "Error: input not reconized. Enter again: ";
			std::cin >> input;
		}
	}

}
