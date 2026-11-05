
#include <iostream>
using namespace std;

// Non-recursive Fibonacci
int nonRecursive(int n) {g+
    int a = 0, b = 1, c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return (n == 0) ? 0 : b;
}

// Recursive Fibonacci
int recursive(int n) {
    if (n <= 1)
        return n;

    return recursive(n - 1) + recursive(n - 2);
}

// Main function
int main() {
    int n;

    cout << "Enter the position: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid input";
        return 0;
    }

    cout << "\nNon-recursive Fibonacci: "
         << nonRecursive(n);

    cout << "\nRecursive Fibonacci: "
         << recursive(n);

    return 0;
}
