#include <iostream>
#include <vector>
using namespace std;

int startStation(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    int startIdx = -1;
    for (int i = 0; i < n; i++)
    {

        // Initially car tank is empty
        int currGas = 0;
        bool flag = true;
        for (int j = 0; j < n; j++)
        {

            // Circular Index
            int idx = (i + j) % n;
            currGas = currGas + gas[idx] - cost[idx];

            // If currGas is less than zero, then it isn't
            // possible to proceed further with this starting point
            if (currGas < 0)
            {
                flag = false;
                break;
            }
        }

        // If flag is true, then we have found
        // the valid starting point
        if (flag)
        {
            startIdx = i;
            break;
        }
    }
    return startIdx;
}

int main()
{
    int n, temp;
    vector<int> gas;
    vector<int> cost;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        gas.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        cost.push_back(temp);
    }

    int ans = startStation(gas, cost);
    cout << ans;
    return 0;
}
