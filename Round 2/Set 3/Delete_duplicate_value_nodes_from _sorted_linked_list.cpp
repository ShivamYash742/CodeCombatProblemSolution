/*
 * Complete the 'removeDuplicates' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode *removeDuplicates(SinglyLinkedListNode *llist)
{
    SinglyLinkedListNode *current = llist, *prev = NULL;

    while (current->next != 0)
    {
        prev = current;
        current = current->next;
        if (prev->data == current->data)
        {
            prev->next = current->next;
            current = prev;
        }
    }

    return llist;
}
