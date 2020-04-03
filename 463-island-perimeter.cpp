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


class Solution {
public:
    
    int get_result(vector<vector<int>>& grid, int row, int col) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid.at(0).size()) {
            return 1;
        }
        else {
            if(grid.at(row).at(col) == 1) {
                grid.at(row).at(col) = -1;
                return get_result(grid, row, col + 1) 
                    + get_result(grid, row, col - 1)
                    + get_result(grid, row - 1, col)
                    + get_result(grid, row + 1, col);
            }
            else if(grid.at(row).at(col) == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.at(0).size(); j++) {
                if(grid.at(i).at(j) == 1) {
                    return get_result(grid, i, j);
                }
            }
        }
        return 0;
    }
};
