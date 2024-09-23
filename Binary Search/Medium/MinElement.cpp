// Find Minimum element in a rotated sorted array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int minn = INT_MAX;
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            //search space is already sorted
            //then arr[low] will always be
            //the minimum in that search space:
            // optimization start
            if(nums[low]<=nums[high]){
                minn = min(minn,nums[low]);
                break;
            }
            //optimization end
            if(nums[low]<=nums[mid]){
                minn = min(minn,nums[low]);
                low = mid+1;
            }
            else{
                minn = min(minn,nums[mid]);
                high = mid-1;
            }
        }
        return minn;
    }
};