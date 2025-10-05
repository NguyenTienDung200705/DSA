#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

struct Rectangle {
    Point topLeft;
    Point bottomRight;
};

Point nhapPoint(string ten) {
    Point p;
    cout << "Nhap toa do diem " << ten << " (x y): ";
    cin >> p.x >> p.y;
    return p;
}
Rectangle nhapRectangle() {
    Rectangle r;
    cout << "Nhap toa do goc trai tren : ";
    cin >> r.topLeft.x >> r.topLeft.y;
    cout << "Nhap toa do goc phai duoi : ";
    cin >> r.bottomRight.x >> r.bottomRight.y;
    return r;
}

double khoangcach(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) +
                (a.y - b.y)*(a.y - b.y));
}

double S(Rectangle r) {
    double width = fabs(r.bottomRight.x - r.topLeft.x);
    double height = fabs(r.topLeft.y - r.bottomRight.y);
    return width * height;
}

double P(Rectangle r) {
    double width = fabs(r.bottomRight.x - r.topLeft.x);
    double height = fabs(r.topLeft.y - r.bottomRight.y);
    return 2 * (width + height);
}


bool Kiemtra(Rectangle r, Point p) {
    return (p.x >= r.topLeft.x && p.x <= r.bottomRight.x &&
            p.y <= r.topLeft.y && p.y >= r.bottomRight.y);
}

int main() {
    Point A = nhapPoint("A");
    Point B = nhapPoint("B");
    cout << "Khoang cach giua A va B: " << khoangcach(A, B) << endl;

    Rectangle rect = nhapRectangle();
    cout << "Dien tich hcn: " << S(rect) << endl;
    cout << "Chu vi hcn: " << P(rect) << endl;

    Point P1 = nhapPoint("P");
    if (Kiemtra(rect, P1))
        cout << "Diem P nam trong hinh chu nhat" << endl;
    else
        cout << "Diem P nam ngoai hinh chu nhat" << endl;

    return 0;
}
