/*
Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

    Increase the height of the tower by K
    Decrease the height of the tower by K

Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.

Examples :

Input: k = 2, arr[] = {1, 5, 8, 10}
Output: 5
Explanation: The array can be modified as {1+k, 5-k, 8-k, 10-k} = {3, 3, 6, 8}.The difference between the largest and the smallest is 8-3 = 5.

Input: k = 3, arr[] = {3, 9, 12, 16, 20}
Output: 11
Explanation: The array can be modified as {3+k, 9+k, 12-k, 16-k, 20-k} -> {6, 12, 9, 13, 17}.The difference between the largest and the smallest is 17-6 = 11. 

Expected Time Complexity: O(n*logn)
Expected Auxiliary Space: O(n)

Constraints
1 ≤ k ≤ 10^7
1 ≤ n ≤ 10^5
1 ≤ arr[i] ≤ 10^7
*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) return 0; // If there's only one tower, no difference to minimize.
    
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
    
        // Initial maximum possible difference (no adjustments)
        int initialDiff = arr[n - 1] - arr[0];
    
        // Step 2: Initialize the smallest and largest after adjustments
        int smallest = arr[0] + k;  // Smallest possible height
        int largest = arr[n - 1] - k; // Largest possible height
    
        // Ensure smallest and largest are valid
        if (smallest > largest) swap(smallest, largest);
    
        // Step 3: Traverse the sorted array
        for (int i = 0; i < n - 1; ++i) {
            int currentMin = min(smallest, arr[i + 1] - k); // Consider reducing the next tower
            int currentMax = max(largest, arr[i] + k);      // Consider increasing the current tower
    
            // Update smallest and largest difference
            if (currentMin >= 0) { // Avoid negative heights
                initialDiff = min(initialDiff, currentMax - currentMin);
            }
        }

        return initialDiff;
}

};
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
        cout << '~' << endl;
    }
    return 0;
}
