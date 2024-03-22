
//ii) Write a method Boolean isKingSafe(int[][]chessBoard)
//Returns true if king in the given chess board is safe from the given enemies otherwise false;
//NOTE: Enemies are- Horse, Camel, Queen, Elephant only
//Do not consider the colour case of the chess board for traversal of camel and all.



#include <iostream>
#include <cmath>

using namespace std;

//bool check_Horse(vector<vector<char>>&chessboard,int row,int col)
//{
//    
//    
//    if(row+2>=0 && row<8 && col-1>=0 && col+2<8)
//    {
//        if(chessboard[row+2][col-1]=='K'|| chessboard[row+2][col+1]=='K')return false;
//    }
//    
//    if(row+1>=0 && row<8 && col-2>=0 && col+2<8)
//    {
//        if(chessboard[row+1][col-2]=='K'|| chessboard[row+1][col+2]=='K')return false;
//    }
//    
//    if(row-1>=0 && row<8 && col-2>=0 && col+2<8)
//    {
//        if(chessboard[row-1][col-2]=='K'|| chessboard[row-1][col+2]=='K')
//        return false;
//    }
//    
//    if(row-2>=0 && row-2<8 && col-1>=0 && col+1<8)
//    {
//        if(chessboard[row-2][col-1]=='K'||chessboard[row-2][col+1]=='K')
//            return false;
//    }
//    return true;
//}




// Function to check if the king is safe from the enemies
bool checkHorse(int kingRow, int kingCol,vector<vector<int>>&chessBoard)
{
    int horseRowsMoves[]={-2,-2,-1,-1,1,1,2,2};
    int horseColMoves[]={-1,1,-2,2,-2,2,-1,1};
    for(int row=0;row<8;row++)
    {
        int modifiedRow=kingRow+horseRowsMoves[row];
        int modifiedCol=kingCol+horseColMoves[row];
        if(modifiedRow>=0 && modifiedRow<8 && modifiedCol>=0 && modifiedCol<8 && chessBoard[modifiedRow][modifiedCol]==2)
            return false;
    }
    return true;
}
bool checkElephant(int kingRow, int kingCol,vector<vector<int>>&chessBoard)
{
    int elephantRowsMoves[]={-1,-1,1,1};
    int elephantColMoves[]={-1,1,-1,1};
    
    for(int row=0;row<4;row++)
    {
        int modifiedRow=kingRow+elephantRowsMoves[row];
        int modifiedCol=kingCol+elephantColMoves[row];
        if(modifiedRow>=0 && modifiedRow<8 && modifiedCol>=0 && modifiedCol<8 && chessBoard[modifiedRow][modifiedCol]==4)
            modifiedRow=modifiedRow+elephantRowsMoves[row];
            modifiedCol=modifiedCol+elephantColMoves[row];
            return false;
    }
    return true;
}
bool CheckQUeen(int king_row, int king_col,vector<vector<int>>&chessBoard)
{
    int queenRow[]={-1,-1,-1,0,0,1,1,1};
    int queenCol[]={-1,0,1,-1,1,-1,0,1};
    for(int row=0;row<8;row++)
    {
        int newRow=king_row+queenRow[row];
        int newCol=king_col+queenCol[row];
        while(newRow>=0 && newRow<8 && newCol>=0 && newCol<8)
        {
            if(chessBoard[newRow][newCol]==3)
                return false;
            if(chessBoard[newRow][newCol]!=0)
                break;
            newRow=newRow+queenRow[row];
            newCol=newCol+queenCol[row];
        }
    
    
    }
    return true;
}

