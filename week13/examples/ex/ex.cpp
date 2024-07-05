#include<iostream>
#include<math.h>//math.h中有sqrt,而cmath中只有pow
using namespace std;

class Point {
private:

    double x, y;
public:

    Point(double newX, double newY) ;
    Point(const Point& p);

    double getX() const; 
    double getY() const; 
};

Point::Point(double newX, double newY):x(newX),y(newY){}
Point::Point(const Point& p):x(p.x),y(p.y){}

inline double Point::getX() const{ return x;}
inline double Point::getY() const{ return y;}

class Line
{
private:

    Point p1, p2;
    double distance;
public:

    Line(Point& xp1, Point& xp2);
    Line(const Line& q);

    double getDistance() const;
};

inline double Line::getDistance()const
{
    return sqrt((p1.getX()-p2.getX())*(p1.getX()-p2.getX())+(p1.getY()-p2.getY())*(p1.getY()-p2.getY()));
}

//注意！！构造函数不是默认inline的
Line::Line(Point& xp1, Point& xp2):p1(xp1),p2(xp2),distance(this->getDistance()){}
Line::Line(const Line& q):p1(q.p1),p2(q.p2),distance(q.distance){}




int main()
{
 Point a(8, 9),b(1,2);
 Point c = a;
 cout << "point a: x = " << a.getX() << ", y = " << a.getY() << endl;
 cout << "point b: x = " << b.getX() << ", y = " << b.getY() << endl;
 cout << "point c: x = " << c.getX() << ", y = " << c.getY() << endl;
 cout << "------------------------------------------" << endl;
 Line line1(a, b);
 cout << "line1's distance:" << line1.getDistance() << endl;
 Line line2(line1);
 cout << "line2's distance:" << line2.getDistance() << endl;
 return 0;
}
