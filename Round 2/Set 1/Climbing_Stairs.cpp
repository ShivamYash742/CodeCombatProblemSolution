#include <iostream>
using namespace std;

int climbStairs(int n)
{
    if (n <= 2)
        return n;

    int prev2 = 1, prev1 = 2; // Base cases: 1 way to climb 1 step, 2 ways to climb 2 steps
    int current;

    for (int i = 3; i <= n; ++i)
    {
        current = prev1 + prev2; // The current step depends on the sum of the previous two steps
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}

int main()
{
    int n;
    cin >> n;

    cout << climbStairs(n) << endl;

    return 0;
}
