#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void rightMove(int gameBoard[][4])
{
    int zeroCounter = 0;
    for (int row = 0; row < 4; row++) // Movement of all numbers to the right direction
    {
        for (int element = 3; element > -1; element--)
        {
            if (gameBoard[row][element] == 0)
            {
                zeroCounter++;
            }
            else if (zeroCounter != 0)
            {
                gameBoard[row][element+zeroCounter] = gameBoard[row][element];
                gameBoard[row][element] = 0;
                zeroCounter = 0;
            }
        }
        zeroCounter = 0;
    }

    for (int row = 0; row < 4; row++) // Combination of all same numbers
    {
        for (int element = 3; element > 0; element--) // Actual combination of numbers
        {
            if (gameBoard[row][element] == gameBoard[row][element-1] && gameBoard[row][element] != 0)
            {
                gameBoard[row][element] = gameBoard[row][element]*2;
                gameBoard[row][element-1] = 0;
            }
        }

        if (gameBoard[row][3] != 0 && gameBoard[row][1] != 0 && gameBoard[row][2] == 0) //Movement of numbers if there is an empty gap
        {
            gameBoard[row][2] = gameBoard[row][1];
            gameBoard[row][1] = 0;
        }
    }
}

void leftMove(int gameBoard[][4])
{
    int zeroCounter = 0;
    for (int row = 0; row < 4; row++) // Movement of all numbers to the left direction
    {
        for (int element = 0; element < 4; element++)
        {
            if (gameBoard[row][element] == 0)
            {
                zeroCounter++;
            }
            else if (zeroCounter != 0)
            {
                gameBoard[row][element-zeroCounter] = gameBoard[row][element];
                gameBoard[row][element] = 0;
                zeroCounter = 0;
            }
        }
        zeroCounter = 0;
    }

    for (int row = 0; row < 4; row++) // Combination of all same numbers
    {
        for (int element = 0; element < 4; element++) // Actual combination of numbers
        {
            if (gameBoard[row][element] == gameBoard[row][element+1] && gameBoard[row][element] != 0)
            {
                gameBoard[row][element] = gameBoard[row][element]*2;
                gameBoard[row][element+1] = 0;
            }
        }

        if (gameBoard[row][0] != 0 && gameBoard[row][2] != 0 && gameBoard[row][1] == 0) // Movement of numbers if there is an empty gap
        {
            gameBoard[row][1] = gameBoard[row][2];
            gameBoard[row][2] = 0;
        }
    }
}

void upMove(int gameBoard[][4]) {
    int zeroCounter = 0;
    for (int column = 0; column < 4; column++) // Movement of all numbers to the upward direction
    {
        for (int row = 0; row < 4; row++)
        {
            if (gameBoard[row][column] == 0) 
            {
                zeroCounter++;
            }
            else if (zeroCounter != 0)
            {
                gameBoard[row-zeroCounter][column] = gameBoard[row][column];
                gameBoard[row][column] = 0;
                zeroCounter = 0;
            }
        }
        zeroCounter = 0;
    }

    for (int column = 0; column < 4; column++) // Combination of all same numbers
    {
        for (int row = 0; row < 4; row++) // Actual combination of numbers
        {
            if (gameBoard[row][column] == gameBoard[row+1][column]) 
            {
                gameBoard[row][column] = gameBoard[row][column]*2;
                gameBoard[row+1][column] = 0;
            }
        }
        if (gameBoard[0][column] != 0 && gameBoard[2][column] != 0 && gameBoard[1][column] == 0) // Movement of numbers if there is an empty gap
        {
            gameBoard[1][column] = gameBoard[2][column];
            gameBoard[2][column] = 0;
        }
    }
}

void downMove(int gameBoard[][4]) {
    int zeroCounter = 0;
    for (int column = 0; column < 4; column++) // Movement of all numbers to the downward direction
    {
        for (int row = 3; row > -1; row--)
        {
            if (gameBoard[row][column] == 0) 
            {
                zeroCounter++;
            }
            else if (zeroCounter != 0)
            {
                gameBoard[row+zeroCounter][column] = gameBoard[row][column];
                gameBoard[row][column] = 0;
                zeroCounter = 0;
            }
        }
        zeroCounter = 0;
    }

    for (int column = 0; column < 4; column++) // Combination of all same numbers
    {
        for (int row = 3; row > -1; row--) // Actual combination of numbers
        {
            if (gameBoard[row][column] == gameBoard[row-1][column]) 
            {
                gameBoard[row][column] = gameBoard[row][column]*2;
                gameBoard[row-1][column] = 0;
            }
        }
        if (gameBoard[1][column] != 0 && gameBoard[3][column] != 0 && gameBoard[2][column] == 0) // Movement of numbers if there is an empty gap
        {
            gameBoard[2][column] = gameBoard[1][column];
            gameBoard[1][column] = 0;
        }
    }
}

void randomSpawning(int gameBoard[][4]) 
{
    bool validSpawnPosition = false;
    for (int row = 0; row < 4; row++) // Check to see if any zero's remain
    {
        for (int element = 0; element < 4; element++)
        {
            if (gameBoard[row][element] == 0)
            {
                validSpawnPosition = true;
                cout << "Found a 0!";
            }
        }
    } 

    int randomRow = rand() % 4;
    int randomPositon = rand() % 4;
    while (gameBoard[randomRow][randomPositon] != 0 && validSpawnPosition == true)
    {
        int randomRow = rand() % 4;
        int randomPositon = rand() % 4;
    }
    if (validSpawnPosition == true) 
    {
        gameBoard[randomRow][randomPositon] = 2;
    }
}

void printBoard(int gameBoard[][4])
{
    for (int row = 0; row < 4; row++)
    {
        for (int element = 0; element < 4; element++)
        {
            cout << gameBoard[row][element] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    srand(2);
    int gameBoard[4][4] = 
    {
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1}
    };

    char userInput;
    while (userInput != 'Q') 
    {
        if (userInput == 'R')
        {
            rightMove(gameBoard);
        }

        if (userInput == 'L')
        {
            leftMove(gameBoard);
        }

        if (userInput == 'U')
        {
            upMove(gameBoard);
        }

        if (userInput == 'D')
        {
            downMove(gameBoard);
        }

        //randomSpawning(gameBoard);

        printBoard(gameBoard);

        cout << "Please input Right (R), Left (L), Down (D), Up (U), or Quit (Q): ";
        cin >> userInput;
        cout << endl;
    }

    return 0;
}