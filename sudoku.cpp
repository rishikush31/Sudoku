#include <bits/stdc++.h>
using namespace std;
#define UNDEF 0
#define N 9
bool unass_loc(int matrix_sud[N][N], int &horizontal, int &vertical);
bool sade(int matrix_sud[N][N], int horizontal,int vertical, int number);
bool solve_s(int matrix_sud[N][N])
{
    int horizontal, vertical;
    if (!unass_loc(matrix_sud, horizontal, vertical))
    {
        return true;
    }
    for (int number = 1; number <= 9; number++)
    {
        if (sade(matrix_sud, horizontal, vertical, number))
        {
            matrix_sud[horizontal][vertical] = number;
            if (solve_s(matrix_sud))
            {
                return true;
            }
            matrix_sud[horizontal][vertical] = UNDEF;
        }
    }

    return false;
}
bool unass_loc(int matrix_sud[N][N], int &horizontal, int &vertical)
{
    for (horizontal = 0; horizontal < N; horizontal++)
    {
        for (vertical = 0; vertical < N; vertical++)
        {
            if (matrix_sud[horizontal][vertical] == UNDEF)
            {
                return true;
            }
        }
    }
    return false;
}
bool UsedInRow(int matrix_sud[N][N], int horizontal, int number)
{
    for (int vertical = 0; vertical < N; vertical++)
    {
        if (matrix_sud[horizontal][vertical] == number)
        {
            return true;
        }
    }
    return false;
}

/* Returns a boolean which indicates whether
an assigned entry in the specified column
matches the given number. */
bool UsedInCol(int matrix_sud[N][N], int vertical, int number)
{
    for (int horizontal = 0; horizontal < N; horizontal++)
    {
        if (matrix_sud[horizontal][vertical] == number)
        {
            return true;
        }
    }
    return false;
}
bool UsedInBox(int matrix_sud[N][N], int boxStartRow,
               int boxStartCol, int number)
{
    for (int horizontal = 0; horizontal < 3; horizontal++)
    {
        for (int vertical = 0; vertical < 3; vertical++)
        {
            if (matrix_sud[horizontal + boxStartRow][vertical + boxStartCol] == number)
            {
                return true;
            }
        }
    }
    return false;
}
bool sade(int matrix_sud[N][N], int horizontal,
            int vertical, int number)
{
    return !UsedInRow(matrix_sud, horizontal, number) && !UsedInCol(matrix_sud, vertical, number) && !UsedInBox(matrix_sud, horizontal - horizontal % 3, vertical - vertical % 3, number) && matrix_sud[horizontal][vertical] == UNDEF;
}
void printGrid(int matrix_sud[N][N])
{
    for (int horizontal = 0; horizontal < N; horizontal++)
    {
        for (int vertical = 0; vertical < N; vertical++)
        {
            cout << matrix_sud[horizontal][vertical] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int matrix_sud[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> matrix_sud[i][j];
        }
    }
    if (solve_s(matrix_sud) == true)
    {
        printGrid(matrix_sud);
    }
    else
    {
        cout << "No solution exists";
    }
    return 0;
}