#include <iostream>
using namespace std;

int CountX(int a[], int left, int right, int X){
    if (left == right) {
        if (a[left] == X){
                return 1;
        }
        else return 0;
    }
    int mid = (left + right) / 2;
    return CountX(a, left, mid, X) + CountX(a, mid + 1, right, X);
}
int main() {
    int n;
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    int a[n];
    cout << "Nhap cac phan tu mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int X;
    cout << "Nhap gia tri X can dem: ";
    cin >> X;
    int count = CountX(a, 0, n - 1, X);
    cout << "So lan xuat hien cua " << X << " trong mang la: " << count << endl;
    return 0;
}