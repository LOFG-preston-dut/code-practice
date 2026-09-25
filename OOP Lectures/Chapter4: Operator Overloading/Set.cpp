#include <iostream>
using namespace std;

class Set{
    private: 
        int size;
        int *data;
    public:
        Set(int s = 0){
            size = s;
            if (size > 0){
                data = new int[size];
            }
            else{
                size = 0;
                data = nullptr;
        }
        }
        Set(const Set& other){
            size = other.size;
            if (size > 0){
                data = new int[size];
                for (int i = 0; i < size; i++){
                    data[i] = other.data[i];
                }
            }else{
                data = nullptr;
        }
        }
        ~Set(){
            delete[] data;
        }
        Set& operator=(const Set& other){
            if (this!=&other){
                delete[] data;
                size = other.size;
                if (size > 0){
                    data = new int[size];
                    for (int i = 0; i < size; i++){
                        data[i] = other.data[i];
                    }
                }else{
                    data = nullptr;
            }
        }
        return *this;
        }
        bool contains(int x) const{
            for (int i = 0; i < size; i++){
                if (data[i] == x) return true;
            }
            return false;
        }
        void insert(int x){
            if (!contains(x)){
                int *tmp = new int[size+1];
                for (int i = 0; i < size; i++){
                    tmp[i] = data[i];
                }
                tmp[size] = x;
                delete[] data;
                data = tmp;
                size++;
            }
        }
        Set operator+(const Set& other) const{
            Set result = *this;
            for (int i = 0; i < other.size; i++){
                result.insert(other.data[i]);
            }
            return result;
        }
        Set operator*(const Set& other) const{
            Set result;
            for (int i = 0; i < size; i++){
                if (other.contains(data[i])){
                    result.insert(data[i]);
                }
            }
            return result;
        }
        Set operator-(const Set& other) const{
            Set result;
            for (int i = 0; i < size; i++){
                if (!other.contains(data[i])){
                    result.insert(data[i]);
                }
            }
            return result;
        }
        int operator[](int idx) const{
            if (idx >= 0 && idx < size){
                return data[idx];
            }
            return -1;
        }
        bool operator==(const Set& other) const{
            if (size != other.size) return false;
            for (int i = 0; i < size; i++){
                if (!other.contains(data[i])) return false;
            }
            return true;
        }
        friend istream& operator>>(istream& in, Set& s){
            int n, val;
            cout << "Nhap so luong phan tu cua tap hop: ";
            in >> n;
            delete[] s.data;
            s.size = 0;
            s.data = nullptr;
            for (int i = 0; i < n; i++){
                cout << "Phan tu thu " << i+1 << ": ";
                in >> val;
                s.insert(val);
            }
            return in;
        }
        friend ostream& operator<<(ostream& out, const Set& s){
            out <<"{ ";
            for (int i = 0; i < s.size; i++){
                out << s.data[i];
                if (i < s.size-1) out << "; ";
            }
            out << " }";
            return out;
        }
};
int main(){
    Set A, B;
    cout << "Nhap tap hop A \n";
    cin >> A;
    cout << "Nhap tap hop B \n";
    cin >> B;
    cout << "Tap hop A = " << A << "\n";
    cout << "Tap hop B = " << B << "\n";
    Set hop = A + B;
    Set giao = A * B;
    Set hieu = A - B;
    cout << "Hop cua A va B = " << hop << "\n";
    cout << "Giao cua A va B = " << giao << "\n";
    cout << "Hieu cua A va B = " << hieu << "\n";
    if (A == B){
        cout << "A va B BANG NHAU \n";
    }
    else{
        cout << "A va B KHAC NHAU \n";
    }
    return 0;
}