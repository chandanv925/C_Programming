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
    int len1 = strlen(str1);  // Get the length of str1
    int len2 = strlen(str2);  // Get the length of str2

    for (int i = 0; i < len2; i++) {
        str1[len1 + i] = str2[i];
    }

    // Add null terminator at the end of the combined string
    str1[len1 + len2] = '\0';
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
int countWords1(char *s) {
    int count = 0;
    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] == ' ' && s[i-1] != ' ') {
            count++;
        }
    }
    return count;
}

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
    char *start = str;
    char *end = str + strlen(str) - 1;

    // Skip leading spaces
    while (isspace(*start)) {
        start++;
    }
    // Skip trailing spaces
    while (isspace(*end) && start <= end) {
        end--;
    }
    // Adjust the string length and null-terminate
    *(end + 1) = '\0';
}

// 00. Substring Search: Write a function to find a substring within a string.
    /*Naive" approach or implement more efficient algorithms like KMP (Knuth-Morris-Pratt) or Boyer-Moore. 
    Use strstr to find the substring char *pos = strstr(str, substr);*/
char* findSubstring(const char* str, const char* substr) {
    int len_str = strlen(str);
    int len_substr = strlen(substr);

    if (len_substr == 0) {
        return (char*)str;
    }

    for (int i = 0; i <= len_str - len_substr; i++) {
        // Check if the substring matches at this position
        int j;
        for (j = 0; j < len_substr; j++) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        // If the whole substring was found, return the pointer to its start
        if (j == len_substr) {
            return (char*)(str + i);
        }
    }
    return NULL;
}

// 00. Substring Delete: Write a function to delete a substring within a string.
void deleteSubstring(char str[], const char substr[]) {
    char *pos = strstr(str, substr); // Find the position of the substring

    if (pos != NULL) { // If the substring is found
        int len = strlen(substr); // Length of the substring

        // Shift the characters after the substring to the left
        while (*(pos + len) != '\0') {
            *pos = *(pos + len);
            pos++;
        }
        *pos = '\0';
    }
}

int main() {
    char str[] = "   Hello   world  this   is a   test  ";
    int wordCount = countWords1(str);
    printf("The number of words is: %d\n", wordCount);
    return 0;
}