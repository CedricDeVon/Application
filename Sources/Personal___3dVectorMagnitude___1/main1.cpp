#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Point3D
{
public:
    double x, y, z;
    Point3D();
    ~Point3D();
};

Point3D::Point3D() {}

Point3D::~Point3D() {}

constexpr const double calculate3DVectorMagnitude(const Point3D* first, const Point3D* second)
{
    if (first == nullptr || second == nullptr)
    {
        throw std::runtime_error("Error found at 'calculate3DVectorMagnitude()': Arguments must not be null");
    }

    double x = second->x - first->x, y = second->y - first->y, z = second->z - first->z;
    return sqrt(x * x + y * y + z * z);
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    Point3D* first = new Point3D(), *second = new Point3D();
    std::cin >> first->x >> first->y >> first->z >> second->x >> second->y >> second->z;
    const double answer = calculate3DVectorMagnitude(first, second);
    std::cout << answer;

    // bool exitCode;
    // std::cin >> exitCode;
    return 0;
}