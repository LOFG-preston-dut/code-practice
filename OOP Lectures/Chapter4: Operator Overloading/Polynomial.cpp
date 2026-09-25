#include <iostream>
#include <cmath>
using namespace std;

class Polynomial{
    private:
        int deg;
        double *coeffs;
    public:
        Polynomial(int d = 0){
            deg = d;
            coeffs = new double[deg+1];
            for (int i = 0; i <= deg; i++) coeffs[i] = 0;
        }
        Polynomial(const Polynomial& other){
            deg = other.deg;
            coeffs = new double[deg+1];
            for (int i = 0; i <= deg; i++) coeffs[i] = other.coeffs[i];
        }
        ~Polynomial(){
            delete[] coeffs;
        }
        Polynomial& operator=(const Polynomial& other){
            if (this!=&other){
                delete[] coeffs;
                deg = other.deg;
                coeffs = new double[deg+1];
                for (int i = 0; i <= deg; i++) coeffs[i] = other.coeffs[i];
            }
            return *this;
        }
        Polynomial operator+(const Polynomial& other) const{
            int maxDeg = max(deg, other.deg);
            Polynomial result(maxDeg);
            for (int i = 0; i <= maxDeg; i++){
                double a = (i <= deg) ? coeffs[i] : 0;
                double b = (i <= other.deg) ? other.coeffs[i] : 0;
                result.coeffs[i] = a + b;
            }
            return result;
        }
        Polynomial operator-(const Polynomial& other) const{
            int maxDeg = max(deg, other.deg);
            Polynomial result(maxDeg);
            for (int i = 0; i <= maxDeg; i++){
                double a = (i <= deg) ? coeffs[i] : 0;
                double b = (i <= other.deg) ? other.coeffs[i] : 0;
                result.coeffs[i] = a - b;
            }
            return result;
        }
        double& operator[](int idx){
            return coeffs[idx];
        }
        double operator()() const{
            double x;
            cout << "Nhap gia tri x tu ban phim: ";
            cin >> x;
            double result = 0;
            for (int i = 0; i <= deg; i++){
                result += coeffs[i]*pow(x,i);
            }
            return result;
        }
        friend istream& operator>>(istream& in, Polynomial& p){
            cout << "Nhap bac cua da thuc tu ban phim: ";
            in >> p.deg;
            delete[] p.coeffs;
            p.coeffs = new double[p.deg+1];
            for (int i = p.deg; i>=0; i--){
                cout << "He so cua x^" << i << " la: ";
                in >> p.coeffs[i];
            }
            return in;
        }
        friend ostream& operator<<(ostream& out, const Polynomial& p) {
            bool f = true;
            for (int i = p.deg; i >= 0; i--){
                if (p.coeffs[i] != 0){
                    if (!f && p.coeffs[i] > 0) out << " + ";
                    if (p.coeffs[i] < 0) out << " - ";
                    out << abs(p.coeffs[i]);
                    if(i > 0) out << "x^"<< i;
                    f = false;
                }
            }
            if (f) out << "0";
            return out;
        }
};
int main(){
    Polynomial p1, p2;
    cout << "Nhap da thuc P1\n";
    cin >> p1;
    cout << "Nhap da thuc P2\n";
    cin >> p2;
    cout << "\nP1(x) = " << p1 << "\n";
    cout << "\nP2(x) = " << p2 << "\n";
    Polynomial p3 = p1 + p2;
    cout << "P1 + P2 = " << p3 << "\n";
    Polynomial p4 = p1 - p2;
    cout << "P1 - P2 = " << p4 << "\n";
    cout << "\n Gia tri cua p1 voi x nhap tu ban phim \n ";
    cout << p1() << "\n";
    return 0; 
}