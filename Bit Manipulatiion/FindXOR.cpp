//You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

//This problems holds a special pattern
//XOR of 'n' numbers are:
// till 1 = 1
// till 2 = 3
// till 3 = 0
// till 4 = 4

// till 5 = 1
// till 6 = 7
// till 7 = 0
// till 8 = 8


// till 9 = 1
// till 10 = 11
// ....so on

// We can see 1%4 = 5%4 = 9%4 = 1 so XOR till 1,5,9 are all 1;
//also 2%4 = (2+1) = 3, 6%4 = (6+1) = 7, 10%4 = (10+1) = 11 
// similarly for other numbers


class Solution {
  private:
    int func(int n){
        if(n%4==0)return n;
        else if(n%4==1)return 1;
        else if(n%4==2)return n+1;
        else if(n%4==3)return 0;
    } 
  public:
    int findXOR(int l, int r) {
        // complete the function here
        return func(l-1)^func(r); // here we are doing like, l=3,r=5 so (1^2)^(1^2^3^4^5) =(3^4^5) 
        
    }
};


//Above is the most optimized version of this problem, TC = O(1) & SC = O(1)

//The Brute Force of this problem would be running a loop between the range with TC = O(N) where N = l-r and applying XOR one by one.


