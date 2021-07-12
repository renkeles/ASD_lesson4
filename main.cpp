#include <iostream>

void DexToBin(size_t n){
    if(n > 1){
        DexToBin(n / 2);
    }
    std::cout << n % 2;
}

size_t Power(size_t a, size_t b){
    if(b == 1){
        return a;
    }else{
        return (a * Power(a, b - 1));
    }

}

size_t PowerB(size_t a, size_t b) {
    if (b == 0){
        return 1;
    }
    size_t x = (b % 2) ? a : 1;
    size_t c = PowerB(a, b / 2);
    return x * c * c;
}


int main() {

    //4  == 100
    //21 == 10101
    //41 == 101001
    //99 == 1100011
    DexToBin(4);

    std::cout << std::endl;

    //8
    std::cout << Power(2,3) << std::endl;
    //3125
    std::cout << Power(5,5) << std::endl;
    //1024
    std::cout << Power(2,10) << std::endl;


    //8
    std::cout << PowerB(2,3) << std::endl;
    //3125
    std::cout << PowerB(5,5) << std::endl;
    //1024
    std::cout << PowerB(2,10) << std::endl;



    return 0;
}
