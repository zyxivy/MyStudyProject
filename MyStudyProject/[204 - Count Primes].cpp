//Description:
//Count the number of prime numbers less than a non - negative number, n.

#include "Header.h";

//https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

/**
Input: an integer n > 1.

    Let A be an array of Boolean values, indexed by integers 2 to n,
    initially all set to true.

    for i = 2, 3, 4, ..., not exceeding √n :
       if A[i] is true :
           for j = i^2, i^2 + i, i^2 + 2i, i^2 + 3i, ..., not exceeding n :
       A[j] : = false.

           Output : all i such that A[i] is true.
**/

int Solution::countPrimes(int n) {
    vector<bool> primes(n, true);
    for (int i = 2; i * i < n; i++) {
        if (primes[i]) {
            for (int j = 2; j*i < n; j++) {
                primes[j*i] = false;
            }   
        }
    }
    int res = 0;
    for (int i = 2; i<n; i++) {
        if (primes[i] == true) {
            res++;
        }
    }
    return res;
}