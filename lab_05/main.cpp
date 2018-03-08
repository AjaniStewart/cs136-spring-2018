#include <iostream>
#include "funcs.h"

int main()
{
    std::cout << "100 " << (isDivisibleBy(100,25) ? "is " : "is not ") << "divisible by 25\n";

    std::cout << "11 " << (isPrime(11) ? "is ": "is not ") << "a prime number and ";
    std::cout << "15 " << (isPrime(15) ? "is " : "is not ") << "prime number.\n";

    std::cout << "The next prime number after 47 is " << nextPrime(47) << std::endl;

    std::cout << "There are " << countPrimes(0,100) << " primes between 0 and 100\n";

    std::cout << "7 is " << (isTwinPrime(7) ? "" : "not") << " a twin prime\n";

    std::cout << nextTwinPrime(7) << " is the next twin prime after 7\n";

    std::cout << "The largest twin prime between 0 and 100 is " << largestTwinPrime(0,100) << std::endl;




}