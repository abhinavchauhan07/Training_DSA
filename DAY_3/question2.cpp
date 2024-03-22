/* Question 2
Write a method Boolean isKingSafe(int[][]chessBoard)
Returns true if king in the given chess board is safe from the given enemies otherwise false;
NOTE: Enemies are- Horse, Camel, Queen, Elephant only
Do not consider the colour case of the chess board for traversal of camel and all.
*/

/*
 MARK:  program is used to find that if the king in the given chess board is safe from the given enemies(Horse, Camel, Queen, Elephant) or not
 DESC:  bool checkForHorse()
           It is checking whether the king is safe from the enemy horse
       
        bool checkForElephant()
        It is checking whether the king is safe from the enemy Elephant
 
        bool checkForQueen()
        It is checking whether the king is safe from the enemy QUeen
 
        bool checkForCamel()
        It is checking whether the king is safe from the enemy camel
 
            
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
 
 RETURN:bool check
        bool checkForCamel()
        it return is king is safe or not from camel in boolean value
 
        bool checkForQueen()
        it return is king is safe or not from queen in boolean value
 
        bool checkForElephant()
        it return is king is safe or not from elephantin boolean value
 
        bool checkForHorse()
        it return is king is safe or not from horse in boolean value
 */

#include <iostream>
using namespace std;

int kingRow=-1, kingCol=-1, horseRow=-1, horseCol=-1, camelRow=-1, camelCol=-1, queenRow=-1, queenCol=-1, elephantRow=-1, elephantCol=-1;

bool checkForHorse()
{
    // upper left1
    if ((horseRow - 2 >= 0 and horseCol - 1 >= 0) and (horseRow - 2 == kingRow and horseCol - 1 == kingCol))
        return false;
    // Upper right1
    else if ((horseRow - 2 >= 0 and horseCol + 1 < 8) and (horseRow - 2 == kingRow and horseCol + 1 == kingCol))
        return false;
    // Lower left1
    else if ((horseRow + 2 < 8 and horseCol - 1 >= 0) and (horseRow + 2 == kingRow and horseCol - 1 == kingCol))
        return false;
    // Lower right1
    else if ((horseRow + 2 < 8 and horseCol + 1 < 8) and (horseRow + 2 == kingRow and horseCol + 1 == kingCol))
        return false;

    // Upper left2
    else if ((horseRow - 1 >= 0 and horseCol - 2 >= 0) and (horseRow - 1 == kingRow and horseCol - 2 == kingCol))
        return false;
    // Upper right2
    else if ((horseRow - 1 >= 0 and horseCol + 2 < 8) and (horseRow - 1 == kingRow and horseCol + 2 == kingCol))
        return false;
    // Lower left2
    else if ((horseRow + 1 < 8 and horseCol - 2 >= 0) and (horseRow - 1 == kingRow and horseCol + 2 == kingCol))
        return false;
    // Lower right2
    else if ((horseRow + 1 < 8 and horseCol + 2 < 8) and (horseRow + 1 == kingRow and horseCol + 2 == kingCol))
        return false;
    else
        return true;
}

bool checkForCamel(int rowCamel, int colCamel)
{

    // Checking for upper left diagonal
    for (int currRow = rowCamel, currCol = colCamel; currRow >= 0 and colCamel >= 0; currRow--, currCol--)
    {
        if ((currRow == horseRow and currCol == horseCol) or (currRow == elephantRow and currCol == elephantCol))
            break;
        if (currRow == kingRow and currCol == kingCol)
            return false;
    }
    // Checking for lower left diagonal
    for (int currRow = rowCamel, currCol = colCamel; currRow < 8 and colCamel >= 0; currRow++, currCol--)
    {
        if ((currRow == horseRow and currCol == horseCol) or (currRow == elephantRow and currCol == elephantCol))
            break;
        if (currRow == kingRow and currCol == kingCol)
            return false;
    }

    // Checking for upper right diagonal
    for (int currRow = rowCamel, currCol = colCamel; currRow >= 0 and colCamel < 8; currRow--, currCol++)
    {
        if ((currRow == horseRow and currCol == horseCol) or (currRow == elephantRow and currCol == elephantCol))
            break;
        if (currRow == kingRow and currCol == kingCol)
            return false;
    }
    // Checking for lower right diagonal
    for (int currRow = rowCamel, currCol = colCamel; currRow < 8 and colCamel < 8; currRow++, currCol++)
    {
        if ((currRow == horseRow and currCol == horseCol) or (currRow == elephantRow and currCol == elephantCol))
            break;
        if (currRow == kingRow and currCol == kingCol)
            return false;
    }

    return true;
}

