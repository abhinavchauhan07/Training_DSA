//ii) Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. The function should find all triplets in the array that sum up to the target sum and return a two-dimensional array of all these triplets. The numbers in each triplet should be ordered in ascending order, and the triplets themselves should be ordered in ascending order with respect to the numbers they hold. If no three numbers sum up to the target sum, the function should return an empty array.

#include<iostream>
#include<vector>
#include<set>
using namespace std;

bool check_distinct_integers(vector<int>array)
{
    set<int>s;
    for(int index=0;index<array.size();index++)
    {
        //if the element is already present in the array
        if(s.find(array[index])!=s.end())
            return false;
        s.insert(array[index]);
    }
    return true;
}

vector<vector<int>>finding_triplets(vector<int>&array,int target)
{
    //container to add all the possible triplets
    vector<vector<int>>triplets_array;
    
    //if the size of the array is less than 3 return the empty 2-D matrix
    if(array.size()<3)return triplets_array;
    
    //sort all the elements in the array
    sort(array.begin(),array.end());
    
    for(int first_triplet_index=0;first_triplet_index<array.size();first_triplet_index++)
    {
        //subtracting the current value at first_triplet_index to find out the remainig_target
        int remaining_target=target-array[first_triplet_index];
        
        //second_triplet_index here is treated as low in two pointer algorithm
        int second_triplet_index=first_triplet_index+1;
        
        //third_triplet_index here is treated as high in two pointer algorithm
        int third_triplet_index=array.size()-1;
        while(second_triplet_index<third_triplet_index)
        {
            //if the sum of the low and high pointers is greater than the remaining target
            //decrease the high pointer(third_triplet_index)
            if(array[second_triplet_index]+array[third_triplet_index]>remaining_target)
                third_triplet_index--;
            //if the sum of the low and high pointers is smaller than the remaining target
            //increase the low pointer(second_triplet_index)
            else if (array[second_triplet_index]+array[third_triplet_index]<remaining_target)
                second_triplet_index++;
            //if the sum of the low and high pointers is equal to the remaining target
            //add it into the triplets_array and increase the low pointer(second_triplet_index) and decrease the high pointer(third_triplet_index)
            else{
                triplets_array.push_back({array[first_triplet_index],array[second_triplet_index],array[third_triplet_index]});
                second_triplet_index++;
                third_triplet_index--;
                
            }
        }
    }
    //return all the triplets found
    return triplets_array;
}

int main()
{
    
    int size_of_array;
    cout<<"Enter the size of the array"<<endl;
    cin>>size_of_array;
    vector<int>array(size_of_array);//declaring the array of size provided by the user
    
    // if the array size is zero print array is empty and end the program
    if(array.size()==0)
    {
        cout<<"Array is empty"<<endl;
        return 0;
    }
    //take input in the array
    for(int index=0;index<size_of_array;index++)
    {
        cin>>array[index];
    }
    //checking for the distinct elements in the array
    if(!check_distinct_integers(array))
    {
        cout<<"Duplicates found"<<endl;
        return 0;
    }
    
    //declaring and taking target as input
    int target;
    cout<<"Enter the target"<<endl;
    cin>>target;
    
    //calling the function finding_triplets
    vector<vector<int>>triplets=finding_triplets(array, target);
    for(int row=0;row<triplets.size();row++)
    {
            cout<<triplets[row][0]<<" "<<triplets[row][1]<<" "<<triplets[row][2];
        cout<<endl;
    }
    
    
    return 0;
}
