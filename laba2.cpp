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
    
}