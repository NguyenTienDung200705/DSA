#include <bits/stdc++.h>
using namespace std;

int partition_low(int a[], int n, int m){
    int pivot = a[n];
    int i = n + 1;
    int j = m;
    while(true){
        while(i <= j && a[i] <= pivot){
            i++;
        }
        while(i <= j && a[j] > pivot){
            j--;
        }
        if(i>j) break;
        swap(a[i], a[j]);
    }
    swap(a[n], a[j]);
    return j;
}
int partition_high(int a[], int n, int m){
    int pivot1 = a[m];
    int i = n;
    int j = m-1;
    while(true){
        while(i <=j && a[i] <= pivot1){
            i++;
        }
        while(i <=j && a[j] > pivot1){
            j--;
        }
        if(i > j) break;
        swap(a[i], a[j]);
    }
    swap(a[i], a[m]);
    return i;
}
int partition(int a[], int n, int m){
    int pivot2 = n + rand() % (m-n+1); 
    int pivot3 = a[pivot2];
    int i=n, j=m;
    while(true){
        while(i <= j && a[i] <= pivot3){
            i++;
        }
        while(i <= j && a[j] > pivot3){
            j--;
        }
        if(i > j) break;
        swap(a[i], a[j]);
    }
    swap(a[pivot2], a[j]);
    return j;
}
void quicksort(int a[], int n, int m){
    if(n < m){
        // int p = partition_low(a, n, m);
        int p = partition(a, n, m);
        //int p = partition_high(a, n, m);
        quicksort(a, n, p-1);
        quicksort(a, p+1, m);
    }
}
int main(){
    int a[] = {1,4,5,8,3,25,82,14};
    int n = 0;
    int m = 7;
    quicksort(a,n,m);
    for(int i = 0; i < m; i++){
        cout << a[i] << " ";
    }
}