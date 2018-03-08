#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Testing isDivisible")
{
    CHECK(isDivisibleBy(18, 9) == true);
    CHECK(isDivisibleBy(4,2) == true);
    CHECK(isDivisibleBy(27,5) == false);
    CHECK(isDivisibleBy(19,20) == false);
    CHECK(isDivisibleBy(20,20) == true);
}

TEST_CASE("Testing isPrime")
{
    CHECK(isPrime(2) == true);
    CHECK(isPrime(29) == true);
    CHECK(isPrime(1) == false);
    CHECK(isPrime(-2) == false);
    CHECK(isPrime(997) == true);
}

TEST_CASE("testing nextPrime")
{
    CHECK(nextPrime(1) == 2);
    CHECK(nextPrime(2) == 3);
    CHECK(nextPrime(7) == 11);
    CHECK(nextPrime(-7) == 2);
    CHECK(nextPrime(89) == 97);
}

TEST_CASE("testing countPrimes")
{
    CHECK(countPrimes(0,10) == 4);
    CHECK(countPrimes(50, 89) == 9);
    CHECK(countPrimes(350, 500) == 25);
    CHECK(countPrimes(24,28) == 0);
    CHECK(countPrimes(23,30) == 2);
}

TEST_CASE("testing isTwinPrime")
{
    CHECK(isTwinPrime(11) == true);
    CHECK(isTwinPrime(10) == false);
    CHECK(isTwinPrime(89) == false);
    CHECK(isTwinPrime(2) == false);
    CHECK(isTwinPrime(5) == true);
}

TEST_CASE("testing nextTwinPrime")
{
    CHECK(nextTwinPrime(2) == 3);
    CHECK(nextTwinPrime(7) == 11);
    CHECK(nextTwinPrime(75) == 101);
    CHECK(nextTwinPrime(30) == 31);
    CHECK(nextTwinPrime(350) == 419);
    CHECK(nextTwinPrime(461) == 463);
}

TEST_CASE("testing largestTwinPrime")
{
    CHECK(largestTwinPrime(5, 18) == 17);
    CHECK(largestTwinPrime(1,31) == 31);
    CHECK(largestTwinPrime(14, 16) == -1);
    CHECK(largestTwinPrime(0, 1000) == 883);
    CHECK(largestTwinPrime(73, 100) == 73);
    CHECK(largestTwinPrime(74, 101) == 101);
    CHECK(largestTwinPrime(74,100) == -1);
}