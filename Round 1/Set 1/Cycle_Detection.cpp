// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode *head)
{
    SinglyLinkedListNode *fast = head;
    SinglyLinkedListNode *slow = head;
    while (fast != NULL && slow != NULL && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return 1;
        }
    }

    return 0;
}
