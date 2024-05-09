#include <iostream>
// Node structure for the linked list
struct Node {
 int data;
 Node* next;

 Node(int val) : data(val), next(nullptr) {}
};
// Function to split the linked list into two halves
void splitLinkedList(Node* head, Node*& firstHalf, Node*& secondHalf) {
 if (!head || !head->next) {
 // If the list is empty or has only one element, no need to split
 firstHalf = head;
 secondHalf = nullptr;
 return;
 }
 Node* slow = head;
 Node* fast = head->next;
 // Move fast pointer two steps and slow pointer one step
 while (fast && fast->next) {
 slow = slow->next;
 fast = fast->next->next;
 }
 // Split the list into two halves
 firstHalf = head;
 secondHalf = slow->next;
 slow->next = nullptr;
}
// Function to display the linked list
void displayList(Node* head) {
 while (head) {
 std::cout << head->data << " ";
 head = head->next;
 }
 std::cout << std::endl;
}
int main() {
 // Create a sample linked list: 1->2->3->4->5
 Node* head = new Node(1);
 head->next = new Node(2);
 head->next->next = new Node(3);
 head->next->next->next = new Node(4);
 head->next->next->next->next = new Node(5);
 // Display the original linked list
 std::cout << "Original Linked List: ";
 displayList(head);
 // Split the linked list
 Node* firstHalf = nullptr;
 Node* secondHalf = nullptr;
 splitLinkedList(head, firstHalf, secondHalf);
 // Display the first half of the linked list
 std::cout << "First Half: ";
 displayList(firstHalf);
 // Display the second half of the linked list
 std::cout << "Second Half: ";
 displayList(secondHalf);
 return 0;
}
