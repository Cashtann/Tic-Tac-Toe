#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>



class Board {
private:
	int occupiedSpots = 0;
public:
	char m_Apossitions[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

	bool OccupyPos(char& OorX, int index) {
		if ((OorX == 'X' || OorX == 'O') && (index > -1 && index < 9)) {
			if (m_Apossitions[index] == ' ') {
				m_Apossitions[index] = OorX;
				occupiedSpots++;
				return true;
			}
			else {
				return false;
			}
		}
	}

	void printColored(HANDLE& console_color, char& msg, int& currentColor, int& nextColor) {
		SetConsoleTextAttribute(
			console_color, currentColor);
		std::cout << msg;
		SetConsoleTextAttribute(
			console_color, nextColor);
	}

	void pcox(HANDLE& console_color, char& msg, int& xColor, int& oColor, int& default_color) {
		if (msg == 'X') {
			printColored(console_color, msg, xColor, default_color);
		}
		else if (msg == 'O') {
			printColored(console_color, msg, oColor, default_color);
		}
		else {
			std::cout << ' ';
		}
	}

	void Draw(HANDLE& console_color, int& xColor, int& oColor, int& default_color) {
		system("cls");

		std::cout << " ,---------------," << std::endl;
		std::cout << " |  Tic Tac Toe  |" << std::endl;
		std::cout << " '---------------'" << std::endl;
		std::cout << "      |     |     " << std::endl;
		std::cout << "   "; pcox(console_color, m_Apossitions[0], xColor, oColor, default_color); std::cout << "  |  ";  pcox(console_color, m_Apossitions[1], xColor, oColor, default_color); std::cout << "  |  "; pcox(console_color, m_Apossitions[2], xColor, oColor, default_color); std::cout << "  " << std::endl;
		std::cout << " _____|_____|_____" << std::endl;
		std::cout << "      |     |     " << std::endl;
		std::cout << "   "; pcox(console_color, m_Apossitions[3], xColor, oColor, default_color); std::cout << "  |  "; pcox(console_color, m_Apossitions[4], xColor, oColor, default_color); std::cout << "  |  "; pcox(console_color, m_Apossitions[5], xColor, oColor, default_color); std::cout << "  " << std::endl;
		std::cout << " _____|_____|_____" << std::endl;
		std::cout << "      |     |     " << std::endl;
		std::cout << "   "; pcox(console_color, m_Apossitions[6], xColor, oColor, default_color); std::cout << "  |  "; pcox(console_color, m_Apossitions[7], xColor, oColor, default_color); std::cout << "  |  "; pcox(console_color, m_Apossitions[8], xColor, oColor, default_color); std::cout << "  " << std::endl;
		std::cout << "      |     |     " << std::endl << std::endl;
	}

	bool isGameOver(char& winner) {
		for (int l = 0; l < 3; l++) {
			// checking rows
			if ((m_Apossitions[3 * l] == m_Apossitions[3 * l + 1]) && (m_Apossitions[3 * l] == m_Apossitions[3 * l + 2]) && (m_Apossitions[3 * l] != ' ')) {
				winner = m_Apossitions[3 * l];
				return true;
			}
			// checking columns
			if ((m_Apossitions[l] == m_Apossitions[l + 3]) && (m_Apossitions[l] == m_Apossitions[l + 6]) && (m_Apossitions[l] != ' ')) {
				winner = m_Apossitions[l];
				return true;
			}
		}
		// checking diagonally '\'
		if ((m_Apossitions[0] == m_Apossitions[4]) && (m_Apossitions[0] == m_Apossitions[8]) && (m_Apossitions[0] != ' ')) {
			winner = m_Apossitions[0];
			return true;
		}
		// cheking diagonally '/'
		if ((m_Apossitions[2] == m_Apossitions[4]) && (m_Apossitions[2] == m_Apossitions[6]) && (m_Apossitions[2] != ' ')) {
			winner = m_Apossitions[2];
			return true;
		}
		if (occupiedSpots > 8) {
			return true;
		}
		return false;
	}
};

void DrawBoard(Board& board, HANDLE& console_color, int& xColor, int& oColor, int& default_color) {
	board.Draw(console_color, xColor, oColor, default_color);
}

bool InputOutput(Board& board, char& playerX, char& playerO, bool& OTurn, HANDLE& console_color, int& xColor, int& oColor, int& default_color) {
	if (_kbhit()) {
		char PlayerSign = ' ';
		if (OTurn) { PlayerSign = playerO; }
		else { PlayerSign = playerX; }
		switch (_getch()) {
		case '1':
			if (!board.OccupyPos(PlayerSign, 0)) {
				return false;
			}
			break;
		case '2':
			if (!board.OccupyPos(PlayerSign, 1)) {
				return false;
			}
			break;
		case '3':
			if (!board.OccupyPos(PlayerSign, 2)) {
				return false;
			}
			break;
		case '4':
			if (!board.OccupyPos(PlayerSign, 3)) {
				return false;
			}
			break;
		case '5':
			if (!board.OccupyPos(PlayerSign, 4)) {
				return false;
			}
			break;
		case '6':
			if (!board.OccupyPos(PlayerSign, 5)) {
				return false;
			}
			break;
		case '7':
			if (!board.OccupyPos(PlayerSign, 6)) {
				return false;
			}
			break;
		case '8':
			if (!board.OccupyPos(PlayerSign, 7)) {
				return false;
			}
			break;
		case '9':
			if (!board.OccupyPos(PlayerSign, 8)) {
				return false;
			}
			break;
		default:
			return false;
		}
		DrawBoard(board, console_color, xColor, oColor, default_color);
		return true;
	}
}

void switchOrder(bool& current) {
	current = !current;
}

void Logic(Board& board, char& winner, bool& gameOver, HANDLE& console_color, int& end_color, int& xColor, int& oColor) {
	if (board.isGameOver(winner)) {
		SetConsoleTextAttribute(
			console_color, end_color);

		std::cout << std::endl << " Game over! ";

		if (winner == 'X') {
			SetConsoleTextAttribute(
				console_color, xColor);
		}
		else if (winner == 'O') {
			SetConsoleTextAttribute(
				console_color, oColor);
		}
		else {
			SetConsoleTextAttribute(
				console_color, end_color);
		}
		if (winner == ' ') {
			SetConsoleTextAttribute(
				console_color, end_color);
			std::cout << "It's a tie!" << std::endl;
			gameOver = true;
		}
		else {
			std::cout << winner;

			SetConsoleTextAttribute(
				console_color, end_color);
			std::cout << " won!" << std::endl;
			gameOver = true;

			SetConsoleTextAttribute(
				console_color, 8);
			std::cout << std::endl << " Press ENTER to terminate. " << std::endl;
		}
	}
}



int main() {
	HANDLE console_color;
	console_color = GetStdHandle(
		STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(
		console_color, 15);

	bool gameOver = false;
	bool OTurn = false;
	Board board;

	char playerX = 'X';
	char playerO = 'O';
	char winner = ' ';

	int default_color = 15;
	int xColor = 11;
	int oColor = 14;
	int end_color = 10;

	DrawBoard(board, console_color, xColor, oColor, default_color);
	std::cout << " X is staring!";
	while (!gameOver) {
		while (InputOutput(board, playerX, playerO, OTurn, console_color, xColor, oColor, default_color)) {
			switchOrder(OTurn); 
			
			if (OTurn) { std::cout << " O's turn" << std::endl; }
			else { std::cout << " X's turn" << std::endl; }
			
			Logic(board, winner, gameOver, console_color, end_color, xColor, oColor);
		};
	}

	std::cin.get();
}
