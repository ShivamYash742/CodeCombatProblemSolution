#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &tree)
    {
        unordered_map<int, int> count; // Map to store the count of each fruit type
        int i = 0, j = 0;              // Two pointers for the sliding window

        // Iterate through the tree array
        for (; j < tree.size(); ++j)
        {
            count[tree[j]]++; // Increment the count of the current fruit type

            // If more than 2 types of fruits are in the window, move the left pointer
            if (count.size() > 2)
            {
                if (--count[tree[i]] == 0)
                {
                    count.erase(tree[i]); // Remove the fruit type if its count drops to 0
                }
                i++; // Move the left pointer
            }
        }

        // Return the size of the largest window with at most 2 types of fruits
        return j - i;
    }
};

int main()
{
    Solution solution;
    int n;

    cin >> n;

    vector<int> tree(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }

    // Call the totalFruit function and print the result
    int result = solution.totalFruit(tree);
    cout << result << endl;

    return 0;
}
