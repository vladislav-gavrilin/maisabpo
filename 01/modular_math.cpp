#include <iostream>
#include <string>

using namespace std;

 unsigned long long modPow( unsigned long long base,  unsigned long long pov,  unsigned long long modul)
{
	unsigned long long  res = 1;
	base = base % modul;
	if (base == 0) return 0;
	while (pov > 0)
	{
		if (pov & 1)
		{
			res = (res * base) % modul;
		}
		pov = pov >> 1;
		base = (base * base) % modul;
	}
	return res;
}


  unsigned long long gcdExtended( unsigned long long a,  unsigned long long b,  unsigned long long& x,  unsigned long long& y) {
	 if (a == 0) {
		 x = 0;
		 y = 1;
		 return b;
	 }
	  unsigned long long x1, y1;
	  unsigned long long gcd = gcdExtended(b % a, a, x1, y1);
	 x = y1 - (b / a) * x1;
	 y = x1;
	 return gcd;
 }

  unsigned long long modInverse( unsigned long long a,  unsigned long long m) {
	  unsigned long long x, y;
	  unsigned long long gcd = gcdExtended(a, m, x, y);
	 if (gcd != 1) {
		 return -1;
	 }
	 else {
		 return (x % m + m) % m;
	 }
 }

void modular(int a, int b, int M) {
	string oper;
	cout << "Enter operation. Available are [+, -, *, pow, rev1, rev2, /, \\]" << endl;
	cin >> oper;
	int res = 0;

	if (oper == "+") {
		res = (a + b) % M;
	}
	else if (oper == "-") {
		res = (a - b) % M;
		if (res < 0) {
			res = ((res % M) + M) % M;
		}
	}
	else if (oper == "*") {
		res = (a * b) % M;
	}
	else if (oper == "pow") {
		res = modPow(a, b, M);
	}
	else if (oper == "rev1") {
		res = modInverse(a, M);
	}
	else if (oper == "rev2") {
		res = modInverse(b, M);
	}
	else if (oper == "/") {
		b = modInverse(b, M);
		res = (a * b) % M;
	}
	else if (oper == "\\") {
		a = modInverse(a, M);
		res = (b * a) % M;
	}
	else
		cout << "Error!\n";
	cout << res << endl;
}

int multip(int a, int b, int M)
{
	int res = 0;
	while (b > 0)
	{
		if ((b & 1) != 0)
		{
			res ^= a;
			if (res >= M) res ^= M;
		}
		a <<= 1;
		if (a >= M) a ^= M;
		b >>= 1;
	}
	return res;
}

void galua_math(int a, int b, int M) {
	string oper;
	cout << "Enter operation. Available are [+, -, *, rev]" << endl;
	cin >> oper;
	int res = 0;

	if (oper == "+") {
		res = (a ^ b) % M;
	}
	else if (oper == "-") {
		res = (a ^ b) % M;
	}
	else if (oper == "*") {
		res = multip(a, b, M);
	}
	else if (oper == "rev") {
		res = modInverse(2, M);
	}

	else
		cout << "Error!\n";

	cout << res << endl;
}