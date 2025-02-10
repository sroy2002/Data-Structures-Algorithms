// Given a string s, find the length of the longest 
// substring without repeating characters.

//Time Complexity: O(n) where n = size of the string


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int> hash(256,-1);
        int maxlen = 0;
        int i=0,j=0;
        while(j<s.length()){
            if(hash[s[j]]!=-1){
                i = max(i,hash[s[j]]+1);
            }   
            hash[s[j]]=j;
            maxlen = max(maxlen,j-i+1);
            j++;
            
        }
        return maxlen;
    }
};