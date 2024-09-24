class Solution {
private:
    void recur(vector<int>&nums, int i, vector<int>&temp, vector<vector<int>>&ans){
        int n = nums.size();
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        recur(nums,i+1,temp,ans);
        temp.pop_back();
        recur(nums,i+1,temp,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        recur(nums,0,temp,ans);
        return ans;
    }
};