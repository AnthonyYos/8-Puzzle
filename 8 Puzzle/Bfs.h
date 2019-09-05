#pragma once
#include "Board.h"
#include <queue>
using std::queue;
class Bfs
{
public:
	Bfs();
	~Bfs();
	void doBFS(Board initalBoard);
	bool checkForRepeats(Board board, vector<Board> list);
private:

	vector<Board> visitedStates;
	vector<Board> openStates;
};

