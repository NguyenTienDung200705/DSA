#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string id;
    string name;
    int age;
    double gpa;

public:
    Student() {
        id = "";
        name = "";
        age = 0;
        gpa = 0.0;
    }
    Student(string id, string name, int age, double gpa) {
        setId(id);
        setName(name);
        setAge(age);
        setGpa(gpa);
    }
    void setId(string idValue) {
        if (idValue.empty()) {
            id = "rong";
        } else {
            id = idValue;
        }
    }
    string getId() { 
        return id; 
    }

    void setName(string nameValue) {
        if (nameValue.empty()) {
            name = "No Ten";
        } else {
            name = nameValue;
        }
    }
    string getName() { 
        return name; 
    }

    void setAge(int ageValue) {
        if (ageValue <= 0 || ageValue > 100) {
            cout << "Tuoi sai !\n";
        } else {
            age = ageValue;
        }
    }
    int getAge() { 
        return age; 
    }

    void setGpa(double gpaValue) {
        if (gpaValue < 0.0 || gpaValue > 10.0) {
            gpa = 0.0;
        } else {
            gpa = gpaValue;
        }
    }
    double getGpa() { 
        return gpa; 
    }

    string getPhanLoai() {
        if (gpa >= 8.5) return "Gioi";
        else if (gpa >= 7.0) return "Kha";
        else if (gpa >= 5.0) return "Trung binh";
        else return "Yeu";
    }

    void displayInfo() {
        cout << "ID: " << id
             << ", Ten: " << name
             << ", Tuoi: " << age
             << ", GPA: " << gpa
             << ", Xep loai: " << getPhanLoai()
             << endl;
    }

};
void nhapDanhSach(vector<Student>& ds) {
    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
        string id, name;
        int age;
        double gpa;

        cout << "ID: ";
        getline(cin, id);
        cout << "Ten: ";
        getline(cin, name);
        cout << "Tuoi: ";
        cin >> age;
        cout << "GPA: ";
        cin >> gpa;
        cin.ignore();

        ds.push_back(Student(id, name, age, gpa));
    }
}
int main() {
    vector<Student> students;
    nhapDanhSach(students);
    
    cout << "\nDanh sach sinh vien:\n";
    for (auto& sv : students) {
        if (sv.getPhanLoai() == "Gioi") {
            sv.displayInfo();
        }
        if (sv.getPhanLoai() == "Kha") {
            sv.displayInfo();
        }
        if (sv.getPhanLoai() == "Trung binh") {
            sv.displayInfo();
        }
        if (sv.getPhanLoai() == "Yeu") {
            sv.displayInfo();
        }
    }
    return 0;
}
