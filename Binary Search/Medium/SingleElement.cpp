//You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.
// Your solution must run in O(log n) time and O(1) space.

// the idea is to observe at which position the single element occurs, like the position is odd or even...the answer is always even. Then eliminate one half of the search space based on that (else if, else conditions). Here are some edge cases too like both ends of the array where we can't apply the logic of if condition that's why we are handling the edge elements separately (2nd and 3rd if cond. from the start) and reducing the search space to 1 to (n-2) size.


class Solution{
    public:
        int findSingle(vector<int>& arr){
            int n = arr.size();
            if(n==1) return arr[0];
            if(arr[0]!=arr[1]) return arr[0];
            if(arr[n-1]!=arr[n-2]) return arr[n-1];
            int low = 1;
            int high = n-2;
            while(low<=high){
                int mid = low + (high-low)/2;
                if((arr[mid-1]!=arr[mid]) && (arr[mid]!=arr[mid+1])){
                    return arr[mid];
                }
                else if(((mid%2==1) && (arr[mid-1]==arr[mid])) || ((mid%2==0) && (arr[mid]==arr[mid+1]))){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            return -1;
        }
};