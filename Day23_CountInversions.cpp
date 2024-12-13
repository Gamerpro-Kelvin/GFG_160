/*
Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

    Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
    If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.

Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104
*/
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        vector<int> temp(arr.size());
        return mergeSortAndCount(arr, temp, 0, arr.size() - 1);
}
// Function to merge two halves and count inversions
int mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;    // Starting index of the left subarray
    int j = mid + 1; // Starting index of the right subarray
    int k = left;    // Starting index to store in temp
    int invCount = 0;

    // Merge the two subarrays
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // arr[i] > arr[j], so all elements in left subarray (from i to mid) are greater than arr[j]
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    // Copy remaining elements of left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements of right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy sorted subarray into original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

// Recursive function to implement merge sort and count inversions
int mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        // Count inversions in left subarray
        invCount += mergeSortAndCount(arr, temp, left, mid);

        // Count inversions in right subarray
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);

        // Count split inversions
        invCount += mergeAndCount(arr, temp, left, mid, right);
    }
    return invCount;
}
    
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
