//Given an array arr. Find the majority element in the array. If no majority exists, return -1.
//A majority element in an array is an element that appears strictly more than arr.size()/2 times in the array.


// Bruteforce Approach
// Time Complexity: O(2n) 
// Space Complexity: O(n)


class Solution {
    public:
      int majorityElement(vector<int>& arr) {
  
          // your code here
          unordered_map<int,int> mpp;
          for(int i=0;i<arr.size();i++){
              mpp[arr[i]]++;
          }
          int n = arr.size()/2;
          int ans = -1;
          for(auto it=mpp.begin();it!=mpp.end();it++){
              if(it->second > n){
                  ans = it->first;
              }
          }
          return ans;
      }
  };


// Optimized Approach
// Time Complexity: O(2n)
// Space Complexity: O(1)

class Solution {
    public:
      int majorityElement(vector<int>& arr) {
          //OPTIMAL APPROACH TC:O(N) SC:O(1)
          int n = arr.size();
          int cnt=0,el;
          for(int i=0;i<n;i++){
              if(cnt==0){
                  cnt=1;
                  el=arr[i];
              }
              else if(el==arr[i]) cnt++;
              else cnt--;
          }
          
          int cnt1=0;
          for(int num:arr){
              if(num==el)cnt1++;
          }
          if(cnt1>(n/2)) return el;
          return -1;
      }
  };