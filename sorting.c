#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int numArr[], int size);
void quickSort(int numArr[], int low, int high);
void quickSortRecur(int numArr[], int low, int high);
int partition(int numArr[], int low, int high);
void selectionSort(int numArr[], int size);
void heapSort(int numArr[], int size);
void heapify(int numArr[], int size, int root);
void insertionSort(int numArr[], int size);
void shellSort(int numArr[], int size);
void swap(int *first, int *second);

int main(){

    int numArr[] = {5, 4, 2, 1, 10, 30, 20};
    int size = sizeof(numArr)/sizeof(numArr[0]);
    bubbleSort(numArr, size);
    int numArr2[] = {5, 4, 2, 1, 10, 30, 20};
    quickSort(numArr2, 0, size-1);
    int numArr3[] = {5, 4, 2, 1, 10, 30, 20};
    selectionSort(numArr3, size);
    int numArr4[] = {5, 4, 2, 1, 10, 30, 20};
    heapSort(numArr4, size);
    int numArr5[] = {5, 4, 2, 1, 10, 30, 20};
    // insertionSort(numArr5, size);
    int numArr6[] = {5, 4, 2, 1, 10, 30, 20};
    // shellSort(numArr6, size);
}

void swap(int *first, int *second){

    int temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

void bubbleSort(int numArr[], int size){

    int i, j, k, swapped, passNum = 0;
    printf("Before bubble sort: ");
    for(i = 0; i < size; i++)
        printf("%d ", numArr[i]);
    printf("\n");
    for(i = 0; i < size-1; i++)
    {
        swapped = 0;
        for(j = 0; j < size-i-1; j++) // Limit is up to size-i-1 since there is already a guaranteed i amount of elements that are sorted every iteration.
        {
            if(numArr[j] > numArr[j+1])
            {
                swap(&numArr[j], &numArr[j+1]); // Swap if prev element is greater than next element.
                swapped = 1;
            }
        }
        if(swapped == 0) // If no swaps occur in the previous loop, break the entire loop since it means it is sorted.
            break;
    }
    printf("After bubble sort: ");
    for(i = 0; i < size; i++)
        printf("%d ", numArr[i]);
    printf("\n");
}

void quickSort(int numArr[], int low, int high){

    int i;
    printf("Before quick sort: ");
    for(i = 0; i < high+1; i++)
        printf("%d ", numArr[i]);
    printf("\n");
    quickSortRecur(numArr, low, high); // Calls the recursive quick sort function.
    printf("After quick sort: ");
    for(i = 0; i < high+1; i++)
        printf("%d ", numArr[i]);
    printf("\n");
}

void quickSortRecur(int numArr[], int low, int high){

    if(low < high) // If low < high, that means low and high aren't equal which indicates that the array hasn't been sorted.
    {
        int pi = partition(numArr, low, high); // Creates a partition
        quickSortRecur(numArr, low, pi-1); // Recursively calls the function to sort values before the partition.
        quickSortRecur(numArr, pi+1, high); // Recursively calls the functon to sort values after the partition.
    } 
}

int partition(int numArr[], int low, int high){
                                                       
    int pivot = numArr[high], i = low, j; // Sets the pivot to the last element of the array.
    for(j = low; j < high; j++)
    {
        if(numArr[j] <= pivot) // If current element is less than or equal to pivot, swap the current element and the element with the low's index.
        {
            swap(&numArr[i], &numArr[j]);
            i++;
        }
    }
    swap(&numArr[i], &numArr[high]); // Swap the pivot with the element with the low's index. This is done since it is guaranteed that the value with i's index is greater than the pivot.
    return i;    
}

void selectionSort(int numArr[], int size){

    int i, j, minIdx;
    printf("Before selection sort: ");
    for(i = 0; i < size; i++)
        printf("%d ", numArr[i]);
    printf("\n");
    for(i = 0; i < size; i++)
    {
        minIdx = i; // Set minimum index to the current i iteration which sets a boundary. This boundary signifies the elements before it are already sorted.
        for(j = i+1; j < size; j++)
        {
            if(numArr[j] < numArr[minIdx]) // If current element is lesser than the element with the minimum index, switch the minimum index to the current element's index.
                minIdx = j;
        }
        swap(&numArr[minIdx], &numArr[i]); // Once element with the lowest value is found in the current unsorted portion, swap element with minimum index with the boundary element.
    }
    printf("After selection sort: ");
    for(i = 0; i < size; i++)
        printf("%d ", numArr[i]);
    printf("\n");
}

void heapSort(int numArr[], int size){

    int i;
    printf("Before heap sort: ");
    for(i = 0; i < size; i++)
        printf("%d ", numArr[i]);
    printf("\n");
    for(i = size/2 - 1; i >= 0; i--) // Creates the max heap
        heapify(numArr, size, i);
    for(i = size - 1; i > 0; i--) // Extracts root 1 by 1 
    {
        swap(&numArr[0], &numArr[i]); // Moves root to end
        heapify(numArr, i, 0); // Creates a max heap without the new end
    }
    printf("After heap sort: ");
    for(i = 0; i < size; i++)
        printf("%d ", numArr[i]);
    printf("\n");
}

void heapify(int numArr[], int size, int root){

    int largest = root, left = 2*root+1, right = 2*root+2;
    if(left < size && numArr[left] > numArr[largest]) // Checks if left child is greater than current largest.
        largest = left;
    if(right < size && numArr[right] > numArr[largest]) // Checks if right child is greater than current largest.
        largest = right;
    if(largest != root) // If largest index is not equal to root, swap root index and largest.
    {
        swap(&numArr[root], &numArr[largest]);
        heapify(numArr, size, largest);
    }
}