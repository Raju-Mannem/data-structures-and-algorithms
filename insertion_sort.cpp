#include <iostream>
using namespace std;
void insertionSort(int arr[], int n) {
 for (int i = 1; i < n; ++i) {
 int key = arr[i];
 int j = i - 1;
 while (j >= 0 && arr[j] > key) {
 arr[j + 1] = arr[j];
 j = j - 1;
 }
 arr[j + 1] = key;
 }
}
void printArray(int arr[], int size) {
 for (int i = 0; i < size; i++)
 std::cout << arr[i] << " ";
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
 insertionSort(arr, size);
 std::cout << "Sorted array: ";
 printArray(arr, size);
 return 0;
}
