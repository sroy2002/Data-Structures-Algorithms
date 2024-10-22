#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int arr[]={13,46,24,52,20,9};
	int n = 6;
	for(int i=0;i<n-1;i++){
	    int ind= i;
	    for(int j=i;j<n;j++){
	        if(arr[j]<arr[ind]){
	            ind=j;
	        }
	    }
	    swap(arr[i],arr[ind]);
	}
	
	cout << "The sorted array: " <<endl;
	
	for(int i=0;i<n;i++){
	    cout << arr[i] << " ";
	}
    return 0;
}
