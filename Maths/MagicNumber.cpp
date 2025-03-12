//A number is said to be a magic number, if the sum of its digits are calculated till a single digit recursively by adding the sum of the digits after every addition. If the single digit comes out to be 1,then the number is a magic number. 

//For example- 
// Number= 50113 
// => 5+0+1+1+3=10 
// => 1+0=1 
// This is a Magic Number 

// For example- 
// Number= 1234 
// => 1+2+3+4=10 
// => 1+0=1 
// This is a Magic Number

//1. BRUTE FORCE  

bool isMagic(int n){
    int sum=0;
    while(n>0 || sum>9){
        if(n==0){
            n=sum;
            sum=0;
        }
        sum+=n%10;
        n=n/10;
    }
    return (sum==1);
}

//2. Optimal Approach (using mathematical formula)

bool isMagic(int n){
    return (n%9==1);
}
