/* Question 2
Write a program to print all the possible combinations according to the input values.
Example :
Given Values
'1' : ['Z', 'Y', 'A'],
'2' : ['B', 'O'],
'12' : ['L']
'3' : ['U', 'P']
Input: 123
Output : [ZBU, ZBP, ZOU, ZOP, YBU, YBP, YOU, YOP, ABU, ABP, AOU, AOP, LU, LP]
*/
#include <iostream>
using namespace std;
/*
  MARK:  program to generate all the possible combinations
  DESC:  Takes all the values corresponding to a key and add to the current string and prints the          combinations of that string
  PARAM: possibleCombinations(string combination, int index, string combinationString, unordered_map<string, vector<char>> &values, string input)
         -string combination will takes all the possible combination from the map of corresponding values
         -int index is the iterator to the input
         -string combinationString generates all the combinations
         -values is the unordered_map
         -input is provided through which we have to generate combinations
        
        
*/
void possibleCombinations(string combination, int index, string combinationString, unordered_map<string, vector<char>> &values, string input)
{
    // checking the boundary condition
    if (index == input.length())
    {
        cout<<combinationString <<" ";
        return;
    }
    for (auto iterator : values[combination])
    {
        combinationString += iterator;
        if (index + 1 < input.size())
        {
            string newKey="";
            newKey+=input[index+1];
            possibleCombinations(newKey, index + 1, combinationString, values, input);
        }
        else
        {
            possibleCombinations("", index + 1, combinationString, values, input);
        }

        combinationString.pop_back();
    }
}

int main()
{
    unordered_map<string, vector<char>> values;
    values.insert({"1", {'Z', 'Y', 'A'}});
    values.insert({"2", {'B', 'O'}});
    values.insert({"12", {'L'}});
    values.insert({"3", {'U', 'P'}});
    
    string input = "12";
    

    string combination = "";
    for (int i = 0; i < input.size(); i++)
    {
        combination += input[i];
        possibleCombinations(combination, i, "", values, input);
    }
    cout << endl;
    return 0;
}
