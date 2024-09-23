#include<bits/stdc++.h>
using namespace std;

int fibo(int num){
    if(num<=1) return num;
    return (fibo(num-1)+fibo(num-2));
}
int main()
{
    vector<int> ans;
    int limit;
    cout << "Enter the number: "<< endl;
    cin >> limit;

    cout << limit << "th Fibonacci Number = " << fibo(limit);
    return 0;
}
