#include <iostream>
#include <vector>
#include <optional>

/**
 * Finds two numbers in a sorted array that add up to a target.
 * Uses std::optional to safely handle the "not found" state without 
 * relying on magic return numbers (like -1) that can cause silent logic errors.
 */
std::optional<std::pair<int, int>> two_sum_sorted(const std::vector<int>& arr, int target) {
    if (arr.empty()) return std::nullopt;

    size_t left = 0;
    size_t right = arr.size() - 1;

    while (left < right) {
        int current_sum = arr[left] + arr[right];

        if (current_sum == target) {
            return std::make_pair(arr[left], arr[right]);
        } else if (current_sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return std::nullopt;
}

int main() {
    std::vector<int> system_metrics = {10, 20, 35, 50, 75, 80};
    auto result = two_sum_sorted(system_metrics, 70);
    
    if (result) {
        std::cout << "Metrics found: " << result->first << ", " << result->second << "\n";
    }
    return 0;
}
