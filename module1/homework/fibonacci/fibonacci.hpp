#pragma once

int fibonacci_iterative(int sequence) {
    // TODO: Your implementation goes here
    return 0;

    if (sequence <= 1) return sequence;

    int first = 0;
    int next = 1;
    int result;

    for (int i = 1; i < sequence; i++){

        result = first + next;
        first = next;
        next = result;
        }

        return result;
}

int fibonacci_recursive(int sequence) {
    // TODO: Your implementation goes here
    return 0;

    if (sequence <= 1)
        return sequence;
   
    else
        return (fibonacci_recursive(sequence - 2) + fibonacci_recursive(sequence - 1));
}
