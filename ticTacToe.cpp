#include<iostream>
#include<vector>
#include<random>
using namespace std;

/*
 MARK:  TIC TAC TOE game on console in 3*3 board with AI.
 DESC:  bool checkMove check whether the position is blank or not
        bool checkMoveBoundaries check whether the input is valid for 3*3 board or not
        bool winner checks whether the given palyer mark is winner or not
        printBoard prints the tic tac board
        playerMove determines the player move on the board
        aiMove determines the ai strategic move which includes three conditions
        - firstly aiMove checks for each of the blank position for it to win and return
        -second it checks for the position to block player stop player from winning
        -third it plays a random move
        checkBoardFull checks whether there is any chance for move
        playerFirst function gives the player the first chance to start its move
        aiFirst function gives the computer to take the first move
 PARAM:bool checkMove takes the board as parameter
       bool checkMoveBoundaries takes the row and column as parameter for validation of board limits
       bool winner takes the board and the player sign
       printBoard takes the board as a parameter
       playerMove takes the board and the player sign
       aiMove  takes the board and the player sign
       checkBoardFull  takes the board as a parameter
       playerFirst function takes the board and the player sign as a parameter
       aiFirst function takes the board and the player sign
 */

bool checkMove(vector<vector<char>>&board,int row,int col)
{
    //checks if the current row and col on the board is blank or not
    if(board[row][col]==' ')
    {
        return true;
    }
    return false;
}

bool checkMoveBoundaries(int row,int col)
{
    //checks if the current row and col on the board is valid or not
    if(row>=0 && col>=0 && row<3 && col<3 )return true;
    return false;
}

bool winner(vector<vector<char>>&board, char playerMark)
{
    for(int index=0;index<3;index++)
    {
        //check for the rows to decide winner
        if(board[index][0]==playerMark && board[index][1]==playerMark && board[index][2]==playerMark)
            return true;
        //check for the columns to decide winner
        if(board[0][index]==playerMark && board[1][index]==playerMark && board[2][index]==playerMark)return true;
     }
        // check for the diagonals to decide winner
        if(board[0][0]==playerMark && board[1][1]==playerMark && board[2][2]==playerMark)
            return true;
        if(board[0][2]==playerMark && board[1][1]==playerMark && board[2][0]==playerMark)
            return true;
    return false;
}
void printBoard(vector<vector<char>>&board)
{
    //print the board for the player
    for(int row=0;row<board.size();row++)
    {
        for(int col=0;col<board.size();col++)
        {
            cout<<" "<<board[row][col]<<" ";
            if(col<2)
                cout<<" | ";
        }
        cout<<endl;
        if(row<2)
        cout<<"----------------"<<endl;
    }
    
}
void playerMove(vector<vector<char>>&board,char playerSign,char aiSign)
{
    //takes the player move input
    int row,col;
        cout<<"Enter the row and column from 0 to 2"<<endl;
        cin>>row>>col;
    //validates the boundaries
    while(!checkMoveBoundaries(row, col))
    {
        cout<<"Invalid row and column: Enter row and column from 0-2"<<endl;
        cin>>row>>col;
    }
    //validates the move
    while(!checkMove(board, row, col))
    {
        cout<<"This box is taken! Choose another box"<<endl;
        cin>>row>>col;
        
    }//if the current row and col on the board is blank then play the move for the player
        if(board[row][col]==' '){
            board[row][col]=playerSign;
        }
        
}

void aiMove(vector<vector<char>>&board,char playerSign,char aiSign)
{
    // the ai strategic move  includes three conditions
    //firstly aiMove checks for each of the blank position for it to win
    
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            if(board[row][col]==' ')
            {
                
                board[row][col]=aiSign;
                if(winner(board,aiSign))
                    return;
                board[row][col]=' ';
            }
            
        }
    }
    //second it checks for the position to block the player to stop player from winning
    //block player moves
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            if(board[row][col]==' ')
            {
                board[row][col]=playerSign;
                //check if the player can win by playing move at this row and col on board
                if(winner(board,playerSign))
                {
                    board[row][col]=aiSign;
                    return;
                }
                board[row][col]=' ';
            }
        }
    }
