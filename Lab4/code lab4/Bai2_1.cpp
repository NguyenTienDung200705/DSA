#include <iostream>
#include <cmath>
using namespace std;

void Bubblesort(int a[], int n, int &count, int &swap){
    int temp;
    count = swap = 0; 
    for(int i = 0 ; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            count++; 
            if(a[j] > a[j + 1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swap++; 
            }
        }
    }
}
void Bubblesortflag(int a[], int n, int &count, int &swap){
    int temp;
    count = swap = 0; 
    for(int i = 0 ; i < n - 1; i++){
        bool flag = false;
        for(int j = 0; j < n - i - 1; j++){
            count++;
            if(a[j] > a[j + 1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swap++; 
                flag = true;
            }
        }
        if(!flag){
            break; 
        }
    }
}
void nhapmang(int a[], int n){
    cout << "Nhap mang:" << endl;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}
void inmang(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int main(){
    int n;
    int a[n], b[n];
    int count1, swap1, count2, swap2;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    nhapmang(a, n);

    for(int i = 0; i < n; i++){
        b[i] = a[i];
    }

    Bubblesort(a, n, count1, swap1);
    Bubblesortflag(b, n, count2, swap2);

    cout << "\nKet qua phien ban co ban:\n";
    inmang(a, n);
    cout << "So phep so sanh: " << count1 << endl;
    cout << "So phep hoan doi: " << swap1 << endl;

    cout << "\nKet qua phien ban toi uu:\n";
    inmang(b, n);
    cout << "So phep so sanh: " << count2 << endl;
    cout << "So phep hoan doi: " << swap2 << endl;

    return 0;
}
