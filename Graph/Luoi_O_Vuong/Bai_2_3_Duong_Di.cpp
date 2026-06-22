#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n, s, t;
int x1, y1;
int x2, y2;
vector<vector<char>> grid;
vector<vector<char>> grid_backup;
vector<vector<int>> d;
// vector<vector<bool>> visited(m, vector<bool>(n));

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool dfs(int i, int j)
{
    if (grid[i][j] == 'B')
        return true;

    grid[i][j] = 'X';
    for (int k = 0; k < 4; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];

        if (i1 < m && i1 >= 0 && j1 < n && j1 >= 0 && grid[i1][j1] != 'X')
        {
            if (dfs(i1, j1) == true)
                return true;
        }
    }

    return false;
}

void bfs(int i, int j) {
    queue<pair<int,int>> q;
    q.push({i,j});

    grid[i][j] = 'X';

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int i1 = v.first + dx[k];
            int j1 = v.second + dy[k];

            if (i1 < m && i1 >= 0 && j1 < n && j1 >= 0 && grid[i1][j1] != 'X')
            {
                d[i1][j1] = d[v.first][v.second] + 1;
                if (grid[i1][j1] == 'B')
                    return;

                else {
                    q.push({i1,j1});
                    grid[i1][j1] = 'X';
                }
            }
        }
    }
}

void input()
{
    cin >> m >> n;
    grid.assign(m, vector<char>(n));
    d.assign(m,vector<int> (n, 0));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                x1 = i, y1 = j;

            else if (grid[i][j] == 'B')
                x2 = i, y2 = j;
        }

    grid_backup = grid;
    bfs(x1,y1);
    // if (dfs(x1, y1))
    //     cout << "DFS: YES \n";

    // else
    //     cout << "DFS: NO \n";

    // grid = grid_backup;

    // if (bfs(x1, y1))
    //     cout << "BFS: YES \n";
    // else 
    //     cout << "BFS: NO \n"; 

    if (d[x2][y2] == 0) {
        cout << "Khong co duong di! \n"; 
    }
    
    else
        cout << "Duong di ngan nhat: " << d[x2][y2] << "\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    return 0;
}