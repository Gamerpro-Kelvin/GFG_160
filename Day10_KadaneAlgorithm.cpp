/*
Given an integer array arr[]. You need to find the maximum sum of a subarray.

Examples:

Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.

Input: arr[] = [-2, -4]
Output: -2
Explanation: The subarray {-2} has the largest sum -2.

Input: arr[] = [5, 4, 1, 7, 8]
Output: 25
Explanation: The subarray {5, 4, 1, 7, 8} has the largest sum 25.

Constraints:
1 ≤ arr.size() ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^4
*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        int max_sum = arr[0];  // Initialize max_sum to the first element
        int current_sum = arr[0];  // Initialize current_sum to the first element
    
        for (int i = 1; i < arr.size(); i++) {
            // Update current_sum by either adding the current element or starting a new subarray
            current_sum = max(arr[i], current_sum + arr[i]);
    
            // Update max_sum if current_sum is greater
            max_sum = max(max_sum, current_sum);
        }
    
        return max_sum;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends
