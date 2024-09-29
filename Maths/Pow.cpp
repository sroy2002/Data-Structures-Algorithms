// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
        double power(double& result, int x, int expo){
            if(expo>0){
                if(expo%2==0){
                    x*=x;
                    expo/=2;
                    power(result,x,expo);
                }
                else{
                    result*=x;
                    expo--;
                    power(result,x,expo);
                }
            }
            return result;
        }
    public:
        double myPow(int x, int n){
            double res = 1.0;
            long long N = n;
            if(n<0) N = N*(-1);

            // Iteration Method
            // while(N>0){
            //     if(N%2==0){
            //         x*=x;
            //         N/=2;
            //     }
            //     else{
            //         res*=x;
            //         N--;
            //     }
            // }

            //Recursive Approach
            res = power(res,x,n);
            if(n<0){
                res = (double)(1.0)/(double)res;
            }
            return res;
        }
};


int main(){
    int x;
    cout << "Enter the number = ";
    cin >> x;
    int n;
    cout << "Enter the power = ";
    cin >> n;

    Solution sol;
    double result = sol.myPow(x,n);

     cout << "Result of " << x << "^" << n << " = " << result << endl;

     return 0;
}