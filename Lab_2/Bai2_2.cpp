#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

long long fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

long long fib_memo(int n, vector<long long> &dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib_memo(n - 1, dp) + fib_memo(n - 2, dp);
}

long long fib_iterative(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
long long sum_divide(vector<int> &arr, int l, int r) {
    if (l == r) return arr[l];
    int mid = (l + r) / 2;
    return sum_divide(arr, l, mid) + sum_divide(arr, mid + 1, r);
}

long long power_naive(long long a, int n) {
    long long res = 1;
    for (int i = 0; i < n; i++)
        res *= a;
    return res;
}

long long power_divide(long long a, int n) {
    if (n == 0) return 1;
    long long half = power_divide(a, n / 2);
    if (n % 2 == 0) return half * half;
    else return half * half * a;
}

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) return;
    hanoi(n - 1, from, aux, to);
    hanoi(n - 1, aux, to, from);
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

    cout << left << setw(5) << "n"
         << setw(18) << "Fib de quy (ms)"
         << setw(18) << "Fib co nho (ms)"
         << setw(18) << "Fib lap (ms)"
         << setw(18) << "Sum chia de tri (ms)"
         << setw(18) << "Pow Naive (ms)"
         << setw(18) << "Pow chia de tri (ms)"
         << setw(18) << "Hanoi (ms)"
         << "\n";

    for (int n = 1; n < 40; n++) {
        vector<int> arr(n, 1);
        vector<long long> dp(n + 1, -1);

        double t1 = measureTime([&]() { fib_recursive(n); });
        double t2 = measureTime([&]() { fib_memo(n, dp); });
        double t3 = measureTime([&]() { fib_iterative(n); });
        double t4 = measureTime([&]() { sum_divide(arr, 0, n - 1); });
        double t5 = measureTime([&]() { power_naive(2, n); });
        double t6 = measureTime([&]() { power_divide(2, n); });
        double t7 = measureTime([&]() { hanoi(n, 'A', 'C', 'B'); });

        cout << setw(5) << n
             << setw(18) << t1
             << setw(18) << t2
             << setw(18) << t3
             << setw(18) << t4
             << setw(18) << t5
             << setw(18) << t6
             << setw(18) << t7
             << "\n";
    }
    return 0;
}
