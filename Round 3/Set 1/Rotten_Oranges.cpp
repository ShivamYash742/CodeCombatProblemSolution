#include <iostream>
#include <vector>
#include <utility> // For std::pair
using namespace std;

class Solution
{
public:
    // Function to check if a cell is safe to rot
    bool issafe(int i, int j, int n, int m)
    {
        if (i >= 0 && i < n && j >= 0 && j < m)
            return true;
        return false;
    }

    // Function to find the minimum time required to rot all oranges
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        while (true)
        {
            bool changed = false;
            vector<pair<int, int>> v;

            // Find all rotten oranges
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == 2)
                    {
                        v.push_back({i, j});
                    }
                }
            }

            // Rot adjacent fresh oranges
            for (int k = 0; k < v.size(); k++)
            {
                int i = v[k].first;
                int j = v[k].second;

                if (issafe(i + 1, j, n, m) && grid[i + 1][j] == 1)
                {
                    grid[i + 1][j] = 2;
                    changed = true;
                }
                if (issafe(i, j + 1, n, m) && grid[i][j + 1] == 1)
                {
                    grid[i][j + 1] = 2;
                    changed = true;
                }
                if (issafe(i - 1, j, n, m) && grid[i - 1][j] == 1)
                {
                    grid[i - 1][j] = 2;
                    changed = true;
                }
                if (issafe(i, j - 1, n, m) && grid[i][j - 1] == 1)
                {
                    grid[i][j - 1] = 2;
                    changed = true;
                }
            }

            // If no more changes, break the loop
            if (changed == false)
                break;
            ans++;
        }

        // Check if any fresh orange remains
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int result = solution.orangesRotting(grid);
    cout << result << endl;

    return 0;
}
