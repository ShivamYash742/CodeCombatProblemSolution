#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For INT_MAX
using namespace std;

class Solution
{
public:
    // Function to find the minimum difference
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        // If there are no packets or no students, return 0
        if (n == 0 || m == 0)
        {
            return 0;
        }

        // If the number of students is greater than the number of packets, return 0
        if (m > n)
        {
            return 0;
        }

        // Sort the array
        sort(a.begin(), a.end());

        // Initialize the minimum difference to a large value
        long long min_diff = LONG_MAX;

        // Use a sliding window of size m to find the minimum difference
        for (long long i = 0; i + m - 1 < n; i++)
        {
            long long diff = a[i + m - 1] - a[i];
            if (diff < min_diff)
            {
                min_diff = diff;
            }
        }

        return min_diff;
    }
};

int main()
{
    Solution solution;
    long long n, m;

    cin >> n;

    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;

    long long result = solution.findMinDiff(a, n, m);
    cout << result << endl;

    return 0;
}
