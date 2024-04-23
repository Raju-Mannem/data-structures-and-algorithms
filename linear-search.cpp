#include <iostream>
using namespace std;
// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
 for (int i = 0; i < size; ++i) {
 if (arr[i] == key) {
 return i; // Key found, return the index
 }
 }
 return -1; // Key not found
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
 int key;
 std::cout << "Enter the element to search: \t";
 std::cin >> key;
 int result = linearSearch(arr, size, key);
 if (result != -1) {
 std::cout << "Element found at index " << result << std::endl;
 } else {
 std::cout << "Element not found in the array" << std::endl;
 }
 return 0;
}
