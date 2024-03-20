//i)Write a program to remove duplicate values from an array and returns an array of unique values. int[] removeDuplicates(int[]values)


#include<iostream>
#include<vector>
using namespace std;

vector<int> remove_duplicates(vector<int>&array)
{
    unordered_map<int,int>map;
    vector<int>temporary_container;
    for(int index=0;index<array.size();index++)
    {
        if(map[array[index]]==0)
            temporary_container.push_back(array[index]);
        map[array[index]]++;
    }
    array=temporary_container;
    return array;
}


int main()
{

    int size_of_array;
    cin>>size_of_array;
    vector<int>array(size_of_array);
    for(int index=0;index<size_of_array;index++)
    {
        cin>>array[index];
    }
    remove_duplicates(array);
    for(auto iterator:array)
        cout<<iterator<<" ";
    
    return 0;
}
