#include <iostream>
#include <string>
using namespace std;

// ================= PARALLELOGRAM =================
class Parallelogram {
    double base, height, side;
    string color;
public:
    Parallelogram() {
        base = 1; height = 1; side = 1; color = "white";
    }

    Parallelogram(double b, double h, double s, string c) {
        setBase(b); setHeight(h); setSide(s); setColor(c);
    }

    void setBase(double b) { base = (b > 0) ? b : 1; }
    void setHeight(double h) { height = (h > 0) ? h : 1; }
    void setSide(double s) { side = (s > 0) ? s : 1; }
    void setColor(string c) { color = (c != "") ? c : "white"; }

    double getBase() { return base; }
    double getHeight() { return height; }
    double getSide() { return side; }
    string getColor() { return color; }

    double area() { return base * height; }
    double perimeter() { return 2 * (base + side); }

    void print() {
        cout << "\nParallelogram\n";
        cout << "Base: " << base << endl;
        cout << "Height: " << height << endl;
        cout << "Side: " << side << endl;
        cout << "Color: " << color << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

// ================= VECTOR =================
class VectorShort {
    short* a;
    int n;
    int state;
    static int count;
public:
    VectorShort() {
        n = 1; state = 0;
        a = new short[n];
        a[0] = 0;
        count++;
    }

    VectorShort(int size, short value = 0) {
        if (size <= 0) size = 1;
        n = size; state = 0;
        a = new short[n];
        for (int i = 0; i < n; i++) a[i] = value;
        count++;
    }

    VectorShort(const VectorShort& other) {
        n = other.n; state = other.state;
        a = new short[n];
        for (int i = 0; i < n; i++) a[i] = other.a[i];
        count++;
    }

    VectorShort& operator=(const VectorShort& other) {
        if (this != &other) {
            delete[] a;
            n = other.n; state = other.state;
            a = new short[n];
            for (int i = 0; i < n; i++) a[i] = other.a[i];
        }
        return *this;
    }

    ~VectorShort() {
        delete[] a;
        count--;
    }

    void set(int i, short value = 0) {
        if (i < 0 || i >= n) { state = 1; return; }
        a[i] = value; state = 0;
    }

    short get(int i) {
        if (i < 0 || i >= n) { state = 1; return 0; }
        state = 0; return a[i];
    }

    VectorShort add(VectorShort b) {
        VectorShort t(n);
        if (n != b.n) { state = 2; return t; }
        for (int i = 0; i < n; i++) t.a[i] = a[i] + b.a[i];
        return t;
    }

    VectorShort sub(VectorShort b) {
        VectorShort t(n);
        if (n != b.n) { state = 2; return t; }
        for (int i = 0; i < n; i++) t.a[i] = a[i] - b.a[i];
        return t;
    }

    VectorShort mul(unsigned char x) {
        VectorShort t(n);
        for (int i = 0; i < n; i++) t.a[i] = a[i] * x;
        return t;
    }

    bool equal(VectorShort b) {
        if (n != b.n) return false;
        for (int i = 0; i < n; i++)
            if (a[i] != b.a[i]) return false;
        return true;
    }

    bool notEqual(VectorShort b) {
        return !equal(b);
    }

    bool greater(VectorShort b) {
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++) s1 += a[i];
        for (int i = 0; i < b.n; i++) s2 += b.a[i];
        return s1 > s2;
    }

    void print() {
        cout << "[ ";
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << "]\n";
    }

    static int objects() { return count; }
};
int VectorShort::count = 0;

// ================= MATRIX =================
class Matrix {
    short* a;
    int r, c;
    int state;
    static int count;
public:
    Matrix() {
        r = 4; c = 4; state = 0;
        a = new short[r * c];
        for (int i = 0; i < r * c; i++) a[i] = 0;
        count++;
    }

    Matrix(int n) {
        if (n <= 0) n = 4;
        r = c = n; state = 0;
        a = new short[r * c];
        for (int i = 0; i < r * c; i++) a[i] = 0;
        count++;
    }

