#include <iostream>
#include <cmath>
using namespace std;
int search(int a[], int n, int m, int x){
    if (n > m) return 0;
    if (n ==m ) return (a[n] == x  ?1 :0); 
    int mid = (n+m)/2;
    int left = search(a, n, mid, x);
    int right = search(a, mid+1, m, x);
    return left + right;
}
int duyet_mang(int a[], int y, int x ){
    int cnt;
    for (int i=0; i < y; i++){
        if (a[i] == x) {
            cnt++;
        }
    }
}
int main(){
    int a[6] = {1, 2, 2, 3, 4, 2};
    int x =2;
    cout << search(a, 0, 5, 2);    
}