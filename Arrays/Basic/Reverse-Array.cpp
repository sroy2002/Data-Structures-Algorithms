#include <bits/stdc++.h>
using namespace std;
// using Recursion
void reverseArray(vector<int> &arr,int i){
    int n = arr.size();
    if(i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    reverseArray(arr,i+1);
}

int main() {
	// your code goes here
	vector<int> arr = {2,5,3,10,9,8,20};
    cout << "Original Array: "<< endl;
    for(auto i:arr){
        cout << i << " ";
    }
    cout << endl;

    //using Recursion TC: O(N) SC:O(N)
    reverseArray(arr,0);

    //Using Iteration - Two Pointer Approach TC: O(N) SC: O(1)
    // int n = arr.size();
    // int i=0,j=n-1;
    // while(i<=j){
    //     swap(arr[i],arr[j]);
    //     i++;
    //     j--;
    // }
    cout << "Reversed Array using Recursion:"<<endl;
    for(auto i:arr){
        cout << i << " ";
    }
    return 0;
}