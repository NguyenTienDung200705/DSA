#include <iostream>
using namespace std;

long long tinhgiaithua(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1) return 1;
    return n * tinhgiaithua(n-1);
}
long long fibonacci(int m){
    if (m < 0) return -1;
    if (m == 0) return 0;
    if (m == 1) return 1;
    return fibonacci(m-1) + fibonacci(m-2);
}
long long daonguoc(int k){
    long long sdn = 0;
    while (k > 0) {
        sdn = sdn * 10 + k%10;  
        k /= 10;
    }
    return sdn;
}

int main() {
    int* n = new int;
    int* m = new int;
    int* k = new int;

    cout << "Nhap vao 1 so : ";
    cin >> *n;
    cout << tinhgiaithua(*n) << endl;

    cout << "Nhap vao 1 so : ";
    cin >> *m;
    cout << fibonacci(*m) << endl;

    cout << "Nhap vao 1 so : ";
    cin >> *k;
    cout << daonguoc(*k) << endl;

    delete n;
    delete m;
    delete k;
    
    return 0; 
}
