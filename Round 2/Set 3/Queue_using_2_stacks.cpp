#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class StackQueue
{
private:
    stack<int> s1, s2;

public:
    // Function to push an element in queue by using 2 stacks.
    void push(int B)
    {
        s1.push(B);
    }

    // Function to pop an element from queue by using 2 stacks.
    int pop()
    {
        if (s2.empty())
        {
            if (s1.empty())
                return -1;
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int k = s2.top();
        s2.pop();
        return k;
    }
};

int main()
{
    int n;
    cin >> n; // Number of operations

    StackQueue q;

    for (int i = 0; i < n; i++)
    {
        int operation;
        cin >> operation;

        if (operation == 1)
        {
            int value;
            cin >> value;
            q.push(value);
        }
        else if (operation == 2)
        {
            cout << q.pop() << endl;
        }
    }

    return 0;
}
