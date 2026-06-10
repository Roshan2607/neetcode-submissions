#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int island_count = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                
                // OPEN land check
                if (grid[r][c] == '1') {
                    island_count++;

                    // Everything below must happen ONLY if we found land
                    queue<pair<int, int>> q;
                    q.push({r, c});
                    grid[r][c] = '0';

                    while (!q.empty()) {
                        auto [curr_r, curr_c] = q.front();
                        q.pop();

                        for (int i = 0; i < 4; i++) {
                            int nr = curr_r + dr[i];
                            int nc = curr_c + dc[i];

                            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1') {
                                q.push({nr, nc});
                                grid[nr][nc] = '0';
                            }
                        }
                    } 
                } 
                
            }
        }
        return island_count;
    }
};