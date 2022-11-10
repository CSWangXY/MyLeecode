//自顶向下方法实现归并排序
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *sortlist1(ListNode *head, ListNode *tail)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == tail)
        {
            head->next = nullptr;
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
                fast = fast->next;
        }
        return merge(sortlist1(head, slow), sortlist1(slow, tail));
    }

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        if (l1->val <= l2->val)
        {
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
    ListNode *sortList(ListNode *head)
    {
        return sortlist1(head, nullptr);
    }
};