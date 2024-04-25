#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
 for (int i = 0; i < n - 1; ++i) {
 for (int j = 0; j < n - i - 1; ++j) {
 if (arr[j] > arr[j + 1]) {
 // Swap arr[j] and arr[j+1]
 int temp = arr[j];
 arr[j] = arr[j + 1];
 arr[j + 1] = temp;
 }
 }
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
 bubbleSort(arr, size);
 std::cout << "Sorted array: ";
 printArray(arr, size);
 return 0;
}
