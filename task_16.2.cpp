#include <iostream>
#include <cmath>

using namespace std;


class Point {
public:
    double x, y;
    int dim = 2;

    friend ostream& operator<<(ostream& out, Point& p) {
        cout << "(" << p.x << "; " << p.y << ")";
    }
    friend istream& operator>>(istream& in, Point& p) {
        cout << "\nx: ";
        cin >> p.x;
        cout << "y: ";
        cin >> p.y;
    }
    Point(double x, double y) :x(x), y(y) {};
    Point() {};
    friend class Point3D;
};


class Point3D : public Point {
public:
    double z;
    int dim = 3;

    friend ostream& operator<<(ostream& out, Point3D& p) {
        cout << "(" << p.x << "; " << p.y << "; " << p.z << ")";
    }
    friend istream& operator>>(istream& in, Point3D& p) {
        cout << "\nx: ";
        cin >> p.x;
        cout << "y: ";
        cin >> p.y;
        cout << "z: ";
        cin >> p.z;
    }

    Point3D(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
        dim = 3;
    };
    Point3D() {};
};


class Line {
public:
    Point p1, p2;
    Point3D pd1, pd2;
    int dim;

    friend ostream& operator<<(ostream& out, Line& l) {
        if (l.dim == 3) cout << l.pd1 << " " << l.pd2;
        else cout << l.p1 << " " << l.p2;
    }

    friend istream& operator>>(istream& in, Line& l) {
        cout << "Dimension: ";
        cin >> l.dim;
        if (l.dim == 3) cin >> l.pd1 >> l.pd2;
        else cin >> l.p1 >> l.p2;
    }

    double length() {
        if (dim == 3) return sqrt(pow(pd1.x - pd2.x, 2) + pow(pd1.y - pd2.y, 2) + pow(pd1.z - pd2.z, 2));
        else return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }

    void build(Point p1, Point p2) {
        this->p1.x = p1.x;
        this->p1.y = p1.y;
        this->p2.x = p2.x;
        this->p2.y = p2.y;
        dim = 2;
    }

    void build(Point3D p1, Point3D p2) {
        pd1.x = p1.x;
        pd1.y = p1.y;
        pd1.z = p1.z;
        pd2.x = p2.x;
        pd2.y = p2.y;
        pd2.z = p2.z;
        dim = 3;
    }

    Line(Point p1, Point p2) :p1(p1), p2(p2), dim(2) {};
    Line(Point3D p1, Point3D p2) :pd1(p1), pd2(p2), dim(3) {};
    Line() {};
};


int main() {
    Point p1, p2;
    Point3D p3, p4;
    cin >> p1 >> p2 >> p3 >> p4;
    Line l1(p1, p2), l2(p3, p4), l3;
    cout << l1 << endl << l2;
    cin >> l3;
    cout << l3;
}