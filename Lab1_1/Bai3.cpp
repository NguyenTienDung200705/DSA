#include<iostream>
#include<cmath>
using namespace std;

bool soNguyenTo(int n){
    if (n<2) return false;
    if (n==2) return true;
    if (n%2 ==0 ) return false;
    for (int i=3; i<=sqrt(n); i+=2){
        if(n%i == 0) return false;
    }
    return true;
}
int main(){
     int a, b;
     cout << "Nhap a, b : \n";
     cin >> a >> b;
     cout << "so nguyen to trong [a,b] : ";
     for (int i=a; i<=b ;i++){
        if (soNguyenTo(i)){
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}