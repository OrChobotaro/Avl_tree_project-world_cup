#include "EmptyTree.h"


int calcEmptyTreeHeight(int requiredSize) {
    int height = 0;
    int temp = 2;
    while (requiredSize > temp) {
        temp *=2;
        height+=1;
    }
    return height;
}


int exponent (int exponent) {
    int result = 1;
    while(exponent > 0) {
        result *= 2;
        --exponent;
    }
    return result;
}
