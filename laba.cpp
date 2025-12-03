#include <iostream>
#include <string>

using namespace std;

class Point {
    private:
        double x_;
        double y_;
    protected:
        int size_;
    public:
        double GetX() const { return x_; };
        double GetY() const { return y_; };
        int GetSize() const { return size_; };
        void SetX(double x) { x_ = x; };
        void SetY(double y) { y_ = y; };
        void SetSize(int size) { size_ = size; }
        void Print() const;

        Point();
        Point(double x, double y, int px);
        Point(const Point& other);

        ~Point();
};

void Point::Print() const { cout << "Point::Print(): X = " << x_ << ", Y = " << y_ << ", size = " << size_; }

Point::Point() : x_(0), y_(0), size_(5) { cout << "Point: Конструктор по умолчанию" << endl; }

Point::Point(double x, double y, int size) : x_(x), y_(y), size_(size) { 
    cout << "Point: Конструктор с параметрами (" << x << ", " << y << ", " << size << ")" << endl;
}

Point::Point(const Point& other) : x_(other.x_), y_(other.y_), size_(other.size_) { 
    cout << "Point: Конструктор копирования" << endl; 
}

Point::~Point() { cout << "Point: Деструктор (" << x_ << ", " << y_ << ", " << size_ << ")" << endl; }

class ColoredPoint : public Point {
    private: 
        string color_;
    public:
        ColoredPoint();
        ColoredPoint(double x, double y, int size, const string& color);
        ColoredPoint(const ColoredPoint& other);

        ~ColoredPoint();

        void SetPointSize(int size) { size_ = size; } // size_ - protected в классе Point
        string GetColor() const { return color_; };
        void SetColor(const string& color) { color_ = color; };
        void Print() const;
};

ColoredPoint::ColoredPoint() : Point(), color_("black") { cout << "ColoredPoint: Конструктор по умолчанию" << endl; }

ColoredPoint::ColoredPoint(double x, double y, int size, const string& color) : Point(x, y, size), color_(color) {
    cout << "ColoredPoint: Конструктор с параметрами (" << color << ")" << endl;
}

ColoredPoint::ColoredPoint(const ColoredPoint& other) : Point(other), color_(other.color_) {
    cout << "ColoredPoint: Конструктор копирования" << endl;
}

ColoredPoint::~ColoredPoint() { cout << "ColoredPoint: Деструктор (" << color_  << ")" << endl; }

void ColoredPoint::Print() const {
    cout << "ColoredPoint::Print(): ";
    Point::Print();
    cout << ", color = " << GetColor() << endl;
}

class Line {
    private:
        Point start_;
        Point* end_;
    public:
        Line();
        Line(const Point& start, const Point& end);
        Line(const Line& other);
        ~Line();

        void Print() const;
        void Move(double dx, double dy);
};

Line::Line() : start_(), end_(new Point()) { cout << "Line: Конструктор по умолчанию" << endl; }

Line::Line(const Point& start, const Point& end) : start_(start), end_(new Point(end)) {
    cout << "Line: Конструктор с параметрами Start (" << start_.GetX() << ", " << start_.GetY() << "), End (" <<
                                                        end_->GetX() << ", " << end_->GetY() << ")" << endl;
}

Line::Line(const Line& other) : start_(other.start_), end_(new Point(*other.end_)) {
    cout << "Line: Конструктор копирования Start (" << start_.GetX() << ", " << start_.GetY() << "), End (" <<
                                                        end_->GetX() << ", " << end_->GetY() << ")" << endl;
}

Line::~Line() { 
    cout << "Line: Деструктор Start (" << start_.GetX() << ", " << start_.GetY() << "), End (" <<
                                        end_->GetX() << ", " << end_->GetY() << ")" << endl;
    delete end_;
}

void Line::Print() const {
    cout << "Line::Print(): ";
    cout << "Line: Start (" << start_.GetX() << "," << start_.GetY() << "), End (" 
                            << end_->GetX() << ", " << end_->GetY() << ")" << endl;
}

