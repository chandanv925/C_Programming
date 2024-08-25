#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <ctype.h>

// 00. String Length: Write a function to find the length of a string. for loop and while loop
int strlen2(char *str){
    int i=0;
    for(i = 0; str[i] != '\0'; i++){
    }
    return i;
}

int strlen3(char *str){
    int i=0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

// 00. concatenating one string to the end of the other
void addStrings(char str1[], char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Resize str1 to accommodate str2
    str1[len1 + len2] = '\0';

    // Append characters of str2 to str1
    for (int i = 0; i < len2; i++) {
        str1[len1 + i] = str2[i];
    }
}

void addStrings2(char str1[], char str2[]){
    int i = 0, j = 0;

    while(str1[i] != '\0'){
        i++;
    }
    while(str2[j] != '\0'){
        str1[i++] = str2[j++];
    }
    str1[i]='\0';

}

// 00. String Compare: Write a function to compare two strings.
bool strcmp2(char *str1, char *str2){
	int len1 = strlen2(str1);
	int len2 = strlen2(str2);
	
	if (len1 != len2) 
		return false;
	
	for (int i = 0; i < len1; i++){
		if( str1[i] != str2[i])
			return false;	
	}
	return true;
}

// 00. Remove Duplicate Characters: Write a function to remove duplicate characters from a string
void del_dup_char(char *str) {
    int len = 0;
    bool seen[256] = {0}; // Assuming ASCII characters, we use a boolean array to track seen characters

    for (int i = 0; str[i] != '\0'; i++) {
        if (!seen[(unsigned char)str[i]]) {
            seen[(unsigned char)str[i]] = 1;
            str[len++] = str[i]; // Place the character in the current "clean" position
        }
    }

    str[len] = '\0'; 
}

// 00. Count Words in a String: Write a function to count the number of words in a string.
int countWords(char *s) {
    int count = 0;
    bool inWord = false;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' && !inWord) {
            // Starting a new word
            inWord = true;
            count++;
        } else if (s[i] == ' ') {
            // End of a word
            inWord = false;
        }
    }
    return count;
}

// 00. String Palindrome with Pointers: Write a program to check if a string is a palindrome using pointers.
int isPalindrome(char *str) {
    int len = strlen(str);
    int i = 0, j = len - 1;
    
    while (i < j) {
        char left = tolower(str[i]);
        char right = tolower(str[j]);
        
        if (!isalpha(left)) {
            i++;
            continue;
        }
        if (!isalpha(right)) {
            j--;
            continue;
        }
        if (left != right) {
            return 0; // Not a palindrome
        }   
        i++;
        j--;
    }   
    return 1; // Palindrome
}

bool is_palindrome(const char *str) {
    int len = strlen(str);
    int i, j;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (tolower(str[i]) != tolower(str[j])) {
            return false;
        }
    }
    return true;
}


// 00. Convert the string "12345" to an integer in C,
int string_to_int(const char *str) {
    int result = 0;
    int i = 0;
    int sign = 1;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] != '\0') {
        // ASCII value of '0' is 48, so subtracting '0' from the character converts it to the corresponding integer
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return sign * result;
}


// 00. Function to strip leading and trailing whitespace from a string

void strip(char *str) {
    char *end;
    char *start = str;  // Keep track of the original start of the string

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    if (*str == 0) { // All spaces
        *start = 0; // Set the original start to null terminator
        return;
    }

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Write new null terminator
    *(end + 1) = '\0';

    // Shift the trimmed string to the start of the original buffer
    memmove(start, str, strlen(str)+1); // +2 
	
}


// 00. Remove Whitespace from String: Write a function to remove whitespace characters from a string.


// 00. Substring Search: Write a function to find a substring within a string.

int main() {
    char str[] = "   Hello   world  this   is a   test  ";
    int wordCount = countWords(str);
    printf("The number of words is: %d\n", wordCount);
    return 0;
}