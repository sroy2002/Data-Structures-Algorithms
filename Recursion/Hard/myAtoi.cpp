class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n = s.length();
        int sign = 1;
        while(i<n && s[i]==' '){
            i++;
        }
        if(s[i]=='-') {
            sign = -1;
            i++;
        }
        else if(s[i]=='+') i++;
        long ans = 0;
        while(i<n){
            if(s[i]>='0' && s[i]<='9'){
                int digit = s[i] - '0';
                ans = ans*10+digit;
                if(ans>INT_MAX && sign==1){
                    return INT_MAX;
                }
                if(ans>INT_MAX && sign==-1){
                    return INT_MIN;
                }
                i++;
            }
            else return ans*sign;
        }
        return ans*sign;
    }
};