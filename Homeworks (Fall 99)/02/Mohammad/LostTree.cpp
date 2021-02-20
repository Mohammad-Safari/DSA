#include <bits/stdc++.h>
#define ll long long
using namespace std;
// tree nodes
struct node
{
    ll entry;
    node *parent;
    node *right_child;
    node *left_child;
};
void inorder_traverse_numbering(node *cur)
{
    static ll num = 0;
    if (cur == NULL)
    {
        // ++num;
        return;
    }
    inorder_traverse_numbering(cur->left_child);
    cur->entry = ++num;
    inorder_traverse_numbering(cur->right_child);
}
int main(void)
{
    ll n;
    cin >> n;
    node *nodes[n]; // node array based on index

    for (ll i = 0; i < n; i++) // creating array of required nodes related to each node's index
        nodes[i] = ((node *)malloc(sizeof(node)));

    for (ll k = 0; k < n; k++) // now ready to create the tree(matching the created nodes)
    {
        ll i, lft_chld_ind, rght_chld_ind; // index and child properties
        cin >> i >> lft_chld_ind >> rght_chld_ind;

        --i;
        --lft_chld_ind;
        --rght_chld_ind;

        if (lft_chld_ind >= 0) // left child assignment
        {
            nodes[i]->left_child = nodes[lft_chld_ind];
            nodes[lft_chld_ind]->parent = nodes[i];
        }
        else
            nodes[i]->left_child = NULL;

        if (rght_chld_ind >= 0) // right child assignment
        {
            nodes[i]->right_child = nodes[rght_chld_ind];
            nodes[rght_chld_ind]->parent = nodes[i];
        }
        else
            nodes[i]->right_child = NULL;
    }

    node *root; // tree root
    for (ll i = 0; i < n; i++)
    {
        if (nodes[i]->parent == NULL)
        {
            root = nodes[i];
            break;
        }
    }

    inorder_traverse_numbering(root);

    for(ll i = 0; i < n; i++)
        cout << to_string(nodes[i]->entry) + " ";

    return 0;
}