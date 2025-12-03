#include <iostream>
#include <string>

using namespace std;

class Point {
    private:
        double x_ = 0;
        double y_ = 0;

    public:
        // методы
        double GetX();
        double GetY();
        void SetX();
        void SetY();
        void Print();

        // конструкторы
        Point();
        Point(double x, double y);
        Point(const Point& other);

        // деструктор
        ~Point();
};

double Point::GetX() { return x_;}
double Point::GetY() { return y_;}
void Point::SetX() {
    int x;
    cout << "Введите X: ";
    cin >> x;
    cout << endl;
    x_ = x;
}
void Point::SetY() {
    int y;
    cout << "Введите Y: ";
    cin >> y;
    cout << endl;
    y_ = y;
}

void Point::Print() {
    cout << "\nВызван метод Print()\n";
    cout << "Координата X: " << GetX() << ", координата Y: " << GetY() << endl;
}

Point::Point() {
    x_ = 0;
    y_ = 0;
    cout << "Вызван конструктор Point()\n";
    cout << "Объект класса Point создан.\n";
}

Point::Point(double x, double y) {
    x_ = x;
    y_ = y;
    cout << "Вызван конструктор Point(double x, double y)\n";
    cout << "Объект класса Point создан\n";
}

Point::Point(const Point& other) {
    x_ = other.x_;
    y_ = other.y_;
    cout << "Вызван конструктор Point(const Point& other)\n";
    cout << "Объект класса Point создан.\n";
}

Point::~Point() {
    cout << "Вызван деструктор ~Point(). Объект удалён." << endl;
}

class ColoredPoint : public Point {
    private: 
        string color_;

    public:
        ColoredPoint();
        ColoredPoint(double x, double y, const string& color);
        ColoredPoint(const ColoredPoint& other);
        ~ColoredPoint();

        string GetColor();
        void SetColor(const string& color);
        void Print();
};

ColoredPoint::ColoredPoint() : Point(), color_("black") {
    cout << "\nВызван конструктор ColoredPoint()\n";
    cout << "Объект класса ColoredPoint создан.\n";
}

ColoredPoint::ColoredPoint(double x, double y, const string& color) : Point(x, y), color_(color) {
    cout << "\nВызван констуктор ColoredPoint(double x, double y, const string& color)\n";
    cout << "Объект класса ColoredPoint создан.\n";
}

ColoredPoint::ColoredPoint(const ColoredPoint& other) : Point(other), color_(other.color_) {
    cout << "\nВызван констуктор ColoredPoint(const ColoredPoint& other)\n";
    cout << "Объект класса ColoredPoint создан.\n";
}

ColoredPoint::~ColoredPoint() {
    cout << "Вызван деструктор ~ColoredPoint(). Объект удалён." << endl;
}

string ColoredPoint::GetColor() { return color_; }

void ColoredPoint::SetColor(const string& color) { color_ = color; }

void ColoredPoint::Print() {
    Point::Print();
    cout << "Color: " << GetColor() << endl;
}

int main() {
    cout << "\nСоздаем динамический объект Point по умолчанию....." << endl;
    cout << "===================================================" << endl;
    Point *pa = new Point;
    pa->Print();

    cout << "\n\n";

    cout << "\nСоздаем динамический объект Point....." << endl;
    cout << "======================================" << endl;
    Point *pb = new Point(4.0, 10.0);
    pb->Print();

    cout << "\n\n";

    cout << "\nКопируем динамический объект Point в другой объект Point....." << endl;
    cout << "=============================================================" << endl;
    Point *pc = new Point(*pb);
    pc->Print();

    cout << "\nУдаляем последний созданный динамический объект....." << endl;
    cout << "===========================================================" << endl;
    delete pa;

    cout << "\n\n";

    cout << "\nСоздаем объект Point по умолчанию....." << endl;
    cout << "======================================" << endl;
    Point a;
    a.Print();

    cout << "\n\n";

    cout << "\nСоздаем объект Point....." << endl;
    cout << "=========================" << endl;
    Point b(2.5, 3.5);
    b.Print();

    cout << "\n\n";

    cout << "\nКопируем объект Point в другой объект Point....." << endl;
    cout << "================================================" << endl;
    Point c(b);
    c.Print();

    cout << "\n\n";

    cout << "\nСоздаем динамический объект ColoredPoint по умолчанию....." << endl;
    cout << "==========================================================" << endl;
    ColoredPoint *cp1 = new ColoredPoint();
    cp1->Print();

    cout << "\n\n";

    cout << "\nСоздаем динамический объект ColoredPoint....." << endl;
    cout << "=============================================" << endl;
    ColoredPoint *cp2 = new ColoredPoint(3.0, 8.5, "blue");
    cp2->Print();

    cout << "\n\n";

    cout << "\nКопируем динамический объект ColoredPoint в другой объект ColoredPoint....." << endl;
    cout << "===========================================================================" << endl;
    ColoredPoint *cp3 = new ColoredPoint(*cp1);
    cp3->Print();

    cout << "\n\n";

    cout << "\nУдаляем созданные динамические объекты....." << endl;
    cout << "===========================================" << endl;
    delete cp1;
    delete cp2;
    delete cp3;

    cout << "\n\n";

    cout << "\nСоздаем объект ColoredPoint по умолчанию....." << endl;
    cout << "======================================" << endl;
    ColoredPoint cp_1;
    cp_1.Print();

    cout << "\n\n";

    cout << "\nСоздаем объект ColoredPoint....." << endl;
    cout << "================================" << endl;
    ColoredPoint cp_2(5.0, 2.0, "white");
    cp_2.Print();

    cout << "\n\n";

    cout << "\nКопируем объект ColoredPoint в другой объект ColoredPoint....." << endl;
    cout << "==============================================================" << endl;
    ColoredPoint cp_3(cp_2);
    cp_3.Print();

    cout << "\n\n";

    return 0;
}