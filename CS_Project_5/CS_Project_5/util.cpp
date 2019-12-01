#include "util.h"

bool is_prime(int n) {

	if(n < 0) return false;

	for (int i = 2; i < n - 1; i++) if (n % i == 0) return false;

	return true;

}

bool is_num(std::string s) {

	for(int i = (s[0] == '-' ? 1 : 0); s[i] != '\0'; i++) if(s[i] < '0' || s[i] > '9') return false;

	return true;

}
