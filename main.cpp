#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

#include <chrono>
using namespace std::chrono;

class boord {
public:
	long long int wPawn = 65280;
	long long int wRook = 129;
	long long int wBishop = 36;
	long long int wKnight = 66;
	long long int wQueen = 16;
	long long int wKnook = 0;
	long long int bPawn = 71776119061217280;
	long long int bRook = -9151314442816847872;
	long long int bBishop = 2594073385365405696;
	long long int bKnight = 4755801206503243776;
	long long int bQueen = 1152921504606846976;
	long long int bKnook = 0;
	int kingLocation[2] = { 3,59 };
	char color(int i) {
		//white = 0; black = 1; empty = 2
		int f = (*this)[i];
		if(f < 6 || f == 13){
			return 0;
		}
		if(f == 12) {
			return 2;
		}
		return 1;
	}
	int operator[](int i) {
		if ((wPawn >> i) & 1LL) {
			return 5;
		}
		if ((wRook >> i) & 1LL) {
			return 0;
		}
		if ((wBishop >> i) & 1LL) {
			return 2;
		}
		if ((wKnight >> i) & 1LL) {
			return 1;
		}
		if ((wQueen >> i) & 1LL) {
			return 3;
		}
		if ((bPawn >> i) & 1LL) {
			return 11;
		}
		if ((bRook >> i) & 1LL) {
			return 6;
		}
		if ((bBishop >> i) & 1LL) {
			return 8;
		}
		if ((bKnight >> i) & 1LL) {
			return 7;
		}
		if ((bQueen >> i) & 1LL) {
			return 9;
		}
		if (i == kingLocation[0]) {
			return 4;
		}
		if (i == kingLocation[1]) {
			return 10;
		}
		return 12;
	}
	void set(int i, int piece) {
		switch (piece) {
		case 12:
			wPawn &= ~(1LL << i);
			wRook &= ~(1LL << i);
			wBishop &= ~(1LL << i);
			wKnight &= ~(1LL << i);
			wQueen &= ~(1LL << i);
			bPawn &= ~(1LL << i);
			bRook &= ~(1LL << i);
			bBishop &= ~(1LL << i);
			bKnight &= ~(1LL << i);
			bQueen &= ~(1LL << i);
			bKnook &= ~(1LL << i);
			bKnook &= ~(1LL << i);
			break;
		case 0:
			wRook ^= 1LL << i;
			break;
		case 1:
			wKnight ^= 1LL << i;
			break;
		case 2:
			wBishop ^= 1LL << i;
			break;
		case 3:
			wQueen ^= 1LL << i;
			break;
		case 4:
			kingLocation[0] = i;
			break;
		case 5:
			wPawn ^= 1LL << i;
			break;
		case 6:
			bRook ^= 1LL << i;
			break;
		case 7:
			bKnight ^= 1LL << i;
			break;
		case 8:
			bBishop ^= 1LL << i;
			break;
		case 9:
			bQueen ^= 1LL << i;
			break;
		case 10:
			kingLocation[1] = i;
			break;
		case 11:
			bPawn ^= 1LL << i;
			break;
		case 13:
			wKnook ^= 1LL << i;
			break;
		case 14:
			bKnook ^= 1LL << i;
			break;
		}
		

	}
	void move(int i, int a) {
		set(a, (*this)[i]);
		set(i, 12);
	}

	boord() {

	}
	boord(long long int a, long long int b, long long int c, long long int d, long long int e, long long int f, long long int g, long long int h, long long int i, long long int j, int k, int l) {
		wPawn = a;
		wRook = b;
		wBishop = c;
		wKnight = d;
		wQueen = e;
		bPawn = f;
		bRook = g;
		bBishop = h;
		bKnight = i;
		bQueen = j;
		kingLocation[0] = k;
		kingLocation[1] = l;
	}
};

