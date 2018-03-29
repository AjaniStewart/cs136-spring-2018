/*
Author: Ajani Stewart
Course: CSCI-135
Instructor: Professor Marayash
Assignment: Project 2

The program accepts a word and the program outputs
similar sounding words accoriding to its phos
using a dictionary file in the working directory
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//Ignore lines that start with ;;;
//Ignore words that contain non-alphabet characters except '
//return the pho deconstruction of the word
//print identical sounding words (all of those phos + one extra)
//print identical sounding words (all of those phos - one)
//print words with one pho replaced

//heler functions
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

//to normalize inputs
string toUpper(string s)
{
    string str = "";
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            str += s[i] - 32;
        else
            str += s[i];
    }
    return str;
}

bool isValid(string s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        if ((!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z')) && s[i] != '\'')
            return false;
    }
    return true;
}

//if it has everthing in pho + one more, return true
bool isAddedPhoneme(string sPho, string pho)
{
    for (int i = 0; i < pho.size(); ++i)
    {
        
    }
}
//
int main()
{
    string input;
    cin >> input;
    string uInput = toUpper(input); 
    string line, phoneme;
    bool found = false;
    fstream dictFile("cmudict.0.7a");
    //first pass to find the inital pronunciatino
    //consider making this a function
    while(getline(dictFile, line))
    {   
        //skip if its a comment
        if (line[0] == ';') continue;
        string word, pho;
        splitOnSpace(line,word,pho);
        //skip if it doesn't contain valid characters
        if (!isValid(word)) continue;
        if (uInput == word)
        {
            cout << "Pronunciation    :" << pho << endl;
            phoneme = pho;
            found = true;
            break;
        }
    }
    //end early if it is not in the dict
    if (!found)
    {
        cout << "Not found" << endl;
        return 0;
    }
    //reset to the top of the file
    cout << "Identical        :"; 
    dictFile.seekg(0, ios::beg);
    while (getline(dictFile, line))
    {
        //skip if its a comment
        if (line[0] == ';') continue;
        string word, pho;
        splitOnSpace(line, word, pho);
        //skip if it doesn't contain valid characters
        if (!isValid(word)) continue;
        if (pho == phoneme && word != uInput)
            cout << " " << word;
    }
    cout << "\nAdd phoneme      :";

    return 0;
}