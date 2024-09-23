// NOTE: When we are determining Fibonacci Series then we are taking a vector "ans" and storing the values in there and later printing the ans array, the commented code is the series one and When we are told to print the nth fibonacci number then we need to do this ⬇️

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int limit;
	cin >> limit;
	// vector<int> ans;
	int a = 0,b=1;
// 	ans.push_back(a);
// 	ans.push_back(b);
    int c;
	for(int i=2;i<=limit;i++){
	   c = a+b;
	   //ans.push_back(c);
	   a=b;
	   b=c;
	}

    // cout  << endl << "Fibonacci Series: " << endl;
    cout  << limit << "th Fibonacci Number: " << c;
    
    // for(auto it:ans){
    //     cout << it <<" ";
    // }
    return 0;
}
