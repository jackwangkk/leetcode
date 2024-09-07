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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSubPath(ListNode *head, TreeNode *root);
bool dfs(ListNode *head, ListNode *cur, TreeNode *root);

int main()
{
    ListNode *head = new ListNode(2);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);

    TreeNode *root = new TreeNode(2);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);


    cout << isSubPath(head, root) << endl;

    return 0;
}

bool isSubPath(ListNode *head, TreeNode *root)
{
    if (!root)
    {
        return false;
    }

    return dfs(head, head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
}

bool dfs(ListNode *head, ListNode *cur, TreeNode *root)
{
    if (!cur)
    {
        return true;
    }

    if (!root)
    {
        return false;
    }

    if (root->val == cur->val)
    {
        return dfs(head, cur->next, root->left) || dfs(head, cur->next, root->right);
    }
    else
    {
        return false;
    }
}