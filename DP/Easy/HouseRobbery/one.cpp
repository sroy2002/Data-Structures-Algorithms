// similar problem of Max Sum of non-adjacent elements

long long int solve(long long int start, long long int end, vector<int>&arr){
    long long int prev2=0;
    long long int prev=arr[start];
    for(long long int i=start+1;i<=end;i++){
        long long int pick = arr[i];
        if(i>1) pick+=prev2;
        long long int notpick = prev;
        long long int curr = max(pick,notpick);
        prev2=prev;
        prev=curr;
    }
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    long long int n = valueInHouse.size();
    if (n == 1) return valueInHouse[0];
    long long int ans1 = solve(0,n-2,valueInHouse);
    long long int ans2 = solve(1,n-1,valueInHouse);
    return max(ans1,ans2);
}