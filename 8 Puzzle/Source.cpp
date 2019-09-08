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

	int numberOfBoards;
	string value;
	vector<vector<int>> puzzlePieces;
	int placedPieces = 0;
	int puzzleIndex = 0;

	read >> numberOfBoards;
	puzzlePieces.resize(numberOfBoards);//Resize vector to have n amount of boards

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
	//Push a board into puzzleBoards each intialized with its own arrangement
	vector<Board> puzzleBoards;
	for (int i = 0; i < puzzlePieces.size(); i++) {
		puzzleBoards.push_back(Board(puzzlePieces[i]));
	}

	for (int i = 0; i < puzzleBoards.size(); i++) {
		Bfs bfs;
		cout << "Puzzle " << i << endl;
		bfs.doBFS(puzzleBoards[i]);
		cout << endl;
	}

}