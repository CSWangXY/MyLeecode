#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *insertionSortList(ListNode *head)
{
    if (head == nullptr)
        return nullptr;

    ListNode *dummy = new ListNode(-6000, head);
    ListNode *curr = head;
    ListNode *last = dummy;
    while (curr != nullptr)
    {
        if (curr->val >= last->val)
        {
            last->next = curr;
            last = curr;
            curr = curr->next;
        }
        else
        {
            ListNode *tmp = dummy;
            while (tmp->next->val < curr->val)
            {
                tmp = tmp->next;
                cout << 2;
            }
            last->next = last->next->next;
            curr->next = tmp->next;
            tmp->next = curr;
            curr = last->next;
        }
    }
    return dummy->next;
}

int main()
{
    ListNode *d = new ListNode(3);
    ListNode *c = new ListNode(1, d);
    ListNode *b = new ListNode(2, c);
    ListNode *a = new ListNode(4, b);
    insertionSortList(a);
}