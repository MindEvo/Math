#include <iostream>

struct CoordinateSystem {
    int left, right;        // X dimension
    int bottom, top;        // Y dimension

    CoordinateSystem(int xMin, int xMax, int yMin, int yMax)
        :left(xMin), right(xMax), bottom(yMin), top(yMax) {}
    bool PointInSystem(float x, float y) {
        return ((x <= right && x >= left) && (y <= top && y >= bottom));
    }
};

struct Point {
    float x, y;

    Point () {}
    void SetPoint(float px, float py, CoordinateSystem mySys) {
        if (mySys.PointInSystem(px, py)) {
            x = px;
            y = py;
        }
    }
};

int main() {
    CoordinateSystem myCoordinateSystem(0, 640, 0, 360);
    Point myPoint;
    myPoint.SetPoint(12.0f, 13.0f, myCoordinateSystem);

    std::cout << "x(" << myCoordinateSystem.left << ", " << myCoordinateSystem.right  << ") "
              << "y(" << myCoordinateSystem.bottom  << ", " << myCoordinateSystem.top << ") \n";

    std::cout << "(" << myPoint.x << ", " << myPoint.y << ")";
    return 0;
}
