#include <iostream>
#include <cmath>
using namespace std;

// Definition of a node in the linked list
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to append a node to the linked list
void appendNode(Node *&head, int data)
{
    if (head == nullptr)
    {
        head = new Node(data);
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new Node(data);
    }
}

// Function to convert binary linked list to decimal
int binaryToDecimal(Node *head)
{
    int result = 0;

    // Traverse the linked list
    while (head != nullptr)
    {
        result = result * 2 + head->data;
        head = head->next;
    }

    return result;
}

int main()
{
    int n;
    cin >> n; // Number of nodes in the linked list

    Node *head = nullptr;

    // Input the binary digits and create the linked list
    for (int i = 0; i < n; ++i)
    {
        int binaryDigit;
        cin >> binaryDigit;
        appendNode(head, binaryDigit);
    }

    // Output the decimal equivalent
    cout << binaryToDecimal(head) << endl;

    return 0;
}
