#include "AStarSearch.h"


AStarSearch::AStarSearch() {
}
AStarSearch::~AStarSearch(){
}

void AStarSearch::PrintBoard(vector<vector<State>> grid) {
	for (auto& row : grid) {
		for (auto& col : row) {
			cout << GetCellString(col)<<" ";
		}
		cout << endl;
		
	}
}

vector<vector<State>> AStarSearch::ReadBoardFromFile(string filePath) {
	vector<vector<State>> board;
	ifstream myFile;
	myFile.open(filePath);
	
	if(myFile.is_open()){
		while (myFile.good()) {
			string line;
			getline(myFile, line);
			auto col = ParseLine(line);
			board.push_back(col);
		}
	}

	return board;
	//PrintBoard(board);


}


vector<State> AStarSearch::ParseLine(string line) {
	vector<State> col{};
	istringstream stream{ line };
	int i;
	char c;
	while (stream >> i >> c) {
		col.push_back(i==0? State::Empty : State::Obstacle);
	}

	return col;
}

string AStarSearch::GetCellString(State state) {
	switch (state)
	{
		{
	case State::Obstacle:
		return "#";
	case State::Path:
		return "*";
	
	case State::kStart:
		return "=";
	case State::kFinish:
		return "+";
	default:
		return "0 ";
		}
	}
}


vector<vector<State>> AStarSearch::Search(vector<vector<State>> grid, int init[2], int goal[2])
{
	// Create the vector of open nodes.
	vector<vector<int>> open{};

	// Initialize the starting node.
	int x = init[0];
	int y = init[1];
	int g = 0;
	int h = Heuristic(x, y, goal[0], goal[1]);
	AddToOpen(x, y, g, h, open, grid);

	while (open.size() > 0)
	{
		// Get the next node
		SortCells(&open);
		auto current = open.back();
		open.pop_back();
		x = current[0];
		y = current[1];
		grid[x][y] = State::Path;

		// Check if we're done.
		if (x == goal[0] && y == goal[1])
		{
			// TODO: Set the init grid cell to kStart, and
			// set the goal grid cell to kFinish before returning the grid.
			grid[init[0]][init[1]] = State::kStart;
			grid[goal[0]][goal[1]] = State::kFinish;
			return grid;
		}

		// If we're not done, expand search to current node's neighbors.
		ExpandNeighbours(current, open, grid, goal);
	}

	// We've run out of new nodes to explore and haven't found a path.
	cout << "No path found!"
		<< "\n";
	return std::vector<vector<State>>{};
}

int AStarSearch::Heuristic(int x1, int y1, int x2, int y2) {
	return abs(x2 - x1) + abs(y2 - y1);
}

void AStarSearch::AddToOpen(int x, int y, int g, int h, vector<vector<int>>& openList, vector<vector<State>>& grid) {
	openList.push_back(vector<int>{x, y, g, h});
	grid[x][y] = State::Closed;
}

bool AStarSearch::CompareCell(vector<int> node1, vector<int> node2) {
	/*int f1 = node1[2] + node1[3];
	int f2 = node2[2] + node2[3];

	return f1 > f2;*/

	return false;
}

void AStarSearch::SortCells(vector<vector<int>>* vec) {
	auto Compare = [](vector<int> node1, vector<int> node2) {
		int f1 = node1[2] + node1[3];
		int f2 = node2[2] + node2[3];

		return f1 > f2;
	};

	std::sort(vec->begin(), vec->end(), Compare);
}


bool AStarSearch::CheckValidCell(int x, int y, vector<vector<State>>& grid) {
	bool on_grid_x = (x >= 0 && x < grid.size());
	bool on_grid_y = (y >= 0 && y < grid[0].size());
	if (on_grid_x && on_grid_y)
		return grid[x][y] == State::Empty;
	return false;
}

void AStarSearch::ExpandNeighbours(const vector<int> &current, vector<vector<int>>& open, vector<vector<State>>& grid, int goal[2]) {
	// directional deltas
	const int delta[4][2]{ {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
	// current node data
	int x = current[0];
	int y = current[1];
	int g = current[2];
	int h = Heuristic(x, y, goal[0], goal[1]);
	for (auto i : delta)
	{
		int x2 = x + i[0];
		int y2 = y + i[1];
		if (CheckValidCell(x2, y2, grid))
		{
			int g2 = g + 1;
			int h2 = Heuristic(x2, y2, goal[0], goal[1]);
			AddToOpen(x2, y2, g2, h2, open, grid);
		}
	}
	
}