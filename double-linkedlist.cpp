#include <iostream>
using namespace std;
// Node structure for the double linked list
struct Node {
 double data;
 Node* prev;
 Node* next;
};
// Class for the double linked list
class DoubleLinkedList {
private:
 Node* head;
public:
 // Constructor
 DoubleLinkedList() {
 head = nullptr;
 }
 // Function to create a double linked list
 void createList() {
 int n;
 cout << "Enter the number of nodes: ";
 cin >> n;
 for (int i = 0; i < n; ++i) {
 double value;
 cout << "Enter the data for node " << i + 1 << ": ";
 cin >> value;
 insertEnd(value);
 }
 }
 // Function to insert a node at the end of the list
 void insertEnd(double value) {
 Node* newNode = new Node;
 newNode->data = value;
 newNode->next = nullptr;
 if (head == nullptr) {
 newNode->prev = nullptr;
 head = newNode;
 } else {
 Node* temp = head;
 while (temp->next != nullptr) {
 temp = temp->next;
 }
 temp->next = newNode;
 newNode->prev = temp;
 }
 cout << "Node inserted at the end successfully." << endl;
 }
 // Function to delete a node with a given value
 void deleteNode(double value) {
 if (head == nullptr) {
 cout << "List is empty. Cannot delete from an empty list." << endl;
 return;
 }
 Node* temp = head;
 while (temp != nullptr && temp->data != value) {
 temp = temp->next;
 }
 if (temp == nullptr) {
 cout << "Node with value " << value << " not found in the list." << endl;
 return;
 }
 if (temp->prev != nullptr) {
 temp->prev->next = temp->next;
 } else {
 head = temp->next;
 }
 if (temp->next != nullptr) {
 temp->next->prev = temp->prev;
 }
 delete temp;
 cout << "Node with value " << value << " deleted successfully." << endl;
 }
 // Function to display the double linked list
 void displayList() {
 if (head == nullptr) {
 cout << "List is empty." << endl;
 return;
 }
 Node* temp = head;
 cout << "Double Linked List: ";
 while (temp != nullptr) {
 cout << temp->data << " ";
 temp = temp->next;
 }
 cout << endl;
 }
};
int main() {
 DoubleLinkedList dll;
 int choice;
 double value;
 do {
 cout << "\nMenu:\n";
 cout << "1. Create List\n";
 cout << "2. Insert at End\n";
 cout << "3. Delete Node\n";
 cout << "4. Display List\n";
 cout << "5. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 dll.createList();
 break;
 case 2:
 cout << "Enter the value to insert: ";
 cin >> value;
 dll.insertEnd(value);
 break;
 case 3:
 cout << "Enter the value to delete: ";
 cin >> value;
 dll.deleteNode(value);
 break;
 case 4:
 dll.displayList();
 break;
 case 5:
 cout << "Exiting program. Bye!" << endl;
 break;
 default:
 cout << "Invalid choice. Please enter a valid option." << endl;
 }
 } while (choice != 5);
 return 0;
}
