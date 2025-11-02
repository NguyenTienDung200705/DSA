#include <bits/stdc++.h>
using namespace std;

bool compareIgnoreCase(const string&a, const string&b){
    string A = a, B = b;
    transform(A.begin(), A.end(), A.begin(), ::tolower);
    transform(B.begin(), B.end(), B.begin(), ::tolower);
    return A < B;
}
int partitionquicksort(vector<string>& a, int n, int m){
    string pivot = a[m];
    int i = n - 1;
    for(int j = n; j < m ; j++){
        if(compareIgnoreCase(a[j], pivot)){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[m]);
    return i+1;
}
void quicksort(vector<string>& a, int n, int m){
    if(n < m){
        int p = partitionquicksort(a, n, m);
        quicksort(a, n, p - 1);
        quicksort(a, p + 1, m);
    }
}
void merge(vector<string>& a, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<string> L(n1), R(n2);
    for(int i = 0; i < n1; i++){
        L[i] = a[left + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = a[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2){
        if(compareIgnoreCase(L[i], R[j])){
            a[k++] = L[i++];
        }
        else{
            a[k++] = R[j++];
        }
    }
    while(i < n1) a[k++] = L[i++];
    while(j < n2) a[k++] = R[j++];
}
void mergesort(vector<string>& a, int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;
        mergesort(a, left, mid);
        mergesort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}
void Bubblesort(vector<string>& a, int n){
    int temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(compareIgnoreCase(a[j+1], a[j])){
                swap(a[j], a[j+1]);
            }
        }
    }
}
void selectionsort(vector<string>& a, int n){
    for(int i = 0 ;i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(compareIgnoreCase(a[j], a[min])){
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}
void insectionsort(vector<string>& a, int n){
    for(int i = 0;i < n-1; i++){
        string key = a[i+1];
        int j = i;
        while(j >= 0 && compareIgnoreCase(key, a[j])){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main(){
    vector<string> a = {"Banana", "date", "cherry", "apple"};
    // quicksort(a, 0, a.size() - 1);
    // mergesort(a, 0 , a.size() - 1);
    // Bubblesort(a, a.size());
    // selectionsort(a, a.size());
    insectionsort(a, a.size());
    for(int k = 0; k < a.size(); k++){
        cout << a[k] << " ";
    }
}