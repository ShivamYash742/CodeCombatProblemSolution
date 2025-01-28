#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Function to reverse a queue
void reverseQueue(queue<int> &q)
{
    stack<int> s;

    // Push all elements of the queue onto a stack
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    // Push all elements back into the queue from the stack
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    int n;
    cin >> n; // Number of elements in the queue

    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        q.push(x); // Input elements of the queue
    }

    reverseQueue(q); // Reverse the queue

    // Print the reversed queue
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
