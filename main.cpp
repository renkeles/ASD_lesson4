#include <iostream>

const size_t sizeX = 7;
const size_t sizeY = 6;

void DexToBin(size_t n) {
    if (n > 1) {
        DexToBin(n / 2);
    }
    std::cout << n % 2;
}

size_t Power(size_t a, size_t b) {
    if (b == 1) {
        return a;
    }
    else {
        return (a * Power(a, b - 1));
    }

}

size_t PowerB(size_t a, size_t b) {
    if (b == 0) {
        return 1;
    }
    size_t x = (b % 2) ? a : 1;
    size_t c = PowerB(a, b / 2);
    return x * c * c;
}

size_t Routes(size_t x, size_t y) {
    int arMap[sizeY][sizeX] = { 0,0,0,0,0,1,0,
                                0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,
                                0,0,0,1,0,0,0,
                                0,1,0,0,0,1,0,
                                0,0,0,1,0,0,0};
    if (arMap[y][x] == 1) return 0;
    if (x == 0 && y == 0) {
        return 0;
    }
    else if((x == 0) ^ (y == 0)) {
        return 1;
    }
    else {
        return Routes(x, y - 1) + Routes(x - 1, y);
    }
}

int main() {

    //4  == 100
    //21 == 10101
    //41 == 101001
    //99 == 1100011
    DexToBin(4);

    std::cout << std::endl;

    //8
    std::cout << Power(2, 3) << std::endl;
    //3125
    std::cout << Power(5, 5) << std::endl;
    //1024
    std::cout << Power(2, 10) << std::endl;


    //8
    std::cout << PowerB(2, 3) << std::endl;
    //3125
    std::cout << PowerB(5, 5) << std::endl;
    //1024
    std::cout << PowerB(2, 10) << std::endl;




    std::cout << std::endl;


    for (size_t y = 0; y < sizeY; ++y) {
        for (size_t x = 0; x < sizeX; ++x) {
            //std::cout << Routes(x, y) << " ";
            printf("%5d", Routes(x,y));
        }
        std::cout << std::endl;
    }


    return 0;
}