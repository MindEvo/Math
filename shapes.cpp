#include <iostream>
#include <cmath>

struct point {
    float x;
    float y;
    point(float x, float y):x(x), y(y) {}
};

struct rectangle {
    point p1;
    point p2;
    rectangle(point p1, point p2):p1(p1), p2(p2) {}
    float Width() {
        return (((int)(p1.x - p2.x) >> 31) | 1) * (p1.x - p2.x);        
    }
    float Height() {
        return (((int)(p1.y - p2.y) >> 31) | 1) * (p1.y - p2.y);
    }
    float Area() {return Width() * Height();}
};

int main() {

    
    return 0;

}






// Absolute Value Trick
//
//   ( (value >> 31) | 1) * value;
//
//
//