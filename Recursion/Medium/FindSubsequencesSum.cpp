// Print all the subsequences with the given sum S

class Solution {
private:
    void recur(vector<int>&nums, int i, vector<int>&temp, vector<vector<int>>&ans, int sum, int tempSum){
        int n = nums.size();
        if(i>=n){
            if(tempSum==sum){
                ans.push_back(temp);
                return;
            }
        }
        //pick
        temp.push_back(nums[i]);
        tempSum+=nums[i];
        recur(nums,i+1,temp,ans,tempSum);
        tempSum-=nums[i];
        temp.pop_back();
        //not pick
        recur(nums,i+1,temp,ans,tempSum);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        int tempSum = 0;
        recur(nums,0,temp,ans,sum, tempSum);
        return ans;
    }
};