#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Testing lab_12 funcs")
{
    SUBCASE("TASK B")
    {
        CHECK(sumRange(-2,2) == 0);
        CHECK(sumRange(1,4) == 10);
        CHECK(sumRange(1,100)==5050);
    }

    SUBCASE("TASK C")
    {
        int arr[] = {1,2,3,4};
        CHECK(sumArray(arr,4) == 10);
        CHECK(sumArray(arr,3) == 6);
        CHECK(sumArray(arr,0) == 0);
    }

    SUBCASE("TASK D")
    {
        CHECK(isAlphanumeric("abc123") == true);
        CHECK(isAlphanumeric("ABC123") == true);
        CHECK(isAlphanumeric("abc-123") == false);
        CHECK(isAlphanumeric("") == true);
    }

    SUBCASE("TASK E")
    {
        int arr[] = {1,2,1,2,1,2};
        int arr2[] = {1,1,1,1};
        CHECK(divisible(arr,6) == false);
        CHECK(divisible(arr2,4) == true);
    }
}