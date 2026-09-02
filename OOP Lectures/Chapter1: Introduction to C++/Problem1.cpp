#include <iostream>
#include <cmath>
using namespace std;

struct ComplexNumber {
    double Real;
    double Imaginary;
};

ComplexNumber ComplexNumberInput() {
    ComplexNumber NewNumber;
    cout << "Enter the real part of the complex number: ";
    cin >> NewNumber.Real;
    cout << "Enter the imaginary part of the complex number: ";
    cin >> NewNumber.Imaginary;
    return NewNumber;
}

void ComplexNumberOutput(ComplexNumber NewNumber) {
    if (NewNumber.Imaginary >= 0) {
        cout << NewNumber.Real << " + " << NewNumber.Imaginary << "i";
    } else {
        cout << NewNumber.Real << " - " << -NewNumber.Imaginary << "i";
    }
}

double ComplexNumberModulus(ComplexNumber a) {
    return sqrt(a.Real * a.Real + a.Imaginary * a.Imaginary);
}

ComplexNumber Addition(ComplexNumber a, ComplexNumber b) {
    ComplexNumber Result;
    Result.Real = a.Real + b.Real;
    Result.Imaginary = a.Imaginary + b.Imaginary;
    return Result;
}

ComplexNumber Subtraction(ComplexNumber a, ComplexNumber b) {
    ComplexNumber Result;
    Result.Real = a.Real - b.Real;
    Result.Imaginary = a.Imaginary - b.Imaginary;
    return Result;
}

ComplexNumber Multiplication(ComplexNumber a, ComplexNumber b) {
    ComplexNumber Result;
    Result.Real = a.Real * b.Real - a.Imaginary * b.Imaginary;
    Result.Imaginary = a.Imaginary * b.Real + a.Real * b.Imaginary;
    return Result;
}

ComplexNumber Division(ComplexNumber a, ComplexNumber b) {
    ComplexNumber Result;
    double Denominator = b.Real * b.Real + b.Imaginary * b.Imaginary;
    
    if (Denominator == 0) {
        cout << "\nIt is not possible to divide a complex number by 0!\n";
        Result.Real = 0;
        Result.Imaginary = 0;
        return Result;
    }
    
    Result.Real = (a.Real * b.Real + a.Imaginary * b.Imaginary) / Denominator;
    Result.Imaginary = (a.Imaginary * b.Real - a.Real * b.Imaginary) / Denominator;
    return Result;
}

bool Equalization(ComplexNumber a, ComplexNumber b) {
    return (a.Real == b.Real) && (a.Imaginary == b.Imaginary);
}

bool Difference(ComplexNumber a, ComplexNumber b) {
    return !Equalization(a, b);
}

bool Bigger(ComplexNumber a, ComplexNumber b) {
    return (ComplexNumberModulus(a) > ComplexNumberModulus(b));
}

bool Smaller(ComplexNumber a, ComplexNumber b) {
    return (ComplexNumberModulus(a) < ComplexNumberModulus(b));
}

int main() {
    ComplexNumber CN1, CN2;
    cout << "Enter the first complex number:" << endl;
    CN1 = ComplexNumberInput();
    cout << "\nEnter the second complex number:" << endl;
    CN2 = ComplexNumberInput();

    cout << "\nEntered complex numbers:" << endl;
    cout << "CN1 = "; ComplexNumberOutput(CN1); cout << endl;
    cout << "CN2 = "; ComplexNumberOutput(CN2); cout << endl;

    cout << "\nModulus:" << endl;
    cout << "|CN1| = " << ComplexNumberModulus(CN1) << endl;
    cout << "|CN2| = " << ComplexNumberModulus(CN2) << endl;

    cout << "\nArithmetic operations:" << endl;
    cout << "CN1 + CN2 = "; ComplexNumberOutput(Addition(CN1, CN2)); cout << endl;
    cout << "CN1 - CN2 = "; ComplexNumberOutput(Subtraction(CN1, CN2)); cout << endl;
    cout << "CN1 * CN2 = "; ComplexNumberOutput(Multiplication(CN1, CN2)); cout << endl;
    cout << "CN1 / CN2 = "; ComplexNumberOutput(Division(CN1, CN2)); cout << endl;

    cout << "\nComparisons:" << endl;
    cout << "CN1 == CN2: " << (Equalization(CN1, CN2) ? "True" : "False") << endl;
    cout << "CN1 != CN2: " << (Difference(CN1, CN2) ? "True" : "False") << endl;
    cout << "CN1 > CN2: "  << (Bigger(CN1, CN2) ? "True" : "False") << endl;
    cout << "CN1 < CN2: "  << (Smaller(CN1, CN2) ? "True" : "False") << endl;

    return 0;
}