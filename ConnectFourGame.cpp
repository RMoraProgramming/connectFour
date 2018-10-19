
#include <iostream>
#include <string> 
using namespace std;

// Set the global variables
const int ROWS = 6;
const int COLS = 7;
bool win = false;
char connectBoard[ROWS][COLS];

//All my functions

//These functions is to print title and player win message
void printTitle() {
	cout << "\t _______  _______  _        _        _______  _______ _________   _______  _______           _______ " << endl;
	cout << "\t(  ____ \\(  ___  )( (    /|( (    /|( ____ \\ (  ____ \\\\__   __/  (  ____ \\(  ___  )|\\     /|(  ____ )" << endl;
	cout << "\t| (    \\/| (   ) ||  \\  ( || \\   ( || (   \\/ | (    \\/   ) (     | (    \\/| (   ) || )   ( || (    )|" << endl;
	cout << "\t| |      | |   | ||   \\ | ||   \\ | || (__    | |         | |     | (__    | |   | || |   | || (____)|" << endl;
	cout << "\t| |      | |   | || (\\ \\) || (\\ \\) ||  __)   | |         | |     |  __)   | |   | || |   | ||     __)" << endl;
	cout << "\t| |      | |   | || | \\   || | \\   || (      | |         | |     | (      | |   | || |   | || (\\ (   " << endl;
	cout << "\t| (____/\\| (___) || )  \\  || )  \\  || (____/\\| (____/\\   | |     | )      | (___) || (___) || ) \\ \\__" << endl;
	cout << "\t(_______/(_______)|/    )_)|/    )_)(_______/(_______/   )_(     |/       (_______)(_______)|/   \\__/" << endl;
	return;
}

void printPlayerOneWin() {
	cout << "\t______ _                        _____              _    _ _           _ _ _ " << endl;
	cout << "\t| ___ \\ |                      |  _  |            | |  | (_)         | | | |" << endl;
	cout << "\t| |_/ / | __ _ _   _  ___ _ __ | | | |_ __   ___  | |  | |_ _ __  ___| | | |" << endl;
	cout << "\t|  __/| |/ _` | | | |/ _ \\ '__|| | | | '_ \\ / _ \\ | |/\\| | | '_ \\/ __| | | |" << endl;
	cout << "\t| |   | | (_| | |_| |  __/ |   \\ \\_/ / | | |  __/ \\  /\\  / | | | \\__ \\_|_|_|" << endl;
	cout << "\t\\_|   |_|\\__,_|\\__, |\\___|_|    \\___/|_| |_|\\___|  \\/  \\/|_|_| |_|___(_|_|_)" << endl;
	cout << "\t                __/ |                                                        " << endl;
	cout << "\t               |___/                                                         " << endl;
	return;
}

void printPlayerTwoWin() {
	cout << "\t______ _                         _____               _    _ _           _ _ _" << endl;
	cout << "\t| ___ \\ |                       |_   _|             | |  | (_)         | | | |" << endl;
	cout << "\t| |_/ / | __ _ _   _  ___ _ __    | |_      _____   | |  | |_ _ __  ___| | | |" << endl;
	cout << "\t|  __/| |/ _` | | | |/ _ \\ '__|   | \\ \\ /\\ / / _ \\  | |/\\| | | '_ \\/ __| | | |" << endl;
	cout << "\t| |   | | (_| | |_| |  __/ |      | |\\ V  V / (_) | \\  /\\  / | | | \\__ \\_|_|_|" << endl;
	cout << "\t\\_|   |_|\\__,_|\\__, |\\___|_|      \\_/ \\_/\\_/ \\___/   \\/  \\/|_|_| |_|___(_|_|_)" << endl;
	cout << "\t                __/ |                  " << endl;
	cout << "\t               |___ /                   " << endl;
	return;
}

//Initialize my char array board
void boardInitialize() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			connectBoard[i][j] = ' ';

		}
	}
	return;
}

 //Function to display the board
void displayBoard() {
	cout << endl;
	cout << "Player One is x and Player Two is o" << endl;
	cout << "The Current Connect Four Board.." << endl;
	
	for (int i = 0; i < COLS; i++) {

		cout << " " << i + 1 << " ";
	}


	cout << endl;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << "[" << connectBoard[i][j] << "]";
		}
		cout << endl;
	}
	return;
}

