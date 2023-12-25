#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <format>

using namespace std;

void info() {
	cout << "This program output the contents of the file." << endl
		<< "<type> <path>" << endl
		<< "<type> hex8 / dec8 / hex16 / dec16 / hex32" << endl;
}

vector<uint8_t> get_words(string inp) {
	ifstream input(inp, ios::binary);
	if (!input)
	{
		cout << " ' " << inp << " ' " << " file reading failed!" << endl;
		input.close();
		exit(1);
	}
	else {
		vector<uint8_t> v((std::istreambuf_iterator<char>(input)),
			std::istreambuf_iterator<char>());
		input.close();
		return v;
	}
}

void get_binary_data(string type, string path) {

	//сначала прочитать текст как коды чаров и потом с помощью формата изменять!
	cout << "You've choose " << type << " :\n";
	vector<uint8_t> text = get_words(path);

	for (int i = 0; i < text.size(); i++) {
		if (type == "hex8") {
			cout << format("{:x}", (int)text[i]) << " ";
		}
		else if (type == "dec8") {
			cout << (int)text[i] << " ";
		}
		else if (type == "hex16") {
			cout << format("{:04x}", (int)text[i]) << " ";
		}
		else if (type == "dec16") {
			cout << format("{:05}", (int)text[i]) << " ";
		}
		else if (type == "hex32") {
			cout << format("{:08x}", (int)text[i]) << " ";
		}
		else {
			cout << "Error! Please check info..." << endl;
			info();
		}
	}
	cout << endl;
}