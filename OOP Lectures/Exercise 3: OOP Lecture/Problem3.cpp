#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Date {
private:
    int d, m, y;
public:
    Date() : d(1), m(1), y(2000) {}
    Date(int day, int month, int year) : d(day), m(month), y(year) {}
    Date(const Date& other) : d(other.d), m(other.m), y(other.y) {}
    ~Date() {}
    int getD() const { return d; }
    int getM() const { return m; }
    int getY() const { return y; }
    void setD(int day) { d = day; }
    void setM(int month) { m = month; }
    void setY(int year) { y = year; }
    friend istream& operator>>(istream& in, Date& dt) {
        cout << "  Nhap ngay: "; in >> dt.d;
        cout << "  Nhap thang: "; in >> dt.m;
        cout << "  Nhap nam: "; in >> dt.y;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Date& dt) {
        if (dt.d < 10) out << "0";
        out << dt.d << "/";
        if (dt.m < 10) out << "0";
        out << dt.m << "/" << dt.y;
        return out;
    }
};
class NhanVien {
private:
    string MaNV;
    string TenNV;
    Date NgayVao;
    bool Gioi;
    double HSLuong;
    double Luong;

public:
    NhanVien() : MaNV("00000000"), TenNV("Chua biet"), Gioi(false), HSLuong(1.0), Luong(0) {}
    NhanVien(string ma, string ten, Date ngay, bool gt, double heSo) 
        : MaNV(ma), TenNV(ten), NgayVao(ngay), Gioi(gt), HSLuong(heSo) {
        tinhLuong();
    }
    NhanVien(const NhanVien& other) 
        : MaNV(other.MaNV), TenNV(other.TenNV), NgayVao(other.NgayVao), 
          Gioi(other.Gioi), HSLuong(other.HSLuong), Luong(other.Luong) {}

