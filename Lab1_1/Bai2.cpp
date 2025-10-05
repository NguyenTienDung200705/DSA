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
    int setup;

    do {
        cout << "\n MENU \n";
        cout << "1. Nhap mang\n";
        cout << "2. In mang\n";
        cout << "3. Tinh tong cac phan tu\n";
        cout << "4. Sap xep tang dan\n";
        cout << "5. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> setup;

        switch (setup)
        {
        case 1 :
            nhapMang(arr, n);
            break;
        case 2 :
            if (n>0) inMang(arr ,n);
            else cout << " Mang sai";
            break;
        case 3 :
            if (n>0) cout << "tong : " << tong(arr, n) << endl;
            else cout << "Mang chua duoc nhap ";
            break;
        case 4: 
            if (n>0) {
                sapXep(arr, n);
                cout << "Mang sau khi sap xep : ";
                for (int i = 0; i<n ; i++){
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            break;
        case 5 : 
            cout << "Thoat";
            break;
        default:
            if (setup != -1){
                cout << "Khong hop le";
            }
            break;
        }
    }
    while (setup != 0);
    return 0;
}