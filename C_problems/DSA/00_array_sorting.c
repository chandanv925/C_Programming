#include <stdio.h>
#include <stdlib.h>

/*
Sorting Algorithm    Best Case        Average Case	  Worst Case	 Space Complexity
Selection Sort        O(n²)            O(n²)	        O(n²)	        O(1)
Insertion Sort        O(n)             O(n²)	        O(n²)	        O(1)
Quick Sort            O(n log n)	   O(n log n)	    O(n²)	        O(log n)
Merge Sort            O(n log n)	   O(n log n)	    O(n log n)	    O(n)
Heap Sort             O(n log n)	   O(n log n)	    O(n log n)	    O(1)
*/

// Create a structure of an array
struct Array
{
    int A[10];
    int size;
    int length;
};

// Display the array
void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

// Check if array is sorted
int isSorted(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}

// Swap
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;   
}

// Bubble sort
void Bubble_sort(struct Array *arr){
    int i = 0, j = 0;
    for(i = 0; i < arr->length; i++){
        for(int j = 0; j < (arr->length - i - 1); j++){
            if(arr->A[j] > arr->A[j+1]){
                swap(&arr->A[j], &arr->A[j+1]);
            }
        }
    }
}

// Selection sort
void Selection_Sort(struct Array *arr) {
    int i, j, minIdx, temp;

    for (i = 0; i < arr->length-1; i++) {
        minIdx = i;
        for (j = i+1; j < arr->length; j++) {
            if (arr->A[j] < arr->A[minIdx]) {
                minIdx = j;   //find min element and update inedx
            }
        }
        if(minIdx != i) {
            swap(&arr->A[minIdx], &arr->A[i]);
        }
    }
}

// Merge two sorted array
void two_way_merge(int *arr1, int *arr2, int *arr3, int len1, int len2, int low){
    int i = 0, j = 0, k = low;
    while (i < len1 && j < len2) {
        if (arr1[i] <= arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }

    while (i < len1) {
        arr3[k++] = arr1[i++];
    }
    while (j < len2) {
        arr3[k++] = arr2[j++];
    }
}

// Merge sort helper function
void merge(int *arr, int low, int mid, int high) {
    int i, j, k;
    int n1 = (mid - low) + 1;
    int n2 = high - mid;

    int Left[n1];
    int Right[n2];

    for (i = 0; i < n1; i++)
        Left[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 + j];

    two_way_merge(Left, Right, arr, n1, n2, low);    
}

// Merge sort
void mergeSort(int *arr, int low, int high) {
    if (low < high) {
        int mid = (low + high)/ 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Driver code
int main()
{
    struct Array arr1 = {{21, 28, 32, 35, 2, 3, 9, 16, 18}, 20, 9};
    printf("%d", isSorted(arr1));
    Display(arr1);
    //Bubble_sort(&arr1);
    //Selection_Sort(&arr1);
    mergeSort(arr1.A, 0, arr1.length-1);
    Display(arr1);

    return 0;
}
