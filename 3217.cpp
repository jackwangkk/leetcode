#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *modifiedList(vector<int> &nums, ListNode *head);

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *newHead = modifiedList(nums, head);
    while (newHead)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }\

    return 0;
}

ListNode *modifiedList(vector<int> &nums, ListNode *head)
{
    unordered_set<int> numSet(nums.begin(), nums.end());
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *current = head;
    ListNode *prev = dummy;

    while (current) {
        if (numSet.find(current->val) != numSet.end()) {
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }

    ListNode *newHead = dummy->next;
    delete dummy;
    return newHead;
}