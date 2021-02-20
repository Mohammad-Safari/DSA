#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    int entry;
    node *next;
    node(int e)
    {
        entry = e;
    }
    void add_next_to_end(node *n)
    {
        next = n;
    }
    void remove_next_to_end()
    {
        next = NULL;
    }
};
int main(void)
{
    int num, move;
    cin >> num >> move;
    node *heads[num]; // each column

    for (int i = 0; i < num; i++) // initializing stacks
    {
        heads[i] = new node(0);                     // head node
        heads[i]->add_next_to_end(new node(i + 1)); // box node
    }
    for (int i = 0; i < move; i++) // moving all boxes from origin to target
    {
        int origin, target;
        cin >> origin >> target;
        node *cur = heads[--target];
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->add_next_to_end(heads[--origin]->next);
        heads[origin]->remove_next_to_end();
    }
    int s;
    cin >> s;
    node *cur = heads[--s];
    int count = 0;
    string result = "";
    while (cur->next != NULL)
    {
        cur = cur->next;
        result += to_string(cur->entry) + " ";
        count++;
    }
    if (count != 0)
    {
        result = to_string(count) + " " + result.substr(0, result.size() - 1);
        cout << result;
    }
}