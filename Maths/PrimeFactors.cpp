// Given a number N. Find its unique prime factors in increasing order.


class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    // Code here
        int cnt=0;
        vector<int> ans;
        for(int i=2;i*i<=N;i++){ //the loop is running till sqrt(N)
            if(N%i==0){
                cnt++;
                ans.push_back(i);
                while(N%i==0){
                    N=N/i;
                }
            }
        }
        if(N!=1)ans.push_back(N);
        return ans;
	}
};