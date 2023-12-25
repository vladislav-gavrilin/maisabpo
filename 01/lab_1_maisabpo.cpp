#include <iostream>
#include "binary.h"
#include "bit_oper.h"
#include "modular_math.h"
#include "simple.h"
#include <format>

using namespace std;

int main()
{
    while(true){
        cout << "Choose task: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Format [hex8, dec8, hex16, dec16, hex32] : ";
            string fmt;
            cin >> fmt;
            cout << "\nPath: ";
            string path;
            cin >> path;
            get_binary_data(fmt, path);
        }
        else if (choice == 2) {
            cout << "Operation : ";
            string op;
            cin >> op;
            cout << "\nnum1: ";
            int num1;
            cin >> num1;
            cout << "\nnum2: ";
            int num2;
            cin >> num2;
            operations(op, num1, num2);
        }
        else if (choice == 3) {
            int a, b, M;
            cout << "Enter a,b,M\n";
            cin >> a;
            cin >> b;
            cin >> M;
            cout << "1. Modular Math 2. Galua Field Math\n";
            int chc;
            cin >> chc;
            if (chc == 1)
                modular(a, b, M);
            else if (chc == 2)
                galua_math(a, b, M);
            else {
                cout << "Error!\n";
                return -1;
            }
        }
        else if (choice == 4) {
            simple();
        }
        else if (choice == 5) {

        }
        else {
            cout << "Error!\n";
            return -1;
        }
    }
}

