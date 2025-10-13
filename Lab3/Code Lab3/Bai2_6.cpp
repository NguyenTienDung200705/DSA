#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Result {
    int buyDay;
    int sellDay;
    int profit;
};
Result brute_force_max_profit(const vector<int>& prices) {
    int n = prices.size();
    Result res = {0, 0, 0};

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int p = prices[j] - prices[i];
            if (p > res.profit) {
                res.profit = p;
                res.buyDay = i;
                res.sellDay = j;
            }
        }
    }
    return res;
}
Result divide_and_conquer(const vector<int>& prices, int left, int right) {
    if (left >= right) return {left, right, 0};

    int mid = (left + right) / 2;

    Result leftRes = divide_and_conquer(prices, left, mid);
    Result rightRes = divide_and_conquer(prices, mid + 1, right);

    int minLeftPrice = prices[left], minLeftDay = left;
    for (int i = left; i <= mid; i++) {
        if (prices[i] < minLeftPrice) {
            minLeftPrice = prices[i];
            minLeftDay = i;
        }
    }

    int maxRightPrice = prices[mid + 1], maxRightDay = mid + 1;
    for (int i = mid + 1; i <= right; i++) {
        if (prices[i] > maxRightPrice) {
            maxRightPrice = prices[i];
            maxRightDay = i;
        }
    }

    int crossProfit = maxRightPrice - minLeftPrice;
    Result crossRes = {minLeftDay, maxRightDay, crossProfit};

    if (leftRes.profit >= rightRes.profit && leftRes.profit >= crossRes.profit)
        return leftRes;
    else if (rightRes.profit >= leftRes.profit && rightRes.profit >= crossRes.profit)
        return rightRes;
    else
        return crossRes;
}
Result divide_and_conquer_with_n0(const vector<int>& prices, int left, int right, int n0) {
    if (right - left + 1 <= n0) {
        vector<int> sub(prices.begin() + left, prices.begin() + right + 1);
        Result res = brute_force_max_profit(sub);
        res.buyDay += left;
        res.sellDay += left;
        return res;
    }

    int mid = (left + right) / 2;
    Result leftRes = divide_and_conquer_with_n0(prices, left, mid, n0);
    Result rightRes = divide_and_conquer_with_n0(prices, mid + 1, right, n0);

    int minLeftPrice = prices[left], minLeftDay = left;
    for (int i = left; i <= mid; i++) {
        if (prices[i] < minLeftPrice) {
            minLeftPrice = prices[i];
            minLeftDay = i;
        }
    }

    int maxRightPrice = prices[mid + 1], maxRightDay = mid + 1;
    for (int i = mid + 1; i <= right; i++) {
        if (prices[i] > maxRightPrice) {
            maxRightPrice = prices[i];
            maxRightDay = i;
        }
    }

    int crossProfit = maxRightPrice - minLeftPrice;
    Result crossRes = {minLeftDay, maxRightDay, crossProfit};

    if (leftRes.profit >= rightRes.profit && leftRes.profit >= crossRes.profit)
        return leftRes;
    else if (rightRes.profit >= leftRes.profit && rightRes.profit >= crossRes.profit)
        return rightRes;
    else
        return crossRes;
}
int find_crossover_point(const vector<int>& prices) {
    int n0 = 2;
    while (n0 < (int)prices.size()) {
        auto start1 = high_resolution_clock::now();
        brute_force_max_profit(vector<int>(prices.begin(), prices.begin() + n0));
        auto end1 = high_resolution_clock::now();
        double t1 = duration<double, milli>(end1 - start1).count();

        auto start2 = high_resolution_clock::now();
        divide_and_conquer(prices, 0, n0 - 1);
        auto end2 = high_resolution_clock::now();
        double t2 = duration<double, milli>(end2 - start2).count();

        if (t2 < t1) return n0;
        n0++;
    }
    return n0;
}
int main() {
    vector<int> prices = {100, 113, 110, 85, 105, 102, 86, 63, 75, 95, 88, 92, 78, 105, 98};

    cout << "Mang gia co phieu: ";
    for (int p : prices) cout << p << " ";
    cout << "\n\n";

    Result brute = brute_force_max_profit(prices);
    cout << "Brute-force:\n";
    cout << "Mua ngay " << brute.buyDay + 1 << ", Ban ngay " << brute.sellDay + 1
         << ", Loi nhuan = " << brute.profit << "\n\n";

    Result div = divide_and_conquer(prices, 0, prices.size() - 1);
    cout << "Divide and Conquer:\n";
    cout << "Mua ngay " << div.buyDay + 1 << ", Ban ngay " << div.sellDay + 1
         << ", Loi nhuan = " << div.profit << "\n\n";

    int n0 = find_crossover_point(prices);
    cout << "Diem giao (crossover point) xuat hien tai n0 = " << n0 << "\n\n";

    Result divn0 = divide_and_conquer_with_n0(prices, 0, prices.size() - 1, n0);
    cout << "Divide and Conquer voi n0 = " << n0 << ":\n";
    cout << "Mua ngay " << divn0.buyDay + 1 << ", Ban ngay " << divn0.sellDay + 1
         << ", Loi nhuan = " << divn0.profit << "\n";

    return 0;
}
