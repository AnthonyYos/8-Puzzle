#include <iostream>
#include <fstream>
#include <queue>
#include "Board.h"
#include "Bfs.h"
#include <time.h>

using namespace std;

void main() {
	ifstream read("Input.txt");
	if (!read.is_open()) {
		cout << "Failed to open file";
		exit(1);
	}

	int numberOfGrids;
	string value;
	vector<vector<int>> puzzlePieces;
	int placedPieces = 0;
	int puzzleIndex = 0;

	read >> numberOfGrids;
	puzzlePieces.resize(numberOfGrids);//Resize vector to have n amount of 

	while (read >> value) {
		if (placedPieces == 9) {
			puzzleIndex++;
			placedPieces = 0;
		}

		if (value == "E")
			puzzlePieces[puzzleIndex].push_back(0);
		else {
			int x = stoi(value);
			puzzlePieces[puzzleIndex].push_back(x);
		}
		placedPieces++;
	}
	//vector<Node> board; each board[i] is a vector of tiles for one board
	vector<Board> boards;
	for (int i = 0; i < puzzlePieces.size(); i++) {
		boards.push_back(Board(puzzlePieces[i]));
	}

	for (int i = 0; i < boards.size(); i++) {
		Bfs bfs;
		cout << "Puzzle " << i << endl;
		bfs.doBFS(boards[i]);
		cout << endl;
	}

}