#ifndef _LINKLIST_HPP_
#define _LINKLIST_HPP_
#include <initializer_list>
#include <iostream>
template<typename T>
class LinkList
{
public:
    struct ListNode {
        T val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
    LinkList()
    {
        head = new ListNode();
        tail = head;
    }
    LinkList(T first_element)
    {
        head = new ListNode(first_element);
        tail = head;
    }
    LinkList(std::initializer_list<T> inlist)
    {
        if (inlist.size() != 0)
        {
            typename std::initializer_list<T>::iterator iter = inlist.begin();
            head = new ListNode(*(inlist.begin()));
            tail = head;
            ++iter;
            for (; iter != inlist.end(); ++iter)
            {
                _push_back(*iter);
            }
        }
    }

    void print()
    {
        ListNode* p = head;
        while(p)
        {
            std::cout << p->val << "->";
            p = p->next;
        }
        std::cout << "end" << std::endl;
    }

private:
    void _push_back(T value)
    {
        ListNode* p = new ListNode(value);
        tail->next = p;
        tail = p;
    }
    ListNode* head;
    ListNode* tail;
};

#endif //_LINKLIST_CPP_