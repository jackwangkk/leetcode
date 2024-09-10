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

vector<vector<int>> spiralMatrix(int m, int n, ListNode *head);

int main()
{
    int m, n;
    cin >> m >> n;
    ListNode *head = new ListNode(1);
    ListNode *current = head;
    for (int i = 2; i <= m * n; i++)
    {
        current->next = new ListNode(i);
        current = current->next;
    }
    vector<vector<int>> matrix = spiralMatrix(m, n, head);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}

vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
{
    vector<vector<int>> matrix(m, vector<int>(n,-1));
    ListNode *current = head;
    int cx = 0, cy = -1;
    m--;
    while (current)
    {
        for (int i = 0; i < n and current; i++)
        {
            cy++;
            matrix[cx][cy] = current->val;
            current = current->next;
        }
        n--;
        for (int i = 0; i < m and current; i++)
        {
            cx++;
            matrix[cx][cy] = current->val;
            current = current->next;
        }
        m--;
        for (int i = 0; i < n and current; i++)
        {
            cy--;
            matrix[cx][cy] = current->val;
            current = current->next;
        }
        n--;
        for (int i = 0; i < m and current; i++)
        {
            cx--;
            matrix[cx][cy] = current->val;
            current = current->next;
        }
        m--;
    }

    return matrix;
}