#include <iostream>

enum class Color {
    RED,
    GREEN,
    BLUE
};

class Shape {
private:
    int x, y;
    Color color;
public:
    Shape(int coordinate_x, int coordinate_y, Color shapeColor): x(coordinate_x), y(coordinate_y), color(shapeColor) {}

    virtual void area() {
        std::cout << "Nothing";
    }
};

class Triangle: public Shape {
private:
    int a, b, c;
public:
    Triangle(int coordinate_x, int coordinate_y, Color shapeColor, int valueA, int valueB, int valueC) : Shape(coordinate_x, coordinate_y, shapeColor),
        a(valueA), b(valueB), c(valueC) {}
    void area() {
        double p = (a + b + c) / 2;
        std::cout << "Area of Triangle: " << sqrt(p * (p - a)*(p - b)*(p - c)) << std::endl;
    }
};

class Rectangle : public Shape {
private:
    int a, b;
public:
    Rectangle(int coordinate_x, int coordinate_y, Color shapeColor, int valueA, int valueB): Shape(coordinate_x, coordinate_y, shapeColor),
        a(valueA), b(valueB) {}
    void area() {
        std::cout << "Area of Rectangle: " << a * b << std::endl;
    }
};

class Circle :public Shape {
private:
    int r;
public:
    Circle(int coordinate_x, int coordinate_y, Color shapeColor, int valueR) : Shape(coordinate_x, coordinate_y, shapeColor), r(valueR) {}
    void area() {
        std::cout << "Area of Circle: " << r * r * 3.14 << std::endl;
    }
};



int main()
{
    Triangle triangle(0, 0, Color::RED, 3, 4, 5);
    Rectangle rectangle(0, 0, Color::BLUE, 5, 2);
    Circle circle(0, 0, Color::GREEN, 10);
    triangle.area();
    rectangle.area();
    circle.area();

}

