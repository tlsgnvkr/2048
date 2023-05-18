#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;

#define LEFT 97
#define RIGHT 100
#define UP 119
#define DOWN 115
#define END 99

int score = 0;
int act;

vector<vector<int>> board(4, vector<int>(4, 0));

void printBoard(void);
void randNum(void);
int checkGameOver(void);
int checkGameClear(void);
void left(void);
void right(void);
void up(void);
void down(void);
void gameCrash(void);
void boardClear(void);
void afterAct(void);

void printBoard(void) {
	system("cls");
	cout << "忙式式式式式式成式式式式式式成式式式式式式成式式式式式式忖" << endl;
	for (int i = 0; i < 4; i += 1) {
		cout << "弛      弛      弛      弛      弛" << endl;
		for (int j = 0; j < 4; j += 1) {
			cout << "弛";
			if (board[i][j] == 0) {
				cout << "      ";
			}
			else {
				cout << " ";
				cout.width(4);
				cout << board[i][j];
				cout << " ";
			}
		}
		cout << "弛" << endl;
		cout << "弛      弛      弛      弛      弛" << endl;
		if (i != 3) cout << "戍式式式式式式托式式式式式式托式式式式式式托式式式式式式扣" << endl;
		else cout << "戌式式式式式式扛式式式式式式扛式式式式式式扛式式式式式式戎";
	}
	cout << endl << "Score : " << score << endl;
}

void randNum(void) {
	int cnt = 0;
	int* generator[16] = { 0 };

	for (int i = 0; i < 4; i += 1) {
		for (int j = 0; j < 4; j += 1) {
			if (board[i][j] == 0) {
				generator[cnt] = &board[i][j];
				cnt += 1;
			}
		}
	}

	*generator[rand() % cnt] = (rand() % 100 <= 80) ? 2 : 4;
}

int checkGameOver(void) {
	int i, j;
	for (i = 0; i < 4; i += 1) {
		for (j = 0; j < 4; j += 1) {
			if (board[i][j] == 0) {
				return 0;
			}
		}
	}
	for (i = 0; i < 4; i += 1) {
		for (j = 0; j < 3; j += 1) {
			if (board[i][j] == board[i][j + 1]) {
				return 0;
			}
		}
	}
	for (j = 0; j < 4; j += 1) {
		for (i = 0; i < 3; i += 1) {
			if (board[i][j] == board[i + 1][j]) {
				return 0;
			}
		}
	}
	printf("Game Over\n");
	return 1;
}

int checkGameClear(void) {
	for (int i = 0; i < 4; i += 1) {
		for (int j = 0; j < 4; j += 1) {
			if (board[i][j] == 2048) {
				printf("Game Clear\n");
				return 1;
			}
		}
	}
	return 0;
}
void left(void) {
	int hit = 0;
	int i, j, k;
	for (i = 0, act = 0; i < 4; i += 1) {
		for (j = 1; j <= 3; j += 1) {
			for (k = j; k > 0; k -= 1) {
				if (board[i][k] == 0 || board[i][k] > 10000) {
					break;
				}
				if (board[i][k - 1] != 0 && board[i][k - 1] != board[i][k]) {
					break;
				}
				if (board[i][k - 1] == 0) {
					board[i][k - 1] = board[i][k];
				}
				else if (board[i][k] == board[i][k - 1]) {
					board[i][k - 1] *= 2;
					board[i][k - 1] += 10000;
					score += 2 * (board[i][k]);
				}
				board[i][k] = 0;
				act += 1;
			}
		}
	}
}

void right(void) {
	int hit = 0;
	int i, j, k;
	for (i = 0, act = 0; i < 4; i += 1) {
		for (j = 2; j >= 0; j -= 1) {
			for (k = j; k < 3; k += 1) {
				if (board[i][k] == 0 || board[i][k] > 10000) {
					break;
				}
				if (board[i][k + 1] != 0 && board[i][k + 1] != board[i][k]) {
					break;
				}
				if (board[i][k + 1] == 0) {
					board[i][k + 1] = board[i][k];
				}
				else if (board[i][k] == board[i][k + 1]) {
					board[i][k + 1] *= 2;
					board[i][k + 1] += 10000;
					score += 2 * (board[i][k]);
				}
				board[i][k] = 0;
				act += 1;
			}
		}
	}
}

void up(void) {
	int hit = 0;
	int i, j, k;
	for (j = 0, act = 0; j < 4; j += 1) {
		for (i = 1; i <= 3; i += 1) {
			for (k = i; k > 0; k -= 1) {
				if (board[k][j] == 0 || board[k][j] > 10000) {
					break;
				}
				if (board[k - 1][j] != 0 && board[k - 1][j] != board[k][j]) {
					break;
				}
				if (board[k - 1][j] == 0) {
					board[k - 1][j] = board[k][j];
				}
				else if (board[k][j] == board[k - 1][j]) {
					board[k - 1][j] *= 2;
					board[k - 1][j] += 10000;
					score += 2 * (board[k][j]);
				}
				board[k][j] = 0;
				act += 1;
			}
		}
	}
}

void down(void) {
	int hit = 0;
	int i, j, k;
	for (j = 0, act = 0; j < 4; j += 1) {
		for (i = 2; i >= 0; i -= 1) {
			for (k = i; k < 3; k += 1) {
				if (board[k][j] == 0 || board[k][j] > 10000) {
					break;
				}
				if (board[k + 1][j] != 0 && board[k + 1][j] != board[k][j]) {
					break;
				}
				if (board[k + 1][j] == 0) {
					board[k + 1][j] = board[k][j];
				}
				else if (board[k][j] == board[k + 1][j]) {
					board[k + 1][j] *= 2;
					board[k + 1][j] += 10000;
					score += 2 * (board[k][j]);
				}
				board[k][j] = 0;
				act += 1;
			}
		}
	}
}

void gameCrash(void) {
	printf("Game Over\n");
	exit(0);
}

void boardClear(void) {
	int i, j;
	for (i = 0; i < 4; i += 1) {
		for (j = 0; j < 4; j += 1) {
			if (board[i][j] > 10000) {
				board[i][j] -= 10000;
			}
		}
	}
}

void afterAct(void) {
	randNum();
	printBoard();
	if (checkGameOver()) {
		exit(0);
	}
	if (checkGameClear()) {
		exit(0);
	}
}

int main(void) {
	int key;
	randNum();
	randNum();
	printBoard();

	while (1) {
		key = _getch();
		switch (key) {
		case LEFT: left();
			break;

		case RIGHT: right();
			break;

		case UP: up();
			break;

		case DOWN: down();
			break;

		case END: gameCrash();
			break;

		}

		boardClear();
		if (act > 0) {
			afterAct();
		}
	}
}