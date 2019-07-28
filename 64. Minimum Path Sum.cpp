class Solution {
public:
    void min(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& new_grid) {
        if (0x00 == x && 0x00 == y) {
            new_grid[x][y] = grid[0][0];
            return;
        } else if (0x00 == x) {
            new_grid[x][y] = new_grid[x][y-1] + grid[x][y];
            return;
        } else if (0x00 == y) {
            new_grid[x][y] = new_grid[x-1][y] + grid[x][y];
            return;
        } 
        int left_value = new_grid[x][y-1];
        int up_value = new_grid[x-1][y];
        int min = left_value < up_value ? left_value : up_value;
        new_grid[x][y] =  min + grid[x][y];
        return;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> new_grid = grid;
        int rows = grid.size();
        int columns = grid[0].size();
        int i = 0;
        for (; i<rows; i++) {
            int j = 0;
            for (; j< columns; j++) {
                this->min(grid, i, j, new_grid);
            }
        }
        return new_grid[rows-1][columns-1];
    }
};
