class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long numXor = 0;
        for(int i=0;i<nums.size();i++){
            numXor = numXor^nums[i];
        }
        int rightMost = numXor^(numXor&(numXor-1));
        int b1=0,b2=0;
        for(auto it:nums){
            if(rightMost&it){
                b1=b1^it;
            }
            else{
                b2=b2^it;
            }
        }

        return {b1,b2};
    }
};