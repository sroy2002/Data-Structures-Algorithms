// this string doesn't include spaces or numbers or special characters
#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string &s,int i, int n){
    if(i>=n/2) return true;
    if(s[i]!=s[n-i-1]) return false;
    checkPalindrome(s,i+1,n);
}

int main()
{
    string s;
    cout << "Enter the string: "<< endl;
    cin >> s;
    int n = s.size();
    cout << "The string is palindrome ? " << ((checkPalindrome(s,0,n)) ? "YES" : "NO");
    return 0;
}

