//i) Write down a method boolean isNameValid(String  name).
//A name is valid if following conditions are satisfied:
//• It does not contain any vowel more than once.
//• If the name contains two ‘S’, then there is not any ‘T’ in between them (both in capital cases).
 
#include<iostream>
using namespace std;

bool isNameValid(string  name) //returns true if the name is valid otherwise returns false
{
    unordered_map<char,int>check_vowels; // unordered_map to check the counts of vowels
    
    for(int index=0;index<name.length();index++)
    {
        if(check_vowels[name[index]]>0)return false;//if the vowel occurs more than one time
        else if(check_vowels[name[index]]==0) // if the vowel does not occur
        {
            if(name[index]=='S'&& index+1<name.length())//checking the second condition if T occurs between the two S
            {
                int temporary_index=index+1;
                int count_of_T=0;
                while(temporary_index<name.length())
                {
                    if(name[temporary_index]=='T')count_of_T++;
                    if(name[temporary_index]=='S')break;
                    temporary_index++;
                }
                if(count_of_T>0 && temporary_index!=name.length())return false;//if the T occurs then we will check if the count of T is more than one and it is not the last alphabet of the string  then it will return false
            }
        
        }
        if(name[index]=='a'|| name[index]=='e'|| name[index]=='i' || name[index]=='o' || name[index]=='u'||name[index]=='A'|| name[index]=='E'|| name[index]=='I' || name[index]=='O' || name[index]=='U') //checking for the vowels
            check_vowels[name[index]]++; //putting count of vowels in the map check_vowels
    }
    
    
    
    
    return true;
}
int main()
{
    string Name;
    cout<<"enter the Name"<<endl;
    getline(cin,Name);              //taking input as the name
    if(isNameValid(Name))       //if the name is valid then function isNameValid returns true and we will print true
        cout<<"TRUE"<<endl;
    else
        cout<<"FALSE"<<endl;//if the name is not valid then function isNameValid returns false and we will print false
    
    
    return 0;
}















//            if(name[index]=='T'&& name[index-1]=='S' )  //checking the second condition that T should not occur between two S
//            {
//                while(name[index]=='T')
//                    index++;
//                if(name[index]=='S')return false;
//
