#include <iostream>
#include <cmath>
using namespace std;

void khugauss(int n){
    double** a = new double*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new double[n];
    }
    double* b = new double[n];
    double* x = new double[n];

    cout << "Nhap ma tran : " << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    cout << "Nhap vector b : " << endl;
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    for (int k = 0; k < n-1; k++){
        int maxR = k;
        for (int i = k+1; i < n; i++){
            if (fabs(a[i][k]) > fabs(a[maxR][k])){
                maxR = i;
            }
        }
        if (fabs(a[maxR][k]) < 1e-12){
            cout << "He phuong trinh vo nghiem hoac vo so nghiem" << endl;
            return;
        }
        if (maxR != k){
            for (int j = 0; j < n; j++) swap(a[k][j], a[maxR][j]);
            swap(b[k], b[maxR]);
        }
        for (int i = k+1; i < n; i++){
            double m = a[i][k] / a[k][k];
            for (int j = k; j < n; j++){
                a[i][j] -= m * a[k][j];
            }
            b[i] -= m * b[k];
        }
    }
    for (int i = n-1; i >= 0; i--){
        double s = 0;
        for (int j = i+1; j < n; j++){
            s += a[i][j] * x[j];
        }
        if (fabs(a[i][i]) < 1e-12){
            cout << "He phuong trinh vo nghiem hoac vo so nghiem" << endl;
            return;
        }
        x[i] = (b[i] - s) / a[i][i];
    }

    cout << "Nghiem cua he :" << endl;
    for (int i = 0; i < n; i++){
        cout << x[i] << endl;
    }

    for (int i = 0; i < n; i++){
        delete [] a[i];
    }
    delete[] a;
    delete[] b;
    delete[] x;
}

int main(){
    int n;
    cout << "Nhap ma tran cap : ";
    cin >> n;
    khugauss(n);
    return 0;
}
