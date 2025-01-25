// Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.

// Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.

class Solution{
    public:
    vector<int> findUnion(vector<int>&a,vector<int>&b){
        int i=0,j=0;
        int n1 = a.size();
        int n2 = b.size();
        vector<int> ans;
        while(i<n1 && j<n2){
            if((i!=0) && (a[i]==a[i-1])){
                i++;
                continue;
            }
            if((j!=0) && (a[j]==a[j-1])){
                j++;
                continue;
            }
            if(a[i]==b[j]){
                ans.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i]<b[j]){
                ans.push_back(a[i]);
                i++;
            }
            else{
                ans.push_back(b[j]);
                j++;
            }
        }
        while(i<n1){
            if(i==0 || a[i]!=a[i-1]){
                ans.push_back(a[i]);
            }
            i++;
        }
        while(j<n2){
            if(j==0 || b[j]!=b[j-1]){
                ans.push_back(b[j]);
            }
            j++;
        }
        return ans;
    }
}