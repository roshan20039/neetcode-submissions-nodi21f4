class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &visited, const vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = 1;
        int dr[] = {-1, 0, 1, 0, -1};
        for(int k = 0; k < 4; k++) {
            int ni = i + dr[k];
            int nj = j + dr[k+1];
            if(ni < n and ni >= 0 and nj <m and nj >=0 and grid[ni][nj] == '1' and !visited[ni][nj]) {
                dfs(ni, nj, visited, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;  
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    if(!visited[i][j]) {
                        dfs(i,j, visited, grid);
                        count++;
                    }
                }  
            }
        }
        return count;
    }
};























