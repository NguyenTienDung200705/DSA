#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = new int[n1];
    int *R = new int[n2];
    
    for(int i = 0; i < n1; i++){
        L[i] = a[left + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = a[mid + 1 + j]; 
    }
    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if (L[i] <= R[j]){
            a[left++] = L[i++];
        }
        else{
            a[left++] = R[j++];
        }
    }
    while(i < n1) a[left++] = L[i++];
    while(j < n2) a[left++] = R[j++];

    delete[] L;
    delete[] R;
}
void mergesort(int a[], int left, int right){
    if(left < right){
        int mid = left + (right -left)/2;
        mergesort(a, left, mid);
        mergesort(a, mid +1, right);
        merge(a, left, mid, right);
    }
}
void mergesortiterative(int a[], int n){
    for(int iter = 1; iter < n; iter*=2){
        for(int left = 0; left < n - iter + 1; left +=  2*iter){
            int mid = left + iter - 1;
            int right = min(left + 2 *iter - 1, n-1);
            merge(a,left, mid, right);
        }
    }
}
int main(){
    int a[] = {2,5,8,3,9,4,76};
    int n = 7;
    // mergesort(a, 0 ,n-1);
    mergesortiterative(a, 7);
    for(int k = 0; k < n; k++){
        cout << a[k] << " ";
    }
}