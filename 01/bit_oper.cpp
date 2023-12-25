#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <format>
#include <bitset>

using namespace std;

int operations(string type, int num_one, int num_two) {
	int res = 0;
	const int n = 8;
	if(type == "xor") {
		res = num_one ^ num_two;
	}
	else if (type == "and") {
		res = num_one & num_two;
	}
	else if (type == "or") {
		res = num_one | num_two;
	}
	else if (type == "set1") {
		if (0 <= num_one < 8) {
			bitset<n> binary = bitset<n>(num_two);
			binary[num_one] = 1;
			res = (int)(binary.to_ulong());
		}		
		else
			cout << "Error! Check n.\n";
		return -1;
	}
	else if (type == "set0") {
		if (0 <= num_one < 8) {
			bitset<n> binary = bitset<n>(num_two);
			binary[num_one] = 0;
			res = (int)(binary.to_ulong());
		}
		else
			cout << "Error! Check n.\n";
		return -1;
	}
	else if (type == "shl") {
		res = num_two << num_one;
	}
	else if (type == "shr") {
		res = num_two >> num_one;
	}
	else if (type == "rol") {
		string binary = bitset<n>(num_two).to_string();
		string new_bin_str = binary.substr(num_one % (n-1), n - num_one % (n - 1)) + binary.substr(0, num_one % (n - 1));
		res = stoi(new_bin_str, 0, 2);
	}
	else if (type == "ror") {
		string binary = bitset<n>(num_two).to_string(); 
		reverse(binary.begin(), binary.end());
		string new_bin_str = binary.substr(num_one % (n - 1), n - num_one % (n - 1)) + binary.substr(0, num_one % (n - 1));
		res = stoi(new_bin_str, 0, 2);
	}
	else if (type == "mix") {
		string binary = bitset<n>(num_two).to_string();
		string changed_str = "";
		for (int i = 0; i < binary.size(); i++) {
			int integer = (int)to_string(num_one)[i] - 48;
			changed_str += binary[integer];
		}
		res = stoi(changed_str);
	}
	else{
	}
	cout << res << " " << endl;
}