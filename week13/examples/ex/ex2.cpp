#include<iostream>
#include<math.h>
using namespace std;


template<typename T>
class Point {
private:

    T x, y;
public:

    Point(T newX, T newY) ;
    Point(const Point& p);

    T getX() const; 
    T getY() const; 
};

template<typename T>
Point<T>::Point(T newX, T newY):x(newX),y(newY){}
template<typename T>
Point<T>::Point(const Point& p):x(p.x),y(p.y){}

template<typename T>
inline T Point<T>::getX() const{ return x;}
template<typename T>
inline T Point<T>::getY() const{ return y;}


template<typename T>
class Line
{
private:

    Point<T> p1, p2;
    double distance;
public:

    Line(Point<T>& xp1, Point<T>& xp2);
    Line(const Line<T>& q);

    double getDistance() const;
};

template<typename T>
inline double Line<T>::getDistance()const
{
    return sqrt(((p1.getX()-p2.getX())*(p1.getX()-p2.getX())+(p1.getY()-p2.getY())*(p1.getY()-p2.getY())));
}

//注意！！构造函数不是默认inline的
template<typename T>
Line<T>::Line(Point<T>& xp1, Point<T>& xp2):p1(xp1),p2(xp2),distance(this->getDistance()){}
template<typename T>
Line<T>::Line(const Line& q):p1(q.p1),p2(q.p2),distance(q.distance){}




int main()
{
 Point<int> a(8, 9),b(1,2);//必须要指定对象类型
 Point<int> c = a;
 cout << "point a: x = " << a.getX() << ", y = " << a.getY() << endl;
 cout << "point b: x = " << b.getX() << ", y = " << b.getY() << endl;
 cout << "point c: x = " << c.getX() << ", y = " << c.getY() << endl;
 cout << "------------------------------------------" << endl;
 Line<int> line1(a, b);
 cout << "line1's distance:" << line1.getDistance() << endl;
 Line<int> line2(line1);
 cout << "line2's distance:" << line2.getDistance() << endl;
 return 0;
}
