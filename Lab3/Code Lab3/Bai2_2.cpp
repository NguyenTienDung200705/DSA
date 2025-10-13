#include<iostream>
#include<algorithm>
using namespace std;

int binarySearch(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x){
            return mid; 
        }
        else if (a[mid] < x) {
            left = mid + 1; 
        }
        else { 
            right = mid - 1;
        }
    }
    return -1; 
}
int findPairWithSum(int a[], int n, int sum) {
    for (int i = 0; i < n; i++) {
        int x = sum - a[i];
        int index = binarySearch(a, n, x);
        if (index != -1 && index != i) {
            cout << "Pair : (" << a[i] << ", " << a[index] << ")" << endl;
            return 1; 
        }
    }
    cout << "khong thoa man" << endl;
    return 0; 
}
void nhapMang(int a[], int m) {
    for (int i = 0; i < m; i++) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> a[i];
    }
}
void xuatMang(int a[], int m) {
    cout << "Mang vua nhap: ";
    for (int i = 0; i < m; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main() {
    int a[100] ,m, sum; 
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> m;
    cout << "Nhap gia tri sum: ";
    cin >> sum;

    nhapMang(a, m);
    sort(a, a + m); 
    xuatMang(a, m);
    findPairWithSum(a, m, sum);
    
    return 0;
}
