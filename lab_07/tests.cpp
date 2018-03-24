#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Testing Caesar")
{
    SUBCASE("Encrypt")
    {
        CHECK("Wklv lv d vhfuhw phvvdjh" == encryptCaesar("This is a secret message",3));
        CHECK("Lzw imauc tjgof xgp Bmehwv gnwj lzw dsrq vgy!" == encryptCaesar("The quick brown fox Jumped over the lazy dog!", 18));
        CHECK("LEELNVLEOLHY" == encryptCaesar("ATTACKATDAWN",11));
        CHECK("LEELNVLEOLHY" == encryptCaesar("ATTACKATDAWN",37));
    }

    SUBCASE("Decrypt")
    {
        CHECK("This is a secret message" == decryptCaesar("Wklv lv d vhfuhw phvvdjh",3));
        CHECK("The quick brown fox Jumped over the lazy dog!" == decryptCaesar("Lzw imauc tjgof xgp Bmehwv gnwj lzw dsrq vgy!", 18));
        CHECK("ATTACKATDAWN" == decryptCaesar("LEELNVLEOLHY",11));
        CHECK("ATTACKATDAWN" == decryptCaesar("LEELNVLEOLHY", 37));
        }

}

TEST_CASE("Testing Vigenere")
{
    SUBCASE("Encrypt")
    {
        CHECK("Jevpq, Wyvnd!" == encryptVigenere("Hello, World!", "cake"));
        CHECK("YHW JZWZP BJHBB CTX BNRDBI ONXW HEJ LSSD RLL!" == encryptVigenere("THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG!", "FASTFOX"));
        CHECK("LXFOPVEFRNHR" == encryptVigenere("ATTACKATDAWN", "LEMON"));
    }
    SUBCASE("Decrypt")
    {
        CHECK("Hello, World!" == decryptVigenere("Jevpq, Wyvnd!", "cake"));
        CHECK("THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG!" == decryptVigenere("YHW JZWZP BJHBB CTX BNRDBI ONXW HEJ LSSD RLL!", "FASTFOX"));
        CHECK("ATTACKATDAWN" == decryptVigenere("LXFOPVEFRNHR", "LEMON"));
    }
}