#include <iostream>

using namespace std;

// Cấu trúc biểu diễn số phức: z = a + bi
struct SoPhuc {
    double thuc; // Phần thực
    double ao;   // Phần ảo
};

// Hàm nhập số phức
void nhapSoPhuc(SoPhuc &z, const string &ten) {
    cout << "Nhap " << ten << ":" << endl;
    cout << "  Phan thuc: ";
    cin >> z.thuc;
    cout << "  Phan ao: ";
    cin >> z.ao;
}

// Hàm xuất số phức dạng a + bi
void xuatSoPhuc(const SoPhuc &z) {
    if (z.ao >= 0) {
        cout << z.thuc << " + " << z.ao << "i";
    } else {
        cout << z.thuc << " - " << -z.ao << "i";
    }
}

// Phép cộng: (a + bi) + (c + di) = (a + c) + (b + d)i
SoPhuc cong(const SoPhuc &z1, const SoPhuc &z2) {
    SoPhuc ketQua;
    ketQua.thuc = z1.thuc + z2.thuc;
    ketQua.ao = z1.ao + z2.ao;
    return ketQua;
}

// Phép trừ: (a + bi) - (c + di) = (a - c) + (b - d)i
SoPhuc tru(const SoPhuc &z1, const SoPhuc &z2) {
    SoPhuc ketQua;
    ketQua.thuc = z1.thuc - z2.thuc;
    ketQua.ao = z1.ao - z2.ao;
    return ketQua;
}

// Phép nhân: (a + bi)*(c + di) = (ac - bd) + (ad + bc)i
SoPhuc nhan(const SoPhuc &z1, const SoPhuc &z2) {
    SoPhuc ketQua;
    ketQua.thuc = z1.thuc * z2.thuc - z1.ao * z2.ao;
    ketQua.ao = z1.thuc * z2.ao + z1.ao * z2.thuc;
    return ketQua;
}

// Phép chia: (a + bi)/(c + di) = [(ac + bd) + (bc - ad)i] / (c^2 + d^2)
bool chia(const SoPhuc &z1, const SoPhuc &z2, SoPhuc &ketQua) {
    double mauSo = z2.thuc * z2.thuc + z2.ao * z2.ao;
    
    // Kiểm tra mẫu số bằng 0 (số phức thứ 2 bằng 0)
    if (mauSo == 0) {
        return false;
    }
    
    ketQua.thuc = (z1.thuc * z2.thuc + z1.ao * z2.ao) / mauSo;
    ketQua.ao = (z1.ao * z2.thuc - z1.thuc * z2.ao) / mauSo;
    return true;
}

int main() {
    SoPhuc z1, z2, ketQua;

    // Nhập dữ liệu
    nhapSoPhuc(z1, "so phuc z1");
    cout << endl;
    nhapSoPhuc(z2, "so phuc z2");
    cout << endl;

    // Hiển thị số phức đã nhập
    cout << "z1 = "; xuatSoPhuc(z1); cout << endl;
    cout << "z2 = "; xuatSoPhuc(z2); cout << endl;
    cout << "-----------------------------------" << endl;

    // Phép cộng
    ketQua = cong(z1, z2);
    cout << "z1 + z2 = "; xuatSoPhuc(ketQua); cout << endl;

    // Phép trừ
    ketQua = tru(z1, z2);
    cout << "z1 - z2 = "; xuatSoPhuc(ketQua); cout << endl;

    // Phép nhân
    ketQua = nhan(z1, z2);
    cout << "z1 * z2 = "; xuatSoPhuc(ketQua); cout << endl;

    // Phép chia
    if (chia(z1, z2, ketQua)) {
        cout << "z1 / z2 = "; xuatSoPhuc(ketQua); cout << endl;
    } else {
        cout << "z1 / z2 = Khong the chia vi z2 = 0!" << endl;
    }

    return 0;
}