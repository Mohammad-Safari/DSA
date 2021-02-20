#include <bits/stdc++.h>
#define ll long long
// #define Max(a, b) a > b ? a : b
using namespace std;
// struct node
// {
//     ll *entry;
//     node *parent;
//     node *right_child;
//     node *left_child;
// };
// node *array_tree_build(node *arr[], ll size)
// {
//     for (ll i = 1; i < size; i++)
//     {
//         node *tmp = arr[i];
//         ll ind = (int)((i + 1) / 2) - 1;
//         if (ind < size && ind >= 0)
//             tmp->parent = arr[ind];
//         ind = (2 * (i + 1) - 1);
//         if (ind < size && ind >= 0)
//             tmp->left_child = arr[ind];
//         ind = (2 * (i + 1));
//         if (ind < size && ind >= 0)
//             tmp->right_child = arr[ind];
//     }
// }
ll max_heap_filler(ll arr[], ll i, int size /* , bool *flag */)
{
    if (i >= size) //in condition which the last node was the child less node
        return 0ll;
    else if (arr[i] == -1) // filing this node and childs according to child keys
        arr[i] = max(max_heap_filler(arr, (2 * (i + 1) - 1), size /* , flag */),
                     max_heap_filler(arr, (2 * (i + 1)), size /* , flag */)) +
                 1;
        return arr[i];
}
int main()
{
    ///
    ll size;
    cin >> size;
    ll arr[size];
    for (ll i = 0; i < size; i++)
        cin >> arr[i];
    ///
    bool flag = true; // is heapifying possible
    // ll p_ind, l_ind, rc_ind;
    for (ll i = 0; i < size; i++)
    {
        if (arr[i] == -1)
            max_heap_filler(arr, i, size);
    }
    for (ll i = 0; i < size; i++)
    {
        ll p_ind = (int)((i + 1) / 2) - 1; // parent
        p_ind = (p_ind < size && p_ind >= 0) ? p_ind : -1;

        ll lc_ind = (2 * (i + 1) - 1); // left child
        lc_ind = (lc_ind < size && lc_ind >= 0) ? lc_ind : -1;

        ll rc_ind = (2 * (i + 1)); // right child
        rc_ind = (rc_ind < size && rc_ind >= 0) ? rc_ind : -1;
        
        // checking existing keys(nodes)
        if (p_ind != -1)
            if (arr[i] >= arr[p_ind])
            {
                flag = false;
                break;
            }

        if (lc_ind != -1)
            if (arr[i] <= arr[lc_ind])
            {
                flag = false;
                break;
            }
        if (rc_ind != -1)
            if (arr[i] <= arr[rc_ind])
            {
                flag = false;
                break;
            }
    }
    if (!flag)
    {
        cout << "-1";
        return 0;
    }
    for (ll i = 0; i < size; i++)
        cout << arr[i] << " ";
}