//Given an integer n, return the number of prime numbers that are strictly less than n.

// Sieve of Eratosthenes: This is a special algorithm for prime numbers. Watch Strivers video or ask chatgpt to explain it.

class Solution {
public:
    int countPrimes(int n) {
       if(n<=2) return 0;
       int primes[n+1];
       for(int i=2;i<n;i++) primes[i]=1;
       for(int i=2;i*i<n;i++){
            if(primes[i]==1){
                for(int j=i*i;j<=n;j+=i){
                    primes[j]=0;
                }
            }
       }
       int cnt=0;
       for(int i=2;i<n;i++){
            if(primes[i]==1)cnt++;
       }

       return cnt;
    }
};