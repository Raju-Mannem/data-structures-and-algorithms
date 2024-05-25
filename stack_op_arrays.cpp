#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
class Stack {
private:
 int arr[MAX_SIZE];
 int top;
public:
 Stack() {
 top = -1;
 }
 void push(int value) {
 if (top >= MAX_SIZE - 1) {
 cout << "Stack Overflow, cannot push element.\n";
 return;
 }
 arr[++top] = value;
 cout << value << " pushed into the stack.\n";
 }
 void pop() {
 if (top < 0) {
 cout << "Stack Underflow, cannot pop element.\n";
 return;
 }
 cout << arr[top--] << " popped from the stack.\n";
 }
 void display() {
 if (top < 0) {
 cout << "Stack is empty.\n";
 return;
 }
 cout << "Stack elements: ";
 for (int i = 0; i <= top; ++i) {
 cout << arr[i] << " ";
 }
 cout << "\n";
 }
 int peek() {
 if (top < 0) {
 cout << "Stack is empty.\n";
 return -1; // or any appropriate value for an empty stack
 }
 return arr[top];
 }
 bool isEmpty() {
 return top < 0;
 }
};
int main() {
 Stack myStack;
 myStack.push(10);
 myStack.push(20);
 myStack.push(30);
 myStack.display();
 cout << "Top element: " << myStack.peek() << "\n";
 myStack.pop();
 myStack.display();
 cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << "\n";
 return 0;
}
