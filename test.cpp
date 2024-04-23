#include <iostream>
using namespace std;

// Function to add two polynomials represented by arrays
void addPolynomials(int A[], int B[], int m, int n) {
    int size = max(m, n);
    int sum[size];

    for (int i = 0; i < m; ++i)
        sum[i] = A[i];

    for (int i = 0; i < n; ++i)
        sum[i] += B[i];

    cout << "Sum of polynomials: ";
    for (int i = 0; i < size; ++i) {
        cout << sum[i];
        if (i != 0)
            cout << "x^" << i;
        if (i != size - 1)
            cout << " + ";
    }
}

int main() {
    int A[] = {5, 0, 10, 6}; // First polynomial: 5 + 10x^2 + 6x^3
    int B[] = {1, 2, 4};     // Second polynomial: 1 + 2x + 4x^2

    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);

    addPolynomials(A, B, m, n);

    return 0;
}
