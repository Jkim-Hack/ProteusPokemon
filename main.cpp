#include <iostream>

int main()
{
    int (*pixels)[5];
    int pixel[5] = {1,2,3,4,5};
    pixels = &pixel;

    for (int i = 0; i < sizeof(*pixels)/ sizeof(int); ++i) {
        std::cout << (*pixels)[i] << std::endl;
    }

    return 0;
}