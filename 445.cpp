#include <iostream>
#include "LinkList.hpp"

class Solution {
public:
    typedef struct ListNode<int> ListNode;
    ListNode* reverseList(ListNode* head)
    {
        if (!head) return head;
        if (!head->next) return head;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        ListNode *p3 = head->next->next;
        p1->next = nullptr;
        while (p3)
        {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;   
        }
        p2->next = p1;
        
        return p2;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rl1 = reverseList(l1);
        ListNode* rl2 = reverseList(l2);
        ListNode* result, *p = nullptr;
        int carry = 0;
        int temp;
        while (!rl1->next && !rl2->next)
        {
            temp = rl1->val + rl2->val + carry;
            if (temp > 10)
            {
                carry = 1;
                temp = temp%10;
            }
            else
            {
                carry = 0;
            }
            result = new ListNode(temp);
            result->next = p;
            p = result;
        }
        if (carry == 1)
        {
            result = new ListNode(temp);
            result->next = p;
            p = result;
        }
        return result;
    }
};

int main()
{
    Solution solu;
    LinkList<int> l1 = {1, 2, 3, 4};
    LinkList<int> l2 = {4, 3, 2, 1};
    LinkList<int> l3;
    l3.set_head(solu.addTwoNumbers(l1.get_head(), l2.get_head()));
    l3.print();

    return 0;
}