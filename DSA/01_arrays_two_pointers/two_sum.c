#include <stdio.h>
#include <stdbool.h>

/**
 * Finds two numbers in a sorted array that add up to a target.
 * 
 * Instead of using array indices (arr[left]), this uses raw pointer arithmetic.
 * This is how memory is manipulated directly in a device driver or when 
 * processing a packed hardware sensor buffer.
 */
bool two_sum_pointers(const int* arr, size_t length, int target, int* out_val1, int* out_val2) {
    if (arr == NULL || length < 2) return false;

    const int* left_ptr = arr;
    const int* right_ptr = arr + (length - 1);

    while (left_ptr < right_ptr) {
        int current_sum = *left_ptr + *right_ptr;

        if (current_sum == target) {
            *out_val1 = *left_ptr;
            *out_val2 = *right_ptr;
            return true;
        } else if (current_sum < target) {
            left_ptr++; // Move pointer forward by sizeof(int)
        } else {
            right_ptr--; // Move pointer backward by sizeof(int)
        }
    }
    return false;
}

int main() {
    int sensor_buffer[] = {10, 20, 35, 50, 75, 80};
    size_t len = sizeof(sensor_buffer) / sizeof(sensor_buffer[0]);
    
    int val1 = 0, val2 = 0;
    
    if (two_sum_pointers(sensor_buffer, len, 70, &val1, &val2)) {
        printf("Sensor calibration pair found: %d, %d\n", val1, val2);
    }
    return 0;
}
