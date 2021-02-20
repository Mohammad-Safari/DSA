#include <bits/stdc++.h>
#define ll long long
using namespace std;
// class heap
// {
// private:
//     ll *arr;
//     ll max_size = 0;
//     ll cur_size = 0;
//     ll heapify()
//     {
//         for (ll i = p_index(cur_size - 1); i >= 0; i--)
//             check_heap(i);
//     }
//     void check_heap(ll i)
//     {
//         if (i > p_index(cur_size - 1))
//             return;
//         ll max = i;
//         ll l = lc_index(i), r = rc_index(i);
//         max = arr[max] < arr[l] ? l : max;
//         max = arr[max] < arr[r] ? r : max;
//         if (max != i)
//         {
//             ll temp = arr[i];
//             arr[i] = arr[max];
//             arr[max] = temp;
//             check_heap(max); // goes down the heap
//         }
//     }

// public:
//     heap(ll size)
//     {
//         max_size = size;
//         cur_size = 0;
//         ll array[max_size];
//         arr = array;
//     }
//     void insert_key(ll key)
//     {
//         if (cur_size >= max_size)
//             return;
//         arr[cur_size++] = key;
//         heapify();
//         for (ll i = 0; i < cur_size; i++)
//             cout << arr[i] << " ";
//     }
//     ll indexof(ll key, bool remove = false)
//     {
//         ll i;
//         for (i = 0; i < cur_size; i++)
//             if (arr[i] == key)
//                 if (remove)
//                 {
//                     for (ll j = i + 1; j < cur_size; j++)
//                         arr[j - 1] = arr[j];
//                     heapify();
//                     break;
//                 }
//         return i;
//     }
//     ll key(ll index)
//     {
//         if (index >= cur_size)
//             return -1;
//         return arr[index];
//     }
//     ll p_index(ll i)
//     {
//         if (i != 0 && i < cur_size)
//             return (ll)((i + 1) / 2) - 1;
//         return -1;
//     }
//     ll rc_index(ll i)
//     {
//         if (i < (ll)(cur_size / 2) && i >= 0)
//             return 2 * i;
//         return -1;
//     }
//     ll lc_index(ll i)
//     {
//         if (i < (ll)(cur_size/ 2))
//             return 2 * i - 1;
//     }
// };
int main()
{
    ll num;
    ll m;
    cin >> num >> m;
    ll p[num][3];
    vector<ll> money;
    money.push_back(0);
    for (ll i = 0; i < num; i++)
    {
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    }
    //
    for (ll t = 1; t <= m; t++)
    {
        for (ll n = 0; n < num; n++)
        {
            if (t == p[n][0])
            {
                money.push_back(p[n][2]);
                make_heap(money.begin(), money.end());
            }
            else if (t == p[n][1] + 1)
            {
                money.erase(find(money.begin(), money.end(), p[n][2]));
                make_heap(money.begin(), money.end());
            }
        }
        cout << money.front() << " ";
    }
}