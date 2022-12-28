#include <iostream>
#include <vector>
using namespace std;

void printSuduku(vector<vector<int>> problem)
{
    for (int i = 0; i < problem.size(); i++)
    {
        if (i % 3 == 0 and i != 0)
        {
            cout << "- - - - - - - - - - -" << endl;
        }
        for (int j = 0; j < problem[0].size(); j++)
        {
            if (j % 3 == 0 and j != 0)
            {
                cout << "| ";
            }
            cout << problem[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValidPos(vector<vector<int>> problem, int row, int col, int numberToCheak)
{
    for (int i = 0; i < 9; i++)
    {
        if (problem[row][i] == numberToCheak)
            return false;
        if (problem[i][col] == numberToCheak)
            return false;
        if (problem[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == numberToCheak)
            return false;
    }
    return true;
}

bool isValidSuduku(vector<vector<int>> &problem)
{
    for (int row = 0; row < problem.size(); row++)
    {
        for (int col = 0; col < problem[0].size(); col++)
        {
            if (!problem[row][col])
            {
                for (int numberToCheak = 0; numberToCheak <= 9; numberToCheak++)
                {
                    if (isValidPos(problem, row, col, numberToCheak))
                    {
                        problem[row][col] = numberToCheak;
                        if (isValidSuduku(problem))
                        {
                            return true;
                        }
                        else
                        {
                            problem[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> problem = {
        {0, 0, 0, 5, 0, 0, 0, 8, 7},
        {7, 0, 8, 0, 0, 0, 0, 0, 0},
        {9, 5, 3, 0, 0, 0, 0, 0, 6},
        {0, 0, 2, 3, 7, 0, 0, 0, 0},
        {0, 9, 0, 6, 0, 5, 0, 2, 0},
        {0, 0, 0, 0, 8, 9, 7, 0, 0},
        {5, 0, 0, 0, 0, 0, 9, 7, 1},
        {0, 0, 0, 0, 0, 0, 8, 0, 2},
        {8, 1, 0, 0, 0, 2, 0, 0, 0}};
    cout << "Bfore solving suduku : " << endl;
    printSuduku(problem);
    if (isValidSuduku(problem))
    {
        cout << "Your suduku was solved" << endl;
    }
    else
    {
        cout << "Your suduku could not solved" << endl;
    }
    cout << endl
         << "After solving suduku : " << endl;
    printSuduku(problem);
}
