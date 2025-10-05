#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const double PI = 3.14159265359;

class Shape {
public:
    virtual double getArea() const = 0;      
    virtual double getPerimeter() const = 0;
    virtual void printInfo() const = 0;      
    virtual ~Shape() {}                      
};

class Circle : public Shape {
private:
    double r;
public:
    Circle(double r) : r(r) {}
    
    double getArea() const override {
        return PI * r * r;
    }
    
    double getPerimeter() const override {
        return 2 * PI * r;
    }

    void printInfo() const override {
        cout << "Hinh Tron - ban kinh: " << r
             << ", dien tich: " << getArea()
             << ", chu vi: " << getPerimeter() << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double getArea() const override {
        return width * height;
    }
    
    double getPerimeter() const override {
        return 2 * (width + height);
    }

    void printInfo() const override {
        cout << "Hinh Chu Nhat - chieu rong: " << width
             << ", chieu dai: " << height
             << ", dien tich: " << getArea()
             << ", chu vi: " << getPerimeter() << endl;
    }
};

class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}
    
    double getArea() const override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    
    double getPerimeter() const override {
        return a + b + c;
    }

    void printInfo() const override {
        cout << "Hinh Tam Giac - canh: " << a << ", " << b << ", " << c
             << ", dien tich: " << getArea()
             << ", chu vi: " << getPerimeter() << endl;
    }
};

int main() {
    vector<Shape*> shapes;
    int choice;

    cout << "Chuong trinh tinh dien tich & chu vi cac hinh hoc" << endl;
    cout << "Nhap so luong hinh: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nChon loai hinh (1-Tron, 2-Chu Nhat, 3-Tam Giac): ";
        cin >> choice;

        if (choice == 1) {
            double r;
            cout << "Nhap ban kinh: ";
            cin >> r;
            shapes.push_back(new Circle(r));
        } else if (choice == 2) {
            double w, h;
            cout << "Nhap chieu rong: ";
            cin >> w;
            cout << "Nhap chieu dai: ";
            cin >> h;
            shapes.push_back(new Rectangle(w, h));
        } else if (choice == 3) {
            double a, b, c;
            cout << "Nhap 3 canh tam giac: ";
            cin >> a >> b >> c;
            if (a + b > c && a + c > b && b + c > a) {
                shapes.push_back(new Triangle(a, b, c));
            } else {
                cout << "3 canh khong tao thanh tam giac hop le!" << endl;
            }
        } else {
            cout << "Lua chon khong hop le!" << endl;
            i--; 
        }
    }

    double totalArea = 0.0;
    cout << "\nInfor cac hinh " << endl;
    for (const Shape* shape : shapes) {
        shape->printInfo();
        totalArea += shape->getArea();
    }

    cout << "\nTong dien tich tat ca cac hinh: " << totalArea << endl;

    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
