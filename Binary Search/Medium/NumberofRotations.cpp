class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int low=0,high=n-1;
        int lowest = INT_MAX; //minimum element
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[low]<=arr[mid]){
                if(arr[low]<lowest){
                    lowest = arr[mid];
                    ans = low;
                }
                low = mid+1;
            }
            else{
                 if(arr[mid]<lowest){
                    lowest = arr[mid];
                    ans = mid;
                }
                high = mid-1;
            }
        }
        return ans;
    }
};