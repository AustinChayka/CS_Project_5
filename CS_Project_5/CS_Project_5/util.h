/**
**	Program: Utility Function Definitions
**	Author: Austin Chayka
**	Date: 12.3.2019
**	Description: Definitions for utility functions
**/
#ifndef UTIL_H
#define UTIL_H

#include <string>
#include "Linked_List.hpp"

bool is_prime(int);
bool is_num(std::string);

int get_mode();
int get_int_input();
unsigned int get_uint_input();

int count_primes(Linked_List<int>&);
int count_primes(Linked_List<unsigned int>&);

void handle_int_input(Linked_List<int>&);
void handle_uint_input(Linked_List<unsigned int>&);
void handle_restart_check(bool&);

#endif