Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1

Example 2:

Input:
11000
11000
00100
00011


class Solution {
public:
    void burn_the_map(vector<vector<char>>& grid, int r, int c, int rows, int cols) {
        
        grid[r][c] = 'd';
        if(r + 1 < rows && grid[r + 1][c] == '1') {
            burn_the_map(grid, r + 1, c, rows, cols); 
        }
        if(c + 1 < cols && grid[r][c + 1] == '1') {
            burn_the_map(grid, r, c + 1, rows, cols);
        }
        if(r - 1 >= 0 && grid[r - 1][c] == '1')
            burn_the_map(grid, r - 1, c, rows, cols);
        if(c - 1 >= 0 && grid[r][c - 1] == '1')
            burn_the_map(grid, r, c - 1, rows, cols);
    }
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.size() == 0) return 0;
        int count = 0; 
        int rows = grid.size(); 
        int cols = grid[0].size();
        
        for(int r = 0; r < grid.size(); r++) {
            
            for(int c = 0; c < grid[0].size(); c++) {
                
                if(grid[r][c] == '1') {
                    burn_the_map(grid, r, c, rows, cols);
                    count += 1;
                }
            }
        }
        return count;
    }
};
