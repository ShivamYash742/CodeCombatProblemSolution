#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true; // Empty list or single element is a palindrome

        // Step 1: Find the middle of the linked list
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the linked list
        ListNode *reversedHalf = reverseList(slow);

        // Step 3: Compare the first and second halves
        ListNode *firstHalf = head;
        ListNode *secondHalf = reversedHalf;
        while (secondHalf)
        { // Only iterate through the reversed half
            if (firstHalf->val != secondHalf->val)
            {
                return false; // Not a palindrome
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Optional: Restore the original list structure if required
        // reverseList(reversedHalf);

        return true; // The linked list is a palindrome
    }

private:
    // Function to reverse a linked list
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *current = head;
        while (current)
        {
            ListNode *nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }
};

// Helper function to create a linked list from a vector
ListNode *createLinkedList(const vector<int> &values)
{
    if (values.empty())
        return nullptr;

    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;

    for (size_t i = 1; i < values.size(); ++i)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

// Helper function to delete a linked list
void deleteLinkedList(ListNode *head)
{
    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    // Input: Number of elements in the list
    int n;
    cin >> n;

    // Input: Values of the linked list
    vector<int> values(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    // Create the linked list
    ListNode *head = createLinkedList(values);

    // Solution
    Solution solution;
    bool result = solution.isPalindrome(head);

    // Clean up memory
    deleteLinkedList(head);

    // Output result
    cout << (result ? 1 : 0) << endl;

    return 0;
}
