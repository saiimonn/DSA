#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"decode.h"

// Write your functions here...

int *bitmaskToArray(short int word[]) {
    int *bitVector = (int*)malloc(sizeof(int) * 4);
    
    for(int i = 0; i < 4; i++) {
        for(int mask = 15; mask >= 0; mask--) {
            if(word[i] >> mask & 1) {
                bitVector[i] |= 1 << mask;
            }
        }
    }
    
    return bitVector;
}

char *decodeString(int arr[]) {
    char *str = (char*)malloc(sizeof(char) * 8);
    
    int idx = 0;
    for(int i = 0; i < 4; i++) {
        int sum = 0;
        for(int mask = 15; mask >= 8; mask--) {
            if(arr[i] >> mask & 1) {
                sum += pow(2, mask - 8);
            }
        }
        
        str[idx++] = sum;
        
        sum = 0;
        for(int mask = 7; mask >= 0; mask--) {
            if(arr[i] >> mask & 1) {
                sum += pow(2, mask);
            }
        }
        str[idx++] = sum;
    }
    
    return str;
}

void displayBitPattern(int arr[]) {
    int mask;
    
    for(int i = 0; i < 4; i++) {
        for(mask = 15; mask >= 0; mask--) {
            printf("%d", arr[i] >> mask & 1);
        }
        printf(" ");
    }
}