#include <iostream>
using namespace std;

void Selectionsort(int a[], int n){
    for (int i = 0; i < n-1; i++){
        int min = i;
        for (int j = i+1; j < n; j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        swap(a[i], a[min]);
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
    int a[100];
    cout << "Nhap so phan tu cua mang" << endl;
    cin >> n;
    nhapmang(a,n);
    Selectionsort(a,n);
    inmang(a,n);
    return 0;
}