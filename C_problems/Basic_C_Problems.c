#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>

// Replace printf
#define LOG_MESSAGE(format, ...) printf("[INFO] " format "\n", ##__VA_ARGS__)

// 00. Find max using macro
#define MAX(a, b, c) ((a > b && a > c) ? a : (b > c ? b : c))

// 00. Count the element in array
#define COUNTOF(arr) (sizeof(arr) / sizeof(arr[0]))

// 00. Swap using macro
#define SWAP(a, b)			 \
    do {          			 \
        typeof(a) _tmp = a;	 \
        a = b;     			 \
        b = _tmp;  			 \
    } while (0)

// 00.Function to subtract two integers using bitwise operations
int subtract(int a, int b) {
    while (b != 0) {
        int borrow = (~a) & b;
        a = a ^ b;
        b = borrow << 1;
    }
    return a;
}

// 00. Function to add two integers using bitwise operations
int add(int a, int b) {
    while (b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

// 00. check if number is power of 2
int isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;  // (n & (n - 1)) rest the last set
}

// 00. check if number is odd or even
bool is_odd(int n) {
    return n > 0 && (n & 1) == 1;
}

bool is_even(int n) {
    return n > 0 && (n & 1) == 0;
}

// 00. Check the most significant bit (sign bit) for a negative number
int is_negative(int n){
	return (n >> (sizeof(n)*8 - 1)) & 1 == 1;
	//or
	if(n<0)
		return true;
}

// 00. count number of set and reset bit
int count_resetbit(int n) {
    int count = 0;  
    while (n) {
        if ((n & 1) == 0)  // Proper precedence for bitwise AND and comparison
            count++;
        n >>= 1;  
    }
    return count;
}

int count_setbit(int n) {
    int count = 0;  
    while (n) {
        count = count + (n & 1);  
        n >>= 1;  
    }
    return count;  
}

// 00. Check even and odd parity
bool is_odd_parity(int n) {
    int flag = 0; 
    while (n) {
        flag = flag ^ (n & 1);  // Toggle flag based on the least significant bit
        n >>= 1; 
    }
    return flag != 0;  
}

bool is_even_parity(int n) {
    int flag = 0;
    while (n) {
        flag = flag ^ (n & 1);  // Toggle flag based on the least significant bit
        n >>= 1;
    }
    return flag == 0;
}

// 00. Big Endian and little Endian
bool is_little_endian(void) {
    unsigned int n = 0x12345; 
    unsigned char *ptr = (unsigned char*)&n;

    if (*ptr == 0x45) {
        return true; // If the first byte is 45, it's little-endian
    } else {
        return false; // If the first byte is 0 or something else, it's big-endian
    }
}

// 00 . Swap ith and jth bits
int swapBits(int n, int i, int j) {
    int bit_i = (n >> i) & 1;      // Extract the ith and jth bits
    int bit_j = (n >> j) & 1;
    
    if (bit_i != bit_j) {                  // Check if the ith and jth bits are different
        n = n ^ ((1 << i) | (1 << j));     // Then toggle it
    }
    return n;
}

// 00 . Reverse all the bit 
int rev_all_bit(int num) {
	int num2 = 0;
	while(num) {
		int temp = num & 1;
		num2 = (num2 << 1) | temp;
		num = num>>1;
	}
	return num2;
}

// 00. Bitwise opration: Implement bitwise AND, OR, XOR, and left/right shift operations.
int set_bit(int num, int k){
    return (num | (1 << k));
}
int reset_bit(int num, int k){
    return (num & (~(1 << k)));
}
int toggle_bit(int num, int k, int j){
    return (num ^ ((1 << k) | (1 << j)));   //xor
}

int set_bit_from_MSB(int num, int k){
    int num_bits = sizeof(num) * 8;     
    return (num | (1 << (num_bits - k))); 
}

int reset_bit_from_MSB(int num, int k){
    int num_bits = sizeof(num) * 8;        
    return (num & (~(1 << (num_bits - k)))); 
}

int toggle_bit_from_MSB(int num, int k){
    int num_bits = sizeof(num) * 8;       // Determine the number of bits in 'num'
    return (num ^ (1 << (num_bits - k)));
}

// 00. Reverse a String: Write a program to reverse a given string
void reverse_string(char *ptr){
    int length = strlen(ptr);
	
    for(int i = 0; i < length/2; i++){
        char temp = ptr[i];
        ptr[i] = ptr[length - i - 1];
        ptr[length - i - 1]= temp;

	}
 
}

// 00. Factorial: Write a function to compute the factorial of a given number.
unsigned long long factorial1(int num){
    if (num == 0)
        return 1;
    else  // else is not mendatory because there is return in if.
    {
        unsigned long long result = 1;
        for (int i = 2; i <= num; i++)
        {
            result = result * i;
        }
        return result;
    }
}

 //using--recursion
unsigned long long factorial(int n) {
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}

// 00. Fibonacci Series: Generate the Fibonacci series up to a given number of terms.
void fib(int n){
    int first = 0, second = 1, next;
    for(int i = 0; i < n; i++){
       if (i <= 1){
        next = i;
        }
        else{
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d", next);
    }
}

// 00. Reverse digit: Write a program to rev digit.
int reverseDecDigits(int n) {
    int rev = 0;
    while (n) {
        int last_d = n % 10;   
        rev = rev * 10 + last_d; 
        n = n / 10;
    }
    return rev;
}

int reverseHexaDigits(int n) {
    int rev = 0;
    while (n) {
        int last_d = n & 0xF;
        rev = (rev << 4) | last_d;
        n = n >> 4;
    }
    return rev;
}

int reverseOCTDigits(int n) {
    int rev = 0;
    while (n) {
        int last_d = n & 7;
        rev = (rev << 3) | last_d;
        n = n >> 3;
    }
    return rev;
}

// 00. Sum of Digits: Write a function to find the sum of digits of a number.
int sum_of_digit(int num){
    long long int result =0;
    while(num>0){
        int rem = num%10;
        result = result + rem;
        num =num/10;
    }
    return result;
}


// 00. Prime Number Check: Write a function to check if a given number is prime or not.
bool isPrime(int num) {
    if (num < 2) {
        return false;  // 0 and 1 are not prime numbers
    }
    
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false; 
        }
    }
    
    return true;  
}

