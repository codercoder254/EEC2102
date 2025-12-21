# Assignment Submission ✅

| **Student Name** | Adan Onyancha |
| --- | --- |
| **Registration No.** | ENE212-0082/2024 |
| **Course** | ECE |
| **Email** | codercoder254@gmail.com |

---

## Task 1 — Pointer Concepts (Short Notes) 🔧

- **Normal variable vs pointer**
  - A normal variable stores a value directly (e.g., `int x = 10;`).
  - A pointer stores the address of a variable (e.g., `int *p = &x;`).
  - Use `&` to get an address and `*` to dereference a pointer and access the value.

- **Declaration examples**

```c
int x = 5;   // normal variable
int *p = &x; // pointer to x
```

- **Dereferencing**
  - Dereferencing a pointer (`*p`) accesses the value at the address stored in `p`.

```c
int x = 10;
int *p = &x;
*p = 20; // now x == 20
```

- **When to use pointers**
  - To allow functions to modify original data (pass-by-reference).
  - For large data structures to avoid expensive copies.
  - For dynamic memory management (heap allocation).

- **Risks and limitations**
  - Uninitialized or invalid pointers cause undefined behavior.
  - Incorrect memory access can crash programs.
  - Forgetting to free allocated memory leads to leaks.

- **Call by value vs call by reference**
  - Call by value: function receives a copy — original remains unchanged.
  - Call by reference: function receives an address — original can be modified.

```c
void change_by_value(int x);
void change_by_ref(int *x);
```

---

## Task 2 — Display Address of a Variable 💡

Prints the value and address of a variable.

```c
#include <stdio.h>

int main(void) {
    int num = 10;
    int *ptr = &num;

    printf("Value of num: %d\n", num);
    printf("Address stored in ptr: %p\n", (void*)ptr);
    printf("Address of num: %p\n", (void*)&num);
    printf("Value via *ptr: %d\n", *ptr);

    return 0;
}
```

---

## Task 3 — Access & Modify Value Using Pointer 🔁

Example of modifying a variable through a pointer.

```c
#include <stdio.h>

int main(void) {
    int count = 10;
    int *pCount = &count;

    *pCount = 25; // modifies count
    printf("Updated value of count: %d\n", count);

    return 0;
}
```

---

## Task 4 — Add Two Numbers Using Pointers ➕

Adds two integers by dereferencing their pointers.

```c
#include <stdio.h>

int main(void) {
    int num1 = 5, num2 = 7;
    int *ptr1 = &num1;
    int *ptr2 = &num2;

    int sum = *ptr1 + *ptr2;
    printf("Sum: %d\n", sum);

    return 0;
}
```

---

## Task 5 — Swap Two Numbers Using Pointers 🔀

Swap two integers using pointers.

```c
#include <stdio.h>

void swapNumbers(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(void) {
    int a = 3, b = 7;
    printf("Before swap: a = %d, b = %d\n", a, b);

    swapNumbers(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);

    return 0;
}
```

---

## Task 6 — Pass by Value vs Pass by Reference 🔍

Demonstrates difference between passing a value and passing an address.

```c
#include <stdio.h>

void incrementByValue(int x) {
    x++; // modifies local copy
}

void incrementByReference(int *x) {
    (*x)++; // modifies original
}

int main(void) {
    int num = 10;

    incrementByValue(num);
    printf("After pass by value: %d\n", num); // still 10

    incrementByReference(&num);
    printf("After pass by reference: %d\n", num); // now 11

    return 0;
}
```

---

