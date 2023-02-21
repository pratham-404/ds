#include <bits/stdc++.h>

#define ll long long int

using namespace std;

// Approach 1 => if all the matrix values are positive
// we traverse across the matrix, whenever we encounter '0' we replace the complete row & column with -1 and while traversing through the row or column if we encounter 0 then we leave it as it is, after traversal through the matrix we replace all the -1 with 0
// Time -> O(n*m*(n+m)), Space -> O(1)
void setZeroes1(vector<vector<int>> &matrix)
{
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                for(int k = 0; k < matrix.size(); k++)
                {
                    if(matrix[k][j] != 0)
                    {
                        matrix[k][j] = -1;
                    }
                }

                for(int k = 0; k < matrix[0].size(); k++)
                {
                    if(matrix[i][k] != 0)
                    {
                        matrix[i][k] = -1;
                    }
                }
            }
        }
    }

    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }   
}

// Approach 2 => maintain 2 seperate arrays for rows and columns
// Time -> O(n*m), Space -> O(n+m)
void setZeroes2(vector<vector<int>> &matrix)
{
    int r = matrix.size(), c = matrix[0].size();
    int row[r] = {}, column[c] = {};

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(matrix[i][j] == 0)
            {
                row[i] = 1;
                column[j] = 1;
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        if(row[i] == 1)
        {
            for (int j = 0; j < c; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < c; i++)
    {
        if (column[i] == 1)
        {
            for (int j = 0; j < r; j++)
            {
                matrix[j][i] = 0;
            }   
        } 
    }
}

// Approach 3 => Optimal Approach (using flag and first row & column to implement Approach 2)
// Time -> O(n*m), Space -> O(1)
void setZeroes3(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    bool row = false, col = false;

    if(matrix[0][0] == 0)
    {
        row = true;
        col = true;
    }
    else
    {
        for(int i = 1; i < m; i++)
        {
            if(matrix[i][0] == 0)
            {
                col = true;
                break;
            }
        }

        for(int i = 1; i < n; i++)
        {
            if(matrix[0][i] == 0)
            {
                row = true;
                break;
            }
        }
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int i = 1; i < m; i++)
    {
        if(matrix[i][0] == 0)
        {
            for (int j = 1; j < n; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (matrix[0][i] == 0)
        {
            for (int j = 1; j < m; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }

    if(row)
    {   
        for (int i = 0; i < n; i++)
        {
            matrix[0][i] = 0;
        }
    }
    if(col)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }
    
    return;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix;
    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            temp.push_back(t);
        }
        matrix.push_back(temp);
    }

    // setZeroes1(matrix);
    // setZeroes2(matrix);
    setZeroes3(matrix);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}