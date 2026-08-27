#include <iostream>

using namespace std;

struct Student {
    char fullName[50];
    float literatureScore;
    float mathScore;
    float averageScore;
};

struct Node {
    Student data;
    Node* next;
};

struct LinkedList {
    Node* head;
};

void initList(LinkedList& list) {
    list.head = NULL;
}

Node* createNode(Student student) {
    Node* p = new Node;
    p->data = student;
    p->next = NULL;
    return p;
}

float calculateAverage(float literature, float math) {
    return (literature + math) / 2.0;
}

void printGrade(float average) {
    if (average >= 8.0) {
        cout << "Gioi";
    } else if (average >= 7.0) {
        cout << "Kha";
    } else if (average >= 5.0) {
        cout << "Trung binh";
    } else {
        cout << "Yeu";
    }
}

void inputStudent(Student& student) {
    cin.ignore();
    cout << "Nhap ho ten: ";
    cin.getline(student.fullName, 50);
    cout << "Nhap diem Van: ";
    cin >> student.literatureScore;
    cout << "Nhap diem Toan: ";
    cin >> student.mathScore;
    student.averageScore = calculateAverage(student.literatureScore, student.mathScore);
}

void appendNode(LinkedList& list, Student student) {
    Node* p = createNode(student);
    if (list.head == NULL) {
        list.head = p;
    } else {
        Node* temp = list.head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void inputStudentList(LinkedList& list, int count) {
    for (int i = 0; i < count; i++) {
        cout << "\n--- Nhap hoc sinh thu " << i + 1 << " ---\n";
        Student student;
        inputStudent(student);
        appendNode(list, student);
    }
}

void printStudent(Student student) {
    cout << "Ho ten: " << student.fullName << endl;
    cout << "Diem Van: " << student.literatureScore << endl;
    cout << "Diem Toan: " << student.mathScore << endl;
    cout << "Diem Trung Binh: " << student.averageScore << endl;
    cout << "Xep loai: ";
    printGrade(student.averageScore);
    cout << endl;
}

void printStudentList(LinkedList list) {
    cout << "\n=== DANH SACH HOC SINH ===\n";
    Node* temp = list.head;
    int index = 1;
    while (temp != NULL) {
        cout << "\nHoc sinh " << index++ << ":\n";
        printStudent(temp->data);
        temp = temp->next;
    }
}

void freeList(LinkedList& list) {
    Node* temp = list.head;
    while (temp != NULL) {
        Node* p = temp;
        temp = temp->next;
        delete p;
    }
    list.head = NULL;
}

int main() {
    LinkedList list;
    initList(list);

    int count;
    cout << "Nhap so luong hoc sinh: ";
    cin >> count;

    if (count > 0) {
        inputStudentList(list, count);
        printStudentList(list);
    }

    freeList(list);
    return 0;
}