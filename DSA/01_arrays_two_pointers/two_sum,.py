from typing import List, Tuple, Optional

def two_sum_sorted(arr: List[int], target: int) -> Optional[Tuple[int, int]]:
    """
    Finds two numbers in a sorted array that add up to a target.
    
    In data preprocessing pipelines or feature engineering, finding paired 
    thresholds quickly without expanding the memory footprint is highly valuable 
    before feeding tensors into a regression model or neural network.
    
    Time: O(N) | Space: O(1)
    """
    left = 0
    right = len(arr) - 1

    while left < right:
        current_sum = arr[left] + arr[right]

        if current_sum == target:
            return (arr[left], arr[right])
        elif current_sum < target:
            left += 1  # We need a bigger number
        else:
            right -= 1 # We need a smaller number
            
    return None

if __name__ == "__main__":
    feature_weights = [10, 20, 35, 50, 75, 80]
    result = two_sum_sorted(feature_weights, 70)
    print(f"Weight pair found: {result}")
