/// Finds two numbers in a sorted slice that add up to a target.
/// Rust enforces memory safety without a garbage collector, relying on 
/// ownership rules and built-in Options to handle failure cases securely.
pub fn two_sum_sorted(arr: &[i32], target: i32) -> Option<(i32, i32)> {
    if arr.is_empty() {
        return None;
    }

    let mut left = 0;
    let mut right = arr.len() - 1;

    while left < right {
        let current_sum = arr[left] + arr[right];

        if current_sum == target {
            return Some((arr[left], arr[right]));
        } else if current_sum < target {
            left += 1;
        } else {
            right -= 1;
        }
    }
    
    None
}

fn main() {
    let telemetry_data = vec![10, 20, 35, 50, 75, 80];
    
    // Pattern matching forces the engineer to handle the failure state
    match two_sum_sorted(&telemetry_data, 70) {
        Some((val1, val2)) => println!("Telemetry targets found: {}, {}", val1, val2),
        None => println!("No matching targets found."),
    }
}
