#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Point2D
{
    public:
        double x, y;
        Point2D();
        ~Point2D();
};

Point2D::Point2D()
{
    this->x = this->y = 0;
}

Point2D::~Point2D()
{

}



const char* get_orientation(Point2D* p1, Point2D* p2, Point2D* p3)
{
    double a = (p2->y - p1->y) * (p3->x - p2->x);
    double b = (p3->y - p2->y) * (p2->x - p1->x);
    if (a > b)
    {
        return "Clockwise";
    }
    else if (a < b)
    {
        return "CounterClockwise";
    }
    return "Linear";
}

int main(void)
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // std::cout.tie(nullptr);

    Point2D* p1 = new Point2D();
    Point2D* p2 = new Point2D();
    Point2D* p3 = new Point2D();

    std::cin >> p1->x >> p1->y;
    std::cin >> p2->x >> p2->y;
    std::cin >> p3->x >> p3->y;
    std::cout << get_orientation(p1, p2, p3) << '\n';

    delete p1;
    delete p2;
    delete p3;

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}