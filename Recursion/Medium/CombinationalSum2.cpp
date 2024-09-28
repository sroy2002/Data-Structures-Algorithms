//Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
//Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

//EXAMPLE: arr = {2,1,2,1,1} ans = [[1,1,2],[2,2]]

class Solution {
private:
    void func(vector<int>& candi,int ind, int target, vector<int>&temp,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<candi.size();i++){
            if(i>ind && (candi[i]==candi[i-1]))continue;
            if(candi[i]>target)break;
            temp.push_back(candi[i]);
            func(candi,i+1,target-candi[i],temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candi, int t) {
        int n = candi.size();
        sort(candi.begin(),candi.end());
        vector<int> temp;
        vector<vector<int>> ans;
        func(candi,0,t,temp,ans);
        return ans;
    }
};