

/*
 * Complete the 'deleteNode' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER position
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

SinglyLinkedListNode *deleteNode(SinglyLinkedListNode *llist, int position)
{
    SinglyLinkedListNode *ptr = llist;

    if (position == 0)
    {
        SinglyLinkedListNode *ret = llist->next;
        delete llist;
        return ret;
    }

    for (int i = 0; i < position - 1; i++)
    {
        ptr = ptr->next;
    }

    SinglyLinkedListNode *remove = ptr->next;
    ptr->next = remove->next;
    delete remove;

    return llist;
}