//   third it plays a random move

    int randomRow=rand()%3,randomCol=rand()%3;;
    while(board[randomRow][randomCol]!=' '){
        randomRow=rand()%3;
        randomCol=rand()%3;
    }
    board[randomRow][randomCol]=aiSign;
    
}

bool checkBoardFull(vector<vector<char>>&board)
{
    //checks whether there is any blank space left on the board
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            if(board[row][col]==' ')
                return false;
        }
    }
    return true;
}
void aifirst(vector<vector<char>>&board,char playerSign,char aiSign)
{
    //till the game ends
    while(1){
        cout<<endl;
        aiMove(board,playerSign,aiSign);
        cout<<"AI move on the board"<<endl;
//        print the board
        printBoard(board);
        if(winner(board, aiSign)){
            cout<<"You loose!!! "<<endl;
            break;
        }
        //check if the board is full or not
        if(checkBoardFull(board))
        {
            cout<<"Draw!"<<endl;
            break;
        }
        //player move
        playerMove(board,playerSign,aiSign);
        cout<<"Your Move on the board"<<endl;
        //print the board
        printBoard(board);
        cout<<endl;
        //if players win
        if(winner(board,playerSign))
        {
            cout<<"You Win!!!"<<endl;
            break;
        }
        //if there is a tie
        if(checkBoardFull(board))
        {
            cout<<"Draw!"<<endl;
            break;
        }
        
        
    }
}
void playerFirst(vector<vector<char>>&board,char playerSign,char aiSign)
{
    //print the board
    printBoard(board);
    //till the game ends
    while(1){
        cout<<endl;
        //play the player move
        playerMove(board,playerSign,aiSign);
        cout<<"Your Move on the board"<<endl;
        //print the board
        printBoard(board);
        cout<<endl;
        if(winner(board,playerSign))
        {
            cout<<"You Win!!!"<<endl;
            break;
        }
        if(checkBoardFull(board))
        {
            cout<<"Draw!"<<endl;
            break;
        }
        
        aiMove(board,playerSign,aiSign);
        cout<<"AI move on the board"<<endl;
        printBoard(board);
        cout<<endl;
        //if ai wins
        if(winner(board,aiSign)){
            cout<<"You loose!!! "<<endl;
            break;
        }//if game ties
        if(checkBoardFull(board))
        {
            cout<<"Draw!"<<endl;
            break;
        }
    }
    
}
int main()
{
    vector<vector<char>>board(3,vector<char>(3,' '));
    cout<<"lets start the game"<<endl;
    

    char playerSign;//symbol of player
    char aiSign;//symbol of ai
    char newGame='Y';
    while(newGame=='Y')
    {
        cout<<"Welcome to Tic Tac Toe "<<endl;
        cout<<"choose your move sign bewtween X or 0"<<endl;
        cin>>playerSign;
        //if the input is invalid
        while(playerSign!='X' && playerSign!='0')
        {
            cout<<"Invalid sign: choose X or 0 "<<endl;
            cin>>playerSign;
        }
        //assigning symbol to player and to ai
        if(playerSign=='X')
            aiSign='0';
        else
            aiSign='X';
        
        cout<<"Do you want to play first chance: Y/N(yes or No)"<<endl;
        char chance;
        cin>>chance;
        //if the input is invalid
        while(chance!='Y' && chance!='N')
        {
            cout<<"Invalid input: choose Y or N "<<endl;
            cin>>chance;
        }
        if(chance=='Y')
        playerFirst(board,playerSign,aiSign);
        else
            aifirst(board, playerSign,aiSign);
        
        cout<<endl;
        cout<<"Do you want to play again Y for yes and N for No:"<<endl;
        cin>>newGame;
        //if the input is invalid
        while(newGame!='Y'&& newGame!='N')
        {
            
            cout<<"Invalid input: Enter the valid choice"<<endl;
            cin>>newGame;
        }
        //clear the board for next game
        board={{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};
        
    }
    
    return 0;
}






























    









