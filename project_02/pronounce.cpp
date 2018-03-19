/*
Author: Ajani Stewart
Course: CSCI-135
Instructor: Shankar
Assignment: Project 2

The program accepts a word and the program outputs
similar sounding words accoriding to its phonemes
using a dictionary file in the working directory
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//Ignore lines that start with ;;;
//Ignore words that contain non-alphabet characters except '
//return the phoneme deconstruction of the word
//print identical sounding words (all of those phonemes + one extra)
//print identical sounding words (all of those phonemes - one)
//print words with one phoneme replaced

//heler function
void splitOnSpace(string s, string &before, string &after)
{
    // reset strings
    before = "";
    after = "";
    // accumulate before space
    int i = 0;
    while (i < s.size() && not isspace(s[i]))
    {
        before += s[i];
        i++;
    }
    // skip the space
    i++;
    // accumulate after space
    while (i < s.size())
    {
        after += s[i];
        i++;
    }
}

int main()
{

    return 0;
}

