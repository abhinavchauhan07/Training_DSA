//question3: Write an efficient algorithm that searches for a value in a m x n matrix. This matrix has the following properties:
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row
/*
 MARK: matrixSearch is a function that searches for a value in a m x n matrix having Integers in each row are sorted from left to right and the first integer of each row is greater than the last integer of the previous row .
 
 DESC:matrixSearch(vector<vector<int>>matrix,int target)will searches for the target and will return   true is element is found otherwise false.
 
 PARAM:matrixSearch(vector<vector<int>>matrix,int target)will takes the matrix as input.
 
 RETURN:matrixSearch(vector<vector<int>>matrix,int target)is a boolean function that will return true    is element is found otherwise false;
 
 */
#include<iostream>
using namespace std;
bool matrixSearch(vector<vector<int>>matrix,int target)
{
    int rowSize=matrix.size();
    int colSize=matrix[0].size();
    int row=0,col=colSize-1;//taking the first row last column for starting the search
    while(row<rowSize && col>=0)
    {
        if(matrix[row][col]==target)//if the element is found return true
        {
            return true;
        }
        else if(matrix[row][col]>target)//if the target is smaller than decrease the column
            col--;
        else    //if the target is greater than increase the row 
            row++;
        
    }
    
return false;
}
int main()
{
    vector<vector<int>>matrix{{1,3,5,7},
                            {10,11,16,20},
                            {23,30,34,60}};
    int target=61;
    if(matrixSearch(matrix,target))
        cout<<"Element Found"<<endl;
    else
        cout<<"Element Not Found"<<endl;
    
    
//    int sizeOfMatrix;
//    cout<<"enter the size of the matrix"<<endl;
//    cin>>sizeOfMatrix;
//    vector<vector<int>>matrixx(sizeOfMatrix,vector<int>(sizeOfMatrix));
//    for(int row=0;row<sizeOfMatrix;row++)
//        for(int col=0;col<sizeOfMatrix;col++)
//            cin>>matrixx[row][col];
    return 0;
}
