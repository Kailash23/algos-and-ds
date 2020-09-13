#include <iostream>
using namespace std;

class Box {
  public:
    int width;
    int height;
    int length;

    void volume() {
        cout << length * width * height;
    }
};

int main() {
    Box b;
    b.height = 5;
    b.width = 4;
    b.volume();
}

/*
   Garbage Value
 */
