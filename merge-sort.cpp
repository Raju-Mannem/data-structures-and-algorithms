#include <iostream>
using namespace std;
// Merge two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
 int n1 = m - l + 1;
 int n2 = r - m;
 // Create temporary arrays
 int L[n1], R[n2];
 // Copy data to temporary arrays L[] and R[]
 for (int i = 0; i < n1; i++)
 L[i] = arr[l + i];
 for (int j = 0; j < n2; j++)
 R[j] = arr[m + 1 + j];
 // Merge the temporary arrays back into arr[l..r]
 int i = 0; // Initial index of first subarray
 int j = 0; // Initial index of second subarray
 int k = l; // Initial index of merged subarray
 while (i < n1 && j < n2) {
 if (L[i] <= R[j]) {
 arr[k] = L[i];
 i++;
 } else {
 arr[k] = R[j];
 j++;
 }
 k++;
 }
 // Copy the remaining elements of L[], if there are any
 while (i < n1) {
 arr[k] = L[i];
 i++;
 k++;
 }
 // Copy the remaining elements of R[], if there are any
 while (j < n2) {
 arr[k] = R[j];
 j++;
 k++;
 }
}
// l is for left index and r is the right index of the sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
 if (l < r) {
 // Same as (l+r)/2, but avoids overflow for large l and r
 int m = l + (r - l) / 2;
 // Sort first and second halves
 mergeSort(arr, l, m);
 mergeSort(arr, m + 1, r);
 // Merge the sorted halves
 merge(arr, l, m, r);
 }
}
// Utility function to print an array
void printArray(int A[], int size) {
 for (int i = 0; i < size; i++)
 cout << A[i] << " ";
 cout << endl;
}
// Driver code
int main() {
 int size;
    cout<<"enter no of elements for an array:- \t";
    cin>>size;
    int arr[size],value;
    cout<<"\n enter those elements:- \t \n";
    cout<<"\n ---------------------------------\n \n";
    for(int i=0;i<size;i++){
        cout<<"\t enter the element "<<i+1<<"\t";
        cin>>value;
        arr[i]=value;
    }
 cout << "Given array is \n";
 printArray(arr, size);
 mergeSort(arr, 0, size - 1);
 cout << "Sorted array is \n";
 printArray(arr, size);
 return 0;
}
