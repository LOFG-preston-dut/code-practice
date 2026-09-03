#include <iostream>
#include <cmath>
using namespace std;

struct Fraction{
    int Numerator;
    int Denominator;
};

int GCD(int a, int b){
    a = abs(a);
    b = abs(b);
    while (b != 0){
        int r = a % b;
        a = b;
        b = r;
        }
    return a;
}

void Simplify(Fraction &Fr){
    if (Fr.Denominator < 0){
        Fr.Numerator = - Fr.Numerator;
        Fr.Denominator = - Fr.Denominator;
    }
    int gcd = GCD(Fr.Numerator, Fr.Denominator);
    if (gcd > 0){
        Fr.Numerator /= gcd;
        Fr.Denominator /= gcd;
    }
}

void FractionInput(Fraction &Fr){
    cout << "Enter the numerator and denominator of the fraction: " << endl;
    cin >> Fr.Numerator;
    do{
    cin >> Fr.Denominator;
    if (Fr.Denominator == 0){
        cout << "Please enter the valid denominator: " << endl;
    }
    } while (Fr.Denominator == 0);
    Simplify(Fr);
}

void FractionOutput(Fraction Fr){
    if (Fr.Denominator == 1) cout << Fr.Numerator;
    else if (Fr.Numerator== 0) cout << "0";
    else cout << Fr.Numerator << "/" << Fr.Denominator << endl;
}

Fraction Inversion(Fraction Fr){
    if (Fr.Numerator == 0){
        cout << "This fraction can not be inversed.\n";
    return Fr;
}
    Fraction FrIn = {Fr.Denominator, Fr.Numerator};
    Simplify(FrIn);
    return FrIn;
}

Fraction Addition(Fraction a, Fraction b){
    Fraction Result;
    Result.Numerator = a.Numerator * b.Denominator + a.Denominator * b.Numerator;
    Result.Denominator = a.Denominator * b.Denominator;
    Simplify(Result);
    return Result;
}

Fraction Subtraction(Fraction a, Fraction b){
    Fraction Result;
    Result.Numerator = a.Numerator * b.Denominator - a.Denominator * b.Numerator;
    Result.Denominator = a.Denominator * b.Denominator;
    Simplify(Result);
    return Result;
}

Fraction Multiplication(Fraction a, Fraction b){
    Fraction Result;
    Result.Numerator = a.Numerator * b.Numerator;
    Result.Denominator = a.Denominator * b.Denominator;
    Simplify(Result);
    return Result;
}

Fraction Division(Fraction a, Fraction b){
    Fraction Result;
    if (b.Numerator == 0){
        cout << "The numerator of the second fraction must be different from 0. \n";
        return a; 
    }
    Result.Numerator = a.Numerator * b.Denominator;
    Result.Denominator = a.Denominator * b.Numerator;
    Simplify(Result);
    return Result;
}

bool Equalization(Fraction a, Fraction b){
    return (a.Numerator * b.Denominator == a.Denominator* b.Numerator);
}

bool Difference(Fraction a, Fraction b){
    return !Equalization(a,b);
}

int main() {
    Fraction fr1, fr2;

    FractionInput(fr1);
    FractionInput(fr2);

    cout << "Fraction 1: ";
    FractionOutput(fr1);
    cout << "Fraction 2: ";
    FractionOutput(fr2);

    cout << "Inverse of fraction 1: ";
    FractionOutput(Inversion(fr1));

    cout << "Addition: ";
    FractionOutput(Addition(fr1, fr2));

    cout << "Subtraction: ";
    FractionOutput(Subtraction(fr1, fr2));

    cout << "Multiplication: ";
    FractionOutput(Multiplication(fr1, fr2));

    cout << "Division: ";
    FractionOutput(Division(fr1, fr2));

    if (Equalization(fr1, fr2)) {
        cout << "Fractions are equal." << endl;
    } 
    if (Difference(fr1, fr2)) {
        cout << "Fractions are different." << endl;
    }

    return 0;
}