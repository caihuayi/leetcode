#ifndef _LINKLIST_HPP_
#define _LINKLIST_HPP_
#include <initializer_list>
#include <iostream>

template<typename T>
struct ListNode {
        T val;
        ListNode *next;
        ListNode(T x) : val(x), next(nullptr) {}
};

template<typename T>
class LinkList
{
public:
    LinkList()
    {
        
    }

    LinkList(T first_element)
    {
        head = new ListNode<T>(first_element);
        tail = head;
    }
    LinkList(std::initializer_list<T> inlist)
    {
        if (inlist.size() != 0)
        {
            typename std::initializer_list<T>::iterator iter = inlist.begin();
            head = new ListNode<T>(*(inlist.begin()));
            tail = head;
            ++iter;
            for (; iter != inlist.end(); ++iter)
            {
                _push_back(*iter);
            }
        }
    }

    ListNode<T>* get_head() const
    {
        return head;
    }
    void set_head(ListNode<T>* head)
    {
        this->head = head;
        ListNode<T> *p = head;
        while(p->next)
        {
            p = p->next;
        }
        this->tail = p;
    }

    void print()
    {
        ListNode<T>* p = head;
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
        ListNode<T>* p = new ListNode<T>(value);
        tail->next = p;
        tail = p;
    }
    ListNode<T>* head;
    ListNode<T>* tail;
};

#endif //_LINKLIST_CPP_