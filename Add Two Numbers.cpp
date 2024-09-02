#include<iostream>
using  namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

int main()
{
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode* res = addTwoNumbers(l1, l2);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0); 
    ListNode* cur = &dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
    }
    
    return dummy.next;


    /* 
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    int carry=0;
    int sum;
    while (l1||l2||carry)
    {
        sum = (l1 ? l1->val : 0) +(l2 ? l2->val : 0) + carry;
        carry = sum / 10;
        cur->next=new ListNode(sum%10);
        cur=cur->next;
        if (l1) l1=l1->next;
        if (l2) l2=l2->next;
    }
    return dummy->next;
    */
 }