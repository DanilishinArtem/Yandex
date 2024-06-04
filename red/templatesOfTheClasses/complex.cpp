#include <iostream>
#include <math.h>

using namespace std;

class Complex{
public:
    Complex(double real, double imaginary) {
        _real = real;
        _imaginary = imaginary;
    }

    double GetReal() const {
        return _real;
    }

    double GetImaginary() const {
        return _imaginary;
    }

    Complex operator + (const Complex& a){
        return Complex(_real + a._real, _imaginary + a._imaginary);
    }

    Complex operator - (const Complex& a){
        return Complex(_real - a._real, _imaginary - a._imaginary);
    }

    Complex operator * (const Complex& a){
        return Complex(_real * a._real - _imaginary * a._imaginary, _real * a._imaginary + _imaginary * a._real);
    }

    Complex operator / (const Complex& a){
        return Complex((_real * a._real + _imaginary * a._imaginary) / (a._real * a._real + a._imaginary * a._imaginary),
                       (_imaginary * a._real - _real * a._imaginary) / (a._real * a._real + a._imaginary * a._imaginary));
    }

    Complex operator = (const Complex& a){
        _real = a._real;
        _imaginary = a._imaginary;
        return *this;
    }

    double abs() const {
        return sqrt(_real * _real + _imaginary * _imaginary);
    }

private:
    double _real;
    double _imaginary;
};

ostream& operator << (ostream& os, const Complex& c){
    return os << c.GetReal() << " + " << c.GetImaginary() << "i";
    return os;
}

int main(){
    Complex a(1, 2);
    Complex b(3, 4);
    Complex c = a + b;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "result for c = a + b: " << c << endl;
    c = a - b;
    cout << "result for c = a - b: " << c << endl;
    c = a * b;
    cout << "result for c = a * b: " << c << endl;
    c = a / b;
    cout << "|a| = " << a.abs() << endl;

    return 0;
}