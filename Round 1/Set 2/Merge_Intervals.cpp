#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    for (auto interval : intervals)
    {
        // if the list of merged intervals is empty or if the current
        // interval does not overlap with the previous, simply append it.
        if (merged.empty() || merged.back()[1] < interval[0])
        {
            merged.push_back(interval);
        }
        // otherwise, there is overlap, so we merge the current and previous
        // intervals.
        else
        {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }

    return merged;
}

int main()
{
    int n;
    cin >> n;
    vector<int> temp;
    vector<vector<int>> intervals(n, vector<int>(2));
    vector<vector<int>> merged;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> intervals[i][j];
        }
    }

    merged = merge(intervals);

    for (int i = 0; i < merged.size(); i++)
    {
        cout << merged[i][0] << " ";
        for (int j = 1; j < merged[i].size(); j++)
        {
            cout << merged[i][j];
        }
        if (i != merged.size() - 1)
        {
            cout << "\n";
        }
    }

    return 0;
}
