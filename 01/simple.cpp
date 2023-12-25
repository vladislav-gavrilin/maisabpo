#include <iostream>
#include <string>
#include <vector>

using namespace std;

void eratosphen(int N) {
	int n = 1000;
	vector<char> prime(n + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= n; ++i)
		if (prime[i])
			if (i * 1ll * i <= n)
				for (int j = i * i; j <= n; j += i)
					prime[j] = false;
	int cnt = 0;
	for (int i = 0; i < prime.size(); i++) {
		if (prime[i] && (cnt < N + 1)) {
			cout << i << " ";
			cnt++;
		}		
	}
	cout << endl << endl;
}

bool is_simple(int N) {
	for (long long i = 2; i <= sqrt(N); i++)
		if (N % i == 0)
			return false;
	return true;
}

void simple() {
	int res;
	cout << "Enter N: ";
	int N;
	cin >> N;

	cout << "\n1. Print first N simple nums.\n2.Is N simple?\n";
	int choice;
	cin >> choice;

	if (choice == 1) {
		eratosphen(N);
	}
	else if (choice == 2) {
		bool res = is_simple(N);
		cout << res << endl;
	}
	else
		cout << "Error!\n";	
}