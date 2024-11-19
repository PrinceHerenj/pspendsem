#include <iostream>
#include <vector>
using namespace std;

bool issafe(int newx, int newy, vector<vector<bool>> &vis, vector<vector<int>> &arr, int n) {
    return (newx >= 0 && newx < n && newy >= 0 && newy < n && !vis[newx][newy] && arr[newx][newy] == 1);
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &vis, string path) {
    if (x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }

    // Define directions: (dx, dy) and their corresponding move characters
    vector<pair<int, int>> directions = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};  // down, left, right, up
    string directionChars = "DLRU"; // Corresponding move characters
    
    for (int i = 0; i < 4; ++i) {
        int newX = x + directions[i].first;
        int newY = y + directions[i].second;

        if (issafe(newX, newY, vis, arr, n)) {
            vis[x][y] = 1;
            solve(newX, newY, arr, n, ans, vis, path + directionChars[i]);
            vis[x][y] = 0;
        }
    }
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vector<string> ans;
    if (arr[0][0] == 0) return ans;  // Starting point is blocked, no solution
    solve(0, 0, arr, n, ans, vis, "");
    return ans;
}

int main() {
    vector<vector<int>> arr = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = 4;
    
    vector<string> result = searchMaze(arr, n);
    
    for (const string &path : result) {
        cout << path << endl;
    }
    
    return 0;
}
