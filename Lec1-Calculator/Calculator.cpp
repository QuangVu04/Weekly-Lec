#include <iostream>
using namespace std;

template <class T>
void input() {
    T num1, num2;
    char op;
    cin >> num1 >> op >> num2;

    cout << "Ket qua: ";
    switch (op) {
        case '+':
            cout << num1 + num2;
            break;
        case '-':
            cout << num1 - num2;
            break;
        case '*':
            cout << num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                cout << "Error" << endl;
                return;
            } else {
                cout << num1 / num2;
            }
            break;
        case '%':
            if (num2 == 0) {
                cout << "Error" << endl;
                return;
            } else {
               int a = num1;
               int b = num2;
               cout << a % b;
            }
            break;
        default:
            cout << "Error" << endl;
            return;
    }
    cout << endl;
}

int main() {
    cout << "Nhap phep tinh:" << endl;
    input<double>();
    return 0;
}