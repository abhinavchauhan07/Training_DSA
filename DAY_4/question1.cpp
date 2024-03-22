//question1. Write a method void printArray(int[][]arr)
//Prints array elements clockwise and anti-clockwise alternatively.

/*
 MARK: printClockWise is a function that will print array elements clockwise and anti-clockwise alternatively.
 
 DESC:printClockWise(vector<vector<int>>pattern)will firstly print the array elements in clockwise     and then print the array elements in anti_clockwise
 
      printAntiClockWise(vector<vector<int>>pattern)will print the array elements in anti-clockwise
 
 PARAM: PrintClockWise(vector<vector<int>>pattern)will takes the matrix as input
        printAntiClockWise(vector<vector<int>>pattern)will takes the matrix as input
 
 */

#include<iostream>
#include<vector>
using namespace std;

void printClocWise(vector<vector<int>>pattern)
{
    int rowSize=pattern.size();
    int colSize=pattern[0].size();
    int top=0,bottom=rowSize-1,left=0,right=colSize-1;
    //this loop will print the matrix in the clockwise direction
    while(top<=rowSize && left<=colSize)
    {
        for(int col=left;col<=right;col++)
            cout<<pattern[top][col]<<" ";
        top++;
        for(int row=top;row<=bottom;row++)
            cout<<pattern[row][left]<<" ";
        left++;
        if(top<=bottom)
        {
            for(int col=left;col<=right;col++)
                cout<<pattern[bottom][col]<<" ";
            bottom--;
            
        }
        if(left<=right)
            for(int row=bottom ;row>=top;row--)
                cout<<pattern[row][left]<<" ";
        left++;
    }
}

void printAntiClockWise(vector<vector<int>>pattern)
{
    int rowSize=pattern.size();
    int colSize=pattern[0].size();
    int top=0,bottom=rowSize-1,left=0,right=colSize-1;
    
    //this loop will print the matrix in the Anti-clockwise direction
    while(top<=rowSize && right>=0)
    {
        for(int col=right;col>=left;col--)
            cout<<pattern[top][col]<<" ";
        top++;
        for(int row=top;row<=bottom;row++)
            cout<<pattern[row][left]<<" ";
        left++;
        if(top<=bottom)
        {
            for(int col=left;col<=right;col++)
                cout<<pattern[bottom][col]<<" ";
            bottom--;
            
        }
        if(left<=right)
            for(int row=bottom ;row>=top;row--)
                cout<<pattern[row][right]<<" ";
        right--;
    }
}

int main()
{
    vector<vector<int>>pattern{{1,2,3},
                                {4,5,6},
                               {7,8,9}};
    printClocWise(pattern);
    cout<<endl;
    printAntiClockWise(pattern);
    return 0;
}
