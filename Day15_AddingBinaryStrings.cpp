/*
Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

Input: s1 = "1101", s2 = "111"
Output: 10100
Explanation:
 1101
+ 111
10100

Input: s1 = "00100", s2 = "010"
Output: 110
Explanation: 
  100
+  10
  110

Constraints:
1 ≤s1.size(), s2.size()≤ 106
*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        int i = s1.size() - 1; // Pointer for s1
        int j = s2.size() - 1; // Pointer for s2
        int carry = 0;
        string result = "";
    
        // Traverse both strings from the end
        while (i >= 0 || j >= 0 || carry > 0) {
            int bit1 = (i >= 0) ? s1[i] - '0' : 0; // Get bit from s1 or 0 if exhausted
            int bit2 = (j >= 0) ? s2[j] - '0' : 0; // Get bit from s2 or 0 if exhausted
    
            int sum = bit1 + bit2 + carry; // Add bits and carry
            result += (sum % 2) + '0';     // Add the current bit to the result
            carry = sum / 2;               // Update carry
    
            i--;
            j--;
        }
    
        reverse(result.begin(), result.end()); // Reverse the result to get the correct order
    
        // Remove leading zeros
        int pos = result.find_first_not_of('0');
        return (pos == string::npos) ? "0" : result.substr(pos);
}

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}
