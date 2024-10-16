// You are given 2 numbers (n , m); the task is to find n√m (nth root of m).

// Time Complexity: O(n*logm)
//Space Complexity: O(1)


class Solution{
    private:
        int func(int power, int num, int mid){
           long long ans=1;
            for(int i=1;i<=power;i++){
                ans = ans * mid;
                if(ans>num) return 2;
            }
            if(ans == num) return 1;
            return 0;
        }
	public:
	int NthRoot(int power, int num)
	{
	    // Code here.
	    int low = 1, high = num;
	    
	    while(low<=high){
	        int mid = (low+high)/2;
	        int flag = func(power,num,mid);
	        if(flag == 1) return mid;
	        else if(flag==2) high = mid-1;
	        else low = mid+1;
	        
	    }
	    
	    return -1;
	}  
};