#define ll long long
#include <bits/stdc++.h>
using namespace std;
string cells[550];
ll marked[550][550] = {0};
ll route = 1;

ll n, m;
void ispath(/*ll n, ll m  , string *cells , */ ll r1, ll c1 /* ,  list<ll> r2, list<ll> c2, bool marked[] */)
{
    // ll n = sizeof(marked) / sizeof(marked[0]),
    //    m = sizeof(marked[0]) / sizeof(marked[0][0]);
    // bool flag = true;
    if (marked[r1][c1]==route)
    {
        return; //this cell has been visited
    }

    // for (list<ll>::iterator a = r2.begin(), b = c2.begin(); a != r2.end(); a++, b++)
    //     if (cells[*a][*b] != '#')
    //         if (marked[*a * m + *b] == false)
    //             flag = false; // still destination cells exist to visit

    // for (list<ll>::iterator a = r2.begin(), b = c2.begin(); a != r2.end(); a++, b++)
    // {
    //     if (cells[*a][*b] != '#') // valid dest
    //         if (r1 == *a && c1 == *b)
    //         {
    //             marked[*a * m + *b] = true;
    //             if (flag) // all valid destinations reached
    //                 return;
    //         }
    // }
    if (cells[r1][c1] == '#')
    {
        return; // blocked
    }
    marked[r1][c1] = route; //visiting the cell
    if (r1 + 1 < n)
        ispath( /* n, m, cells ,*/ r1 + 1, c1 /* ,  r2, c2,  marked */);
    if (r1 - 1 >= 0)
        ispath( /* n, m, cells ,*/ r1 - 1, c1 /* ,  r2, c2,  marked */);
    if (c1 + 1 < m)
        ispath( /* n, m, cells ,*/ r1, c1 + 1 /* ,  r2, c2,  marked */);
    if (c1 - 1 >= 0)
        ispath( /* n, m, cells ,*/ r1, c1 - 1 /* ,  r2, c2,  marked */);
    return;
}
int main()
{
    // int n, m;
    cin >> n >> m;
    // string cells[n];
    for (int i = 0; i < n; i++)
    {
        cin >> cells[i];
    }
    ll q;
    cin >> q;
    ll req[q][4];
    for (ll i = 0; i < q; i++)
    {
        cin >> req[i][0] >> req[i][1] >> req[i][2] >> req[i][3];
    }

    //--------------------------------------//
    // ll marked[n][m] = {{0}};
    for (ll i = 0; i < q; i++)
    {
        ll *tmp = req[i];
        ll arr[2] = {tmp[0] - 1, tmp[1] - 1};
        if (marked[arr[0]][arr[1]])
            continue;
        // bool marked = {0};
        ispath(/* n, m , cells, */ tmp[0] - 1, tmp[1] - 1 /* , tmp[2] - 1, tmp[3] - 1,  marked */);
        route++;
    }

    for (ll i = 0; i < q; i++)
    {
        ll *tmp = req[i];
        cout << (marked[(tmp[0] - 1)][(tmp[1] - 1)] == marked[(tmp[2] - 1)][(tmp[3] - 1)] ? "YES" : "NO") << endl;
    }
}
