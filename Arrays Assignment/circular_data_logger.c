#include <stdio.h>

#define BUFFER_SIZE 5

int main() {
    int buffer[BUFFER_SIZE];
    int writeIndex = 0;
    int count = 0;

    int input;

    
    int data[] = {10, 12, 14, 15, 13, 18, 20};
    int n = sizeof(data) / sizeof(data[0]);

   
    for (int i = 0; i < n; i++) {
        input = data[i];

        buffer[writeIndex] = input;
        writeIndex = (writeIndex + 1) % BUFFER_SIZE;

        if (count < BUFFER_SIZE) {
            count++;
        }
    }

   
    int oldestIndex;
    if (count == BUFFER_SIZE)
        oldestIndex = writeIndex;
    else
        oldestIndex = 0;

    printf("Buffer contents: ");
    for (int i = 0; i < count; i++) {
        int index = (oldestIndex + i) % BUFFER_SIZE;
        printf("%d ", buffer[index]);
    }

    return 0;
}