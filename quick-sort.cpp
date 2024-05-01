#include <iostream>
using namespace std;
// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
 int pivot = arr[high];
 int i = low - 1;
 for (int j = low; j < high; j++) {
 if (arr[j] <= pivot) {
 i++;
 std::swap(arr[i], arr[j]);
 }
 }
 std::swap(arr[i + 1], arr[high]);
 return i + 1;
}
// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
 if (low < high) {
 int pivotIndex = partition(arr, low, high);
 // Recursively sort the elements before and after the pivot
 quickSort(arr, low, pivotIndex - 1);
 quickSort(arr, pivotIndex + 1, high);
 }
}
// Function to print the array
void printArray(int arr[], int size) {
 for (int i = 0; i < size; i++) {
 std::cout << arr[i] << " ";
 }
 std::cout << std::endl;
}
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
 std::cout << "Original array: ";
 printArray(arr, size);
 quickSort(arr, 0, size - 1);
 std::cout << "Sorted array: ";
 printArray(arr, size);
 return 0;
}
