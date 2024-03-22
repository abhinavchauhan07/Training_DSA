/* Question 4
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are surrounded by water.
*/
#include <iostream>
#include<vector>
using namespace std;

// MARK:- Does the depth-first traversl in the given matrix
// DESC:- Visits all the elements in the all four directions and marks them true if they are valid and equal to 1
void dfsTraversal(int row, int col, vector<vector<int>> &matrix, vector<vector<bool>> &visited)
{
    // checking boundary conditions
    if (row < 0 or row >= matrix.size() or col < 0 or col >= matrix[0].size() or matrix[row][col] == 0 or visited[row][col] == true)
        return;

    visited[row][col] = true;

    // dfs for the upper row
    dfsTraversal(row - 1, col, matrix, visited);

    // dfs for the next row
    dfsTraversal(row + 1, col, matrix, visited);

    // dfs for the left col
    dfsTraversal(row, col - 1, matrix, visited);

    // dfs for the right col
    dfsTraversal(row, col + 1, matrix, visited);
}

/* MARK:- Calls the dfsTraversal method and returns the valid number of islands
DESC:- If the current element has not been visited , then calls the dfsTraversal method and increments the number of island by 1
 */
int findIslands(vector<vector<int>> &matrix, int rows, int cols)
{
    vector<vector<bool>> visitedArray(rows, vector<bool>(cols, false));
    int numOfIslands = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (visitedArray[i][j] == false and matrix[i][j] == 1)
            {
                dfsTraversal(i, j, matrix, visitedArray);
                numOfIslands++;
            }
        }
    }
    return numOfIslands;
}

int main()
{
    int rows;
    cout << "Enter the rows of matrix: ";
    cin >> rows;

    int cols;
    cout << "Enter the columns of matrix: ";
    cin >> cols;

    if (!(rows > 0 && cols > 0))
        cout << "Invalid dimensions!" << endl;
    else
    {
        vector<vector<int>> matrix(rows, vector<int>(cols));

        cout << "Enter the elements of the matrix" << endl;
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                cin >> matrix[row][col];
            }
    }
        cout<<"Number of islands are: "<< findIslands(matrix, rows, cols)<<endl;
    }
    
    return 0;
}

