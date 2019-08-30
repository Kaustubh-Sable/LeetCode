// https://leetcode.com/problems/number-of-islands/submissions/

#include <iostream>
#include <vector>
using namespace std;

void markAllOnesFromTheIsland(vector<vector<string>>& grid, vector<vector<bool>>& visited, int i, int j);
int numIslands(vector<vector<string>>& grid);

int main()
{
	/* vector<vector<string> > grid{ {"1", "1", "1", "1", "0"},
								{"1", "1", "0", "1", "0"},
								{"1", "1", "0", "0", "0"},
								{"0", "0", "0", "0", "0"} };
	*/
	
	vector<vector<string> > grid{{"1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "0", "0", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"}};
	
	cout << numIslands(grid);
}

int numIslands(vector<vector<string>>& grid) 
{
	vector<vector<bool>> visited(grid.size());

	int i, j, count = 0;

	for (i = 0; i < grid.size(); i++)
		for (j = 0; j < grid[i].size(); j++)
			visited[i].push_back(false);

	for (i = 0; i < grid.size(); i++)
		for (j = 0; j < grid[i].size(); j++)
		{
			if (!visited[i][j] && grid[i][j] == "1")
			{
				count++;
				markAllOnesFromTheIsland(grid, visited, i, j);
			}
		}
	return count;
}

void markAllOnesFromTheIsland(vector<vector<string>>& grid, vector<vector<bool>>& visited, int i, int j)
{
	visited[i][j] = true;

	if (i + 1 < grid.size() && !visited[i + 1][j] && grid[i + 1][j] == "1")
	{
		markAllOnesFromTheIsland(grid, visited, i + 1, j);
	}
	if (j + 1 < grid[i].size() && !visited[i][j + 1] && grid[i][j + 1] == "1")
	{
		markAllOnesFromTheIsland(grid, visited, i, j + 1);
	}
	if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == "1")
	{
		markAllOnesFromTheIsland(grid, visited, i - 1, j);
	}
	if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == "1")
	{
		markAllOnesFromTheIsland(grid, visited, i, j - 1);
	}
}
