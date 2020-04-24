#include "Die.h"
#include <iostream>



int main(){

    int arr[6] = {0,0,0,0,0,0};

    Die test;

    std::cout << "Roll: ";

    for (unsigned int i = 0; i < 5; i++) {
        int roll = test.roll();
        std::cout << roll;
        arr[roll - 1]++;
    }

    int index = 0;
    for (unsigned int i = 1; i < 6; i++) {
        if(arr[i] >= arr[index]) {
            index = i;
        }
    }
    
    std::cout << std::endl << "Best result: " << arr[index] << " occurence(s) of " << index + 1 << std::endl; 

    return 0;
};