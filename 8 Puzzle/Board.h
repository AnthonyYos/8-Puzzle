#pragma once
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::vector;
using std::string;
class Board
{
public:
	Board();
	Board(vector<int> v);
	~Board();
	bool isGoalState();
	void up(vector<int>tiles, vector<string> moveSet);
	void left(vector<int>tiles, vector<string> moveSet);
	void right(vector<int>tiles, vector<string> moveSet);
	void down(vector<int>tiles, vector<string> moveSet);
	void makeAMove();
	int childBoardSize();
	Board getChildBoard(int index);
	vector<int> getTiles();
	void setZeroIndex(vector<int> tiles);
	void setTiles(vector<int> v);
	void setListOfMoves(vector<string> m);
	void printMoves();
private:
	vector<Board> childBoard;
	vector<int> tiles;
	int zeroIndex;
	string move;
	vector<string> moves;
};

