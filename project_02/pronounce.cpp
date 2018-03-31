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

//helper functions
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
string toUpper(const string& s)
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

bool isValid(const string& s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        if ((!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z')) && s[i] != '\'')
            return false;
    }
    return true;
}

int countPhonemes(const string& phonemes)
{
    int count = 0;
    for (int i = 0; i < phonemes.size(); ++i)
    {
        if (phonemes[i] == ' ')
            count++;
    }
    return count;
}

string subString(const string& str, int start, int end)
{
    string s = "";
    for (int i = start; i <= end; ++i)
        s += str[i];
    return s;
}

//--------------------------driver funcs-------------------------

//targetPho is the phonemes of the user inputted word

//if it has everthing in pho + one more, return true
bool isAddedPhoneme(const string& targetPho, const string& curPho)
{
    //It's not a valid one if it has more than one more phoneme than the target word
    if (countPhonemes(curPho) != countPhonemes(targetPho) + 1)
        return false;
    //remember where the last space was
    int lastSpaceIndex = 0;
    for (int i = 0; i < targetPho.size(); ++i)
    {
        //update the value of lastSpaceIndex when new space is encountered
        if (targetPho[i] == ' ')
            lastSpaceIndex = i;

        if (targetPho[i] != curPho[i])
        {
            //go to the next space in targetPho
            int count = i;
            while (curPho[count] != ' ')
                count++;
            //compare the rest of the two strings; if they are equal, curPho is an added phoneme
            return (subString(targetPho, lastSpaceIndex, targetPho.size()) ==
                    subString(curPho, count, curPho.size()));
        }
    }
    //if the loop ends normally, then the added phoneme must be at the end
    return true;
}

//similar to isAddedPhoneme
bool isRemovedPhoneme(const string& targetPho, const string& curPho)
{
    if (countPhonemes(curPho) + 1 != countPhonemes(targetPho))
        return false;
    
    int lastSpaceIndex = 0;
    for (int i = 0; i < curPho.size(); ++i)
    {
        if (curPho[i] == ' ')
            lastSpaceIndex = i;
        if (targetPho[i] != curPho[i])
        {
            int count = i;
            while (targetPho[count] != ' ')
                count++;
            return (subString(targetPho, count,targetPho.size()) == 
                    subString(curPho, lastSpaceIndex, curPho.size()));
        }
    }
    return true;
}

int main()
{
    string input;
    cin >> input;
    string uInput = toUpper(input); 
    string line, phoneme, identicals, addedPhonemes, removedPhonemes;
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
    dictFile.seekg(0, ios::beg);

    //main loop
    while (getline(dictFile, line))
    {
        //skip if its a comment
        if (line[0] == ';') continue;
        string word, pho;
        splitOnSpace(line, word, pho);
        //skip if it doesn't contain valid characters
        if (!isValid(word)) continue;
        //check for the stuff
        if (pho == phoneme && word != uInput)
            identicals += word + ' ';
        else if (isAddedPhoneme(phoneme, pho))
            addedPhonemes += word + ' ';
        else if (isRemovedPhoneme(phoneme,pho))
            removedPhonemes += word + ' ';

    }
    cout << "Identical        :" << identicals;
    cout << "\nAdd phoneme      : " << addedPhonemes;
    cout << "\nRemove phoneme   : " << removedPhonemes;  
     return 0;
}