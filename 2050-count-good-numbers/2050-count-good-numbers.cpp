class Solution {
public:
    int p = 1e9 + 7;
    // we are already told to use this, if our answer is large use " modulo 1e9 + 7"


    // function to implement power, doing mod p to handle large numbers
    long long myPow(long long x, long long n) {
        if( n == 0) return 1;

        long long t = myPow(x, n/2);

        if(n % 2 == 1 ) return  (x * t * t) % p;
        else return (t * t) % p ;
    }

    // evens  = 0, 2, 4, 6, 8  => 5 evens
    // primes = 2, 3, 5, 7     => 4 primes
    // for n = 1, only index is 0 i.e. even and can have 5 evens 0, 2, 4, 6, 8
    // for n = 2, can also have index 1, which can have 4 primes
    // this will make total 5x4 for n = 2
    // for n = 3, 0 1 2 are the indexes, hence the second index can also have 5 evens i.e. 0, 2, 4, 6, 8
    // hence for n = even, 5^n/2 * 4^n/2 
    // hence for n = odd, 5^n/2 + 1 * 4^n/2 
    
    int countGoodNumbers(long long n) {
 
        if(n % 2 == 1) {
            return myPow(5, (n / 2) + 1) * myPow(4, n / 2) % p;
        } else {
            return (myPow(5, (n / 2)) * myPow(4, n / 2)) % p;           
        }
        
    }
};