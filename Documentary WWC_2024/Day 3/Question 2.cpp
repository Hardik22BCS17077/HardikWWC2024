#include <iostream>
#include <vector>

int lastRemaining(int n) {
    bool leftToRight = true; // Direction of removal
    int start = 1;          // Start of the current range
    int step = 1;           // Step between elements
    int remaining = n;      // Number of remaining elements

    while (remaining > 1) {
        // If moving left to right or removing odd elements, update the start
        if (leftToRight || remaining % 2 == 1) {
            start += step;
        }
        // Halve the number of elements and double the step
        remaining /= 2;
        step *= 2;
        leftToRight = !leftToRight; // Alternate the direction
    }

    return start;
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    int result = lastRemaining(n);
    std::cout << "The last remaining number is: " << result << std::endl;

    return 0;
}
