00. concatenating one string to the end of the other

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
--
void addStrings(char str1[], char str2[]){
    int i = 0, j = 0;

    while(str1[i] != '\0'){
        i++;
    }
    while(str2[j] != '\0'){
        str1[i++] = str2[j++];
    }
    str1[i]='\0';

}

========================================================
00. String Length: Write a function to find the length of a string. for loop and while loop
int legth_of_string(char *str){
    int i=0;
    for(i = 0; str[i] != '\0'; i++){
    }
    return i;
}

int legth_of_string(char *str){
    int i=0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

========================================================
00. String Concatenation: Write a function to concatenate two strings.

char *concatstr(char *str1, char* str2){
    int len1 =legth_of_string(str1);
    int len2 =legth_of_string(str2);
    printf("%d,%d\n", len1, len2);

    char *str3 = (char*)malloc((len1+len2)+1);
    int j = 0;

    for(int i = 0; i < len1; i++){
        str3[j++] = str1[i];
    }
    for(int k = 0 ; k < len2; k++){
        str3[j++] = str2[k];
    }
    str3[j]='\0';
    return str3;
}

========================================================
00. String Copy: Write a function to copy one string to another. add/append

void addStrings(char str1[], char str2[]) {
    int i = 0;
    int j = 0;
    int k = 0;


    // Move i to the end of str1
    while (str1[i] != '\0') {
        i++;
    }

    // Append characters of str2 to str1
    while (str2[j] != '\0') {
        str1[i++] = str2[j++];
    }

    // Null-terminate str1
    str1[i] = '\0';
}

========================================================
00. String Compare: Write a function to compare two strings.

void strcmp2(char *str1, char *str2){
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

========================================================
00. Remove Duplicate Characters: Write a function to remove duplicate characters from a string

void del_idx(char *str, int index, int len){

    for(int j = index; j < len-1; j++){
        str[j]= str[j+1];
    }
    str[len-1] = '\0';
}

void del_dup_char(char *str1){
    int len1 = legth_of_string(str1);

    for(int i = 0; i < len1-1; i++){
        char temp = str1[i];

        for(int j = i+1; j < len1; j++){
            if(str1[j] == temp){
                del_idx( str1, j, len1);
                len1--;
            }
        }
    }    
}

int main()
{
    char str1[] = "good morning ";
    char str2[] = "go0od";
    del_dup_char(str1);
    printf("%s",str1);
}

========================================================
00. Count Words in a String: Write a function to count the number of words in a string.

int countWords(char *s) {
    int count = 1; // Initialize count to 1 to account for the first word
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ' && s[i + 1] != ' ') {
            count++;
        }
    }
    
    return count;
}

========================================================
00. Remove Whitespace from String: Write a function to remove whitespace characters from a string.

void del_idx(char *str, int index, int len){

    for(int j = index; j < len-1; j++){
        str[j]= str[j+1];
    }
    str[len-1] = '\0';
}

int word_count(char *str){
    int len = strlen(str);
    int count = 0, i = 0;

    for (i = 0; str[i] != '\0'; i++){
        if(str[i] == ' '){
        count++;
        del_idx( str, i, len);  
        }
    }
    return count;
}
int main(){

    char str[] = "as df gh jk jk";
    printf("space count = %d\n", word_count(str));
    printf("%s",str);


}
========================================================
00. String Palindrome with Pointers: Write a program to check if a string is a palindrome using pointers.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

========================================================
00. Convert the string "12345" to an integer in C,

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

========================================================
00. Function to strip leading and trailing whitespace from a string

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

========================================================

Substring Search: Write a function to find a substring within a string.
