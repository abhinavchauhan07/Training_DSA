//i) Write a method Boolean isValidSudoku(int[][]Sudoku)
//Returns true if the given Sudoku is correctly arranged otherwise false
//Write a method Boolean isValidSudoku(int[][]Sudoku)Returns true if the given Sudoku is correctly arranged otherwise false
//Determine if a 9 x 9 The Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
//Each row must contain the digits 1-9 without repetition.
//Each column must contain the digits 1-9 without repetition.
//Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
#include<iostream>
#include<vector>
#include<set>
using namespace std;

//this boolean function will return true if all the elements in the column are distinct
bool check_in_column(vector<vector<string>>board,int col)
{
    set<string>s;
    for(int row_index=0;row_index<board.size();row_index++)
    {
//        int temporary_variable=board[row_index][col]-'0';
        if(s.find(board[row_index][col])!=s.end() )
            return false;
        if(board[row_index][col]!=".")
            s.insert(board[row_index][col]);
    }
    return true;
    
}
//this boolean function will return true if all the elements in the row are distinct
bool check_in_row(vector<vector<string>>board,int row)
{
    set<string>s;
    for(int col_indx=0;col_indx<board.size();col_indx++)
    {
        if(s.find(board[row][col_indx])!=s.end())
            return false;
        if(board[row][col_indx]!=".")
            s.insert(board[row][col_indx]);
    }
    return true;
    
}
//this boolean function will return true if all the elements in the grids are distinct
bool check_in_grid(vector<vector<string>>board,int row,int col)
{
    set<string>s;
    for(int row_indx=0;row_indx<3;row_indx++)
    {
        for(int col_indx=0;col_indx<3;col_indx++)
        {
            string temp=board[row_indx+row][col_indx+col];
            if(s.find(temp)!=s.end())
                return false;
            if(temp!=".")
                s.insert(temp);
            
        }
    }
    return true;
    
}
bool isValidSudoku(vector<vector<string>>board)
{
    for(int row=0;row<board.size();row++)
    {
        for(int col=0;col<board.size();col++)
        {
//
               
if(!check_in_row(board, row) || !check_in_column(board, col) || !check_in_grid(board,row-row%3,col-col%3))return false;
        }
    }
    return true;
}
int main()
{
    vector<vector<string>>board{{"5","5",".",".","7",".",".",".","."},
        {"6",".",".","1","9","5",".",".","."},
        {".","9","8",".",".",".",".","6","."},
        {"8",".",".",".","6",".",".",".","3"},
        {"4",".",".","8",".","3",".",".","1"},
        {"7",".",".",".","2",".",".",".","6"},
        {".","6",".",".",".",".","2","8","."},
        {".",".",".","4","1","9",".",".","5"},
        {".",".",".",".","8",".",".","7","9"}};

    
    
    
    
    vector<vector<string>>board1{{"8","3",".",".","7",".",".",".","."},
    {"6",".",".","1","9","5",".",".","."},
      {".","9","8",".",".",".",".","6","."},
        {"8",".",".",".","6",".",".",".","3"},
          {"4",".",".","8",".","3",".",".","1"},
            {"7",".",".",".","2",".",".",".","6"},
              {".","6",".",".",".",".","2","8","."},
                {".",".",".","4","1","9",".",".","5"},
                {".",".",".",".","8",".",".","7","9"}};
    cout<<isValidSudoku(board)<<endl;
    
    
    return 0;
}
