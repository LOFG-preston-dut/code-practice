#include <iostream>
using namespace std;

struct HocSinh{
    char HoTen[100];
    double DiemToan;
    double DiemVan;
};

struct Node{
    HocSinh data;
    Node* next;
};

struct LinkedList{
    Node* head = nullptr;
};

double AverageScore(HocSinh hs){
    return (hs.DiemToan + hs.DiemVan) / 2.0;
}

const char* Classification(double avg){
    if (avg >= 8.0) return "Gioi";
    else if (avg >= 7.0 && avg < 8.0) return "Kha";
    else if (avg >= 5.0 && avg < 7.0) return "Trung Binh";
    else return "Yeu";
}

void InputStudent(HocSinh &hs){
    cout << "Nhap ho ten hoc sinh: ";
    cin.ignore();
    cin.getline(hs.HoTen, 100);
    cout << "Nhap diem Toan: ";
    cin >> hs.DiemToan;
    cout << "Nhap diem Van: ";
    cin >> hs.DiemVan;
}

void OutputStudentList(LinkedList &list){
    cout << "Danh sach hoc sinh: \n";
    Node* temp = list.head;
    while (temp != nullptr){
        float average = AverageScore(temp->data);
        cout << "Ho ten: " << temp->data.HoTen << ", Diem Toan: " << temp->data.DiemToan
             << ", Diem Van: " << temp->data.DiemVan << ", Diem trung binh: " << average
             << ", Xep loai: " << Classification(average) << endl;
             temp = temp->next;
    }
}

void AddStudent(LinkedList &list, HocSinh hs){
    Node* newNode = new Node;
    newNode->data = hs;
    newNode->next = nullptr;
    if (list.head == nullptr){
        list.head = newNode;
    } else {
        Node* temp = list.head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main(){
    Node* head = nullptr;
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    LinkedList list;
    for (int i = 0; i < n; ++i){
        HocSinh hs;
        InputStudent(hs);
        AddStudent(list, hs);
    }
    OutputStudentList(list);

    return 0;
}