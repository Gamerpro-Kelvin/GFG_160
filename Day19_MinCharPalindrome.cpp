/*
Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

Note: A palindrome string is a sequence of characters that reads the same forward and backward.

Examples:

Input: s = "abc"
Output: 2
Explanation: Add 'b' and 'c' at front of above string to make it palindrome : "cbabc"

Input: s = "aacecaaaa"
Output: 2
Explanation: Add 2 a's at front of above string to make it palindrome : "aaaacecaaaa"

Constraints:
1 <= s.size() <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:  public:


    int minChar(string& s) {
     string temp = s + "#" + string(s.rbegin(), s.rend());
    int n = temp.size();
    vector<int> lps(n, 0);

    // Compute LPS array
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 && temp[i] != temp[j]) {
            j = lps[j - 1];
        }
        if (temp[i] == temp[j]) {
            j++;
        }
        lps[i] = j;
    }

    // Minimum characters to add
    return s.size() - lps.back();
}

};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
