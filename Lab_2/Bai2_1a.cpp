#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int binarySearch(vector<int> &arr, int x) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void snt(int n, vector<int> &primes) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
}

long long gcdEuclid(long long a, long long b) {
    if (b == 0)
        return a;
    return gcdEuclid(b, a % b);
}

int countBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

template <typename Func>
double measureTime(Func f) {
    auto start = high_resolution_clock::now();
    f();
    auto end = high_resolution_clock::now();
    duration<double, milli> elapsed = end - start;
    return elapsed.count();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> sizes = {1000, 10000, 100000, 500000, 1000000};

    ofstream fout("results.csv");
    fout << "Input(n),Binary Search (ms),Sieve Prime (ms),GCD (ms),Count Bits (ms)\n";
    
    cout << left << setw(15) << "Input(n)"
         << setw(25) << "Binary Search (ms)"
         << setw(25) << "Sieve Prime (ms)"
         << setw(25) << "GCD (ms)"
         << setw(25) << "Count Bits (ms)" << "\n";

    for (int n : sizes) {
        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 1);
        vector<int> primes;

        int key_worst = n + 1;

        double t_search = measureTime([&]() {
            binarySearch(arr, key_worst);
        });

        double t_prime = measureTime([&]() {
            snt(n, primes);
        });

        double t_gcd = measureTime([&]() {
            for (int i = 1; i <= n; i++)
                gcdEuclid(i, n);
        });

        double t_bits = measureTime([&]() {
            for (int i = 1; i <= n; i++)
                countBits(i);
        });

        cout << setw(15) << n
             << setw(25) << t_search
             << setw(25) << t_prime
             << setw(25) << t_gcd
             << setw(25) << t_bits << "\n";

        fout << n << ","
             << t_search << ","
             << t_prime << ","
             << t_gcd << ","
             << t_bits << "\n";
    }

    fout.close();
    return 0;
}
