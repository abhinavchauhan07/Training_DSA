//Q1 Find all interleavings of given strings that can be formed from all the characters of the string1 and string2 string where the order of characters is preserved.
/*
 MARK: findAllStrings is a  function to generate all the possible strings.
 
 DESC: findAllStrings is recursive function which will follow the order of the first charactre of both the strings and call the function for all the possible combinations.
 
 PARAM:findAllStrings takes the two index of string1 and string2 and then the two strings also it takes the currentstring as a parameter which will generate all the possible combinations
 
 */
 

#include<iostream>
using namespace std;

void findAllStrings(int string1Index, int string2Index, string &string1, string &string2, string currentString)
{
    //if the size of the currentString string is equal to the sum of both the string1 and string2 string print and return
    if (currentString.size() == string1.size() + string2.size())
    {
        cout << currentString <<" ";
        return;
    }

    //checking if the stirng1 index is not the last index than add the another char of string 1 recursively and then removing the last character
    if (string1Index < string1.size())
    {
        currentString += string1[string1Index];
        findAllStrings(string1Index + 1, string2Index, string1, string2, currentString);
        currentString.pop_back();
    }
    //checking if the stirng1 index is not the last index than add the another char of string 1 recursively and then removing the last character
    if (string2Index < string2.size())
    {
        currentString += string2[string2Index];
        findAllStrings(string1Index, string2Index + 1, string1, string2, currentString);
        currentString.pop_back();
    }
}

int main()
{
//    string str1, str2;
//    cout << "Enter string1 string: ";
//    cin >> str1;
//
//    cout << "Enter string2 string: ";
//    cin >> str2;

//    findAllStrings(0, 0, str1, str2, "");
    string str1="AB",str2="CD";
    findAllStrings(0, 0,str1,str2,"");

    return 0;
}
