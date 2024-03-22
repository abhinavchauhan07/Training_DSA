
//ii) Write a method Boolean isKingSafe(int[][]chessBoard)
//Returns true if king in the given chess board is safe from the given enemies otherwise false;
//NOTE: Enemies are- Horse, Camel, Queen, Elephant only
//Do not consider the colour case of the chess board for traversal of camel and all.

/*
 MARK:  program is used to find that if the king in the given chess board is safe from the given enemies(Horse, Camel, Queen, Elephant) or not
 DESC:  bool checkHorse(int king_row, int king_col,int enemyRow,int enemyCol)
           It is checking whether the king is safe from the enemy horse
       
        bool checkElephant(int king_row, int king_col,int enemyRow,int enemyCol)
        It is checking whether the king is safe from the enemy Elephant
 
        bool checkQueen(int king_row, int king_col,int enemyRow,int enemyCol)
        It is checking whether the king is safe from the enemy QUeen
 
        bool checkCamel(int king_row, int king_col,int enemyRow,int enemyCol)
 
        bool isKingSafe(vector<vector<int>>&chessBoard)
        validates the co-ordinates of the king and checking all the above boolean functions
            
 PARAM: bool checkHorse(int king_row, int king_col,int enemyRow,int enemyCol)
        King_row denotes the row of the king
        king_col denotes the column of the king
        enemyRow dentes the row of the Horse
        enemyCol denotes the column of the Horse
 
        
        bool checkElephant(int king_row, int king_col,int enemyRow,int enemyCol)
        King_row denotes the row of the king
        king_col denotes the column of the king
        enemyRow dentes the row of the Elephant
        enemyCol denotes the column of the Elephant

        bool checkQueen(int king_row, int king_col,int enemyRow,int enemyCol)
        King_row denotes the row of the king
        king_col denotes the column of the king
        enemyRow dentes the row of the Queen
        enemyCol denotes the column of the Queen
 
        bool checkCamel(int king_row, int king_col,int enemyRow,int enemyCol)
        King_row denotes the row of the king
        king_col denotes the column of the king
        enemyRow dentes the row of the camel
        enemyCol denotes the column of the camel
 
        bool isKingSafe(vector<vector<int>>&chessBoard)
        chessBoard refers to the board
 
 RETURN:bool isKingSafe(vector<vector<int>>&chessBoard)
        it return is king is safe or not from all the enemies in boolean value
 
        bool checkHorse(int king_row, int king_col,int enemyRow,int enemyCol)
        it return is king is safe or not in boolean value
 */

#include <iostream>
#include <cmath>

using namespace std;



bool checkHorse(int king_row, int king_col,int enemyRow,int enemyCol)
{
    int diagonalRow = abs(king_row - enemyRow);
    int diagonalCol = abs(king_col - enemyCol);
    return !((diagonalRow == 1 && diagonalCol == 2) || (diagonalRow == 2 && diagonalCol == 1));
}
// Check condition for the Elephant
bool checkElephant(int king_row, int king_col,int elephantRow,int elephantCol,int horseRow,int horseCol,int camelRow,int camelCol)
{
    if(elephantCol==king_col){
        for(int row=elephantRow;row<8;row++)
        {
            if((row==horseRow && elephantCol==horseCol) || (row==camelRow) && (elephantCol==camelCol))break;
            if(row==king_row)return false;
        }
        for(int row=elephantRow;row>=0;row--)
        {
            if((row==horseRow)&& (elephantCol==horseCol)||(row==camelRow) && (elephantCol==camelCol))break;
            if(row==king_row)
                return false;
        }
    }
    
    if(elephantRow==king_row)
    {
        for(int col=elephantCol;col<8;col++)
        {
            if((col==horseRow && col==horseCol) || (elephantRow==camelRow) && (col==camelCol))break;
            if(col==king_col)return false;
        }
        for(int col=elephantCol;col>=0;col--)
        {
            if((col==horseRow)&& (col==horseCol)||(elephantRow=camelRow) && (col==camelCol))break;
            if(col==king_row)
                return false;
        }
    }
    return true;
}
bool checkCamel(int king_row, int king_col,int enemyRow,int enemyCol)
{
    for(int row=)
    
    
    return true;
}
bool checkQueen(int king_row, int king_col,int elephantRow,int elephantCol,int horseRow,int horseCol,int camelRow,int camelCol)
{
//    int diagonalRow=abs(king_row-enemyRow);
//    int diagonalCol=abs(king_col-enemyCol);
//    if(king_row==enemyRow || king_col==enemyCol)
//        return false;
//    if(diagonalRow==diagonalCol)
//        return false;
//    
    return true;
}
// Check condition for the Camel


