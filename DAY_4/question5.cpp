//question5: You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
#include<iostream>
using namespace std;

/*
 MARK: program to rotate the image by 90 degrees (clockwise) an x n 2D matrix representing an image.
 
 DESC: swapNumbers(int number1,int number2)
       this function will swap two numbers
 
       rotate90Degrees(vector<vector<int>>matrix)
       this function will return the rotated image matrix by 90 degrees
 
 PARAM:swapNumbers(int number1,int number2)
       takes two input number for swapping them
 
       rotate90Degrees(vector<vector<int>>matrix)
       takes matrix(image)for roatation
 */
void swapNumbers(int &number1,int &number2)
{
    int temporaryVariable=number1;
    number1=number2;
    number2=temporaryVariable;
}
void rotate90Degrees(vector<vector<int>>&matrix)
{
    //these nested loops will do the transpose of the matrix
    for(int row=0;row<matrix.size();row++)
    {
        for(int col=0;col<row;col++)
        {
            swapNumbers(matrix[row][col],matrix[col][row]);
        }
    }
    
    // reversing the rows of the transpose matrix
    for(int row=0;row<matrix.size();row++)
    {
        int start=0,end=matrix.size()-1;
        while(start<end)
        {
            swapNumbers(matrix[row][start],matrix[row][end]);
            start++;
            end--;
        }
    }
    
}
void printMatrix(vector<vector<int>>matrix)
{
    for(int row=0;row<matrix.size();row++)
    {
        for(int col=0;col<matrix[0].size();col++)
        {
            cout<<matrix[row][col]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
     vector<vector<int>>matrix{{1,3,5},
                                {10,11,16},
                                {23,30,34}};
    rotate90Degrees(matrix);
    printMatrix(matrix);
    int sizeOfMatrix;
    cout<<"enter the size of the matrix"<<endl;
    cin>>sizeOfMatrix;
    vector<vector<int>>matrixx(sizeOfMatrix,vector<int>(sizeOfMatrix));
    for(int row=0;row<sizeOfMatrix;row++)
        for(int col=0;col<sizeOfMatrix;col++)
            cin>>matrixx[row][col];
        
        return 0;
    
}