//This function is make sure user can drop a piece in a full column
int input(int x) {
	int inputy = 0;
	bool correctMove = false;
	while (correctMove != true) {
		for (int i = ROWS; i >= 0; i--) {
			if (connectBoard[i][x - 1] == ' ') {
				inputy = i;
				correctMove = true;
				break;
			}


		}

	}
	return inputy;
}

//This function is used to see who wins 
bool checkWin(char player) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (connectBoard[i][j] == player && connectBoard[i][j + 1] == player && connectBoard[i][j + 2] == player && connectBoard[i][j + 3] == player) {
				return true;
			}
			else if (connectBoard[i][j] == player && connectBoard[i + 1][j] == player && connectBoard[i + 2][j] == player && connectBoard[i + 3][j] == player) {
				return true;
			}
			else if (connectBoard[i][j] == player && connectBoard[i + 1][j + 1] == player && connectBoard[i + 2][j + 2] == player && connectBoard[i + 3][j + 3] == player) {
				return true;
			}
			else if (connectBoard[i][j] == player && connectBoard[i + 1][j - 1] == player && connectBoard[i + 2][j - 2] == player && connectBoard[i + 3][j - 3] == player) {
				return true;
			}

		}
	}
	return false;
}

int main() {
	
		bool playAgain = true;
		char choicePA;
		int winCheck = 0;
		char playerOne = 'x';
		char playerTwo = 'o';
		int x = 0;
		bool correctMove = false, validataion = true;
		int inputy;

		//Print the title and rules
		printTitle();
		cout << endl;
		cout << "\t\t The Rules...." << endl;
		cout << "1. This game is between a player and another player" << endl;
		cout << "2. During each player's turn that player selects the row to drop 1 piece into the connect four board." << endl;
		cout << "3. The first person to make a row of 4 of that players piece diagonally, vertically, or horizontally wins the game. \n" << endl;
		cout << "Now lets begin ..." << endl;

		//Initialize the board and print the board
		boardInitialize();
		displayBoard();

		//This while loop keeps the game looping until a winner is found
		while (win != true) {

			//Do while to check if column is full
			do {

				// Do while to validate player one input
				do {

					//Ask player one the which column to drop the piece
					cout << "Player one please choose which column you would like to drop your piece in: ";
					cin >> x;
					if (x <= 0 || x >= 8) {

						//Error message if invalid input
						cout << "Oops the input you entered was too high or it was to low or you entered a invalid character.... Please try again \n";
					}

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

				} while (x <= 0 || x >= 8);

				//Check if the column is full and print error if it is full
				if (connectBoard[0][x - 1] == playerOne || connectBoard[0][x - 1] == playerTwo) {
					cout << "Oops that column is full, Please try again \n";
				}
				else {
					correctMove = true;
				}
			} while (correctMove != true);
			correctMove = false;

			//Drop piece into the board and display the new board
			connectBoard[input(x--)][x--] = playerOne;
			displayBoard();

			//Check if player one has connected four of their pieces.
			if (checkWin(playerOne) == true) {

				printPlayerOneWin();
				win = true;
				break;
			}
			x = 0;

			//Do while to check if column is not full
			do {

				//Validate player two input
				do {

					//Ask player two which column to drop the piece
					cout << "Player two please choose which column you would like to drop your piece in : ";
					cin >> x;
					if (x <= 0 || x >= 8) {

						//Error message if player two enters a invalid input
						cout << "Oops the input you entered was too high or it was to low or you entered a invalid character.... Please try again \n";

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}


				} while (x <= 0 || x >= 8);

				//Check if the column is full or not
				if (connectBoard[0][x - 1] == 'x' || connectBoard[0][x - 1] == 'o') {
					cout << "Oops that column is full, Please try again \n";
				}
				else {
					correctMove = true;
				}
			} while (correctMove != true);
			correctMove = false;
			
			//Drop the piece into the board and display the new board
			connectBoard[input(x--)][x--] = 'o';
			displayBoard();

			//Check if player two has connected four of their pieces
			if (checkWin(playerTwo) == true) {
				printPlayerTwoWin();

				win = true;
				break;
			}
			x = 0;
		}
		cout << endl;
		
	
	system("pause");
	return 0;

}