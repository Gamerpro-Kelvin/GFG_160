/*
Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular.

Examples:

Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
Output: 22
Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.

Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
Output: 23
Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].

Input: arr[] = [-1, 40, -14, 7, 6, 5, -4, -1] 
Output: 52
Explanation: Circular Subarray [7, 6, 5, -4, -1, -1, 40] has the maximum sum, which is 52.

Constraints:
1 <= arr.size() <= 10^5
-10^4 <= arr[i] <= 10^4
*/

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();
    
        // Function to apply Kadane's Algorithm
        auto kadane = [&](bool findMax) {
            int current = findMax ? arr[0] : -arr[0];
            int best = current;
    
            for (int i = 1; i < n; i++) {
                int num = findMax ? arr[i] : -arr[i];
                current = max(num, current + num);
                best = max(best, current);
            }
            return best;
        };
    
        int max_normal = kadane(true);
        if (max_normal < 0) return max_normal; // All elements are negative
    
        int total_sum = accumulate(arr.begin(), arr.end(), 0);
        int min_subarray = -kadane(false);
    
        return max(max_normal, total_sum - min_subarray);
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends
