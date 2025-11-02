#include <bits/stdc++.h>
using namespace std;

vector<int> mergearray(const vector<int>& a, const vector<int>& b){
    vector<int> C(a.size() + b.size());
    int i = 0, j = 0, k = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            C[k++] = a[i++];
        }
        else{
            C[k++] = b[j++];
        }
    }
    while(i < a.size()) C[k++] = a[i++];
    while(j < b.size()) C[k++] = b[j++];
    return C;
}
void bubblesortarray(vector<int>& a, int n){
    int temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}
void selectionsortarray(vector<int>& a, int n){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for (int j = i+1; j < n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}
void insertionsortarray(vector<int>& a, int n){
    for(int i = 0; i < n-1; i++){
        int k = a[i+1];
        int j = i;
        while(i >= 0 && a[j] > k){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = k;
    }
}
int partition_low(vector<int>& a, int n, int m){
    int pivot = a[n];
    int i = n+1;
    int j = m;
    while(true){
        while(i <= j && a[i] < pivot){
            i++;
        }
        while(i <= j && a[j] > pivot){
            j--;
        }
        if(i > j) break;
        swap(a[i], a[j]);
    }
    swap(a[n], a[j]);
    return j;
}
void quicksortarray(vector<int>& a, int n, int m){
    if(n < m){
        int p = partition_low(a,n,m);
        quicksortarray(a, n, p);
        quicksortarray(a, p+1, m);
    }
}
int main(){
    vector<int> a = {1,4,6,9,10};
    vector<int> b = {2,3,8,14,15};
    vector<int> D = a;
    D.insert(D.end(), b.begin(), b.end());

    quicksortarray(D, 0, D.size()-1);
    cout << "Quick Sort array" << endl;
    for(int k = 0; k < D.size(); k++){
        cout << D[k] << " ";
    }    
    cout << " " << endl;

    bubblesortarray(D, D.size()-1);
    cout <<"Bubble Sort array : " << endl ;
        for(int k = 0; k < D.size(); k++){
        cout << D[k] << " ";
    }
    cout << " " << endl;

    selectionsortarray(D, D.size()-1);
    cout <<"Selection Sort array : " << endl ;
        for(int k = 0; k < D.size(); k++){
        cout << D[k] << " ";
    }
    cout << " " << endl;

    insertionsortarray(D, D.size()-1);
    cout <<"Insertion Sort array : " << endl ;
    for(int k = 0; k < D.size(); k++){
        cout << D[k] << " ";
    }
    cout << " " << endl;

    cout << "Merge Sort array : "  << endl;
    vector<int> C = mergearray(a,b);
    for(int m = 0; m < a.size() + b.size(); m++){
        cout << C[m] << " ";
    }
}