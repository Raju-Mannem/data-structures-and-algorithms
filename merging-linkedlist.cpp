#include <iostream>
// Define a basic Node structure for the linked list
struct Node {
 int data;
 Node* next;

 Node(int value) : data(value), next(nullptr) {}
};
// Function to merge two linked lists
Node* mergeLinkedLists(Node* list1, Node* list2) {
 // Create a dummy node to simplify the code
 Node* dummy = new Node(0);
 Node* current = dummy;
 // Traverse both lists until one of them becomes empty
 while (list1 != nullptr && list2 != nullptr) {
 if (list1->data < list2->data) {
 current->next = list1;
 list1 = list1->next;
 } else {
 current->next = list2;
 list2 = list2->next;
 }
 current = current->next;
 }
 // If one list is not empty, append the remaining nodes
 if (list1 != nullptr) {
 current->next = list1;
 } else {
 current->next = list2;
 }
 // Save the merged list starting from the dummy node's next
 Node* mergedList = dummy->next;
 // Free the dummy node
 delete dummy;
 return mergedList;
}
// Function to print a linked list
void printLinkedList(Node* head) {
 while (head != nullptr) {
 std::cout << head->data << " ";
 head = head->next;
 }
 std::cout << std::endl;
}
int main() {
 // Example usage
 Node* list1 = new Node(1);
 list1->next = new Node(3);
 list1->next->next = new Node(5);
 Node* list2 = new Node(2);
 list2->next = new Node(4);
 list2->next->next = new Node(6);
 std::cout << "List 1: ";
 printLinkedList(list1);
 std::cout << "List 2: ";
 printLinkedList(list2);
 Node* mergedList = mergeLinkedLists(list1, list2);
 std::cout << "Merged List: ";
 printLinkedList(mergedList);
 // Free memory by deleting the linked lists
 delete list1;
 delete list2;
 delete mergedList;
 return 0;
}
