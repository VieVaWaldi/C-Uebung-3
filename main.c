#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    // Parameters
    int depth = 5;
    int max = pow(2, depth) -1;
    int ar[depth];

    fillBinary(ar, depth, max);

    return 0;
}

void fillBinary(int ar[], int depth, int max) {

    // Parameters
    int iter = max;
    int i, j;

    // Fill Array with 0's
    for( i=0; i<depth; ++i) {
        ar[i] = 0;
    }

    // For every possible number
    while( iter>0 ) {

        // For every idx of array
        for( i=0; i<depth; ++i) {

            // 2 Cases:
            if( ar[i]==0 ) {
                ar[i]=1;
                break;
            }

            if( ar[i]==1 ) {

                // Search for next 0 and set it 1. Set every 1 to 0 on the way
                for( j=0; j<depth; ++j ) {

                    if( ar[j] == 0 ) {
                        ar[j] = 1;
                        break;
                    }

                    if( ar[j] == 1 ) {
                        ar[j] = 0;
                    }
                }
                break;
            }
        }
        printArray(ar, depth);
        iter--;
    }
}

void printArray( int ar[], int size ) {
    int i;
    for( i=size-1; i>-1; --i) {
        print(ar[i]);
    }
    printf("\n");
}

void print(int x) {
    printf("%d", x);
}
