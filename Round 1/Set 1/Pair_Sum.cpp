#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void findTwoSumIndices()
{
    // Read input
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;

    // Hash map to store numbers and their indices
    unordered_map<int, int> numToIndex;

    for (int i = 0; i < n; ++i)
    {
        int complement = target - nums[i];

        // Check if the complement exists in the hash map
        if (numToIndex.find(complement) != numToIndex.end())
        {
            // Print indices in ascending order
            cout << min(i, numToIndex[complement]) << " " << max(i, numToIndex[complement]) << endl;
            return;
        }

        // Store the current number and its index in the hash map
        numToIndex[nums[i]] = i;
    }
}

int main()
{
    findTwoSumIndices();
    return 0;
}
