#include <iostream>
#include <cmath>

using namespace std;

struct Monomial {
    int degree;
    double coefficient;
    double CalculateValue(double x) const {
        return coefficient * pow(x, degree);
    }

    Monomial Derivative() const {
        Monomial result;
        if (degree == 0) {
            result.coefficient = 0;
            result.degree = 0;
        } else {
            result.coefficient = coefficient * degree;
            result.degree = degree - 1;
        }
        return result;
    }

    Monomial Antiderivative() const {
        Monomial result;
        if (degree == -1) {
            cout << "(Integral forms " << coefficient << "*ln|x| + C) ";
            result.coefficient = 0;
            result.degree = 0;
        } else {
            result.coefficient = coefficient / (degree + 1);
            result.degree = degree + 1;
        }
        return result;
    }

    Monomial operator+(const Monomial& other) const {
        Monomial result;
        if (degree == other.degree) {
            result.coefficient = coefficient + other.coefficient;
            result.degree = degree;
        } else {
            cout << "\n[Warning: Degrees are not equal, returning 0] ";
            result.coefficient = 0;
            result.degree = 0;
        }
        return result;
    }

    Monomial operator-(const Monomial& other) const {
        Monomial result;
        if (degree == other.degree) {
            result.coefficient = coefficient - other.coefficient;
            result.degree = degree;
        } else {
            cout << "\n[Warning: Degrees are not equal, returning 0] ";
            result.coefficient = 0;
            result.degree = 0;
        }
        return result;
    }

    Monomial operator*(const Monomial& other) const {
        Monomial result;
        result.coefficient = coefficient * other.coefficient;
        result.degree = degree + other.degree;
        return result;
    }

    Monomial operator/(const Monomial& other) const {
        Monomial result;
        if (other.coefficient == 0) {
            cout << "\n[Error: Division by zero! Returning 0] ";
            result.coefficient = 0;
            result.degree = 0;
        } else {
            result.coefficient = coefficient / other.coefficient;
            result.degree = degree - other.degree;
        }
        return result;
    }

    bool operator==(const Monomial& other) const {
        return (coefficient == other.coefficient) && (degree == other.degree);
    }

    bool operator!=(const Monomial& other) const {
        return !(*this == other);
    }
};

void MonomialInput(Monomial &a) {
    cout << "Please enter the coefficient of the monomial: ";
    cin >> a.coefficient;
    cout << "Please enter the degree of the monomial: ";
    cin >> a.degree;
    cout << endl;
}

void MonomialOutput(Monomial a) {
    if (a.coefficient == 0) {
        cout << 0;
        return;
    }
    if (a.degree == 0) {
        cout << a.coefficient;
        return;
    }
    if (a.degree == 1) {
        if (a.coefficient == 1) cout << "x";
        else if (a.coefficient == -1) cout << "-x";
        else cout << a.coefficient << "x";
        return;
    }
    if (a.coefficient == 1) cout << "x^" << a.degree;
    else if (a.coefficient == -1) cout << "-x^" << a.degree;
    else cout << a.coefficient << "x^" << a.degree;
}

int main() {
    Monomial m1, m2;

    cout << "--- INPUT MONOMIAL 1 ---\n";
    MonomialInput(m1);
    cout << "--- INPUT MONOMIAL 2 ---\n";
    MonomialInput(m2);

    cout << "Monomial 1: "; MonomialOutput(m1); cout << endl;
    cout << "Monomial 2: "; MonomialOutput(m2); cout << endl;

    double x;
    cout << "\nEnter value of x = ";
    cin >> x;
    cout << "Value of Monomial 1 at x = " << x << " is: " << m1.CalculateValue(x) << endl;

    cout << "\nDerivative of Monomial 1: ";
    MonomialOutput(m1.Derivative());
    cout << endl;

    cout << "Antiderivative of Monomial 1: ";
    MonomialOutput(m1.Antiderivative());
    cout << endl;

    cout << "\n--- ARITHMETIC OPERATIONS ---";
    cout << "\nMonomial 1 + Monomial 2 = "; MonomialOutput(m1 + m2);
    cout << "\nMonomial 1 - Monomial 2 = "; MonomialOutput(m1 - m2);
    cout << "\nMonomial 1 * Monomial 2 = "; MonomialOutput(m1 * m2);
    cout << "\nMonomial 1 / Monomial 2 = "; MonomialOutput(m1 / m2);

    cout << "\n\n--- COMPARISON ---";
    if (m1 == m2) {
        cout << "\nTwo monomials are EQUAL (==).";
    } else {
        cout << "\nTwo monomials are DIFFERENT (!=).";
    }

    cout << endl;
    return 0;
}