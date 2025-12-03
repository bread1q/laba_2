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
    cout << "Вызван метод Print()\n";
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

    return 0;
}