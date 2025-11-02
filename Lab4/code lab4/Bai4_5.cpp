#include<bits/stdc++.h>
using namespace std;

void bubblesort(vector<vector<int>>& a){
    for(int i = 0; i < a.size() - 1; i++){
        for(int j = 0; j < a.size() - 1 - i; j++){
            if(a[j][0] > a[j+1][0]){
                swap(a[j], a[j+1]);
            }
        }
    }
}
vector<vector<int>> interval1(vector<vector<int>>& a){
    bubblesort(a);

    vector<vector<int>> bubble;
    for(auto a1 : a){
        if(bubble.empty() || bubble.back()[1] < a1[0]){
            bubble.push_back(a1);
        }
        else{
            bubble.back()[1] = max(bubble.back()[1], a1[1]);
        }
    }
    return bubble;
}

void selectionsort(vector<vector<int>>& b){
    for(int i = 0; i < b.size()-1; i++){
        int min = i;
        for(int j = i +1; j < b.size(); j++){
            if(b[j] < b[min]){
                min = j;
            }
        }
        swap(b[i], b[min]);
    }
}
vector<vector<int>> interval2(vector<vector<int>>& b){
    selectionsort(b);

    vector<vector<int>> selection;
    for(auto b1 : b){
        if(selection.empty() || selection.back()[1] < b1[0]){
            selection.push_back(b1);
        }else{
            selection.back()[1] = max(selection.back()[1], b1[1]);
        }
    }
    return selection;
}

void insertionsort(vector<vector<int>>& c){
    for(int i = 0; i < c.size()-1; i++){
        vector<int> c1 = c[i+1];
        int j = i;
        while(j >= 0 && c[j+1] < c[j]){
            c[j+1] = c[j];
            j--;
        }
        c[i+1] = c1;
    }
}
vector<vector<int>> interval3(vector<vector<int>>& c){
    insertionsort(c);
    vector<vector<int>> insertion;
    for(auto c2 :c){
        if(insertion.empty() || insertion.back()[1] < c2[0]){
            insertion.push_back(c2);
        }else{
            insertion.back()[1] = max(insertion.back()[1], c2[1]);
        }
    }
    return insertion;
}

void merge(vector<vector<int>>& d, int left, int mid, int right){
    int n1 = mid- left + 1;
    int n2 = right - mid;
    vector<vector<int>> L(n1), R(n2);
    for(int i=0; i < n1; i++){
        L[i] = d[left+i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = d[mid+1+j];
    }
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(L[i][0] < R[j][0]){
            d[k++] = L[i++];
        }else{
            d[k++] = R[j++];
        }
    }
    while(i < n1) d[k++] = L[i++];
    while(j < n2) d[k++] = R[j++];
}
void mergesort(vector<vector<int>>& d, int left, int right){
    if(left < right) {
        int mid = left + (right - left)/2;
        mergesort(d, left, mid);
        mergesort(d, mid+1, right);
        merge(d,left,mid,right);
    }
}
vector<vector<int>> interval4(vector<vector<int>>& d){
    mergesort(d,0,d.size()-1);

    vector<vector<int>> merge1;
    for(auto d1 : d){
        if(merge1.empty() || merge1.back()[1] < d1[0]){
            merge1.push_back(d1);
        }else{
            merge1.back()[1] = max(merge1.back()[1], d1[1]);
        }
    }
    return merge1;
}

int partition(vector<vector<int>>& e, int n, int m){
    vector<int> pivot = e[m];
    int i = n-1;
    for(int j = n; j < m; j++){
        if(e[j][0] < pivot[0]){
            i++;
            swap(e[i], e[j]);
        }
    }
    swap(e[i+1], e[m]);
    return i+1;
}
void quicksort(vector<vector<int>>& e, int n, int m){
    if(n < m){
        int p = partition(e,n,m);
        quicksort(e,n,p-1);
        quicksort(e,p+1,m);
    }
}
vector<vector<int>> interval5(vector<vector<int>>& e){
    quicksort(e,0,e.size()-1);

    vector<vector<int>> quick;
    for(auto e1 : e){
        if(quick.empty() || quick.back()[1] < e1[0]){
            quick.push_back(e1);
        }else{
            quick.back()[1] = max(quick.back()[1], e1[1]);
        }
    }
    return quick;
}
int main(){
    cout << "Bubble Sort " << endl;
    vector<vector<int>> a = {{1,3},{2,6},{8,10},{15,18}};
    for(auto a2 : interval1(a)){
        cout << "[" << a2[0] << "," << a2[1] <<"]" ;
    }
    cout << endl;

    cout << "Selection Sort" << endl;
    vector<vector<int>> b = {{1,6},{3,10},{9,20},{36,71}};
    for(auto b2 : interval2(b)){
        cout << "[" << b2[0] << "," << b2[1] << "]";
    }
    cout << endl;

    cout << "Insertion Sort" << endl;
    vector<vector<int>> c = {{1,5},{3,20},{12, 34},{45,62},{65,70}};
    for(auto c3 : interval3(c)){
        cout << "[" << c3[0] << "," << c3[1] << "]";
    }
    cout << endl;

    cout << "Merge sort "<< endl;
    vector<vector<int>> d = {{1,5},{4,10},{13,18},{32,60}};
    for(auto d2 : interval4(d)){
        cout << "[" << d2[0] << "," << d2[1] << "]";
    }
    cout << endl;

    cout << "Quick Sort" << endl;
    vector<vector<int>> e = {{1,6},{4,25},{45,97},{222,855}};
    for(auto e2 : interval5(e)){
        cout << "[" << e2[0] << "," << e2[1] << "]";
    }
    cout << endl;
}