void printBoard(boord board) {

	//string bord[64];
	char pieces[] = { 'R', 'N', 'B', 'Q', 'K', 'P',
					 'r', 'n', 'b', 'q', 'k', 'p', ' ', 'Ñ', 'ñ'};
	// Ñ ñ
	cout << "  hgfedcba";
	int a;
	int j = 0;
	for (int i = 0; i < 64; i++) {
		a = board[i];
		if (i % 8 == 0) {
			cout << "\n" << i / 8 + 1 << ' ';
			j++;
		}
		/*
		if (j % 2 == 0) {
			if (a == 12) {
				if (i % 2 == 0) {
					cout << "X";
				}
				else {
					cout << " ";
				}
			}
			else {
				cout << pieces[a];
			}
		}
		else {
			if (a == 12) {
				if (i % 2 == 1) {
					cout << "X";
				}
				else {
					cout << " ";
				}
			}
			else {
				cout << pieces[a];
			}
		}
		*/
		cout << pieces[a];
		
	}
	cout << "\n";
}
int convertMove(string move) {
	int x = move[1] - '0';
	x *= 8;
	x -= 8;
	char y = move[0];
	/*
if (y == 'a') {
	x += 7;
  } else if (y == 'b') {
	x += 6;
  } else if (y == 'c') {
	x += 5;
  } else if (y == 'd') {
	x += 4;
  } else if (y == 'e') {
	x += 3;
  } else if (y == 'f') {
	x += 2;
  } else if (y == 'g') {
	x += 1;
  }*/
	x += 7 * (y == 'a') + 6 * (y == 'b') + 5 * (y == 'c') + 4 * (y == 'd') + 3 * (y == 'e') + 2 * (y == 'f') + (y == 'g');
	return x;
}
int evaluate(boord board) {
	int evaluation = 0;
	for (int i = 0; i < 64; i++) {
		switch (board[i]) {
		case 12:
			break;
		case 0:
			evaluation += 5;
			break;
		case 1:
			evaluation += 3;
			break;
		case 2:
			evaluation += 3;
			break;
		case 3:
			evaluation += 9;
			break;
		case 4:
			break;
		case 5:
			evaluation += 1;
			break;
		case 6:
			evaluation += -5;
			break;
		case 7:
			evaluation += -3;
			break;
		case 8:
			evaluation += -3;
			break;
		case 9:
			evaluation += -9;
			break;
		case 10:
			break;
		case 11:
			evaluation += -1;
			break;
		}
	}
	return evaluation;
}
void updateBoard(bool turn, string input, boord(*bord), int moves[2], int enPassant, int kingLocation[2]) {
	if (moves[0] - 2 == moves[1] && (*bord)[moves[0]] == 4) {

		bord->set(0, 12);
		bord->set(2, 0);
	}
	else if (moves[0] - 2 == moves[1] && (*bord)[moves[0]] == 10) {
		bord->set(56, 12);
		bord->set(58, 0);
	}
	else if (moves[0] + 2 == moves[1] && (*bord)[moves[0]] == 4) {
		bord->set(7, 12);
		bord->set(4, 0);
	}
	else if (moves[0] + 2 == moves[1] && (*bord)[moves[0]] == 10) {
		bord->set(63, 12);
		bord->set(60, 0);
	}
	bord->move(moves[0], moves[1]);

	if (turn) {
		if (moves[1] < 8 && (*bord)[moves[1]] == 5) {
			if (input[4] == 'k') {
				bord->set(moves[1], 13);
			}
			if (input[4] == 'q') {
				bord->set(moves[1], 3);
			}
			else if (input[4] == 'r') {
				bord->set(moves[1], 0);
			}
			else if (input[4] == 'b') {
				bord->set(moves[1], 2);
			}
			else {
				bord->set(moves[1], 1);
			}

		}
		else if ((*bord)[moves[1]] == 5 && moves[1] - 8 == enPassant) {
			bord->set(moves[1] - 8, 12);
		}
		if ((*bord)[moves[1]] == 4) {
			kingLocation[0] = moves[1];
		}

	}
	else {
		if (moves[1] > 55 && (*bord)[moves[1]] == 11) {
			if (input[4] == 'k') {
				bord->set(moves[1], 14);
			}
			if (input[4] == 'q') {
				bord->set(moves[1], 9);
			}
			else if (input[4] == 'r') {
				bord->set(moves[1], 6);
			}
			else if (input[4] == 'b') {
				bord->set(moves[1], 8);
			}
			else {
				bord->set(moves[1], 7);
			}
		}
		else if ((*bord)[moves[1]] == 11 && moves[1] + 8 == enPassant) {
			bord->set(moves[1] + 8, 12);
		}
		if ((*bord)[moves[1]] == 10) {
			kingLocation[1] = moves[1];
		}

	}
}
void updateBoard(int* tomato, int* enPassant, boord(*board), int moves[2], bool turn, string input, bool(*castling)[4]) {
	int(*kingLocation)[2] = &(board->kingLocation);
	if ((*board)[moves[0]] == 5 || (*board)[moves[0]] == 11) {
		*tomato = 0;
	}
	else if ((*board)[moves[1]] != 12) {
		*tomato = 0;
	}
	if (moves[0] - 2 == moves[1] && (*board)[moves[0]] == 4) {
		board->set(0, 12);
		board->set(2, 0);
	}
	else if (moves[0] - 2 == moves[1] && (*board)[moves[0]] == 10) {
		board->set(56, 12);
		board->set(58, 0);
	}
	else if (moves[0] + 2 == moves[1] && (*board)[moves[0]] == 4) {
		board->set(7, 12);
		board->set(4, 0);
	}
	else if (moves[0] + 2 == moves[1] && (*board)[moves[0]] == 10) {
		board->set(63, 12);
		board->set(60, 0);
	}
	board->move(moves[0], moves[1]);

	if (turn) {
		if ((*board)[moves[0]] == 4) {
			(*castling)[0] = false;
			(*castling)[1] = false;
		}
		else if (moves[0] == 0 || moves[1] == 0) {
			(*castling)[0] = false;
		}
		else if (moves[0] == 7 || moves[1] == 7) {
			(*castling)[1] = false;
		}
		if (moves[0] + 16 == moves[1] && (*board)[moves[1]] == 5) {
			*enPassant = moves[1];
		}
		else {
			*enPassant = -1;
		}
		if (moves[1] < 8 && (*board)[moves[1]] == 5) {
			if (input[4] == 'k') {
				board->set(moves[1], 13);
			}
			if (input[4] == 'q') {
				board->set(moves[1], 3);
			}
			else if (input[4] == 'r') {
				board->set(moves[1], 0);
			}
			else if (input[4] == 'b') {
				board->set(moves[1], 2);
			}
			else {
				board->set(moves[1], 1);
			}

		}
		else if ((*board)[moves[1]] == 5 && moves[1] - 8 == *enPassant) {
			board->set(moves[1] - 8, 12);
		}
		if ((*board)[moves[1]] == 4) {
			*kingLocation[0] = moves[1];
		}
	}
	else {
		if ((*board)[moves[0]] == 10) {
			(*castling)[2] = false;
			(*castling)[3] = false;
		}
		else if (moves[0] == 56 || moves[1] == 56) {
			(*castling)[2] = false;
		}
		else if (moves[0] == 63 || moves[1] == 63) {
			(*castling)[3] = false;
		}
		if (moves[0] - 16 == moves[1] && (*board)[moves[1]] == 11) {
			*enPassant = moves[1];
		}
		else {
			*enPassant = -1;
		}
		if (moves[1] > 55 && (*board)[moves[1]] == 11) {
			if (input[4] == 'k') {
				board->set(moves[1], 14);
			}
			if (input[4] == 'q') {
				board->set(moves[1], 9);
			}
			else if (input[4] == 'r') {
				board->set(moves[1], 6);
			}
			else if (input[4] == 'b') {
				board->set(moves[1], 8);
			}
			else {
				board->set(moves[1], 7);
			}
		}
		else if ((*board)[moves[1]] == 11 && moves[1] + 8 == *enPassant) {
			board->set(moves[1] + 8, 12);
		}
		if ((*board)[moves[1]] == 10) {
			*kingLocation[1] = moves[1];
		}
	}
	(*tomato)++;

}

