#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<ListNode *> splitListToParts(ListNode *head, int k);

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next->next = new ListNode(10);
    vector<ListNode *> v = splitListToParts(head, 3);
    for (int i = 0; i < v.size(); i++)
    {
        ListNode *current = v[i];
        while (current)
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }

    return 0;
}

vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    ListNode *current = head;
    int len = 0;
    while (current)
    {
        len++;
        current = current->next;
    }
    int n = len / k, m = len % k;
    current = head;
    vector<ListNode *> v;
    ListNode *prev;
    prev = current;
    for (int i = 0; i < k; i++)
    {
        if (!current)
        {
            v.push_back(nullptr);
            continue;
        }
        int cu = n;
        if (m>0)
        {
            m--;
            cu++;
        }
        v.push_back(current);
        while (cu-- and current)
        {
            prev = current;
            current = current->next;
        }
        prev->next = nullptr;
    }

    return v;
}