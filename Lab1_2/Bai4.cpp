#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

class NhanVien {
protected:
    string ten;
    int tuoi;
    double luongCoBan;
public:
    NhanVien(string n = "", int t = 0, double l = 0.0): 
        ten(n), tuoi(t), luongCoBan(l) {}

    virtual double tinhLuong() const {
        return luongCoBan;
    }

    virtual void hienThiThongTin() const {
        cout << "Ten: " << ten 
             << ", Tuoi: " << tuoi 
             << ", Luong co ban: " << luongCoBan;
    }

    virtual string loaiNhanVien() const {
        return "NhanVien";
    }

    virtual ~NhanVien() {}
};

class QuanLy :
public NhanVien {
    private:
        double phuCapQuanLy;
    public:
        QuanLy(string n = "", int t = 0, double l = 0.0, double pc = 0.0):
            NhanVien(n, t, l), phuCapQuanLy(pc) {}

        double tinhLuong() const override {
            return luongCoBan + phuCapQuanLy;
        }

        void hienThiThongTin() const override {
            cout << "Quan Ly ";
            NhanVien::hienThiThongTin();
            cout << ", Phu cap: " << phuCapQuanLy
                << ", Tong luong: " << tinhLuong() << endl;
        }

        string loaiNhanVien() const override {
            return "QuanLy";
        }
};

class LapTrinhVien : public NhanVien {
private:
    string ngonNgu;
public:
    LapTrinhVien(string n = "", int t = 0, double l = 0.0, string nn = ""):
        NhanVien(n, t, l), ngonNgu(nn) {}

    void hienThiThongTin() const override {
        cout << "Lap Trinh Vien ";
        NhanVien::hienThiThongTin();
        cout << ", Ngon ngu: " << ngonNgu
             << ", Tong luong: " << tinhLuong() << endl;
    }

    string loaiNhanVien() const override {
        return "LapTrinhVien";
    }
};

void nhapDanhSachNhanVien(vector<NhanVien*>& ds) {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin nhan vien thu " << i + 1 << ":\n";
        int loai;
        cout << "Chon loai (1. Quan Ly, 2. Lap Trinh Vien): ";
        cin >> loai;
        cin.ignore();

        string ten;
        int tuoi;
        double luong;
        cout << "Ten: ";
        getline(cin, ten);
        cout << "Tuoi: ";
        cin >> tuoi;
        cout << "Luong co ban: ";
        cin >> luong;
        cin.ignore();

        if (loai == 1) {
            double phuCap;
            cout << "Phu cap quan ly: ";
            cin >> phuCap;
            ds.push_back(new QuanLy(ten, tuoi, luong, phuCap));
        } else {
            string ngonNgu;
            cout << "Ngon ngu lap trinh: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, ngonNgu);
            ds.push_back(new LapTrinhVien(ten, tuoi, luong, ngonNgu));
        }
    }
}

void menuNhanVien(vector<NhanVien*>& ds) {
    int m;
    do {
        cout << "\nMENU NHAN VIEN\n";
        cout << "1. Xem danh sach nhan vien\n";
        cout << "2. Xem tong luong cua tat ca nhan vien\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> m;

        if (m == 1) {
            cout << "\nDanh sach nhan vien\n";
            for (auto nv : ds) {
                nv->hienThiThongTin();
            }
        } 
        else if (m == 2) {
            double tong = 0;
            for (auto nv : ds) {
                tong += nv->tinhLuong();
            }
            cout << "Tong luong tat ca nhan vien: " << tong << endl;
        }

    } while (m != 0);

    cout << "Thoat chuong trinh!\n";
}

int main() {
    vector<NhanVien*> dsNhanVien;

    nhapDanhSachNhanVien(dsNhanVien);
    menuNhanVien(dsNhanVien);

    for (auto nv : dsNhanVien) {
        delete nv;
    }

    return 0;
}
