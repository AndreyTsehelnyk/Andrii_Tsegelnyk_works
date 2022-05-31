#include<iostream>
#include<complex>
#include<cmath>

using namespace std;

class InputError : public logic_error {
public:
    InputError(const char* message) : logic_error(message) {}
};


class ValueError : public logic_error {
public:
    ValueError(const char* message) : logic_error(message) {}
};


template<class T>
ostream& operator<<(ostream& out, complex<T>& z) {
    out << real(z) << " + " << imag(z) << "i";
    return out;
}


void InputWithExceptions(complex<double>* z) {
    while (true) {
        try {
            double real, imag;
            cout << "enter a and b: ";
            cin >> real >> imag;

            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                throw InputError("Wrong input. It is not a comlex number. Enter a b\nTry again");
            }
            *z = complex<double>(real, imag);
            if (abs(*z) >= 1) throw InputError("|z| must be less than 1. Enter a b\nTry again");
            break;
        }
        catch (InputError& error) {
            cout << error.what() << endl;
            cin.ignore();
        }
    }
}
complex<double> arctan(complex<double> z) {
    double eps = 0.0001;
    complex<double> ans(0.0, 0.0);
    try {
        for (double i = 0;; i++) {
            if (abs((pow(-1, i) * pow(z, 2 * i + 1)) / (2 * i + 1)) < eps)
                throw ValueError((char*)"The element is less than eps = 0.0001.\n");
            ans += pow(-1, i) * pow(z, 2 * i + 1) / (2 * i + 1);
            cout << pow(-1, i) * pow(z, 2 * i + 1) / (2 * i + 1) << endl;
        }
    }
    catch (ValueError& error) {
        cout << error.what() << endl;
    }

    return ans;
}

int main() {
    complex<double> z, ans;
    InputWithExceptions(&z);
    cout << z << endl;
    ans = arctan(z);
    cout << "atctan(" << z << ")" << " = " << ans << endl << endl;
    return 0;
}