bool checkCamel(int kingRow, int kingCol,vector<vector<int>>&chessBoard)
{
    
    int camelRowsMoves[]={-2,-2,2,2,-1,-1,1,1};
    int camelColMoves[]={1,-1,1,-1,2,-2,2,-2};
    
    for(int row=0;row<8;row++)
    {
        int modifiedRow=kingRow+camelRowsMoves[row];
        int modifiedCol=kingCol+camelColMoves[row];
        if(modifiedRow>=0 && modifiedRow<8 && modifiedCol>=0 && modifiedCol<8 && chessBoard[modifiedRow][modifiedCol]==1)
            return false;
    }
    return true;
    
}
//bool isKingSafe(vector<vector<int>>&chessBoard) {
//    int KingRow=-1,KingCol=-1;
//    int CamelRow=-1,CamelCol=-1;
//    int QueenRow=-1,QueenCol=-1;
//    int HorseRow=-1,HorseCol=-1;
//    int ElephantRow=-1,ElephantCol=-1;
//    bool KingFound=false;
//    for(int row=0;row<8;row++)
//    {
//        for(int col=0;col<8;col++)
//        {
//            if(chessBoard[row][col]==7)
//            {
//                KingRow=row;
//                KingCol=col;
//                KingFound=true;
//            }
//            
//        }
//    }
//    if(KingFound==false){
//        cout<<"King not found"<<endl;
//        return false;
//    }
////    bool camel=false,horse=false,queen=false,elephant=false;
////    if(CamelRow!=-1 && CamelCol!=-1)
////    {
////         camel= checkCamel(KingRow, KingCol, chessBoard);
////    }
////    if(HorseRow!=-1 && HorseCol!=-1)
////    {
////         horse= checkHorse(KingRow, KingCol,chessBoard);
////    }
////    if(QueenRow!=-1 && QueenCol!=-1)
////    {
////        queen= CheckQUeen(KingRow, KingCol, chessBoard);
////    }
////    if(ElephantCol!=-1 && ElephantRow!=-1)
////    {
////         elephant= checkElephant(KingRow,KingCol, chessBoard);
////    }
////    if(camel && horse && queen && elephant)
////        return true;
//    return (checkCamel(KingRow, KingCol, chessBoard));
//    
//    
////    return false;
//    
//}

    
    
    
    
    




bool isValidPosition(int row, int col)
{
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

bool isKingSafe(vector<vector<int>> &chessBoard)
{
    int kingRow = -1;
    int kingCol = -1;
    bool kingFound = false;

    // Find the position of the king
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (chessBoard[row][col] == 7)
            {
                kingRow = row;
                kingCol = col;
                kingFound = true;
                break;
            }
        }
        if (kingFound)
            break;
    }

    if (!kingFound)
    {
        return false;
    }

    // horse
    int horseDenomination = 2;
    int horseRow[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int horseCol[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int row = 0; row < 8; row++)
    {
        int newRow = kingRow + horseRow[row];
        int newCol = kingCol + horseCol[row];
        if (isValidPosition(newRow, newCol) && chessBoard[newRow][newCol] == 2)
        {
            return false;
        }
    }
    // Check for threats from queen
//    int queenDenomination = 3;
    int queenRowOffsets[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int queenColOffsets[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int row = 0; row < 8; row++)
    {
        int newRow = kingRow + queenRowOffsets[row];
        int newCol = kingCol + queenColOffsets[row];
        while (isValidPosition(newRow, newCol))
        {
            if (chessBoard[newRow][newCol] == 3)
            {
                return false;
            }
            if (chessBoard[newRow][newCol] != 0)
            {
                break;
            }
            newRow += queenRowOffsets[row];
            newCol += queenColOffsets[row];
        }
    }

    // Check for threats from elephant
//    int elephantDenomination = 4;
    int elephantRowOffsets[] = {-1, -1, 1, 1};
    int elephantColOffsets[] = {-1, 1, -1, 1};

    for (int row = 0; row < 4; row++)
    {
        int newRow = kingRow + elephantRowOffsets[row];
        int newCol = kingCol + elephantColOffsets[row];
        if (isValidPosition(newRow, newCol) && chessBoard[newRow][newCol] == 4)
        {
            return false;
        }
    }

    // If no threats found, king is safe
    return true;
}

int main()
{
    // Example usage:
    vector<vector<int>> chessBoard = {
        {6, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0} // Assuming king is at position (7,7)
    };
   
    if(isKingSafe(chessBoard))
        cout<<"King is safe"<<endl;
    else
        cout<<"king is in Danger"<<endl;
    
    return 0;
}
