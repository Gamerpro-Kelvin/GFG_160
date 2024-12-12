/*
Given an integer array citations[], where citations[i] is the number of citations a researcher received for the ith paper. The task is to find the H-index.

    H-Index is the largest value such that the researcher has at least H papers that have been cited at least H times.

Examples:

Input: citations[] = [3, 0, 5, 3, 0]
Output: 3
Explanation: There are at least 3 papers (3, 5, 3) with at least 3 citations.

Input: citations[] = [5, 1, 2, 4, 1]
Output: 2
Explanation: There are 3 papers (with citation counts of 5, 2, and 4) that have 2 or more citations. However, the H-Index cannot be 3 because there aren't 3 papers with 3 or more citations.

Input: citations[] = [0, 0]
Output: 0

Constraints:
1 ≤ citations.size() ≤ 10^6
0 ≤ citations[i] ≤ 10^6

*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
            int n = citations.size();
    vector<int> freq(n + 1, 0); // Frequency array

    // Populate frequency array
    for (int c : citations) {
        if (c >= n)
            freq[n]++;
        else
            freq[c]++;
    }

    // Calculate H-index using cumulative sum
    int cumulative = 0;
    for (int h = n; h >= 0; --h) {
        cumulative += freq[h];
        if (cumulative >= h) {
            return h;
        }
    }

    return 0; // If no H-index is found
}

};


//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}
