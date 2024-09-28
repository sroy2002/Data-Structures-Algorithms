//Given an integer N, print all the divisors of N in the ascending order.
// time & space complexities are both O(sqrt(N));

//EXPLANATION:
//The divisors of N come in pairs. For example, if N=36, then one divisor pair is
// (2,18) since 2*18=36. Similarly, 
// (3,12),(4,9),(6,6) etc., are divisor pairs.
// Instead of iterating through all the numbers from 1 to N, we only need to iterate up to sqrtr(N) because:
//  1. If i is a divisor of N, then N/i is also a divisor.
//  2. So for every i from 1 to sqrt(N), we can find both i and N/i.

//  This approach ensures that we only need to check up to sqrt(N), reducing the time complexity to O(sqrt(N)).

class solution{
    public:
        void printDivisors(int N){
            vector<int> arr;
            for(int i=1;i<=sqrt(N);i++){
                if(N%i==0){
                    arr.push_back(i);
                    if(N/i!=i) arr.push_back(N/i);
                }
            }

            sort(arr.begin(),arr.end());
            for(auto it:arr){
                cout << it << " ";
            }
        }
}