bool inCheck(bool turn, boord board, int kingLocation1, int kingLocation2) {

	if (turn) {
		int move2 = kingLocation1;
		if (board[move2 + 9] == 11 || board[move2 + 7] == 11) {
			if (move2 % 8 == (move2 + 9) % 8 + 1 && move2 % 8 == (move2 + 7) % 8 - 1) {
				return true;
			}
		}
		for (int move1 = 0; move1 < 64; move1++) {
			if (board[move1] == 6) {

				if (move1 % 8 == move2 % 8) {
					for (int i = move1 + 8; true; i += 8) {
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}
						if (i > 55 && i != move2) {
							break;
						}
						if (i == move2) {
							return true;
							break;
						}
					}
					for (int i = move1 - 8; true; i -= 8) {
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (i < 8 && i != move2) {
							break;
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}
				}
				else {
					for (int i = move1 + 1; true; i++) {
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}
						if (i % 8 == 7 && i != move2) {
							break;
						}
						if (i == move2) {
							return true;
							break;
						}
					}
					for (int i = move1 - 1; true; i--) {
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}
						if (i % 8 == 0 && i != move2) {
							break;
						}
						if (i == move2) {
							return true;
							break;
						}
					}
				}
			}
			else if (board[move1] == 7) {
				if (move1 + 17 == move2 || move1 - 15 == move2) {
					if (move1 % 8 + 1 != move2 % 8) {

					}
					return true;
				}
				else if (move1 + 10 == move2 || move1 - 6 == move2) {
					if (move1 % 8 + 2 != move2 % 8) {

					}
					return true;
				}
				else if (move1 + 15 == move2 || move1 - 17 == move2) {
					if (move1 % 8 - 1 != move2 % 8) {

					}
					return true;
				}
				else if (move1 + 5 == move2 || move1 - 10 == move2) {
					if (move1 % 8 - 2 != move2) {

					}
					return true;
				}
			}
			else if (board[move1] == 8) {

				if (move1 < move2) {
					for (int i = move1 + 9; true; i += 9) {
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}
						if (i > 55 || i % 8 == 0 || i % 8 == 7) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}
					for (int i = move1 + 7; true; i += 7) {
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (i > 55 || i % 8 == 0 || i % 8 == 7) {
							if (i != move2) {
								break;
							}
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}
				}
				else {
					for (int i = move1 - 9; true; i -= 9) {
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}
						if (i < 8 || i % 8 == 0 || i % 8 == 7) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}
					for (int i = move1 - 7; true; i -= 7) {
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (i < 8 || i % 8 == 0 || i % 8 == 7) {
							if (i != move2) {
								break;
							}
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}
				}
			}
			else if (board[move1] == 10) {
				if (move1 + 8 == move2 || move1 - 8 == move2) {
					return true;
				}
				else if (move1 + 9 == move2 || move1 - 7 == move2 || move1 + 1 == move2) {
					if (move1 % 8 + 1 != move2 % 8) {
						return false;
					}
					return true;
				}
				else if (move1 - 9 == move2 || move1 + 7 == move2 || move1 - 1 == move2) {
					if (move1 % 8 - 1 != move2 % 8) {
						return false;
					}
					return true;
				}
			}
			else if (board[move1] == 9) {

				if (move1 < move2) {
					for (int i = move1 + 9; true; i += 9) {
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}
						if (i > 55 || i % 8 == 0 || i % 8 == 7) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}
					for (int i = move1 + 7; true; i += 7) {
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (i > 55 || i % 8 == 0 || i % 8 == 7) {
							if (i != move2) {
								break;
							}
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}

				}
				else {
					for (int i = move1 - 9; true; i -= 9) {
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}
						if (i < 8 || i % 8 == 0 || i % 8 == 7) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}
					for (int i = move1 - 7; true; i -= 7) {
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (i < 8 || i % 8 == 0 || i % 8 == 7) {
							if (i != move2) {
								break;
							}
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}

				}

				if (move1 % 8 == move2 % 8) {
					for (int i = move1 + 8; true; i += 8) {
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}
						if (i > 55 && i != move2) {
							break;
						}
						if (i == move2) {
							return true;
							break;
						}
					}
					for (int i = move1 - 8; true; i -= 8) {
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (i < 8 && i != move2) {
							break;
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}

				}
				else {
					for (int i = move1 + 1; true; i++) {
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}
						if (i % 8 == 7 && i != move2) {
							break;
						}
						if (i == move2) {
							return true;
							break;
						}
					}
					for (int i = move1 - 1; true; i--) {
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}
						if (i % 8 == 0 && i != move2) {
							break;
						}
						if (i == move2) {
							return true;
							break;
						}
					}
				}
			}
		}
	}
	else {
		int move2 = kingLocation2;
		if (board[move2 - 9] == 11 || board[move2 - 7] == 11) {
			if (move2 % 8 == (move2 - 9) % 8 - 1 && move2 % 8 == (move2 - 7) % 8 + 1) {
				return true;
			}
		}
		for (int move1 = 0; move1 < 64; move1++) {
			if (board[move1] == 0) {
				// rooks
				// vertical

				if (move1 % 8 == move2 % 8) {
					for (int i = move1 + 8; true; i += 8) {
						if (board[i] < 6) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i > 55 && i != move2) {
							break;
						}
						if (i == move2) {
							return true;
							break;
						}
					}
					for (int i = move1 - 8; true; i -= 8) {
						if (board[i] < 6) {
							break;
						}
						if (i < 8 && i != move2) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}

				}
				else {
					for (int i = move1 + 1; true; i++) {
						if (board[i] < 6) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i % 8 == 7 && i != move2) {
							break;
						}
						if (i == move2) {
							return true;
							break;
						}
					}
					for (int i = move1 - 1; true; i--) {
						if (board[i] < 6) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i % 8 == 0 && i != move2) {
							break;
						}
						if (i == move2) {
							return true;
							break;
						}
					}
				}
			}
			else if (board[move1] == 1) {
				// knight
				if (move1 + 17 == move2 || move1 - 15 == move2) {
					if (move1 % 8 + 1 != move2 % 8) {

					}
					else {
						return true;
					}
				}
				else if (move1 + 10 == move2 || move1 - 6 == move2) {
					if (move1 % 8 + 2 != move2 % 8) {

					}
					else {
						return true;
					}
				}
				else if (move1 + 15 == move2 || move1 - 17 == move2) {
					if (move1 % 8 - 1 != move2 % 8) {

					}
					else {
						return true;
					}
				}
				else if (move1 + 5 == move2 || move1 - 10 == move2) {
					if (move1 % 8 - 2 != move2) {

					}
					else {
						return true;
					}
				}
			}
			else if (board[move1] == 2) {
				// bishop
				if (move1 < move2) {
					for (int i = move1 + 9; true; i += 9) {
						if (board[i] < 6) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i > 55 || i % 8 == 0 || i % 8 == 7) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}
					for (int i = move1 + 7; true; i += 7) {
						if (board[i] < 6) {
							break;
						}
						if (i > 55 || i % 8 == 0 || i % 8 == 7) {
							if (i != move2) {
								break;
							}
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}

				}
				else {
					for (int i = move1 - 9; true; i -= 9) {
						if (board[i] < 6) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i < 8 || i % 8 == 0 || i % 8 == 7) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}
					for (int i = move1 - 7; true; i -= 7) {
						if (board[i] < 6) {
							break;
						}
						if (i < 8 || i % 8 == 0 || i % 8 == 7) {
							if (i != move2) {
								break;
							}
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}
				}
			}
			else if (board[move1] == 4) {
				// king
				if (move1 + 8 == move2 || move1 - 8 == move2) {
					return true;
				}
				else if (move1 + 9 == move2 || move1 - 7 == move2 || move1 + 1 == move2) {
					if (move1 % 8 + 1 != move2 % 8) {

					}
					else {
						return true;
					}
				}
				else if (move1 - 9 == move2 || move1 + 7 == move2 || move1 - 1 == move2) {
					if (move1 % 8 - 1 != move2 % 8) {
						return false;
					}
					else {
						return true;
					}
				}
			}
			else if (board[move1] == 3) {
				// queen

				// rooks
				// vertical
				if (move1 % 8 == move2 % 8) {
					for (int i = move1 + 8; true; i += 8) {
						if (board[i] < 6) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i > 55 && i != move2) {
							break;
						}
						if (i == move2) {
							return true;
							break;
						}
					}
					for (int i = move1 - 8; true; i -= 8) {
						if (board[i] < 6) {
							break;
						}
						if (i < 8 && i != move2) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}

				}
				else {
					for (int i = move1 + 1; true; i++) {
						if (board[i] < 6) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i % 8 == 7 && i != move2) {
							break;
						}
						if (i == move2) {
							return true;
							break;
						}
					}
					for (int i = move1 - 1; true; i--) {
						if (board[i] < 6) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i % 8 == 0 && i != move2) {
							break;
						}
						if (i == move2) {
							return true;
							break;
						}
					}

				}

				// bishop
				if (move1 < move2) {
					for (int i = move1 + 9; true; i += 9) {
						if (board[i] < 6) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i > 55 || i % 8 == 0 || i % 8 == 7) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}
					for (int i = move1 + 7; true; i += 7) {
						if (board[i] < 6) {
							break;
						}
						if (i > 55 || i % 8 == 0 || i % 8 == 7) {
							if (i != move2) {
								break;
							}
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}

				}
				else {
					for (int i = move1 - 9; true; i -= 9) {
						if (board[i] < 6) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i < 8 || i % 8 == 0 || i % 8 == 7) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}
					for (int i = move1 - 7; true; i -= 7) {
						if (board[i] < 6) {
							break;
						}
						if (i < 8 || i % 8 == 0 || i % 8 == 7) {
							if (i != move2) {
								break;
							}
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							return true;
							break;
						}
					}

				}
			}
		}
	}
	return false;
}
void restoreBoard(int& capturedPiece, int move1, int move2, int enPassant, int(*board)[64], bool turn, int promotion = -1) {
	(*board)[move1] = (*board)[move2];
	(*board)[move2] = capturedPiece;
	if (move2 == enPassant) {
		if (turn) {
			(*board)[move2 - 8] = 11;
		}
		else {
			(*board)[move2 + 8] = 5;
		}
	}
	else if (move2 == promotion) {
		if (turn) {
			(*board)[move1] = 5;
		}
		else {
			(*board)[move1] = 11;
		}
	}
	if (move2 == 4 && move1 - 2 == move2) {
		(*board)[0] = 0;
		(*board)[2] = 12;
	}
	else if (move2 == 4 && move1 + 2 == move2) {
		(*board)[7] = 0;
		(*board)[4] = 12;
	}
	else if (move2 == 10 && move1 - 2 == move2) {
		(*board)[0] = 0;
		(*board)[2] = 12;
	}
	else if (move2 == 10 && move1 - 2 == move2) {
		(*board)[0] = 0;
		(*board)[2] = 12;
	}
	capturedPiece = 12;
}
int minimax(boord board, int depth, bool turn, int* enPassant, string input, int(*kingLocation)[2], bool(*castling)[4], int* tomato, int move1 = -1, int move2 = -1) {
	return 1;
}


