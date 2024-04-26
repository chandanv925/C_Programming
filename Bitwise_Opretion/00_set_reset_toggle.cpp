#include <stdio.h>
#include <iostream>
using namespace std;


    /*
    (a & b)  // Bitwise AND
    (a | b)  // Bitwise OR (set bit)
    (a ^ b)  // Bitwise XOR (toggle bit)        
    (~a)     // Bitwise NOT (in two's complement) (reset_bit)
    (a << 1) // Left Shift
    (b >> 1) // Right Shift
    */

int set_bit(int num, int k)
{
    return (num | (1 << (k - 1)));
}
int reset_bit(int num, int k)
{
    return (num & (~(1 << (k - 1))));
}
int toggle_bit(int num, int k)
{
    return (num ^ (1 << (k - 1)));
}

int set_bit_from_MSB(int num, int k)
{
    int num_bits = sizeof(num) * 8;       
    return (num | (1 << (num_bits - k))); 

}
int reset_bit_from_MSB(int num, int k)
{
    int num_bits = sizeof(num) * 8;        
    return (num & ~(1 << (num_bits - k))); 
}
int toggle_bit_from_MSB(int num, int k)
{
    int num_bits = sizeof(num) * 8;       
    return (num ^ (1 << (num_bits - k))); 
}

int main()
{
    long int m = 6;
    cout << "setbit(4)=" << set_bit(4, 2) << endl;
    cout << "resetbit(4)=" << reset_bit(16, 2) << endl;
    cout << "togglebit(4)=" << toggle_bit(4, 2) << endl;

  
    cout << "setbit(4)=" << set_bit_from_MSB(4, 2) << endl;
    cout << "resetbit(4)=" << reset_bit_from_MSB(16, 2) << endl;
    cout << "togglebit(4)=" << toggle_bit_from_MSB(4, 2) << endl;

    cout << (1 << 2);

    return 0;
}
