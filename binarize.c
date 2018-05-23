//
// Created by cubazis on 23.05.18.
//

#include "binarize.h"

void binarize_u(unsigned long long x){

    // Store chars in result and j for checking how much binary digits have x
    char result[64];
    int j = 63;

    // Initializing statement of result all zeros
    for (int i = 0; i < 64; i++) {
        result[i] = '0';
    }

    /* While x is not equal to zero take its reminder.
     *
     * if it equals to 1 then result's jth cell is equal to 1
     * Otherwise it equals to 0
     *
     * Decrease j and divide x by two
    */
    while (x != 0) {
        if (x % 2) {
            result[j] = '1';
        } else {
            result[j] = '0';
        }
        x /= 2;
        j--;
    }

    // If j less or equal to 31 then number is 64 bit long and we need to go from 0'th to 63'th element in result
    // Otherwise number is 32 bit long and we start from 32 till the 63
    if (j <= 31) {
        j = 0;
    } else {
        j = 32;
    }

    // Print digit to screen with spaces each 8 digits
    for (; j < 64; j++) {
        printf("%c", result[j]);
        if ((j + 1) % 8 == 0) {
            printf(" ");
        }
    }

    // Print end line symbol
    printf("\n");
}

void binarize_s(signed long long y){

    // If y is positive number then just binarize it as unsinged number
    if (y > 0) {
        binarize_u(y);
    } else {

        // Otherwise make y positive
        y *= -1;
        char result[64];
        int j = 63;

        // Initial state of result
        for (int i = 0; i < 64; i++) {
           result[i] = '1';
        }

        // If y % 2 == 1 then write to result cell 0
        // Otherwise 1
        while (y != 0) {
            if (y % 2) {
               result[j] = '0';
            } else {
               result[j] = '1';
            }
            y /= 2;
            j--;
        }

        if (j <= 31) {
            j = 0;
        } else {
            j = 32;
        }

        // Print digits to screen
        for (; j < 64; j++) {
           printf("%c", result[j]);
           if ((j + 1) % 8 == 0) {
               printf(" ");
           }
        }

    }

    // Print end line symbol
    printf("\n");
}