// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
// Return the kth positive integer that is missing from this array.

//Brute Force TC = O(N), SC = O(1)
//Optimal Approach using Binary Search, TC = O(logN), SC = O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (k < arr[0])
            return k;
        //Brute Force Start
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i]<=k)k++;
        //     else break;
        // }
        // return k;
        //Brute Force End
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        int diff = arr[high] - (high + 1);
        int more = k - diff;
        return (arr[high] + more);
    }
};