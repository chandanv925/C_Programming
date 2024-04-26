#include <stdio.h>

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += (n & 1); // Check if the least significant bit is set
        n >>= 1; // Shift the bits of n to the right by 1
    }
    return count;
}


int countSetBits2(int n) {
    int count = 0;
    for(int i = 0; i < sizeof(n) * 8; i++) {
        if (n & (1 << i)) { // Use bitwise AND (&) to check if the bit is set
            count++;
        }
    }
    return count;
}



int main() {
    int num = 15; // Example integer
    printf("Number of set bits in %d: %d\n", num, countSetBits2(num));
    return 0;
}
