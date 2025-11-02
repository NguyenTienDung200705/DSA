#include <iostream>
using namespace std;

void InsectionSort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        int key = a[i+1];
        int j = i;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key; 
    }
}
int binarysearch(int a[], int m, int left, int right){
    while (left <= right){
        int mid = left + (right - left)/2;
        if (a[mid] > m) 
            right = mid - 1;
        else 
            left = mid + 1;
        }
    return left;
}
void binaryInsertionsort(int a[], int n){
    for (int i = 1; i <  n; i++){
        int m = a[i];
        int pos = binarysearch(a, m, 0, i-1);
        for(int j = i - 1; j >= pos; j--){
            a[j+1] = a[j];
        }
        a[pos] = m;
    }
}
int main(){
    int a[] = {5, 2, 9, 1, 5, 6};
    int n = 6;
    // InsectionSort(a, n);
    binaryInsertionsort(a,n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}