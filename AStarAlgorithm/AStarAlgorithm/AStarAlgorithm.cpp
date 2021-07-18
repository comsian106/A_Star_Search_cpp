#include <iostream>
#include"AStarSearch.h";

class AStarSearch;
AStarSearch m_AStarSearch;

using namespace std;

int main()
{
	auto board = m_AStarSearch.ReadBoardFromFile("grid.board");
	
	int start[2]{ 0, 0 };
	int end[2]{ 4, 5 };
	auto solution = m_AStarSearch.Search(board, start, end);

	m_AStarSearch.PrintBoard(solution);



	getchar();

	return 0;
}