bool isKingSafe(vector<vector<int>>&chessBoard)
{
    int KingRow=-1,KingCol=-1;
    int CamelRow=-1,CamelCol=-1;
    int QueenRow=-1,QueenCol=-1;
    int HorseRow=-1,HorseCol=-1;
    int ElephantRow=-1,ElephantCol=-1;
    bool KingFound=false;
    for(int row=0;row<8;row++)
    {
        for(int col=0;col<8;col++)
        {
            if(chessBoard[row][col]==7)
            {
                KingRow=row;
                KingCol=col;
                KingFound=true;
            }
            else if(chessBoard[row][col]==1)
            {
                HorseRow=row;
                HorseCol=col;
            }
            
            else if(chessBoard[row][col]==2)
            {
                CamelRow=row;
                CamelCol=col;
            }
            else if(chessBoard[row][col]==3)
            {
                QueenRow=row;
                QueenCol=col;
            }
            else if(chessBoard[row][col]==4)
            {
                ElephantRow=row;
                ElephantCol=col;
            }
        }
    }
    if(KingFound==false){
        cout<<"King not found"<<endl;
        return false;
    }
    bool camel=false,horse=false,queen=false,elephant=false;
    if(CamelRow!=-1 && CamelCol!=-1)
    {
         camel= checkCamel(KingRow, KingCol, CamelRow, CamelCol);
    }
    if(HorseRow!=-1 && HorseCol!=-1)
    {
         horse= checkHorse(KingRow, KingCol, CamelRow, CamelCol);
    }
    if(QueenRow!=-1 && QueenCol!=-1)
    {
        queen= checkQueen(KingRow, KingCol, QueenRow,QueenCol);
    }
    if(CamelRow!=-1 && CamelCol!=-1)
    {
         elephant= checkElephant(KingRow, KingCol, CamelRow, CamelCol);
    }
    if(camel && horse && queen && elephant)
        return true;
    
    
    return false;
    
        
    
    
}

int main() {
    vector<vector<int>>chessBoard{{7,0,0,0,0,0,0,0},
                                  {0,2,0,0,0,0,0,0},
                                  {0,4,3,0,0,0,0,0},
                                  {0,0,0,0,0,0,0,0},
                                  {0,0,0,0,0,0,0,0},
                                  {0,0,0,0,0,0,0,0},
                                  {0,0,0,0,0,0,0,0},
                                  {0,0,0,0,0,0,0,0}};
    
    if(isKingSafe(chessBoard))
        cout<<"King is safe"<<endl;
    else
        cout<<"king is in Danger"<<endl;
    
    
//    int king_row, king_col;
//    cout << "Enter The postion of the king "<<endl;
//    cin >> king_row >> king_col;
//    
//    int Horse_row,Horse_col;
//    cout<<"Enter the position of the Horse"<<endl;
//    cin>>Horse_row>>Horse_col;
//    bool Horse=checkHorse(king_row, king_col, Horse_row, Horse_col);
//    
//    int Queen_row,Queen_col;
//    cout<<"Enter the position of the Queen"<<endl;
//    cin>>Queen_row>>Queen_col;
//    bool Queen=checkHorse(king_row, king_col, Queen_row, Queen_col);
//    
//    
//    int Camel_row,Camel_col;
//    cout<<"Enter the position of the Camel"<<endl;
//    cin>>Camel_row>>Camel_col;
//    bool Camel=checkHorse(king_row, king_col, Camel_row, Camel_col);
//    
//    int Elephant_row,Elephant_col;
//    cout<<"Enter the position of the Elephant"<<endl;
//    cin>>Elephant_row>>Elephant_col;
//    bool Elephant=checkHorse(king_row, king_col, Elephant_row, Elephant_col);
//    
//    
//    if(Horse && Queen && Camel && Elephant)
//        cout<<"King is safe"<<endl;
//    else
//        cout<<"king is in danger"<<endl;
//    
//    
//    
//    
    return 0;
}







//int main()
//{
//    vector<vector<char>>chess_board{
//        {'.','.','.','.','.','.','.','.'},
//        {'.','.','K','.','.','.','.','.'},
//        {'.','.','.','.','.','.','.','.'},    {1,2}     {3,4}
//        {'.','.','.','H','.','.','.','.'},
//        {'.','.','.','.','.','.','.','.'},
//        {'.','C','.','Q','.','.','.','.'},
//        {'.','.','.','.','.','.','.','E'},
//        {'.','H','.','.','.','.','H','.'}};
//
//
//
//    return 0;
//}

