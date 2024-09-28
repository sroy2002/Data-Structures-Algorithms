// Given a list arr of n integers, return sums of all subsets in it. Output sums can be printed in any order.

//Time Complexity = O(2^n) Space Complexity = O(2^n)

class Solution {
  private:
    void func(vector<int>&arr, int lim, int ind, int sum, vector<int>&ans){
        if(ind==lim){
            ans.push_back(sum);
            return;
        }
        sum+=arr[ind];
        func(arr,lim,ind+1,sum,ans);
        sum-=arr[ind];
        func(arr,lim,ind+1,sum,ans);
    }
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        // sort(arr.begin(),arr.end());
        vector<int> ans;
        func(arr,n,0,0,ans);
        // sort(ans.begin(),ans.end());
        return ans;
    }
};