void Line::Move (double dx, double dy) {
    start_.SetX(start_.GetX() + dx);
    start_.SetY(start_.GetY() + dy);
    end_->SetX(end_->GetX() + dx);
    end_->SetY(end_->GetY() + dy);
}

int main() {
    cout << "=============== Часть 1. Создание и удаление объектов базового класса ===============\n";

    cout << "\n1. Создание динамических объектов Point.\n" << endl;
    Point *pa = new Point;
    Point *pb = new Point(4.0, 10.0, 5);
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
    Point b(5.0, 8.5, 3);
    Point c(b);

    cout << "\n5. Вызов методов.\n" << endl;
    a.Print(); cout << endl;
    b.Print(); cout << endl;
    c.Print(); cout << endl;

    cout << "\n\n=============== Часть 2. Создание и удаление объектов класса-наследника ===============\n";

    cout << "\n6. Создание динамических объектов ColoredPoint.\n" << endl;
    ColoredPoint *cp1 = new ColoredPoint();
    ColoredPoint *cp2 = new ColoredPoint(3.0, 6.0, 7, "blue");
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
    ColoredPoint cpb(5.0, 8.5, 5, "white");
    ColoredPoint cpc(cpb);

    cout << "\n10. Вызов методов.\n" << endl;
    cpa.Print();
    cpb.Print();
    cpc.Print();

    cout << "\n11. Присваивание производного класса базовому указателю:" << endl;
    Point* ptr1 = new ColoredPoint(7.0, 8.0, 5, "green");
    cout << "Вызов Print() через указатель на базовый класс:" << endl;
    ptr1->Print(); 

    cout << endl;
    delete ptr1;

    cout << "\n\n12. Копирование объектов:" << endl;
    cout << "До копирования ColoredPoint в Point:" << endl;
    cpb.Print();
    Point p4 = cpb;
    cout << "После копирования:" << endl;
    p4.Print();

    cout << "\n\n=============== Часть 3. Композиция ===============\n";

    cout << "\n13. Композиция объектов." << endl;
    cout << "Создание линии:" << endl;
    Line line(Point(0, 0, 5), Point(10, 10, 5));
    line.Print();

    cout << endl;
    cout << "\nКопирование линии:" << endl;
    Line line2 = line;
    line2.Print();

    cout << "\nИзменение копии." << endl;
    line2.Move(5, 5);
    cout << "Оригинал: ";
    line.Print();
    cout << "Копия: ";
    line2.Print();

    cout << endl;

    cout << "\n\n=============== Часть 4. Присваивание ===============\n";

    cout << "\n10. Разница между копированием объекта и указателя:" << endl;
    Point e(1, 1, 4);
    Point f(2, 2, 6);
    Point* pe = &e;
    Point* pf = &f;
    
    cout << "\nДо присваивания объектов:";
    cout << "\ne: ";
    e.Print();
    cout << "\nf: ";
    f.Print();

    e = f;
    e.SetX(100);

    cout << "\nПосле e = f и e.SetX(100):";
    cout << "\ne: ";
    e.Print();
    cout << "\nf: ";
    f.Print();

    cout << "\nДо присваивания указателей:";
    cout << "\n*pe: ";
    pe->Print();
    cout << "\n*pf: ";
    pf->Print();

    pe = pf; 
    pe->SetX(200);

    cout << "\nПосле pe = pf и pe->SetX(100): ";
    cout << "\n*pe: ";
    pe->Print();
    cout << "\n*pf: ";
    pf->Print();

    cout << "\n\n=============== Часть 5. Демонстрация работы конструкторов и деструкторов ===============\n";

    ColoredPoint* cp = new ColoredPoint(3.5, 6.0, 7, "green");
    delete cp;

    cout << "\nАвтоматическое удаление всех статических объектов, использующихся в программе:" << endl;

    return 0;
}