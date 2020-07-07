/**

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

Explanation: The perimeter is the 16 yellow stripes in the image below:

**/

class Solution {
public:
    int p(vector<vector<int>>& grid, int row, int col) {
        // here, grid[row][col] = 1;
        if (row == -1 || row == grid.size()
            || col == -1 || col == grid.at(0).size()) {
            return 1;
        }
        else if (grid.at(row).at(col) == 0) {
            return 1;
        }
        else if (grid.at(row).at(col) == 1) {
            // we make it 2 so as to avoid coming back to the same case
            grid.at(row).at(col) = 2;
            return p(grid, row + 1, col) 
                + p(grid, row - 1, col) 
                + p(grid, row, col + 1)
                + p(grid, row, col - 1);
        }
        return 0;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        // assumption: only 1 island exists
        if (grid.empty()) {
            return 0;
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.at(0).size(); j++) {
                if (grid.at(i).at(j)) {
                    return p(grid, i, j);
                }
            }
        }
        return 0;
    }
};
