#include "Bfs.h"
#include<iostream>
using std::cout;
using std::endl;
Bfs::Bfs()
{
}

Bfs::~Bfs()
{
}

void Bfs::doBFS(Board initalBoard)
{
	//Initial check if board is already in a goal state
	if (initalBoard.isGoalState()) {
		cout << "we did w/o bfs" << endl;
		return;
	}
	//Push board into openstates, board states that haven't been checked
	openStates.push_back(initalBoard);

	//Check the next board 
	while (!openStates.empty()) {
		Board currentBoardState = openStates.front();
		visitedStates.push_back(currentBoardState);
		openStates.erase(openStates.begin());
		if (currentBoardState.isGoalState()) {
			currentBoardState.printMoves();
			return;
		}
		else {
			//Create a new set  of childboards of legal moves in a cardinal direction
			currentBoardState.makeAMove();
			//Check if a childboard is a state that has been visited or it will be visited, if not for both push it into the openStates for checking
			for (int i = 0; i < currentBoardState.childBoardSize(); i++) {
				Board child = currentBoardState.getChildBoard(i);
				if (!checkForRepeats(child, visitedStates) && !checkForRepeats(child, openStates)) {
					child.setZeroIndex(child.getTiles());
					openStates.push_back(child);
				}
			}
		}
	}
	if (openStates.empty()) {
		cout << "No solution found" << endl;
		return;
	}
}

//Check to see if a board's state is seen in the list
bool Bfs::checkForRepeats(Board checkBoard, vector<Board> list) {
	vector<int> boardTiles = checkBoard.getTiles();
	for (int i = 0; i < list.size(); i++) {
		vector<int> listOfTiles = list[i].getTiles();
		if (listOfTiles == boardTiles)
			return true;
	}
	return false;
}
