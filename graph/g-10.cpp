#include <bits/stdc++.h>
using namespace std;

// ── Rotting Oranges ──────────────────────────────────────────

// T: O(n*m) S: O(n*m)
class RottingOranges {
private:
  int bfs(vector<vector<int>> &visited, queue<pair<int, int>> &que,
          vector<vector<int>> &grid) {
    int ans = -1;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    while (!que.empty()) {
      int size = que.size();
      ans++;
      while (size--) {
        pair<int, int> child = que.front();
        que.pop();
        for (auto it : dir) {
          int newRow = child.first + it[0];
          int newCol = child.second + it[1];
          if (newRow >= 0 && newRow < grid.size() && newCol >= 0 &&
              newCol < grid[0].size()) {
            if (!visited[newRow][newCol] && grid[newRow][newCol] == 1) {
              visited[newRow][newCol] = 1;
              grid[newRow][newCol] = 2;
              que.push({newRow, newCol});
            }
          }
        }
      }
    }
    return ans;
  }

public:
  int orangesRotting(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> que;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j] && grid[i][j] == 2) {
          visited[i][j] = 1;
          que.push({i, j});
        }
      }
    }
    int ans = bfs(visited, que, grid);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j] && grid[i][j] == 1)
          return -1;
      }
    }
    if (ans == -1)
      return 0;
    return ans;
  }
};