bool validateMove(boord board, string input, int move1, int move2, bool turn, int enPassant, bool castling[4]) {
	int kingLocation[2];
	kingLocation[0] = board.kingLocation[0];
	kingLocation[1] = board.kingLocation[1];
	// castling parameter needed
	if (turn) {
		if (board[move1] == 0) {
			// rooks
			// vertical
			bool x = true;
			if (move1 % 8 == move2 % 8) {
				for (int i = move1 + 8; true; i += 8) {
					if (i > 63) {
						break;
					}
					if (board[i] < 6) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}
				for (int i = move1 - 8; true; i -= 8) {
					if (i < 0) {
						break;
					}
					if (board[i] < 6) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}

			}
			else {
				for (int i = move1 + 1; true; i++) {
					if (i % 8 == 0) {
						break;
					}
					if (board[i] < 6) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						if (i != move2) {
							break;
						}
					}

					if (i == move2) {
						x = false;
						break;
					}
				}
				for (int i = move1 - 1; true; i--) {
					if (i % 8 == 7) {
						break;
					}
					if (board[i] < 6) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}

			}
			if (x) {
				return false;
			}
		}
		else if (board[move1] == 1) {
			// knight
			if (move1 + 17 == move2 || move1 - 15 == move2) {
				if (move1 % 8 + 1 != move2 % 8) {
					return false;
				}
			}
			else if (move1 + 10 == move2 || move1 - 6 == move2) {
				if (move1 % 8 + 2 != move2 % 8) {
					return false;
				}
			}
			else if (move1 + 15 == move2 || move1 - 17 == move2) {
				if (move1 % 8 - 1 != move2 % 8) {
					return false;
				}
			}
			else if (move1 + 5 == move2 || move1 - 10 == move2) {
				if (move1 % 8 - 2 != move2) {
					return false;
				}
			}
			else {
				return false;
			}
			if (board[move2] < 6) {
				return false;
			}
		}
		else if (board[move1] == 2) {
			// bishop
			bool x = true;
			if (move1 < move2) {
				for (int i = move1 + 9; true; i += 9) {
					if (i > 63 || i % 8 == 0) {
						break;
					}
					if (board[i] < 6) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}
				for (int i = move1 + 7; true; i += 7) {
					if (i > 63 || i % 8 == 7) {
						break;
					}
					if (board[i] < 6) {
						break;
					}
					if (i > 55 || i % 8 == 0 || i % 8 == 7) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}

			}
			else {
				for (int i = move1 - 9; true; i -= 9) {
					if (i < 0 || i % 8 == 7) {
						break;
					}
					if (board[i] < 6) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}
				for (int i = move1 - 7; true; i -= 7) {
					if (i < 0 || i % 8 == 0) {
						break;
					}
					if (board[i] < 6) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}

			}
			if (x) {
				return false;
			}
		}
		else if (board[move1] == 4) {
			// king
			if (move1 - 2 == move2) {
				if (!(move1 == 3 && castling[0])) {
					return false;
				}
				if (board[2] != 12 || board[1] != 12) {
					return false;
				}
				if (inCheck(true, board, 2, -1) || inCheck(true, board, 3, -1)) {
					return false;
				}
			}
			else if (move1 + 2 == move2) {
				if (!(move1 == 3 && castling[1])) {
					return false;
				}
				if (board[4] != 12 || board[5] != 12 || board[6] != 12) {
					return false;
				}
				if (inCheck(true, board, 4, -1) || inCheck(true, board, 5, -1) || inCheck(true, board, 3, -1)) {
					return false;
				}
			}
			else if (move1 + 8 == move2 || move1 - 8 == move2) {

			}
			else if (move1 + 9 == move2 || move1 - 7 == move2 || move1 + 1 == move2) {
				if (move1 % 8 + 1 != move2 % 8) {
					return false;
				}
			}
			else if (move1 - 9 == move2 || move1 + 7 == move2 || move1 - 1 == move2) {
				if (move1 % 8 - 1 != move2 % 8) {
					return false;
				}
			}
			else {
				return false;
			}
			if (board[move2] < 6) {
				return false;
			}
		}
		else if (board[move1] == 3) {
			// queen

			// rooks
			// vertical
			bool x = true;
			if (move1 % 8 == move2 % 8) {
				for (int i = move1 + 8; true; i += 8) {
					if (i > 63) {
						break;
					}
					if (board[i] < 6) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}
				for (int i = move1 - 8; true; i -= 8) {
					if (i < 0) {
						break;
					}
					if (board[i] < 6) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}

			}
			else {
				for (int i = move1 + 1; true; i++) {
					if (i % 8 == 0) {
						break;
					}
					if (board[i] < 6) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						if (i != move2) {
							break;
						}
					}

					if (i == move2) {
						x = false;
						break;
					}
				}
				for (int i = move1 - 1; true; i--) {
					if (i % 8 == 7) {
						break;
					}
					if (board[i] < 6) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}

			}

			// bishop
			if (move1 < move2) {
				for (int i = move1 + 9; true; i += 9) {
					if (i > 63 || i % 8 == 0) {
						break;
					}
					if (board[i] < 6) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}
				for (int i = move1 + 7; true; i += 7) {
					if (i > 63 || i % 8 == 7) {
						break;
					}
					if (board[i] < 6) {
						break;
					}
					if (i > 55 || i % 8 == 0 || i % 8 == 7) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}

			}
			else {
				for (int i = move1 - 9; true; i -= 9) {
					if (i < 0 || i % 8 == 7) {
						break;
					}
					if (board[i] < 6) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}
				for (int i = move1 - 7; true; i -= 7) {
					if (i < 0 || i % 8 == 0) {
						break;
					}
					if (board[i] < 6) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}

			}
			if (x) {
				return false;
			}
		}
		else if (board[move1] == 5) {
			// pawn
			if (input[1] == '8' && input.size() == 5) {
				if (input[4] != 'n' && input[4] != 'b' && input[4] != 'q' &&
					input[4] != 'r') {
					return false;
				}
			}
			else if (input[1] == '8') {
				return false;
			}
			else if (move1 + 8 == move2) {
				if (board[move2] != 12) {
					return false;
				}
			}
			else if (move1 + 16 == move2) {
				if (board[move2] != 12 || board[move2 - 8] != 12 || input[1] != '2') {
					return false;
				}
				// captures
			}
			else if (move1 + 9 == move2) {
				if (move2 - 8 == enPassant) {
					if (move1 % 8 + 1 != move2 % 8) {
						return false;
					}
				}
				else if (move1 % 8 + 1 != move2 % 8 || board[move2] < 6) {
					return false;
				}
			}
			else if (move1 + 7 == move2) {
				if (move2 - 8 == enPassant) {
					if (move1 % 8 - 1 != move2 % 8) {
						return false;
					}
				}
				else if (move1 % 8 - 1 != move2 % 8 || board[move2] < 6) {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else if (board[move1] == 13) {
			while (true) {
				bool x = true;
				if (move1 % 8 == move2 % 8) {
					for (int i = move1 + 8; true; i += 8) {
						if (i > 63) {
							break;
						}
						if (board[i] < 6) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							x = false;
							break;
						}
					}
					for (int i = move1 - 8; true; i -= 8) {
						if (i < 0) {
							break;
						}
						if (board[i] < 6) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							x = false;
							break;
						}
					}

				}
				else {
					for (int i = move1 + 1; true; i++) {
						if (i % 8 == 0) {
							break;
						}
						if (board[i] < 6) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}

						if (i == move2) {
							x = false;
							break;
						}
					}
					for (int i = move1 - 1; true; i--) {
						if (i % 8 == 7) {
							break;
						}
						if (board[i] < 6) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							x = false;
							break;
						}
					}

				}
				if (!x) {
					break;
				}
				if (move1 + 17 == move2 || move1 - 15 == move2) {
					if (move1 % 8 + 1 != move2 % 8) {
						return false;
					}
				}
				else if (move1 + 10 == move2 || move1 - 6 == move2) {
					if (move1 % 8 + 2 != move2 % 8) {
						return false;
					}
				}
				else if (move1 + 15 == move2 || move1 - 17 == move2) {
					if (move1 % 8 - 1 != move2 % 8) {
						return false;
					}
				}
				else if (move1 + 5 == move2 || move1 - 10 == move2) {
					if (move1 % 8 - 2 != move2) {
						return false;
					}
				}
				else {
					return false;
				}
				if (board[move2] < 6) {
					return false;
				}
				break;
			}
		}
		else {
			return false;
		}
	}
	else {
		if (board[move1] == 6) {
			bool x = true;
			if (move1 % 8 == move2 % 8) {
				for (int i = move1 + 8; true; i += 8) {
					if (i > 63) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						break;
					}
					if (board[i] < 6) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}
				for (int i = move1 - 8; true; i -= 8) {
					if (i < 0) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						break;
					}
					if (i < 8 && i != move2) {
						break;
					}
					if (i == move2) {
						x = false;
						break;
					}
				}

			}
			else {
				for (int i = move1 + 1; true; i++) {
					if (i % 8 == 0) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						break;
					}
					if (board[i] < 6) {
						if (i != move2) {
							break;
						}
					}

					if (i == move2) {
						x = false;
						break;
					}
				}
				for (int i = move1 - 1; true; i--) {
					if (i % 8 == 7) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						break;
					}
					if (board[i] < 6) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}

			}
			if (x) {
				return false;
			}
		}
		else if (board[move1] == 7) {
			if (move1 + 17 == move2 || move1 - 15 == move2) {
				if (move1 % 8 + 1 != move2 % 8) {
					return false;
				}
			}
			else if (move1 + 10 == move2 || move1 - 6 == move2) {
				if (move1 % 8 + 2 != move2 % 8) {
					return false;
				}
			}
			else if (move1 + 15 == move2 || move1 - 17 == move2) {
				if (move1 % 8 - 1 != move2 % 8) {
					return false;
				}
			}
			else if (move1 + 5 == move2 || move1 - 10 == move2) {
				if (move1 % 8 - 2 != move2) {
					return false;
				}
			}
			else {
				return false;
			}
			if (board[move2] > 5 && board[move2] != 12) {
				return false;
			}
		}
		else if (board[move1] == 8) {
			bool x = true;
			if (move1 < move2) {
				for (int i = move1 + 9; true; i += 9) {
					if (i > 63 || i % 8 == 0) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						break;
					}
					if (board[i] < 6) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}
				for (int i = move1 + 7; true; i += 7) {
					if (i > 63 || i % 8 == 7) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						break;
					}
					if (board[i] < 6) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}

			}
			else {
				for (int i = move1 - 9; true; i -= 9) {
					if (i < 0 || i % 8 == 7) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						break;
					}
					if (board[i] < 6) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}
				for (int i = move1 - 7; true; i -= 7) {
					if (i < 0 || i % 8 == 0) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						break;
					}
					if (i < 8 || i % 8 == 0 || i % 8 == 7) {
						if (i != move2) {
							break;
						}
					}
					if (board[i] < 6) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}

			}
			if (x) {
				return false;
			}
		}
		else if (board[move1] == 10) {
			if (move1 - 2 == move2) {
				if (!(move1 == 59 && castling[2])) {
					return false;
				}
				if (board[58] != 12 || board[57] != 12) {
					return false;
				}
				if (inCheck(true, board, 2, 58) || inCheck(true, board, 3, 59)) {
					return false;
				}
			}
			else if (move1 + 2 == move2) {
				if (!(move1 == 59 && castling[3])) {
					return false;
				}
				if (board[60] != 12 || board[61] != 12 || board[62] != 12) {
					return false;
				}
				if (inCheck(true, board, 4, 60) || inCheck(true, board, 3, 59)) {
					return false;
				}
			}
			else if (move1 + 8 == move2 || move1 - 8 == move2) {

			}
			else if (move1 + 9 == move2 || move1 - 7 == move2 || move1 + 1 == move2) {
				if (move1 % 8 + 1 != move2 % 8) {
					return false;
				}
			}
			else if (move1 - 9 == move2 || move1 + 7 == move2 || move1 - 1 == move2) {
				if (move1 % 8 - 1 != move2 % 8) {
					return false;
				}
			}
			else {
				return false;
			}
			if (board[move2] > 5 && board[move2] != 12) {
				return false;
			}
		}
		else if (board[move1] == 9) {

			bool x = true;
			if (move1 % 8 == move2 % 8) {
				for (int i = move1 + 8; true; i += 8) {
					if (i > 63) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						break;
					}
					if (board[i] < 6) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}
				for (int i = move1 - 8; true; i -= 8) {
					if (i < 0) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						break;
					}
					if (i < 8 && i != move2) {
						break;
					}
					if (i == move2) {
						x = false;
						break;
					}
				}

			}
			else {
				for (int i = move1 + 1; true; i++) {
					if (i % 8 == 0) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						break;
					}
					if (board[i] < 6) {
						if (i != move2) {
							break;
						}
					}

					if (i == move2) {
						x = false;
						break;
					}
				}
				for (int i = move1 - 1; true; i--) {
					if (i % 8 == 7) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						break;
					}
					if (board[i] < 6) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}

			}

			if (move1 < move2) {
				for (int i = move1 + 9; true; i += 9) {
					if (i > 63 || i % 8 == 0) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						break;
					}
					if (board[i] < 6) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}
				for (int i = move1 + 7; true; i += 7) {
					if (i > 63 || i % 8 == 7) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						break;
					}
					if (board[i] < 6) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}

			}
			else {
				for (int i = move1 - 9; true; i -= 9) {
					if (i < 0 || i % 8 == 7) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						break;
					}
					if (board[i] < 6) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}
				for (int i = move1 - 7; true; i -= 7) {
					if (i < 0 || i % 8 == 0) {
						break;
					}
					if (board[i] != 12 && board[i] > 5) {
						break;
					}
					if (i < 8 || i % 8 == 0 || i % 8 == 7) {
						if (i != move2) {
							break;
						}
					}
					if (board[i] < 6) {
						if (i != move2) {
							break;
						}
					}
					if (i == move2) {
						x = false;
						break;
					}
				}

			}
			if (x) {
				return false;
			}
		}
		else if (board[move1] == 11) {
			// pawn
			if (input[1] == '1' && input.size() == 5) {
				if (input[4] != 'n' && input[4] != 'b' && input[4] != 'q' &&
					input[4] != 'r') {
					return false;
				}
			}
			else if (input[1] == '1') {
				return false;
			}
			else if (move1 - 8 == move2) {
				if (board[move2] != 12) {
					return false;
				}
			}
			else if (move1 - 16 == move2) {
				if (board[move2] != 12 || board[move2 + 8] != 12 || input[1] != '7') {
					return false;
				}
				// captures
			}
			else if (move1 - 9 == move2) {
				if (move2 + 8 == enPassant) {
					if (move1 % 8 - 1 != move2 % 8) {
						return false;
					}
				}
				else if (board[move2] == 12 || move1 % 8 - 1 != move2 % 8 ||
					board[move2] > 5) {
					return false;
				}
			}
			else if (move1 - 7 == move2) {
				if (move2 + 8 == enPassant) {
					if (move1 % 8 + 1 != move2 % 8) {
						return false;
					}
				}
				else if (board[move2] == 12 || move1 % 8 + 1 != move2 % 8 ||
					board[move2] > 5) {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else if (board[move1] == 14) {
			while (true) {
				bool x = true;
				if (move1 % 8 == move2 % 8) {
					for (int i = move1 + 8; true; i += 8) {
						if (i > 63) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							x = false;
							break;
						}
					}
					for (int i = move1 - 8; true; i -= 8) {
						if (i < 0) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (i < 8 && i != move2) {
							break;
						}
						if (i == move2) {
							x = false;
							break;
						}
					}

				}
				else {
					for (int i = move1 + 1; true; i++) {
						if (i % 8 == 0) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}

						if (i == move2) {
							x = false;
							break;
						}
					}
					for (int i = move1 - 1; true; i--) {
						if (i % 8 == 7) {
							break;
						}
						if (board[i] != 12 && board[i] > 5) {
							break;
						}
						if (board[i] < 6) {
							if (i != move2) {
								break;
							}
						}
						if (i == move2) {
							x = false;
							break;
						}
					}

				}
				if (!x) {
					break;
				}
				if (move1 + 17 == move2 || move1 - 15 == move2) {
					if (move1 % 8 + 1 != move2 % 8) {
						return false;
					}
				}
				else if (move1 + 10 == move2 || move1 - 6 == move2) {
					if (move1 % 8 + 2 != move2 % 8) {
						return false;
					}
				}
				else if (move1 + 15 == move2 || move1 - 17 == move2) {
					if (move1 % 8 - 1 != move2 % 8) {
						return false;
					}
				}
				else if (move1 + 5 == move2 || move1 - 10 == move2) {
					if (move1 % 8 - 2 != move2) {
						return false;
					}
				}
				else {
					return false;
				}
				if (board[move2] > 5 && board[move2] != 12) {
					return false;
				}
				break;
			}
			
		}
		else {
			return false;
		}
	}
	boord bord;
	bord.wPawn = board.wPawn;
	bord.wRook = board.wRook;
	bord.wBishop = board.wBishop;
	bord.wKnight = board.wKnight;
	bord.wQueen = board.wQueen;
	bord.wKnook = board.bKnook;
	bord.bPawn = board.bPawn;
	bord.bRook = board.bRook;
	bord.bBishop = board.bBishop;
	bord.bKnight = board.bKnight;
	bord.bQueen = board.bQueen;
	bord.kingLocation[0] = board.kingLocation[0];
	bord.kingLocation[1] = board.kingLocation[1];
	bord.bKnook = board.bKnook;
	int moves[2] = { move1,move2 };
	boord(*pbord) = &bord;
	updateBoard(turn, input, pbord, moves, enPassant, bord.kingLocation);
	if (inCheck(turn, board, kingLocation[0], kingLocation[1])) {
		cout << "King in check\n";
		return false;
	}
	return true;
}


