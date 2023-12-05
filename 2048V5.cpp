#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

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

void rightMove(int gameBoard[][4],int score[1])
{
    bool validMove = false;
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
                validMove = true;
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
                score[0] = score[0] + gameBoard[row][element];
                gameBoard[row][element-1] = 0;
                validMove = true;
            }
        } 
    }

    zeroCounter = 0;
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

    if (validMove == true) {
        randomSpawning(gameBoard);
    }
}

void leftMove(int gameBoard[][4], int score[1])
{
    int zeroCounter = 0;
    bool validMove = false;
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
                validMove = true;
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
                score[0] = score[0] + gameBoard[row][element];
                gameBoard[row][element+1] = 0;
                validMove = true;
            }
        }
    }

    zeroCounter = 0;
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

    if (validMove == true) {
        randomSpawning(gameBoard);
    }
}

void upMove(int gameBoard[][4], int score[1]) 
{
    int zeroCounter = 0;
    bool validMove = false;
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
                validMove = true;
            }
        }
        zeroCounter = 0;
    }

    for (int column = 0; column < 4; column++) // Combination of all same numbers
    {
        for (int row = 0; row < 4; row++) // Actual combination of numbers
        {
            if (gameBoard[row][column] == gameBoard[row+1][column] && gameBoard[row][column] != 0) 
            {
                gameBoard[row][column] = gameBoard[row][column]*2;
                score[0] = score[0] + gameBoard[row][column];
                gameBoard[row+1][column] = 0;
                validMove = true;
            }
        }
    }

    zeroCounter = 0;
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

    if (validMove == true) {
        randomSpawning(gameBoard);
    }
}

void downMove(int gameBoard[][4], int score[1]) 
{
    int zeroCounter = 0;
    bool validMove = false;
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
                validMove = true;
            }
        }
        zeroCounter = 0;
    }

    for (int column = 0; column < 4; column++) // Combination of all same numbers
    {
        for (int row = 3; row > -1; row--) // Actual combination of numbers
        {
            if (gameBoard[row][column] == gameBoard[row-1][column] && gameBoard[row][column] != 0) 
            {
                gameBoard[row][column] = gameBoard[row][column]*2;
                score[0] = score[0] + gameBoard[row][column];
                gameBoard[row-1][column] = 0;
                validMove = true;
            }
        }
    }

    zeroCounter = 0;
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

    if (validMove == true) {
        randomSpawning(gameBoard);
    }
}

void printBoard(int gameBoard[][4], int score[1])
{
    cout << "Score: " << score[0] << endl;
    for (int row = 0; row < 4; row++)
    {
        for (int element = 0; element < 4; element++)
        {
            cout << gameBoard[row][element] << "    ";
        }
        cout << endl;
    }
}

int main() 
{
    srand(2);
    int gameBoard[4][4] = 
    {
        {2,0,0,0},
        {0,0,0,0},
        {0,0,0,2},
        {0,0,0,0}
    };

    int score[1] = {0};

    char userInput;
    while (userInput != 'Q') 
    {

        printBoard(gameBoard,score);

        cout << "Please input Right (R), Left (L), Down (D), Up (U), or Quit (Q): ";
        cin >> userInput;
        cout << endl;

        if (userInput == 'R')
        {
            rightMove(gameBoard,score);
        }

        if (userInput == 'L')
        {
            leftMove(gameBoard,score);
        }

        if (userInput == 'U')
        {
            upMove(gameBoard,score);
        }

        if (userInput == 'D')
        {
            downMove(gameBoard,score);
        }
    }

    return 0;
}
