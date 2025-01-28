/*
 * Complete the 'reverse' function below.
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

SinglyLinkedListNode *reverse(SinglyLinkedListNode *llist)
{
    SinglyLinkedListNode *reverse = nullptr;
    while (llist != nullptr)
    {
        SinglyLinkedListNode *newNode = new SinglyLinkedListNode(llist->data);
        newNode->next = reverse;
        reverse = newNode;
        llist = llist->next;
    }
    return reverse;
}
