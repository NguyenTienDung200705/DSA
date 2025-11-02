#include <bits/stdc++.h>
using namespace std;

const int INSERTION_THRESHOLD = 10;

void insertionSort(vector<int>& arr, int low, int high) {
    for (int i = low + 1; i <= high; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int medianOfThree(vector<int>& arr, int low, int high) {
    int mid = (low + high) / 2;
    int a = arr[low], b = arr[mid], c = arr[high];
    if ((a > b) != (a > c)) return low;
    else if ((b > a) != (b > c)) return mid;
    else return high;
}

int partition(vector<int>& arr, int low, int high) {
    int medianIndex = medianOfThree(arr, low, high);
    swap(arr[medianIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void hybridSort(vector<int>& arr, int low, int high) {
    while (low < high) {
        if (high - low + 1 < INSERTION_THRESHOLD) {
            insertionSort(arr, low, high);
            break;
        } else {
            int pi = partition(arr, low, high);
            if (pi - low < high - pi) {
                hybridSort(arr, low, pi - 1);
                low = pi + 1;
            } else {
                hybridSort(arr, pi + 1, high);
                high = pi - 1;
            }
        }
    }
}
int partitionSimple(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionSimple(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 100000;
    vector<int> arr1(N), arr2(N);
    srand(time(nullptr));
    for (int i = 0; i < N; ++i) {
        int x = rand() % N;
        arr1[i] = x;
        arr2[i] = x;
    }

    auto start = chrono::high_resolution_clock::now();
    hybridSort(arr1, 0, N - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> hybridTime = end - start;

    start = chrono::high_resolution_clock::now();
    quickSort(arr2, 0, N - 1);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> quickTime = end - start;

    cout << fixed << setprecision(5);
    cout << "Hybrid Sort time: " << hybridTime.count() << " s\n";
    cout << "Quick Sort time:  " << quickTime.count() << " s\n";

    cout << "Giong nhau: " << boolalpha << (arr1 == arr2) << "\n";
    return 0;
}
