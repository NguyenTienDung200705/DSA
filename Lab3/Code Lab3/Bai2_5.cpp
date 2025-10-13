#include<iostream>
#include<vector>
#include<ctime>
#include<chrono>
using namespace std;
using Matrix = vector<vector<int>>;

Matrix congmatran(const Matrix& A, const Matrix& B) {
    int n = A.size(), m = A[0].size();
    Matrix C(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}
Matrix trumatran(const Matrix& A, const Matrix& B) {
    int n = A.size(), m = A[0].size();
    Matrix C(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}
Matrix nhanmatran(const Matrix& A, const Matrix& B) {
    int n = A.size(), m = A[0].size(), p = B[0].size();
    Matrix C(n, vector<int>(p, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            for (int k = 0; k < m; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

Matrix chiadetri(const Matrix& A, const Matrix& B) {
    int n = A.size();
    if (n == 1) return {{A[0][0] * B[0][0]}};
    int k = n / 2;
    Matrix A11(k, vector<int>(k)), A12(k, vector<int>(k));
    Matrix A21(k, vector<int>(k)), A22(k, vector<int>(k));
    Matrix B11(k, vector<int>(k)), B12(k, vector<int>(k));
    Matrix B21(k, vector<int>(k)), B22(k, vector<int>(k));
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];       A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];   A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j];       B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];   B22[i][j] = B[i + k][j + k];
        }

    Matrix C11 = congmatran(chiadetri(A11, B11), chiadetri(A12, B21));
    Matrix C12 = congmatran(chiadetri(A11, B12), chiadetri(A12, B22));
    Matrix C21 = congmatran(chiadetri(A21, B11), chiadetri(A22, B21));
    Matrix C22 = congmatran(chiadetri(A21, B12), chiadetri(A22, B22));

    Matrix C(n, vector<int>(n));
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    return C;
}

Matrix Strassen(const Matrix& A, const Matrix& B) {
    int n = A.size();
    if (n == 1) return {{A[0][0] * B[0][0]}};
    int k = n / 2;
    Matrix A11(k, vector<int>(k)), A12(k, vector<int>(k));
    Matrix A21(k, vector<int>(k)), A22(k, vector<int>(k));
    Matrix B11(k, vector<int>(k)), B12(k, vector<int>(k));
    Matrix B21(k, vector<int>(k)), B22(k, vector<int>(k));
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];       A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];   A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j];       B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];   B22[i][j] = B[i + k][j + k];
        }

    Matrix M1 = Strassen(congmatran(A11, A22), congmatran(B11, B22));
    Matrix M2 = Strassen(congmatran(A21, A22), B11);
    Matrix M3 = Strassen(A11, trumatran(B12, B22));
    Matrix M4 = Strassen(A22, trumatran(B21, B11));
    Matrix M5 = Strassen(congmatran(A11, A12), B22);
    Matrix M6 = Strassen(trumatran(A21, A11), congmatran(B11, B12));
    Matrix M7 = Strassen(trumatran(A12, A22), congmatran(B21, B22));

    Matrix C11 = congmatran(trumatran(congmatran(M1, M4), M5), M7);
    Matrix C12 = congmatran(M3, M5);
    Matrix C21 = congmatran(M2, M4);
    Matrix C22 = congmatran(congmatran(trumatran(M1, M2), M3), M6); 

    Matrix C(n, vector<int>(n));
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    return C;
}

void thoigianchay(int n) {
    Matrix A(n, vector<int>(n)), B(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }

    auto start = chrono::high_resolution_clock::now();
    Matrix C1 = nhanmatran(A, B);
    auto end = chrono::high_resolution_clock::now();
    double elapsed_basic = chrono::duration<double>(end - start).count();

    start = chrono::high_resolution_clock::now();
    Matrix C2 = chiadetri(A, B);
    end = chrono::high_resolution_clock::now();
    double elapsed_divide = chrono::duration<double>(end - start).count();

    start = chrono::high_resolution_clock::now();
    Matrix C3 = Strassen(A, B);
    end = chrono::high_resolution_clock::now();
    double elapsed_strassen = chrono::duration<double>(end - start).count();

    cout << "Kich thuoc ma tran: " << n << "x" << n << endl;
    cout << " - Truyen thong: " << elapsed_basic << " s" << endl;
    cout << " - Chia de tri:  " << elapsed_divide << " s" << endl;
    cout << " - Strassen:     " << elapsed_strassen << " s" << endl;
    cout << "" << endl;
}

int main() {
    srand(time(0));
    vector<int> sizes = {2, 4, 8, 16, 32, 64, 128};
    for (int n : sizes)
        thoigianchay(n);
}