int main() {
	boord board;
	bool gameEnd = false;
	bool turn = true;
	string input;
	int moves[2];
	int enPassant;

	int tomato = 0;

	int* ptomato = &tomato;
	int* penPassant = &enPassant;
	bool castling[4] = { true, true, true, true };
	//white kingside, white queenside, black kingside, black queenside
	while (!gameEnd) {
		printBoard(board);
		if (turn) {
			cout << "White to move: ";
			cin >> input;
		}
		else {
			cout << "Black to move: ";
			cin >> input;
		}
		cout << "\n";
		auto start = high_resolution_clock::now();
		moves[0] = convertMove(input.substr(0, 2));
		moves[1] = convertMove(input.substr(2, 2));

		while (!validateMove(board, input, moves[0], moves[1], turn, enPassant, castling)) {
			std::cout << u8"\033[2J\033[1;1H";
			cout << "Invalid move\n";

			printBoard(board);
			if (turn) {
				cout << "White to move: ";
				cin >> input;
			}
			else {
				cout << "Black to move: ";
				cin >> input;
			}
			moves[0] = convertMove(input.substr(0, 2));
			moves[1] = convertMove(input.substr(2, 2));
			cout << "\n";
		}

		updateBoard(&tomato, &enPassant, &board, moves, turn, input, &castling);

		turn = !turn;

		if (tomato == 100) {
			gameEnd = true;
			cout << "Game drawn by 50 move rule";
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		std::cout << u8"\033[2J\033[1;1H";
		cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
	}

	return 0;
}
