#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string sotaikhoan;
    string tenchutaikhoan;
    double sodu;
public:
    BankAccount() {
        sotaikhoan = "";
        tenchutaikhoan = "";
        sodu = 0;
    }

    BankAccount(string stk, string tctk, double sd = 0) {
        sotaikhoan = stk;
        tenchutaikhoan = tctk;
        if (sd >= 0) sodu = sd;
        else sodu = 0;
    }

    string getSoTaiKhoan() const {
        return sotaikhoan;
    }

    void deposit(double tien) {
        if (tien > 0) {
            sodu += tien;
            cout << "Da nap " << tien << " vao tai khoan\n";
        } else {
            cout << "sai\n";
        }
    }

    void withdraw(double tien) {
        if (tien <= 0) {
            cout << "Khong rut dc!\n";
        } else if (tien > sodu) {
            cout << "Khong du\n";
        } else {
            sodu -= tien;
            cout << "Da rut " << tien << " tu tai khoan\n";
        }
    }

    double getBalance() const {
        return sodu;
    }

    void displayInfo() const {
        cout << "Tai khoan: " << sotaikhoan
             << ", Chu tai khoan: " << tenchutaikhoan
             << ", So du: " << sodu << endl;
    }

    void transfer(BankAccount &to, double tien) {
        if (tien <= 0) {
            cout << "So tien sai!\n";
        } else if (tien > sodu) {
            cout << "So du thieu!\n";
        } else {
            sodu -= tien;
            to.sodu += tien;
            cout << "Chuyen " << tien << " thanh cong!\n";
        }
    }
};

BankAccount* findAccount(BankAccount accounts[], int n, string acc) {
    for (int i = 0; i < n; i++) {
        if (accounts[i].getSoTaiKhoan() == acc) {
            return &accounts[i];
        }
    }
    return nullptr;
}

void nhapDanhSachTaiKhoan(BankAccount accounts[], int &n) {
    cout << "Nhap so luong tai khoan: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string stk, tctk;
        double initial;
        cout << "\nNhap thong tin tai khoan " << i + 1 << ":\n";
        cout << "So tai khoan: ";
        cin >> stk;
        cin.ignore();
        cout << "Ten chu tai khoan: ";
        getline(cin, tctk);
        cout << "So du ban dau: ";
        cin >> initial;

        accounts[i] = BankAccount(stk, tctk, initial);
    }
}

void Menu(BankAccount accounts[], int n) {
    int m;
    do {
        cout << "\n MENU \n";
        cout << "1. Xem danh sach tai khoan\n";
        cout << "2. Nap tien\n";
        cout << "3. Rut tien\n";
        cout << "4. Chuyen tien\n";
        cout << "5. Xem so du\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> m;

        if (m == 1) {
            cout << "\nDanh sach tai khoan\n";
            for (int i = 0; i < n; i++) {
                accounts[i].displayInfo();
            }
        } 
        else if (m == 2) {
            string accNum;
            double amount;
            cout << "Nhap so tai khoan: ";
            cin >> accNum;
            cout << "Nhap so tien nap: ";
            cin >> amount;

            BankAccount* acc = findAccount(accounts, n, accNum);
            if (acc) acc->deposit(amount);
            else cout << "Tai khoan khong ton tai!\n";
        } 
        else if (m == 3) {
            string accNum;
            double amount;
            cout << "Nhap so tai khoan: ";
            cin >> accNum;
            cout << "Nhap so tien rut: ";
            cin >> amount;

            BankAccount* acc = findAccount(accounts, n, accNum);
            if (acc) acc->withdraw(amount);
            else cout << "Tai khoan khong ton tai!\n";
        } 
        else if (m == 4) {
            string fromAcc, toAcc;
            double amount;
            cout << "Nhap tai khoan chuyen: ";
            cin >> fromAcc;
            cout << "Nhap tai khoan nhan: ";
            cin >> toAcc;
            cout << "Nhap so tien chuyen: ";
            cin >> amount;

            BankAccount* from = findAccount(accounts, n, fromAcc);
            BankAccount* to = findAccount(accounts, n, toAcc);

            if (from && to) from->transfer(*to, amount);
            else cout << "Tai khoan khong ton tai!\n";
        } 
        else if (m == 5) {
            string accNum;
            cout << "Nhap so tai khoan: ";
            cin >> accNum;
            BankAccount* acc = findAccount(accounts, n, accNum);
            if (acc) cout << "So du hien tai: " << acc->getBalance() << endl;
            else cout << "Tai khoan khong ton tai!\n";
        }
    } while (m != 0);

    cout << "Thoat chuong trinh!\n";
}

int main() {
    int n;
    BankAccount accounts[100];

    nhapDanhSachTaiKhoan(accounts, n);
    Menu(accounts, n);

    return 0;
}
