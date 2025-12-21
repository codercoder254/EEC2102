#Assignment Submission

**Student Name:** Adan Onyancha
**Student Registration No:** ENE212-0082/2024
**Course:** ECE
**email** codercoder254@gmail.com


TASK 1: Pointer Concepts (Short Notes)

1. Normal Variable vs Pointer
A normal variable stores an actual value.
Example: an int variable stores a number like 10.
A pointer stores the address of a variable, not the value itself.
Memory-wise:

A normal variable accesses memory directly.
A pointer accesses memory indirectly by holding an address.

Reading & modifying:
With a normal variable, you read or change the value directly.
With a pointer, you must dereference it to read or change the value stored at that address.

In short:
A variable knows what the value is.
A pointer knows where the value lives.

2. Variable Declaration vs Pointer Declaration
Normal variable:
int x = 5;

int → data type
x → variable name
5 → value stored

Pointer:
int *p;
p = &x;

*p → pointer to an integer
&x → address of x

Roles of operators:
& (address-of): gives the memory location of a variable
* (asterisk):
In declaration → means “pointer”
In usage → means “go to that address and access the value”

3. Dereferencing a Pointer
Dereferencing means accessing the value stored at the address inside a pointer.
Example:
int x = 10;
int *p = &x;

p → address of x
*p → value of x (10)

Modifying through pointer:
*p = 20;

Now x becomes 20.
Pointers reach into memory and change things. Handle with care.

4. When Pointers Are Preferred
Pointers are useful when:
You want functions to modify original data
You are dealing with large data structures
You need dynamic memory

Examples:Swapping values in a function
Without pointers → swap fails
With pointers → swap works


Arrays and strings
Arrays are passed as pointers by default, making data access faster and memory-efficient.

5. Limitations and Risks of Pointers
Pointers are powerful but dangerous if abused:

Uninitialized pointers can crash programs
Wrong memory access leads to undefined behavior
Memory leaks occur if allocated memory isn’t freed
Harder to debug compared to normal variables



6. Call by Value vs Call by Reference
Call by Value:
Function receives a copy
Original value remains unchanged
Call by Reference
Function receives the address
Original value gets modified

Example difference:
void change(int x);      // value
void change(int *x);    // reference


7. When to Use Each
a. Call by Value
-When original data must remain safe
-Simple calculations


b. Call by Reference
-When function must update values
-Large data structures (efficiency)
-Swapping, incrementing, modifying arrays

TASK 2: Display Address of a Variable
#include <stdio.h>

int main() {
    int num = 10;
    int *ptr = &num;

    printf("Value of num: %d\n", num);
    printf("Value stored in ptr (address of num): %p\n", ptr);
    printf("Address of num: %p\n", &num);
    printf("Value accessed using *ptr: %d\n", *ptr);

    return 0;
}


TASK 3: Access & Modify Value Using Pointer
#include <stdio.h>

int main() {
    int count = 10;
    int *pCount = &count;

    *pCount = 25;

    printf("Updated value of count: %d\n", count);

    return 0;
}


TASK 4: Add Two Numbers Using Pointers
#include <stdio.h>

int main() {
    int num1 = 5, num2 = 7;
    int *ptr1 = &num1;
    int *ptr2 = &num2;

    int sum = *ptr1 + *ptr2;

    printf("Sum: %d\n", sum);

    return 0;
}


TASK 5: Swap Two Numbers Using Pointers
#include <stdio.h>

void swapNumbers(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 3, b = 7;

    printf("Before swap: a = %d, b = %d\n", a, b);

    swapNumbers(&a, &b);

    printf("After swap: a = %d, b = %d\n", a, b);

    return 0;
}


TASK 6: Pass by Value vs Pass by Reference
#include <stdio.h>

void incrementByValue(int x) {
    x++;
}

void incrementByReference(int *x) {
    (*x)++;
}

int main() {
    int num = 10;

    incrementByValue(num);
    printf("After pass by value: %d\n", num);

    incrementByReference(&num);
    printf("After pass by reference: %d\n", num);

    return 0;
}
