/*
 * Description: This program takes two integers and an operation code from the user
 *              and performs the corresponding arithmetic operation (addition, subtraction,
 *              multiplication, or division) on the input integers using function pointers.
 *              It defines four functions for each arithmetic operation and utilizes a
 *              function pointer array to call the appropriate function based on the user's choice.
 */
#include <iostream>
using namespace std;

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main() {
    // Function pointer array
    int (*operation[4])(int, int) = {add, subtract, multiply, divide};

    int num1, num2, choice;
    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    cout << "Enter the operation you want to perform (0: add, 1: subtract, 2: multiply, 3: divide): ";
    cin >> choice;

    // Call the selected operation function using function pointer
    int result = operation[choice](num1, num2);

    cout << "Result: " << result << endl;

    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "Error: Division by zero" << endl;
        return 0;
    }
}
