#include <iostream>
using namespace std;
// Node structure to represent a term in the polynomial
struct Node {
 int coefficient;
 int exponent;
 Node* next;
};
// Function to create a new node
Node* createNode(int coefficient, int exponent) {
 Node* newNode = new Node;
 newNode->coefficient = coefficient;
 newNode->exponent = exponent;
 newNode->next = nullptr;
 return newNode;
}
// Function to add a term to the polynomial
void addTerm(Node*& poly, int coefficient, int exponent) {
 Node* newNode = createNode(coefficient, exponent);
 if (!poly) {
 poly = newNode;
 } else {
 Node* temp = poly;
 while (temp->next) {
 temp = temp->next;
 }
 temp->next = newNode;
 }
}
// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
 Node* result = nullptr;
 while (poly1 && poly2) {
 if (poly1->exponent > poly2->exponent) {
 addTerm(result, poly1->coefficient, poly1->exponent);
 poly1 = poly1->next;
 } else if (poly1->exponent < poly2->exponent) {
 addTerm(result, poly2->coefficient, poly2->exponent);
 poly2 = poly2->next;
 } else {
 addTerm(result, poly1->coefficient + poly2->coefficient, poly1->exponent);
 poly1 = poly1->next;
 poly2 = poly2->next;
 }
 }
 while (poly1) {
 addTerm(result, poly1->coefficient, poly1->exponent);
 poly1 = poly1->next;
 }
 while (poly2) {
 addTerm(result, poly2->coefficient, poly2->exponent);
 poly2 = poly2->next;
 }
 return result;
}
// Function to display a polynomial
void displayPolynomial(Node* poly) {
 while (poly) {
 cout << poly->coefficient << "x^" << poly->exponent;
 poly = poly->next;
 if (poly) {
 cout << " + ";
 }
 }
 cout << endl;
}
int main() {
 Node* poly1 = nullptr;
 Node* poly2 = nullptr;
 // Adding terms to the first polynomial
 addTerm(poly1, 5, 2);
 addTerm(poly1, -3, 1);
 addTerm(poly1, 2, 0);
 // Adding terms to the second polynomial
 addTerm(poly2, 3, 3);
 addTerm(poly2, 1, 1);
 addTerm(poly2, 7, 0);
 cout << "First Polynomial: ";
 displayPolynomial(poly1);
 cout << "Second Polynomial: ";
 displayPolynomial(poly2);
 Node* result = addPolynomials(poly1, poly2);
 cout << "Sum of Polynomials: ";
 displayPolynomial(result);
 return 0;
}
