#include <iostream>

class Point {
    public:
    int x;
    int y;
    Point(): x(0), y(0) {}
    Point(int x, int y): x(x), y(y) {}
    bool hasNeg() {
        return x < 0 || y <0;
    }
    bool isInGrid(int sizeX = 5, int sizeY = 4) {
    if (this->x >= sizeX || this->y >= sizeY) return false;
    if (this->hasNeg()) return false;
    return true;
}
};

int *copyArr(int *array, int size)
{
    int *copy = new int[size];
    for (int i = 0; i < size; i++)
    {
        copy[i] = array[i];
    }
    return copy;
}


int convertPointToIndex(Point p, int sizeX = 5, int sizeY = 4) {
    if (p.hasNeg()) throw std::invalid_argument("negativ point");
    if (p.x >= sizeX || p.y >= sizeY) throw std::invalid_argument("Point out of grid.");
    int i = p.y * sizeX + p.x;
    if (i >= sizeX * sizeY) throw std::invalid_argument("Point out of grid.");
    return i;
}

bool reachableRecursiv(int * arr, Point start, Point end) {
    int index = convertPointToIndex(start);
    int endex = convertPointToIndex(end);
    if (arr[index] == 0) return false;
    if (arr[endex] == 0) return false;
    if (index == endex) return true;
    arr[index] = 0;
    Point newPoints[4];
    newPoints[0] = Point(start.x+1, start.y);
    newPoints[1] = Point(start.x-1, start.y);
    newPoints[2] = Point(start.x, start.y+1);
    newPoints[3] = Point(start.x, start.y-1);
    for (int i = 0; i < 4; i++) {
        if (newPoints[i].isInGrid() && reachableRecursiv(arr, newPoints[i], end)) return true;
    }
    return false;
}

bool reachable(int * arr, Point start, Point end) {
    int * arrCopy = copyArr(arr, 20);
    bool out = reachableRecursiv(arrCopy, start, end);
    delete arrCopy;
    return out;

}
int main() {

    int arr[] = {
        1, 1, 1, 0, 1,
        0, 1, 1, 0, 1,
        1, 1, 1, 0, 1,
        1, 1, 1, 0, 1
    };
    std::cout << reachable(arr, Point(4,0), Point(4,3)) << std::endl;

    return 0;
}