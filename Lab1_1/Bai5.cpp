#include <iostream>
using namespace std;
#define max 100

void nhapmatran(int a[max][max], int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }    
}
void inmatran(int a[max][max], int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void tongduongcheo(int a[max][max], int n, int m){
    int s = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i == j) {
                s += a[i][j];
            }
        }
    }
    cout << s << endl;
}
void chuyenvi(int a[max][max], int n, int m){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
}
void matrannghichdao(int a[max][max], int n){
    double c[max][2*max];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            c[i][j] = a[i][j];
        }
        for (int j = n; j < 2*n ; j++){
            if (i ==j - n) {
                c[i][j] = 1;
            }
            else {
                c[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n ; i++){
        if (c[i][i] == 0){
            bool found = false;
            for (int k = i+1; k < n; k++){
                if (c[k][i] != 0){
                    for (int j = 0; j < 2*n; j++){
                        swap(c[i][j], c[k][j]);
                        found = true;
                    }
                }
            }
            if (!found) {
                cout << "Ma tran khong kha nghich ";
                return;
            }
        }
        double pivot = c[i][i];
        for (int j = 0; j < 2*n; j++){
            c[i][j] /= pivot;
        }
        for (int k = 0; k < n; k++){
            if (k != i){
                double inverse = c[k][i];
                for (int j = 0; j < 2*n; j++){
                    c[k][j] -= inverse * c[i][j];
                }
            }
        }        
    }
    for (int i = 0; i < n; i++){
        for (int j = n; j < 2*n; j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    int n, m;
    int a[max][max];

    cout << "Nhap so hang : ";
    cin >> n;
    cout << "Nhap so cot : ";
    cin >> m;
    nhapmatran(a, n, m);

    cout << "Ma tran \n";
    inmatran(a, n, m);

    cout << "Tong duong cheo : ";
    tongduongcheo(a, n, m);

    cout << "Ma tran chuyen vi : \n";
    chuyenvi(a, n, m);

    cout << "Ma tran nghich dao : \n";
    if (n == m) {
        matrannghichdao(a, n);
    }
    else {
        cout << "sai";
    }
}