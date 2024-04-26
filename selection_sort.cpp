#include<iostream>
using namespace std;
void selectionSort(int arr[], int n) {
 for (int i = 0; i < n - 1; i++) {
 int minIndex = i;
 for (int j = i + 1; j < n; j++) {
 if (arr[j] < arr[minIndex]) {
 minIndex = j;
 }
 }
 // Swap the found minimum element with the element at index i
 int temp = arr[i];
 arr[i] = arr[minIndex];
 arr[minIndex] = temp;
 }
}
void printArray(int arr[], int size) {
 for (int i = 0; i < size; i++) {
 cout << arr[i] << " ";
 }
 cout << endl;
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
 cout << "Original array: ";
 printArray(arr, size);
 selectionSort(arr, size);
 cout << "Sorted array: ";
 printArray(arr, size);
 return 0;
}