    Matrix(int rows, int cols, short value) {
        if (rows <= 0) rows = 4;
        if (cols <= 0) cols = 4;
        r = rows; c = cols; state = 0;
        a = new short[r * c];
        for (int i = 0; i < r * c; i++) a[i] = value;
        count++;
    }

    Matrix(const Matrix& other) {
        r = other.r; c = other.c; state = other.state;
        a = new short[r * c];
        for (int i = 0; i < r * c; i++) a[i] = other.a[i];
        count++;
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            delete[] a;
            r = other.r; c = other.c; state = other.state;
            a = new short[r * c];
            for (int i = 0; i < r * c; i++) a[i] = other.a[i];
        }
        return *this;
    }

    ~Matrix() {
        delete[] a;
        count--;
    }

    void set(int i, int j, short value = 0) {
        if (i < 0 || i >= r || j < 0 || j >= c) { state = 1; return; }
        a[i * c + j] = value; state = 0;
    }

    short get(int i, int j) {
        if (i < 0 || i >= r || j < 0 || j >= c) { state = 1; return 0; }
        state = 0; return a[i * c + j];
    }

    Matrix add(Matrix b) {
        Matrix t(r, c, 0);
        if (r != b.r || c != b.c) { state = 2; return t; }
        for (int i = 0; i < r * c; i++) t.a[i] = a[i] + b.a[i];
        return t;
    }

    Matrix sub(Matrix b) {
        Matrix t(r, c, 0);
        if (r != b.r || c != b.c) { state = 2; return t; }
        for (int i = 0; i < r * c; i++) t.a[i] = a[i] - b.a[i];
        return t;
    }

    Matrix mulScalar(short x) {
        Matrix t(r, c, 0);
        for (int i = 0; i < r * c; i++) t.a[i] = a[i] * x;
        return t;
    }

    Matrix mul(Matrix b) {
        Matrix t(r, b.c, 0);
        if (c != b.r) { state = 2; return t; }
        for (int i = 0; i < r; i++)
            for (int j = 0; j < b.c; j++)
                for (int k = 0; k < c; k++)
                    t.a[i * b.c + j] += a[i * c + k] * b.a[k * b.c + j];
        return t;
    }

    bool notEqual(Matrix b) {
        if (r != b.r || c != b.c) return true;
        for (int i = 0; i < r * c; i++)
            if (a[i] != b.a[i]) return true;
        return false;
    }

    bool greater(Matrix b) {
        int s1 = 0, s2 = 0;
        for (int i = 0; i < r * c; i++) s1 += a[i];
        for (int i = 0; i < b.r * b.c; i++) s2 += b.a[i];
        return s1 > s2;
    }

    bool less(Matrix b) {
        int s1 = 0, s2 = 0;
        for (int i = 0; i < r * c; i++) s1 += a[i];
        for (int i = 0; i < b.r * b.c; i++) s2 += b.a[i];
        return s1 < s2;
    }

    void print() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                cout << a[i * c + j] << " ";
            cout << endl;
        }
    }

    static int objects() { return count; }
};
int Matrix::count = 0;

// ================= MAIN =================
int main() {
    Parallelogram p1;
    Parallelogram p2(10, 5, 6, "red");
    p1.print();
    p2.print();

    VectorShort v1(3, 2), v2(3, 1);
    v1.set(0, 5);
    cout << "\nVector v1: "; v1.print();
    cout << "Vector v2: "; v2.print();
    cout << "v1 + v2: "; v1.add(v2).print();
    cout << "v1 - v2: "; v1.sub(v2).print();
    cout << "v1 * 2: "; v1.mul(2).print();
    cout << "Vector objects: " << VectorShort::objects() << endl;

    Matrix m1(2, 2, 1), m2(2, 2, 2);
    m1.set(0, 1, 5);
    cout << "\nMatrix m1:\n"; m1.print();
    cout << "Matrix m2:\n"; m2.print();
    cout << "m1 + m2:\n"; m1.add(m2).print();
    cout << "m1 - m2:\n"; m1.sub(m2).print();
    cout << "m1 * 3:\n"; m1.mulScalar(3).print();
    cout << "m1 * m2:\n"; m1.mul(m2).print();
    cout << "Matrix objects: " << Matrix::objects() << endl;

    return 0;
}
