#include <iostream>
#include <cstring>
using namespace std;

class DynamicString {
private:
    char* data;   
    size_t len;    

public:
    DynamicString() : data(new char[1]), len(0) {
        data[0] = '\0';
    }

    DynamicString(const char* str) {
        if (!str) {
            len = 0;
            data = new char[1];
            data[0] = '\0';
        } else {
            len = strlen(str);
            data = new char[len + 1];
            strcpy(data, str);
        }
    }

    DynamicString(const DynamicString& other) {
        len = other.len;
        data = new char[len + 1];
        strcpy(data, other.data);
    }

    ~DynamicString() {
        delete[] data;
    }

    DynamicString& operator=(const DynamicString& other) {
        if (this != &other) {  
            delete[] data;
            len = other.len;
            data = new char[len + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    size_t length() const { return len; }

    void append(const char* str) {
        if (!str) return;
        size_t newLen = len + strlen(str);
        char* newData = new char[newLen + 1];
        strcpy(newData, data);
        strcat(newData, str);
        delete[] data;
        data = newData;
        len = newLen;
    }

    DynamicString substring(size_t start, size_t length) const {
        if (start >= len) return DynamicString();
        if (start + length > len) length = len - start;
        char* sub = new char[length + 1];
        strncpy(sub, data + start, length);
        sub[length] = '\0';
        DynamicString result(sub);
        delete[] sub;
        return result;
    }

    friend ostream& operator<<(ostream& os, const DynamicString& s) {
        os << s.data;
        return os;
    }
};

void testConstructors() {
    cout << "\nKiem tra Constructors \n";
    DynamicString s1;
    DynamicString s2("Hello");
    DynamicString s3(s2);
    cout << "s1: " << s1 << "\n";
    cout << "s2: " << s2 << "\n";
    cout << "s3: " << s3 << "\n";
}

void testAssignment() {
    cout << "\nKiem tra Assignment\n";
    DynamicString s1("1"), s2("2");
    cout << "Truoc: s1=" << s1 << ", s2=" << s2 << "\n";
    s1 = s2;
    cout << "Sau gan : s1=" << s1 << ", s2=" << s2 << "\n";
}

void testMethods() {
    cout << "\nnKiem tra Methods\n";
    DynamicString str("Hello");
    cout << "Chuoi: " << str << ", dai =" << str.length() << "\n";
    str.append(" World");
    cout << "Noi: " << str << "\n";
    str.append("!");
    cout << "noi: " << str << "\n";
    cout << "cc(0,5): " << str.substring(0,5) << "\n";
    cout << "cc(6,5): " << str.substring(6,5) << "\n";
}

void testCopySemantics() {
    cout << "\nKiem tra Copy\n";
    DynamicString goc("K68-EEI");
    DynamicString copy1(goc);
    cout << "Goc: " << goc << ", Copy1: " << copy1 << "\n";
    goc.append(" chao mung");
    cout << "Sau sua : goc=" << goc << ", Copy1=" << copy1 << "\n";
    DynamicString copy2("Temp");
    copy2 = goc;
    cout << "Copy2: " << copy2 << "\n";
}

void testMemoryManagement() {
    cout << "\nKiem tra Memory\n";
    {
        DynamicString t1("Temp1"), t2("Temp2");
        cout << "Trong scope\n";
    }
    cout << "Ra khoi scope \n";
}

int main() {
    cout << "Kiem tra\n";
    testConstructors();
    testAssignment();
    testMethods();
    testCopySemantics();
    testMemoryManagement();
    return 0;
}