bool checkForElephant(int rowElephant, int colElephant)
{

    // Checking for the column
    if (colElephant == kingCol)
    {
        // checking the lower column
        for (int currRow = rowElephant; currRow < 8; currRow++)
        {
            // if piece is in between king and elephant
            if ((currRow == horseRow and colElephant == horseCol) or (currRow == camelRow and colElephant == camelCol))
                break;
            if (currRow == kingRow)
                return false;
        }

        // checking the upper column
        for (int currRow = rowElephant; currRow >= 0; currRow--)
        {
            // if piece is in between king and elephant
            if ((currRow == horseRow and colElephant == horseCol) or (currRow == camelRow and colElephant == camelCol))
                break;

            if (currRow == kingRow)
                return false;
        }
    }

    // Checking for the row
    if (rowElephant == kingRow)
    {
        // checking the left row
        for (int currCol = colElephant; currCol >= 0; currCol--)
        {
            if ((rowElephant == horseRow and currCol == horseCol) or (rowElephant == camelRow and currCol == camelCol))
                break;

            if (currCol == kingCol)
                return false;
        }

        // checking the right row
        for (int currCol = colElephant; currCol < 8; currCol++)
        {
            if ((rowElephant == horseRow and currCol == horseCol) or (rowElephant == camelRow and currCol == camelCol))
                break;

            if (currCol == kingCol)
                return false;
        }
    }

    return true;
}

bool checkForQueen()
{
     
    if (checkForCamel(queenRow, queenCol) and checkForElephant(queenRow, queenCol))
        return true;

    return false;
}

int main()
{
    vector<vector<int>>chessBoard{{0,0,0,7,0,0,0,0},
                                  {0,1,0,0,0,0,0,0},
                                  {0,0,3,0,0,0,0,0},
                                  {0,0,0,0,0,0,0,0},
                                  {0,0,0,0,0,0,0,0},
                                  {0,0,0,0,0,0,0,0},
                                  {0,0,0,0,0,0,0,0},
                                  {0,0,0,0,0,0,0,0}};
    bool KingFound=false;
    for(int row=0;row<8;row++)
    {
        for(int col=0;col<8;col++)
        {
            if(chessBoard[row][col]==7)
            {
                kingRow=row;
                kingCol=col;
                KingFound=true;
            }
            else if(chessBoard[row][col]==1)
            {
                horseRow=row;
                horseCol=col;
            }
            
            else if(chessBoard[row][col]==2)
            {
                camelRow=row;
                camelCol=col;
            }
            else if(chessBoard[row][col]==3)
            {
                queenRow=row;
                queenCol=col;
            }
            else if(chessBoard[row][col]==4)
            {
                elephantRow=row;
                elephantCol=col;
            }
        }
    }
        if(KingFound==false)
        {
            cout<<"king not found"<<endl;
            return 0;
        }

            bool isSafeFromHorse = checkForHorse();
    //
    //    // Checking for the Camel
    
            bool isSafeFromCamel = checkForCamel(camelRow, camelCol);
    //
    //    // Checking for the Elephant

            bool isSafeFromElephant = checkForElephant(elephantRow, elephantCol);
    //
    //    // Checking for Queen
            bool isSafeFromQueen = checkForQueen();
    
    //checking for all the conditions
        if (isSafeFromCamel && isSafeFromElephant && isSafeFromHorse && isSafeFromQueen)
            cout << "King is safe" << endl;
        else
            cout << "King is in danger" << endl;
    

    return 0;
}



   
