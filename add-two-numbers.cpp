/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return this->add(l1, l2, 0);
    }

    ListNode *add(ListNode *l1, ListNode *l2, int p)
    {
        int val = l1->val + l2->val + p;
        p = 0;
        if (val >= 10)
        {
            p = 1;
            val -= 10;
        }

        ListNode *node = new ListNode(val);
        ListNode *pnode = NULL;
        if (l1->next != NULL && l2->next != NULL)
        {
            pnode = this->add(l1->next, l2->next, p);
        }
        else if (l1->next != NULL)
        {
            pnode = this->add(l1->next, new ListNode(0), p);
        }
        else if (l2->next != NULL)
        {
            pnode = this->add(new ListNode(0),l2->next, p);
        }
        else if (p > 0)
        {
            pnode = new ListNode(p);
        }

        node->next = pnode;

        return node;
    }
};

int main()
{
    cout << "Hello World";
    return 0;
}
