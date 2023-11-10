#include <iostream>
#include <string>
using namespace std;

int main() {
    int gameBoard[16] = 
    {2,0,2,2,
    2,2,0,2,
    2,0,0,2,
    0,2,2,0}; // 4x4 board used to track the 2048 game
    char userInput;
    while (userInput != 'N') {

        for (int i = 0; i<16; i++) { //Printing of game board after every move
            cout << gameBoard[i] << " ";
            if (((i+1)%4)==0) {
                cout << "\n";
            }
        }

        cout << "What direction would you like to go? ";
        cin >> userInput;

        if (userInput == 'R') { // Logic for all rows for right input

            for (int row = 0; row < 4; row++) {
                for (int position = 0; position < 3; position++) {
                    if ( (gameBoard[position+(row*4)] != 0) && (gameBoard[(position+(row*4))+1] == 0) ) {
                        gameBoard[position+(row*4)+1] = gameBoard[position+(row*4)];
                        gameBoard[position+(row*4)] = 0;
                    }
                }
            }
            
            for (int row = 0; row < 4; row++) {
                for (int position = 0; position < 3; position++) {
                    if ( (gameBoard[position+(row*4)] != 0) && (gameBoard[(position+(row*4))+1] == 0) ) {
                        gameBoard[position+(row*4)+1] = gameBoard[position+(row*4)];
                        gameBoard[position+(row*4)] = 0;
                    }
                }
            }

            for (int row = 0; row < 4; row++) {
                for (int position = 3; position > -1; position--) {
                    if ( (gameBoard[position+(row*4)] == gameBoard[position+(row*4)-1]) ) {
                        gameBoard[position+(row*4)] = gameBoard[position+(row*4)]*2;
                        gameBoard[position+(row*4)-1] = 0;
                    }
                }
            }

            for (int row = 0; row < 4; row++) {
                for (int position = 0; position < 3; position++) {
                    if ( (gameBoard[position+(row*4)] != 0) && (gameBoard[(position+(row*4))+1] == 0) ) {
                        gameBoard[position+(row*4)+1] = gameBoard[position+(row*4)];
                        gameBoard[position+(row*4)] = 0;
                    }
                }
            }

        }

        if (userInput == 'L') { // Logic for all rows for left input

            for (int row = 0; row < 4; row++) {
                for (int position = 3; position > 0; position--) {
                    if ( (gameBoard[position+(row*4)]) != 0 && (gameBoard[(position+(row*4))-1] == 0) ) {
                        gameBoard[(position+(row*4))-1] = (gameBoard[position+(row*4)]);
                        gameBoard[position+(row*4)] = 0;
                    }
                }
            }

            for (int row = 0; row < 4; row++) {
                for (int position = 3; position > 0; position--) {
                    if ( (gameBoard[position+(row*4)]) != 0 && (gameBoard[(position+(row*4))-1] == 0) ) {
                        gameBoard[(position+(row*4))-1] = (gameBoard[position+(row*4)]);
                        gameBoard[position+(row*4)] = 0;
                    }
                }
            }

            for (int row = 0; row < 4; row++) {
                for (int position = 0; position < 3; position++) {
                    if ( (gameBoard[position+(row*4)] == gameBoard[position+(row*4)+1]) ) {
                        gameBoard[position+(row*4)] = gameBoard[position+(row*4)]*2;
                        gameBoard[position+(row*4)+1] = 0;
                    }
                }
            }

            for (int row = 0; row < 4; row++) {
                for (int position = 3; position > 0; position--) {
                    if ( (gameBoard[position+(row*4)]) != 0 && (gameBoard[(position+(row*4))-1] == 0) ) {
                        gameBoard[(position+(row*4))-1] = (gameBoard[position+(row*4)]);
                        gameBoard[position+(row*4)] = 0;
                    }
                }
            }
        }

        
    }
    return 0;
}
