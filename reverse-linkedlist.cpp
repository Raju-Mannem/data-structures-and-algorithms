#include <iostream>
using namespace std;
// Node structure for the linked list
struct Node {
 int data;
 Node* next;

 Node(int val) : data(val), next(nullptr) {}
};
// Function to traverse and print the linked list
void printList(Node* head) {
 cout << "Original List: ";
 while (head != nullptr) {
 cout << head->data << " ";
 head = head->next;
 }
 cout << endl;
}
// Function to traverse and print the linked list in reverse order
void printReverseList(Node* head) {
 if (head == nullptr) {
 return;
 }
 printReverseList(head->next);
 cout << head->data << " ";
}
int main() {
 // Creating a sample linked list
 Node* head = new Node(1);
 head->next = new Node(2);
 head->next->next = new Node(3);
 head->next->next->next = new Node(4);
 // Print the original linked list
 printList(head);
 // Print the linked list in reverse order
 cout << "Reverse List: ";
 printReverseList(head);
 cout << endl;
 return 0;
}
