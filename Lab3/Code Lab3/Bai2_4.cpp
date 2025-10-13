#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair<int , int> Max2(const vector<int>& a, int left, int right) {
    if (left == right) {
        return {a[left], -1}; 
    }
    int mid = left + (right - left) / 2;
    pair<int, int> leftMax = Max2(a, left, mid);
    pair<int, int> rightMax = Max2(a, mid + 1, right);

    int max1, max2;
    if (leftMax.first > rightMax.first) {
        max1 = leftMax.first;
        max2 = max(leftMax.second, rightMax.first);
    } else {
        max1 = rightMax.first;
        max2 = max(rightMax.second, leftMax.first);
    }
    return {max1, max2};
}
int main(){
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    vector<int> a(n);
    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    pair<int, int> result = Max2(a, 0, n - 1);
    cout << "Phan tu lon thu hai la: " << result.second << endl;
}