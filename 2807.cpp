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

ListNode *insertGreatestCommonDivisors(ListNode *head);

int find_divisor(int a, int b);

int main()
{
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    head->next->next->next->next->next = new ListNode(60);

    ListNode *result = insertGreatestCommonDivisors(head);

    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}

ListNode *insertGreatestCommonDivisors(ListNode *head)
{
    ListNode *current = head->next;
    ListNode *prev = head;
    while (current)
    {
        int divisor = find_divisor(prev->val, current->val);
        prev->next = new ListNode(divisor);
        prev->next->next = current;
        prev = current;
        current = current->next;
    }

    return head;
}

int find_divisor(int a, int b)
{
    while (a != 0)
    {
        int temp = a;
        a = b % a;
        b = temp;
    }

   return b;
}