#include <iostream>
#include <iomanip>
using namespace std;

class Matrix{
    private:
        int n;
        double *data;
        void allocateMemory(){
            data = new double[n*n];
            for (int i = 0; i < n*n; i++){
                data[i] = 0;
            }
        }
        void freeMemory(){
            if (data!=nullptr){
                delete[] data;
                data = nullptr;
            }
        }
    public:
        Matrix(int size = 1){
            n = (size > 0) ? size : 1;
            allocateMemory();
        }
        Matrix(const Matrix& other){
            n = other.n;
            allocateMemory();
            for (int i = 0; i < n*n; i++){
                data[i] = other.data[i];
            }
        }
        ~Matrix(){
            freeMemory();
        }
        Matrix& operator=(const Matrix& other){
            if (this != &other){
                freeMemory();
                n = other.n;
                allocateMemory();
                for (int i = 0; i < n*n; i++){
                    data[i] = other.data[i];
                }
            }
            return *this;
        }
        double operator()(int i, int j) const{
            return data[(i-1)*n + (j-1)];
        }
        Matrix operator+(const Matrix& other) const{
            if (n != other.n){
                cout << "Loi, hai ma tran khong cung cap!\n";
                return *this;
            }
            Matrix result(n);
            for (int i = 0; i < n*n; i++){
                result.data[i] = data[i] + other.data[i];
            }
            return result;
        }
        Matrix operator-(const Matrix& other) const{
            if (n != other.n){
                cout << "Loi, hai ma tran khong cung cap!\n";
                return *this;
            }
            Matrix result(n);
            for (int i = 0; i < n*n; i++){
                result.data[i] = data[i] - other.data[i];
            }
            return result;
        }
        Matrix operator*(const Matrix& other) const{
            if (n != other.n){
                cout << "Loi, hai ma tran khong cung cap!\n";
                return *this;
            }
            Matrix result(n);
            for (int i = 0; i < n*n; i++){
                for (int j = 0; j < n*n; j++){
                    result.data[i*n + j] = 0;
                    for (int k = 0; k < n; k++){
                        result.data[i*n+j] += data[i*n+k] * other.data[k*n + j];
                    }
                }
            }
            return result;
        }
        Matrix& operator+=(const Matrix& other){
            if (n != other.n){
                cout << "Loi, hai ma tran khong cung cap!\n";
                return *this;
            }
            for (int i = 0; i < n*n; i++){
                data[i] += other.data[i];
            }
            return *this;
        }
        friend istream& operator>>(istream& in, Matrix& m){
            cout << "Nhap cap cua ma tran vuong n: \n";
            in >> m.n;
            m.freeMemory();
            m.allocateMemory();
            cout << "Nhap cac phan tu cua ma tran vuong: \n";
            for (int i = 1; i <= m.n; i++){
                for (int j = 1; j <= m.n; j++){
                    cout << "a[" << i << "][" << j << "] = ";
                    in >> m.data[(i-1)*m.n + (j-1)];
                }
            }
            return in;
        }
        friend ostream& operator<<(ostream& out, const Matrix& m){
            for (int i = 0; i < m.n; i++){
                out << " |";
                for (int j = 0; j < m.n; j++){
                    out << setw(8) << m.data[i*m.n+j] << " ";
                }
                out << "|\n";
            }
            return out;
        }
    };
int main(){
    Matrix A, B;
    cout << "Nhap ma tran A\n";
    cin >> A;
    cout << "Nhap ma tran B\n";
    cin >> B;
    cout << "Ma tran A: \n" << A << "\n";
    cout << "Ma tran B: \n" << B << "\n";
    Matrix sum = A + B;
    cout << "Tong cua 2 ma tran A va B la: \n" << sum << "\n";
    Matrix dif = A - B;
    cout << "Hieu cua 2 ma tran A va B la: \n" << dif << "\n";
    Matrix pro = A * B;
    cout << "Tich cua 2 ma tran A va B la: \n" << pro << "\n";
    int r, c;
    cout << "Nhap chi so hang r (tu 1) \n";
    cin >> r;
    cout << "Nhap chi so cot c (tu 1) \n";
    cin >> c;
    cout << "Gia tri phan tu tai hang " << r << "cot " << c << " la: " << A(r,c) << "\n";
    A += B;
    cout << "Ma tran A sau khi thuc hien (A += B): \n" << A << "\n";
    return 0;
}