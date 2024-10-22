#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int arr[]={13,46,24,52,20,9};
	int n = 6;
	
	for(int i=0;i<n-1;i++){
	    int flag=0;
	    for(int j=0;j<n-i-1;j++){
	        if(arr[j]>arr[j+1]){
	            flag=1;
	            swap(arr[j],arr[j+1]);
	        }
	    }
	    if(flag==0)break;
	}
	
	cout << "The sorted array: " <<endl;
	
	for(int i=0;i<n;i++){
	    cout << arr[i] << " ";
	}
    return 0;
}
