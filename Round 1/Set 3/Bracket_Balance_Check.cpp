#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string &s)
{
    stack<char> st;

    for (char ch : s)
    {
        // If it's an opening bracket, push it to the stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        // If it's a closing bracket, check for balance
        else
        {
            if (st.empty())
                return false; // No matching opening bracket
            char top = st.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '['))
            {
                st.pop(); // Pop the matching opening bracket
            }
            else
            {
                return false; // Mismatched brackets
            }
        }
    }

    // If the stack is empty, all brackets are balanced
    return st.empty();
}

int main()
{
    string s;
    cin >> s;

    // Call the function and output the boolean result
    cout << (isBalanced(s) ? "true" : "false") << endl;

    return 0;
}
