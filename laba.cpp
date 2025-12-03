#include <iostream>
#include <string>

using namespace std;

class Point {
    private:
        double x_ = 0;
        double y_ = 0;
    public:
        double GetX() { return x_; };
        double GetY() { return y_; };
        void SetX(double x) { x_ = x; };
        void SetY(double y) { y_ = y; };
        void Print();

        Point();
        Point(double x, double y);
        Point(const Point& other);

        ~Point();
};

void Point::Print() { cout << "Point::Print(): X = " << x_ << ", Y = " << y_; }

Point::Point() : x_(0), y_(0) { cout << "Point: Конструктор по умолчанию" << endl; }

Point::Point(double x, double y) : x_(x), y_(y) { 
    cout << "Point: Конструктор с параметрами (" << x << ", " << y << ")" << endl;
}

Point::Point(const Point& other) : x_(other.x_), y_(other.y_) { cout << "Point: Конструктор копирования" << endl; }

Point::~Point() { cout << "Point: Деструктор (" << x_ << ", " << y_ << ")" << endl; }

class ColoredPoint : public Point {
    private: 
        string color_;
    public:
        ColoredPoint();
        ColoredPoint(double x, double y, const string& color);
        ColoredPoint(const ColoredPoint& other);

        ~ColoredPoint();

        string GetColor() { return color_; };
        void SetColor(const string& color) { color_ = color; };
        void Print();
};

ColoredPoint::ColoredPoint() : Point(), color_("black") { cout << "ColoredPoint: Конструктор по умолчанию" << endl; }

ColoredPoint::ColoredPoint(double x, double y, const string& color) : Point(x, y), color_(color) {
    cout << "ColoredPoint: Конструктор с параметрами (" << color << ")" << endl;
}

ColoredPoint::ColoredPoint(const ColoredPoint& other) : Point(other), color_(other.color_) {
    cout << "ColoredPoint: Конструктор копирования" << endl;
}

ColoredPoint::~ColoredPoint() { cout << "ColoredPoint: Деструктор (" << color_  << ")" << endl; }

void ColoredPoint::Print() {
    cout << "ColoredPoint::Print(): ";
    Point::Print();
    cout << ", color = " << GetColor() << endl;
}

int main() {
    cout << "=============== Часть 1 ===============\n";

    cout << "\n1. Создание динамических объектов Point.\n" << endl;
    Point *pa = new Point;
    Point *pb = new Point(4.0, 10.0);
    Point *pc = new Point(*pb);

    cout << "\n2. Вызов методов.\n" << endl;
    pa->Print(); cout << endl;
    pb->Print(); cout << endl;
    pc->Print(); cout << endl;

    cout << "\n3. Удаление динамических объектов Point.\n" << endl;
    delete pa;
    delete pb;
    delete pc;

    cout << "\n4. Создание статических объектов Point.\n" << endl;
    Point a;
    Point b(5.0, 8.5);
    Point c(b);

    cout << "\n5. Вызов методов.\n" << endl;
    a.Print(); cout << endl;
    b.Print(); cout << endl;
    c.Print(); cout << endl;

    cout << "\n\n=============== Часть 2 ===============\n";

    cout << "\n6. Создание динамических объектов ColoredPoint.\n" << endl;
    ColoredPoint *cp1 = new ColoredPoint();
    ColoredPoint *cp2 = new ColoredPoint(3.0, 6.0, "blue");
    ColoredPoint *cp3 = new ColoredPoint(*cp1);

    cout << "\n7. Вызов методов.\n" << endl;
    cp1->Print();
    cp2->Print();
    cp3->Print();

    cout << "\n8. Удаление динамических объектов ColoredPoint.\n" << endl;
    delete cp1;
    delete cp2;
    delete cp3;

    cout << "\n9. Создание статических объектов ColoredPoint.\n" << endl;
    ColoredPoint cpa;
    ColoredPoint cpb(5.0, 8.5, "white");
    ColoredPoint cpc(cpb);

    cout << "\n10. Вызов методов.\n" << endl;
    cpa.Print();
    cpb.Print();
    cpc.Print();

    cout << "\n\n";

    return 0;
}