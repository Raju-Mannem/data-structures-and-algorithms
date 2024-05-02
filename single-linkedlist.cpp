#include <iostream>
using namespace std;
// Node structure for the linked list
struct Node {
 int data;
 Node* next;
};
// Class for the linked list operations
class LinkedList {
private:
 Node* head;
public:
 // Constructor to initialize an empty linked list
 LinkedList() {
 head = nullptr;
 }
 // Function to create a linked list
 void createList() {
 int n, value;
 cout << "Enter the number of elements: ";
 cin >> n;
 for (int i = 0; i < n; ++i) {
 cout << "Enter element " << i + 1 << ": ";
 cin >> value;
 insertEnd(value);
 }
 }
 // Function to insert a node at the end of the linked list
 void insertEnd(int value) {
 Node* newNode = new Node;
 newNode->data = value;
 newNode->next = nullptr;
 if (head == nullptr) {
 head = newNode;
 } else {
 Node* temp = head;
 while (temp->next != nullptr) {
 temp = temp->next;
 }
 temp->next = newNode;
 }
 cout << "Element inserted successfully." << endl;
 }
 // Function to delete a node from the linked list
 void deleteNode(int value) {
 if (head == nullptr) {
 cout << "List is empty. Cannot delete." << endl;
 return;
 }
 Node* temp = head;
 Node* prev = nullptr;
 // If the node to be deleted is the head
 if (temp != nullptr && temp->data == value) {
 head = temp->next;
 delete temp;
 cout << "Element deleted successfully." << endl;
 return;
 }
 // Search for the node to be deleted
 while (temp != nullptr && temp->data != value) {
 prev = temp;
 temp = temp->next;
 }
 // If the node is not present
 if (temp == nullptr) {
 cout << "Element not found. Cannot delete." << endl;
 return;
 }
 // Delete the node
 prev->next = temp->next;
 delete temp;
 cout << "Element deleted successfully." << endl;
 }
 // Function to display the linked list
 void displayList() {
 if (head == nullptr) {
 cout << "List is empty." << endl;
 return;
 }
 cout << "Linked List: ";
 Node* temp = head;
 while (temp != nullptr) {
 cout << temp->data << " ";
 temp = temp->next;
 }
 cout << endl;
 }
};
int main() {
 LinkedList list;
 int choice, value;
 do {
 cout << "\nOptions:\n";
 cout << "1. Create a linked list\n";
 cout << "2. Insert an element\n";
 cout << "3. Delete an element\n";
 cout << "4. Display the linked list\n";
 cout << "5. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 list.createList();
 break;
 case 2:
 cout << "Enter the element to insert: ";
 cin >> value;
 list.insertEnd(value);
 break;
 case 3:
 cout << "Enter the element to delete: ";
 cin >> value;
 list.deleteNode(value);
 break;
 case 4:
 list.displayList();
 break;
 case 5:
 cout << "Exiting program. Bye!\n";
 break;
 default:
 cout << "Invalid choice. Please try again.\n";
 }
 } while (choice != 5);
 return 0;
}