// 00. Anagram Check: Write a program to check if two strings are anagrams of each other.
int check_angrm(char *str1, char *str2){
    int freq[256] = {0};

    for(int i = 0; str1[i] != '\0'; i++){
        freq[str1[i]]++;
    }

    for(int i = 0; str2[i] != '\0'; i++){
        freq[str2[i]]--;
    }

    for(int i = 0; i < 256; i++){
        if (freq[i] != 0){
            return 0;
        }
    }
    return 1;
}

// 00. Swap Two Numbers: Write a function to swap two numbers without using a temporary variable.
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void swap1(int *a, int *b){
    *a = *a + *b; // Add the values of a and b and store the result in a
    *b = *a - *b; // Subtract the original value of b (stored in *b) from the updated value of a (stored in *a) and store the result in b
    *a = *a - *b; // Subtract the original value of b (stored in *b) from the updated value of a (stored in *a) and store the result in a
}

void swap2(int *a, int *b){
    *a = *a ^ *b;  // if we do tow time xor in a num with a number num will not be change.
    *b = *a ^ *b; 
    *a = *a ^ *b; 
}


// 00. Decimal to binary/octal Conversion: Write a function to convert the same.
long long int dec_to_bin(int n)
{
    long long int result = 0;
    int place = 1;

    while (n > 0)
    {
        int reminder = n % 2;
        result = result + reminder * place;
        n = n / 2;
        place = place * 10;
    }
    return result;
}
int dec_to_oct(int n){
    int result = 0;
    int place = 1;

    while(n>0){
        int rem = n%8;
        result = result + rem* place;
        n = n/8;
        place = place*10;
    }
    return result;
}

// 00. Bianary/ octal to Decimal Conversion: Write a function to convert the same.
int bin_to_dec(int n)
{
    int dec = 0;
    int exp = 0;
    while (n > 0)
    {
        int rem = n % 10;
        dec = dec + rem * pow(2, exp);
        n = n / 10;
        exp++;
    }
    return dec;
}

int oct_to_dec(int n)
{
    int dec = 0;
    int exp = 0;
    while (n > 0)
    {
        int rem = n % 10;
        dec = dec + rem * pow(8, exp);
        n = n / 10;
        exp++;
    }
    return dec;
}

