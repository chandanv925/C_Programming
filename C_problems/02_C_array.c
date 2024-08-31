#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>

// 00. Reverse the array
void reverse(int* nums, int len) {
    int low = 0, high = len - 1;
    while (low < high) {
        // swap (&nums[low], &nums[high])
        int temp = nums[low];
        nums[low] = nums[high];
        nums[high] = temp;

        low++;
        high--;
    }
}

// 00. Remove Duplicates from Sorted Array
int removeDuplicates(int* nums, int numsSize) {
    int i, count = 0;
    nums[count++] = nums[0];
    for(i = 1; i < numsSize; i++){
        if(nums[i] != nums[count-1]){
            nums[count++] = nums[i];
        }
    }
    return count;
}

// 00. Delete Duplicate from unsorted array
int remove_duplicates(int arr[], int n) {
    int i, j, count = 0;

    for (i = 0; i < n; i++) {
        int is_duplicate = 0;
        for (j = 0; j < i; j++) {
            if (arr[j] == arr[i]) {
                is_duplicate = 1;
                break;
            }
        }
        // If the element is not a duplicate, keep it in the array
        if (!is_duplicate) {
            arr[count++] = arr[i];
        }
    }
    return count;
}
// 00. Find Second Max in a arrays 
int findSecondMax(int arr[], int len) {

    int max = arr[0] > arr[1] ? arr[0] : arr[1];
    int second_max = arr[0] > arr[1] ? arr[1] : arr[0];

    for (int i = 2; i < len; i++) {
        if (arr[i] > max) {
            second_max = max;
            max = arr[i];
        } else if (arr[i] > second_max && arr[i] < max) {
            second_max = arr[i];
        }
    }

    return second_max;
}

// 00. Concatenating two integer arrays in 
int *conct_array(int *array1, int *array2, int l1, int l2){
    int *newarray = (int *)malloc((l1 + l2) * sizeof(int));
    int index = 0;
    for(int i = 0; i < l1; i++){
        newarray[index++] = array1[i];
    }
    for(int j = 0; j < l2; j++ ){
        newarray[index++] = array2[j];
    }
    return newarray;
}

// 00. Delete val from an array
int removeElement(int* arry, int len, int val, int val2) {
    int newlen = 0; 
    for (int i = 0; i < len; i++) {
        if ((arry[i] != val) && (arry[i] != val2) ) {
            arry[newlen++] = arry[i];  // Only copy elements that are not equal to val
        }
    }
	return newlen;
}

// 00. Array Rotation: Rotate elements of an array to the left or right by a given number of positions.
void rotate_arrayL(int array[], int length, int rotateby) {
    rotateby %= length;
    for (int i = 0; i < rotateby; i++) {
        int temp = array[0];
        for (int j = 0; j < length - 1; j++) { 
            array[j] = array[j + 1];
        }
        array[length - 1] = temp;
    }
}

void rotate_arrayR(int array[], int length, int rotateby) {
    rotateby %= length;
    for (int i = 0; i < rotateby; i++) {
        int temp = array[length-1];
        for (int j = length; j > 0 ; j--) {
            array[j] = array[j - 1];
			
        }
        array[0] = temp;
    }
}

// 00. Binary Search: Implement the binary search algorithm to search for an element in a sorted array.
bool BinSearch(int *arr, int len, int target) {
    int low = 0, high = len - 1;

    while(low <= high) {
        int mid = (high + low) / 2;

        if(arr[mid] == target)
            return mid;
        if(arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// 00. Function to search in a nearly sorted array
int searchNearlySorted(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = (high + low) / 2;
        
        if (arr[mid] == target)
            return mid;
        
        if (mid > low && arr[mid - 1] == target)
            return mid - 1;
            
        if (mid < high && arr[mid + 1] == target)
            return mid + 1;
        
        if (arr[mid] > target)
            high = mid - 2;
        else
            low = mid + 2;
    }
    
    return -1;
}

// 00. Function to search in a rotated sorted array
int searchRotatedSorted(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target)
            return mid;

        if (arr[low] <= arr[mid]) { // Left part is sorted
            if (target >= arr[low] && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } else { // Right part is sorted
            if (target > arr[mid] && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    
    return -1;
}

// 00. Function to find the element in an sorted array with unknown length
int searchUnknownLength(int arr[], int target) {
    int low = 0, high = 1;
    
    while (arr[high] < target) {
        low = high;
        high = 2 * high;
    }
    
    // Perform binary search within the range
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return -1; // Target not found
}

// 00. Merge two sorted array
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
	int i = 0, j = 0, k = 0;
	while (i < n1 && j < n2){
		if (arr1[i] < arr2[j])
			arr3[k++] = arr1[i++];
		else
			arr3[k++] = arr2[j++];
	}
	while (i < n1)
		arr3[k++] = arr1[i++];

	while (j < n2)
		arr3[k++] = arr2[j++];
}

  // When we have to accomodate value in given array 
void mergeArrays2(int arr1[], int arr2[], int n1, int n2){
	int i = n1-1;
	int j = n2-1;
	int k = n1+n2-1;
	
	while(i >= 0 && j >= 0){
		if(arr1[i] > arr2[j])
			arr1[k--] = arr1[i--];
		else 
			arr1[k--] = arr1[j--];
	}
	while(i >= 0){
		arr1[k--] = arr1[i--];
	}
}

// 00. Function to find the majority element in an array must have occurance numsSize/2
   //code implementing the Boyer-Moore Voting Algorithm:
int majorityElement(int* nums, int numsSize) {
    int candidate = nums[0];
    int count = 1;
 
    // Step 1: Find the candidate
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }
    }
    return candidate;
}

//00. find the mode (or "bahulak") of a set of numbers
int findMode(int arr[], int size) {
    int maxCount = 0;
    int mode = arr[0];

    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }
    return mode;
}

int main() {
    int nums[] = {1, 1, 2, 2,2,2,2,2, 3, 4,4,4,4,4,4, 4, 5, 5,4,5,5,5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("%d\n",findSecondMax(nums, numsSize));

    return 0;
}