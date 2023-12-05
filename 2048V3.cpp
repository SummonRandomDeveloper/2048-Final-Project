#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
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

void upMove(int gameBoard[][4]) 
{
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

void downMove(int gameBoard[][4]) 
{
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
    int availableSpots = 0;
    int rowIndex = 0;
    int elementIndex = 1;
    vector<int> availableIndexes(0);
    for (int row = 0; row < 4; row++) // Check to see if any zero's remain
    {
        for (int element = 0; element < 4; element++)
        {
            if (gameBoard[row][element] == 0)
            {
                validSpawnPosition = true;
                availableSpots++;
                availableIndexes.resize(availableSpots*2);
                availableIndexes.at(rowIndex) = row;
                availableIndexes.at(elementIndex) = element;
                rowIndex = rowIndex + 2;
                elementIndex = elementIndex + 2;
            }
        }
    }
    int randomIndex = rand() % (availableIndexes.size()/2);
    gameBoard[availableIndexes.at(randomIndex*2)][availableIndexes.at((randomIndex*2)+1)] = 2;
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
        {2,2,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };

    char userInput;
    while (userInput != 'Q') 
    {

        printBoard(gameBoard);

        cout << "Please input Right (R), Left (L), Down (D), Up (U), or Quit (Q): ";
        cin >> userInput;
        cout << endl;

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

        randomSpawning(gameBoard);
    }

    return 0;
}