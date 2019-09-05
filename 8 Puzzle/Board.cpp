#include "Board.h"

Board::Board()
{
}

Board::Board(vector<int> v)
{
	tiles = v;
	moves.clear();
	childBoard.clear();
	for (int i = 0; i < tiles.size(); i++)
		if (tiles[i] == 0)
			zeroIndex = i;
}

Board::~Board()
{
}

bool Board::isGoalState()
{
	vector<int> goalState{ 1,2,3,4,5,6,7,8,0 };
	if (tiles == goalState)
		return true;
	else
		return false;
}

void Board::up(vector<int> tiles, vector<string> moveSet)
{
	Board child;//3 = index
	child.setTiles(tiles);
	child.setZeroIndex(tiles);
	if (!moveSet.empty())child.setListOfMoves(moveSet);
	if (zeroIndex > 3) {
		int temp = child.tiles[zeroIndex - 3];
		child.tiles[zeroIndex - 3] = child.tiles[zeroIndex];
		child.tiles[zeroIndex] = temp;
		child.moves.push_back("up");
		child.setZeroIndex(tiles);
		childBoard.push_back(child);
	}
}

void Board::left(vector<int> tiles, vector<string> moveSet)
{
	Board child;//3 - # of columns
	child.setTiles(tiles);
	child.setZeroIndex(tiles);
	if (!moveSet.empty())child.setListOfMoves(moveSet);
	if (zeroIndex % 3 > 0) {
		int temp = child.tiles[zeroIndex - 1];
		child.tiles[zeroIndex - 1] = child.tiles[zeroIndex];
		child.tiles[zeroIndex] = temp;
		child.moves.push_back("left");
		child.setZeroIndex(tiles);
		childBoard.push_back(child);
	}
}

void Board::right(vector<int> tiles, vector<string> moveSet)
{
	Board child;//3 = # of columns
	child.setTiles(tiles);
	child.setZeroIndex(tiles);
	if (!moveSet.empty())child.setListOfMoves(moveSet);
	if (zeroIndex % 3 < 3 - 1) {
		int temp = child.tiles[zeroIndex + 1];
		child.tiles[zeroIndex + 1] = child.tiles[zeroIndex];
		child.tiles[zeroIndex] = temp;
		child.moves.push_back("right");
		child.setZeroIndex(tiles);
		childBoard.push_back(child);
	}

}

void Board::down(vector<int> tiles, vector<string> moveSet)
{
	Board child;//6=index
	child.setTiles(tiles);
	child.setZeroIndex(tiles);
	if (!moveSet.empty())child.setListOfMoves(moveSet);
	if (zeroIndex < 6) {
		int temp = child.tiles[zeroIndex + 3];
		child.tiles[zeroIndex + 3] = child.tiles[zeroIndex];
		child.tiles[zeroIndex] = temp;
		child.moves.push_back("down");
		child.setZeroIndex(tiles);
		childBoard.push_back(child);
	}
}

void Board::makeAMove()
{
	up(tiles, moves);
	left(tiles, moves);
	right(tiles, moves);
	down(tiles, moves);
}

int Board::childBoardSize()
{
	return childBoard.size();
}

Board Board::getChildBoard(int index)
{
	return childBoard[index];
}

vector<int> Board::getTiles()
{
	vector<int> tempvec;
	tempvec = tiles;
	return tempvec;
}

void Board::setZeroIndex(vector<int> tiles)
{
	for (int i = 0; i < tiles.size(); i++)
		if (tiles[i] == 0) zeroIndex = i;
}

void Board::setTiles(vector<int> v)
{
	tiles = v;
}

void Board::setListOfMoves(vector<string> m)
{
	moves = m;
}

void Board::printMoves()
{
	for (int i = 0; i < moves.size(); i++)
		cout << moves[i] << ' ';
}