    ~NhanVien() {}
    string getmanv() const {
        return MaNV;
    }
    double tinhThamNien() const {
        int namLamViec = 2026 - NgayVao.getY();
        return (namLamViec < 0) ? 0 : namLamViec;
    }
    void tinhLuong() {
        double soNam = tinhThamNien();
        double phuCap = (soNam < 5) ? 0 : (soNam / 100.0);
        Luong = (HSLuong * 2390000.0) * (1.0 + phuCap);
    }
    friend istream& operator>>(istream& in, NhanVien& nv) {
        cout << "Nhap ma NV (8 ky tu): ";
        in >> ws;
        getline(in, nv.MaNV);
        cout << "Nhap ten NV: ";
        getline(in, nv.TenNV);
        cout << "Nhap ngay vao lam:\n";
        in >> nv.NgayVao;
        cout << "Gioi tinh (1 = Nu, 0 = Nam): ";
        in >> nv.Gioi;
        cout << "Nhap he so luong: ";
        in >> nv.HSLuong;
        nv.tinhLuong();
        return in;
    }
    friend ostream& operator<<(ostream& out, const NhanVien& nv) {
        out << "Ma NV: " << nv.MaNV 
            << " | Ten: " << nv.TenNV 
            << " | Ngay vao: " << nv.NgayVao 
            << " | Gioi tinh: " << (nv.Gioi ? "Nu" : "Nam")
            << " | He so: " << nv.HSLuong
            << " | Luong: " << fixed << setprecision(0) << nv.Luong << " VND";
        return out;
    }
};
struct Node {
    NhanVien data;
    Node* next;
    Node(const NhanVien& nv) : data(nv), next(nullptr) {}
};
class List {
private:
    Node *head;
    Node *tail;
    int size;
public:
    List() : head(nullptr), tail(nullptr), size(0) {}
    List(const List& other) : head(nullptr), tail(nullptr), size(0) {
        Node* curr = other.head;
        while (curr != nullptr) {
            addTail(curr->data);
            curr = curr->next;
        }
    }
    ~List() {
        while (head != nullptr) {
            deleteHead();
        }
    }
    void addHead(const NhanVien& nv) {
        Node* newNode = new Node(nv);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    void addTail(const NhanVien& nv) {
        Node* newNode = new Node(nv);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void addAtK(const NhanVien& nv, int k) {
        if (k <= 0) {
            addHead(nv);
            return;
        }
        if (k >= size) {
            addTail(nv);
            return;
        }
        Node* newNode = new Node(nv);
        Node* curr = head;
        for (int i = 0; i < k - 1; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }
    void deleteHead() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        if (head == nullptr) tail = nullptr;
    }
    void deleteTail() {
        if (head == nullptr) return;
        if (head == tail) {
            deleteHead();
            return;
        }
        Node* curr = head;
        while (curr->next != tail) {
            curr = curr->next;
        }
        delete tail;
        tail = curr;
        tail->next = nullptr;
        size--;
    }
    void deleteAtK(int k) {
        if (k <= 0) {
            deleteHead();
            return;
        }
        if (k >= size - 1) {
            deleteTail();
            return;
        }
        Node* curr = head;
        for (int i = 0; i < k - 1; i++) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        size--;
    }
    NhanVien* operator()(string maCanTim) {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->data.getmanv() == maCanTim) {
                return &(curr->data); 
            }
            curr = curr->next;
        }
        return nullptr; 
    }
    void sortList(bool (*cmp)(const NhanVien&, const NhanVien&)) {
        if (head == nullptr || head->next == nullptr) return;
        for (Node* i = head; i->next != nullptr; i = i->next) {
            Node* minNode = i; 
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (cmp(minNode->data, j->data)) {
                    minNode = j;
                }
            }
            if (minNode != i) {
                NhanVien temp = i->data;
                i->data = minNode->data;
                minNode->data = temp;
            }
        }
    }
    friend ostream& operator<<(ostream& out, const List& l) {
        if (l.head == nullptr) {
            out << "Danh sach trong!\n";
            return out;
        }
        Node* curr = l.head;
        int i = 1;
        while (curr != nullptr) {
            out << "[" << i++ << "] " << curr->data << endl;
            curr = curr->next;
        }
        return out;
    }
};
bool cmpMaNV(const NhanVien& a, const NhanVien& b) {
    return a.getmanv() > b.getmanv();
}
int main() {
    List danhSach;
    int luaChon;
    do {
        cout << "\n================ MENU QUAN LY ===============";
        cout << "\n1. Xem danh sach nhan vien";
        cout << "\n2. Them nhan vien vao dau";
        cout << "\n3. Them nhan vien vao cuoi";
        cout << "\n4. Them nhan vien vao vi tri K";
        cout << "\n5. Xoa nhan vien o dau";
        cout << "\n6. Xoa nhan vien o cuoi";
        cout << "\n7. Xoa nhan vien o vi tri K";
        cout << "\n8. Tim kiem theo ma (Dung toan tu ())";
        cout << "\n9. Sap xep danh sach theo Ma NV";
        cout << "\n0. Thoat";
        cout << "\n=============================================";
        cout << "\nMoi nguoi dung chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                cout << "\n--- DANH SACH NHAN VIEN ---\n";
                cout << danhSach;
                break;
            }
            case 2: {
                NhanVien nv;
                cout << "\nNhap thong tin nhan vien moi:\n";
                cin >> nv;
                danhSach.addHead(nv);
                cout << "=> Da them vao dau danh sach!\n";
                break;
            }
            case 3: {
                NhanVien nv;
                cout << "\nNhap thong tin nhan vien moi:\n";
                cin >> nv;
                danhSach.addTail(nv);
                cout << "=> Da them vao cuoi danh sach!\n";
                break;
            }
            case 4: {
                NhanVien nv;
                int k;
                cout << "Nhap vi tri can them (tinh tu 0): ";
                cin >> k;
                cout << "\nNhap thong tin nhan vien moi:\n";
                cin >> nv;
                danhSach.addAtK(nv, k);
                cout << "=> Da them vao vi tri " << k << "!\n";
                break;
            }
            case 5: {
                danhSach.deleteHead();
                cout << "=> Da xoa nhan vien dau tien!\n";
                break;
            }
            case 6: {
                danhSach.deleteTail();
                cout << "=> Da xoa nhan vien cuoi cung!\n";
                break;
            }
            case 7: {
                int k;
                cout << "Nhap vi tri can xoa (tinh tu 0): ";
                cin >> k;
                danhSach.deleteAtK(k);
                cout << "=> Da xoa nhan vien o vi tri " << k << "!\n";
                break;
            }
            case 8: {
                string ma;
                cout << "Nhap Ma NV can tim: ";
                cin >> ma;
                NhanVien* ketQua = danhSach(ma);
                if (ketQua != nullptr) {
                    cout << "=> Tim thay: \n" << *ketQua << endl;
                } else {
                    cout << "=> Khong tim thay!\n";
                }
                break;
            }
            case 9: {
                danhSach.sortList(cmpMaNV);
                cout << "=> Da sap xep xong xuoi bang thuat toan chon truc tiep!\n";
                break;
            }
            case 0:
                cout << "Cam on quy khach!\n";
                break;
            default:
                cout << "Vui long nhap tu 0 den 9!\n";
                break;
        }
    } while (luaChon != 0);
    return 0;
}