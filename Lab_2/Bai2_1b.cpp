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
    primes.clear();
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

    srand(time(0));

    vector<int> input_sizes = {1000, 10000, 100000, 500000, 1000000};

    cout << left << setw(20) << "Algorithm"
         << setw(15) << "Case"
         << setw(15) << "Input(n)"
         << setw(15) << "Time (ms)" << "\n";

    for (int n : input_sizes) {
        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 1);
        vector<int> primes;

        double t_bs_best = measureTime([&]() { binarySearch(arr, arr[n / 2]); });
        double t_bs_avg = measureTime([&]() { binarySearch(arr, arr[n / 4]); });
        double t_bs_worst = measureTime([&]() { binarySearch(arr, n + 1); });

        cout << setw(20) << "Binary Search"
             << setw(15) << "Best" << setw(15) << n << setw(15) << t_bs_best << "\n"
             << setw(20) << "" << setw(15) << "Average" << setw(15) << n << setw(15) << t_bs_avg << "\n"
             << setw(20) << "" << setw(15) << "Worst" << setw(15) << n << setw(15) << t_bs_worst << "\n";

        double t_sieve_best = measureTime([&]() { snt(1000, primes); });
        double t_sieve_avg = measureTime([&]() { snt(n / 10, primes); });
        double t_sieve_worst = measureTime([&]() { snt(n, primes); });

        cout << setw(20) << "Sieve Prime"
             << setw(15) << "Best" << setw(15) << n << setw(15) << t_sieve_best << "\n"
             << setw(20) << "" << setw(15) << "Average" << setw(15) << n << setw(15) << t_sieve_avg << "\n"
             << setw(20) << "" << setw(15) << "Worst" << setw(15) << n << setw(15) << t_sieve_worst << "\n";

        double t_gcd_best = measureTime([&]() { gcdEuclid(n, n); });
        double t_gcd_avg = measureTime([&]() { gcdEuclid(n, rand() % n + 1); });
        double t_gcd_worst = measureTime([&]() { gcdEuclid(21, 13); });

        cout << setw(20) << "GCD (Euclid)"
             << setw(15) << "Best" << setw(15) << n << setw(15) << t_gcd_best << "\n"
             << setw(20) << "" << setw(15) << "Average" << setw(15) << n << setw(15) << t_gcd_avg << "\n"
             << setw(20) << "" << setw(15) << "Worst" << setw(15) << n << setw(15) << t_gcd_worst << "\n";

        double t_bits_best = measureTime([&]() { countBits(1); });
        double t_bits_avg = measureTime([&]() { countBits(rand() % n + 1); });
        double t_bits_worst = measureTime([&]() { countBits(INT_MAX); });

        cout << setw(20) << "Count Bits"
             << setw(15) << "Best" << setw(15) << n << setw(15) << t_bits_best << "\n"
             << setw(20) << "" << setw(15) << "Average" << setw(15) << n << setw(15) << t_bits_avg << "\n"
             << setw(20) << "" << setw(15) << "Worst" << setw(15) << n << setw(15) << t_bits_worst << "\n";
    }
    return 0;
}