// 00. LCM (Least Common Multiple) GCD (Greatest Common Divisor): Write a function to find the same.
int hcf(int a, int b)
{
    while (a % b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return b;
}

int lcm(int n, int m){ 
	for(int i = m>n? m:n; i <= n*m; i++){
		if(i%n == 0 && i/m == 0)
			return i;
	}
}

int lcm1(int a, int b)
{
    return a * b / hcf(a, b);
}


// 00. Armstrong Number Check: Write a function to check if a number is an Armstrong number.
int digit_count(int n){
    int count = 0;
    while(n > 0){
        n= n/10;
        count++;
    }
    return count;
}

bool isArmstrong(int n){
    int originalNum = n;
    int result = 0;
    int wc = digit_count(originalNum); 

    while( n > 0){
        int digit = n%10;
        result = result + pow(digit , wc);
        n = n/10;
    }
	return result;
}


// 00. Perfect Number Check: Write a function to check if a number is a perfect number.
bool isPerfect(int num)  //sum of factors is equal to numbers
{

    int sum = 0;
    for (int i = 1; i < num; i++){
        if (num % i == 0){
            sum = sum + i;
        }
    }
    if (num == sum){
        return true;
    } else {
        return false;
    }
}

// 00. Power Function: Write a function to calculate the power of a number (x^y).

int power(int a, int b) {
    int result = 1;
    if (b == 0) {
        return 1;
    }
    if (b < 0) {
        return 1 / power(a, -b);
    }
    for (int i = 0; i < b; i++) {  // Increment i, not b
        result = result * a;       // Multiply result by a
    }
    return result;
}

// 00. Find ASCII Value: Write a program to find the ASCII value of a character.
void ascii(char c){
	int ascii_value = c;
	printf("ASCII value of %c is %d\n", c, ascii_value);
}

// 00. Check Leap Year: Write a function to check if a given year is a leap year.
bool is_leap_year(int n) {
    if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0))
        return true;
    else
        return false;
}
/*
The year 2000 was a leap year because it is divisible by 400.
The year 1900 was not a leap year because although it is divisible by 4, it is also divisible by 100 but not by 400.
The year 2004 was a leap year because it is divisible by 4, but not by 100, so the exception doesn't apply.
*/

/*
===========================================
Matrix
===========================================
*/

// 00. Matrix Operations: Implement addition, subtraction of matrices.
void addMat(int mat1[][4], int mat2[][4], int mat3[][4], int row, int col){

    for(int i = 0; i < row; i++){
        for(int k = 0; k < col; k++){
            mat3[i][k]=mat1[i][k]+mat2[i][k];
        }
    }
}
void display(int mat[][3], int row, int col){
    printf("printing mat \n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

// 00. Matrix Multiplication: Write a function to multiply two matrices.
void multiply(int mat1[][3], int mat2[][3], int mat3[][3], int row, int col){
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            mat3[i][j] = 0; // Initialize mat3[i][j] to 0 before summing up products
            for(int x = 0; x < col; x++) {
                mat3[i][j] += mat1[i][x] * mat2[x][j];
            }
        }
    }
}

// 00. Transpose of a Matrix: Write a program to find the transpose of a matrix. (3X4)
void transpose(int mat[][4], int matt[][3], int row, int col){
    for(int i = 0; i < col; i++){
        for (int j = 0; j < row; j++){
            matt[i][j]= mat[j][i];
        }
    }
}

void log_message(const char* format, ...) {
    va_list args;               // Declare a variable to hold the variable arguments
    va_start(args, format);     // Initialize the variable arguments list

    printf("[INFO] ");          // Print the log prefix
    vprintf(format, args);      // Print the formatted message using the variable arguments
    printf("\n");               // Print a newline character

    va_end(args);               // Clean up the variable arguments list
}

int main() {
    char str[50];
    char str1[20] = "Hello";
    char str2[10] = "world";

    // Correct usage of snprintf to append to str1
    int combined_len = snprintf(str1 + strlen(str1), sizeof(str1) - strlen(str1), " %s %d", str2, 5);
    if (combined_len >= sizeof(str1) - strlen(str1)) {
        printf("Error: snprintf truncated the string.\n");
    }

    // Properly formatting a string using sprintf
    int len = sprintf(str, "This is a long message! %s %d", str2, 5);
    if (len < 0) {
        printf("Error: sprintf failed.\n");
    }

    // Corrected usage of memcpy
    char source[] = "Hello, world!";
    char destination[20]; // Ensure enough space for the entire string, including the null terminator
    memcpy(destination, source, strlen(source) + 1); // Use +1 to include the null terminator

    // Print the results
    printf("Combined string: %s\n", str1);
    printf("Formatted string: %s\n", str);
    printf("Copied string: %s\n", destination);

    return 0;
}














