bool isDivisibleBy(int n, int d)
{
    return n % d == 0;
}

bool isPrime(int n)
{
    //takes advatage of the fact that primes > 5
    //are in the form 6k +/- 1
    //eg 7 = 6(1) + 1
    if (n <= 1) return false;
    else if (n <= 3) return true;
    else if (n % 2 == 0 || n % 3 == 0) return false;

    int i = 5;
    while (i * i <= n)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
        i += 6;
    }
    return true;
}

int nextPrime(int n)
{
    if (n < 2) return 2;
    if (n == 2) return 3;
    bool foundPrime = false;

    while (!foundPrime)
    {
        n += 2;
        if (isPrime(n))
            foundPrime = true;
    }
    return n;
}

int countPrimes(int start, int end)
{
    int count = 0;
    for (int i = start; i <= end; ++i)
    {
        if (isPrime(i))
            ++count;
    }
    return count;
}

bool isTwinPrime(int n)
{
    return (isPrime(n) && (isPrime(n+2) || isPrime(n-2)));
}

int nextTwinPrime(int n)
{
    int start = n;

    bool foundTwinPrime = false;
    while (!foundTwinPrime)
    {
        ++start;
        if (isTwinPrime(start))
            foundTwinPrime = true;
        
    }
    return start;
}

int largestTwinPrime(int a, int b)
{
    for (int i = b; i >= a; --i)
        if (isTwinPrime(i))
            return i;

    return -1;
}
