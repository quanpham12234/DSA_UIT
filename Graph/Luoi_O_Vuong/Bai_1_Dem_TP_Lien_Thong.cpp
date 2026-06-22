#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;

        for (int i = 0;i < m; i++) {
            for (int j = 0;j < n; j++) {
                if (grid[i][j] != '0')
                {
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }

private:
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};

    void dfs(int i,int j, vector<vector<char>>& grid) {
        if (grid[i][j] == '0') return;
        int m = grid.size();
        int n = grid[0].size();

        grid[i][j] = '0';

        for (int k = 0; k < 4; k++) {
            int i1 = i + dx[k];
            int j1 = j + dy[k];

            if (i1 >= 0 && i1 < m && j1 >= 0 && j1 < n && grid[i1][j1] != '0')
                dfs(i1,j1,grid);
        }
    }

    void bfs(int i, int j, vector<vector<char>>& grid) {
        if (grid[i][j] == '0')
            return;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';

        while (!q.empty()) {
            auto v = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int i1 = v.first + dx[k];
                int j1 = v.second + dy[k];

                if (i1 >= 0 && i1 < m && j1 >= 0 && j1 < n &&
                    grid[i1][j1] != '0') {
                    q.push({i1, j1});
                    grid[i1][j1] = '0';
                }
            }
        }
    }
};