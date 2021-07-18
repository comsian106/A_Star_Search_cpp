#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include<math.h>
#include<algorithm>


using namespace std;

enum State{Obstacle, 
	Empty, 
	Open, 
	Closed, 
	Path, 
	kStart,
	kFinish
};

class AStarSearch

{
public:
	AStarSearch();
	~AStarSearch();
	


	void PrintBoard(vector<vector<State>> grid);
	vector<vector<State>> ReadBoardFromFile(string file);
	vector<State> ParseLine(string line);
	string GetCellString(State state);
	vector<vector<State>> Search(vector<vector<State>> grid, int start[2], int end[2]);
	int Heuristic(int x1, int y1, int x2, int y2);
	void AddToOpen(int x, int y, int g, int h, vector<vector<int>>& open, vector<vector<State>>& grid);
	bool CompareCell(vector<int> node1, vector<int> node2);
	void SortCells(vector<vector<int>>* vec);
	bool CheckValidCell(int x, int y, vector<vector<State>>& grid);
	void ExpandNeighbours(const vector<int> &currentNode, vector<vector<int>>& open, vector<vector<State>>& grid, int goal[2]);
};
