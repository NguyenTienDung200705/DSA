#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};
double dist(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double bruteForce(Point P[], int n, Point &p1, Point &p2) {
    double min_dist = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = dist(P[i], P[j]);
            if (d < min_dist) {
                min_dist = d;
                p1 = P[i];
                p2 = P[j];
            }
        }
    }
    return min_dist;
}
double kcmin(Point P[], int n, Point &p1, Point &p2) {
    if (n <= 3)
        return bruteForce(P, n, p1, p2);

    int mid = n / 2;
    Point midPoint = P[mid];

    Point p1_left, p2_left, p1_right, p2_right;
    double dl = kcmin(P, mid, p1_left, p2_left);
    double dr = kcmin(P + mid, n - mid, p1_right, p2_right);

    double d;
    if (dl < dr) {
        d = dl;
        p1 = p1_left;
        p2 = p2_left;
    } else {
        d = dr;
        p1 = p1_right;
        p2 = p2_right;
    }
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j++] = P[i];

    sort(strip, strip + j, [](Point a, Point b){ return a.y < b.y; });
    for (int i = 0; i < j; i++) {
        for (int k = i + 1; k < j && (strip[k].y - strip[i].y) < d; k++) {
            double dist_now = dist(strip[i], strip[k]);
            if (dist_now < d) {
                d = dist_now;
                p1 = strip[i];
                p2 = strip[k];
            }
        }
    }

    return d;
}
double closesUtil(Point P[], int n, Point &A, Point &B) {
    sort(P, P + n, [](Point a, Point b){ return a.x < b.x; });
    return kcmin(P, n, A, B);
}

int main() {
    int n;
    cout << "Nhap so diem: ";
    cin >> n;
    Point P[n];
    cout << "Nhap toa do cac diem:\n";
    for (int i = 0; i < n; i++) {
        cout << "Diem " << i + 1 << ": ";
        cin >> P[i].x >> P[i].y;
    }

    Point A, B;
    double min_dist = closesUtil(P, n, A, B);

    cout << "\nHai diem gan nhau nhat la:\n";
    cout << "A(" << A.x << ", " << A.y << ")\n";
    cout << "B(" << B.x << ", " << B.y << ")\n";
    cout << "Khoang cach nho nhat la: " << min_dist << endl;

    return 0;
}
