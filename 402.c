#include <stdio.h>
#include <string.h>

int main() {
    long long num = 0;
    int k = 0;

    long long temp = num;
    int num_digits = 0;

    while (temp > 0) {
        num_digits++;
        temp /= 10;
    }

    int digits_arr[num_digits];
    for (int i = num_digits - 1; i >= 0; i--) {
        digits_arr[i] = num % 10;
        num /= 10;
    }

    if(k == num_digits) { printf("%d", 0); return 0; }

    int stack[num_digits];
    int stack_top = 0;
    memset(stack, 0, num_digits * sizeof(int));
    int last_index = 0;

    for (int i = 0; i < num_digits; i++) {
        if (stack[stack_top] <= digits_arr[i]) {
            stack_top++;
            stack[stack_top] = digits_arr[i];
        } else {
            while (stack[stack_top] > digits_arr[i] && k != 0) {
                stack[stack_top] = 0;
                stack_top--;
                k--;
            } // remove all the elements that are bigger than the digit at i
            // because we need to have a monotonically increasing stack

            stack_top++;
            stack[stack_top] = digits_arr[i];
        }

        last_index = i+1;
        if(k == 0) break;
    }

    int printed = 0;

    for (int i = 0; i <= stack_top - k; i++) { // decrease by k because the last elements of the stack are the biggest
        if(stack[i] == 0 && !printed) continue;

        printf("%d", stack[i]);
        printed = 1;
    }

    for (int i = last_index; i < num_digits; i++) {
        if(digits_arr[i] == 0 && !printed) continue;

        printf("%d", digits_arr[i]);
        printed = 1;
    }

    if(!printed) printf("%d", 0);
    return 0;
}

