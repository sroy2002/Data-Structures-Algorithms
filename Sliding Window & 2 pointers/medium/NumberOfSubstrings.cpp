// Problem Statement

//Given a string s consisting only of characters a, b and c. Return the number of substrings containing at least one occurrence of all these characters a, b and c.

//Brute Force Solution 
//TC = O(N^2) SC=O(3)~O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
       int n = s.size();
        int cnt = 0;

        // Iterate through all possible starting points
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> hash;
            
            // Check substrings starting from index i
            for (int j = i; j < n; j++) {
                hash[s[j]]++;

                // If all three characters are present, count substrings
                if (hash['a'] > 0 && hash['b'] > 0 && hash['c'] > 0) {
                    cnt += (n - j); // All substrings starting from j are valid
                    break;          // Move to the next starting point
                }
            }
        }

        return cnt;
    }
};


// Optimal Solution
//TC=O(N) SC=O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> hash(3,-1);
        int n = s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            hash[s[i]-'a']=i;
            if(hash[0]!=-1 && hash[1]!=-1 && hash[2]!=-1){
                cnt+=1+min(hash[0],min(hash[1],hash[2]));
            }
        }
        return cnt;
    }
};