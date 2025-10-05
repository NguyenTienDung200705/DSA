#include <iostream>
using namespace std;

void nhapMang(int arr[], int &n){
    cout << "Nhap so phan tu :";
    cin >> n;
    cout << "Nhap " << n << " phan tu :\n";
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

}
void inMang(int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int tong(int arr[], int n){
    int S = 0;
    for (int i=0; i<n; i++){
        S += arr[i];
    }
    return S;
}
int timMax(int arr[], int n){
    int max = arr[0];
    for (int i=1; i<n; i++){
        if (arr[i] > max) max = arr[i];
    }
    return max;
}
int timMin(int arr[], int n){
    int min = arr[0];
    for (int i=1; i<n; i++){
        if (arr[i] < min) min = arr[i];
    }
    return min;
}
void sapXep(int arr[], int n){
    for (int i=0; i<n-1; i++){
        for (int j = i+1; j<n; j++){
            if (arr[i] > arr[j]){
                int k = arr[i];
                arr[i] = arr[j];
                arr[j] = k;
            }
        }
    }
}

int main (){
    int n;
    int arr[100];
    nhapMang(arr, n);
    cout << "Mang vua nhap :";
    inMang(arr, n);

    cout << "Tong cac phan tu : " << tong(arr, n) << endl;
    cout << "Phan tu lon nhat : " << timMax(arr, n) << endl;
    cout << "Phan tu nho nhat : " << timMin(arr, n) << endl;

    sapXep(arr, n);
    cout << "Mang sau khi sap xep : ";
    for (int i = 0;i<n ;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}