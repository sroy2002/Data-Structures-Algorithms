//Given an integer array nums of unique elements, return all possible subsetsc(the power set).
//The solution set must not contain duplicate subsets. Return the solution in any order.

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int y = (1<<n);
        vector<vector<int>> ans;
        for(int i=0;i<y;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};