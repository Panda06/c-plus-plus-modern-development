#include <cmath>
#include <iostream>
#include <iomanip>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Figure {
public:
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
    virtual string Name() const = 0;

};

class Circle : public Figure {
public:
    Circle(const double& _r) : r(_r) {}
    double Perimeter() const override {
        return 2 * r * pi;
    }
    double Area() const override {
        return pi * r * r;
    }
    string Name() const override {
        return "CIRCLE";
    }
private:
    const double pi = 3.14;
    double r;
};

class Rect : public Figure {
public:
    Rect(const double& _width, const double& _height) :
        width(_width), height(_height) {}
    double Perimeter() const override {
        return 2 * (width + height);
    }
    double Area() const override {
        return width * height;
    }
    string Name() const override {
        return "RECT";
    }
private:
    double width;
    double height;
};

class Triangle : public Figure {
public:
    Triangle(const double& _a, const double& _b, const double& _c) :
        a(_a), b(_b), c(_c) {}
    double Perimeter() const override {
        return a + b + c;
    }
    double Area() const override {
        auto p = Perimeter() / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    string Name() const override {
        return "TRIANGLE";
    }
private:
    double a;
    double b;
    double c;
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
    string figure;
    is >> figure;

    if (figure == "RECT") {
        int width, height;
        is >> width >> height;
        return make_shared<Rect>(width, height);
    } else if (figure == "TRIANGLE") {
        int a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    } else {
        int r;
        is >> r;
        return make_shared<Circle>(r);
  }
}
int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
