#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Point3D
{
public:
    double x, y, z;
    Point3D();
    virtual ~Point3D() = default;
};

Point3D::Point3D() {}

constexpr const double calculate3DVectorMagnitude(const Point3D& first, const Point3D& second)
{
    const double dx = second.x - first.x, dy = second.y - first.y, dz = second.z - first.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

int main(void)
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // std::cout.tie(nullptr);

    Point3D first, second;
    std::cin >> first.x >> first.y >> first.z >> second.x >> second.y >> second.z;
    std::cout << calculate3DVectorMagnitude(first, second);

    bool exitCode;
    std::cin >> exitCode;
    return 0;
}