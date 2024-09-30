/// check if the given number is a power of 2 or not


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool check(int num){
            if(num<=0) return false;
            return ((num&(num-1))==0);
        }
};

int main()
{
    int num;
    cout << "Enter the num = ";
    cin >> num;
    Solution sol;
    bool ans = sol.check(num);
    cout << "The entered number is a power of 2: " << ((ans) ? "TRUE" : "FALSE");
    return 0;
}
