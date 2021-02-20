#include <bits/stdc++.h>
#define ll long long
using namespace std;
class SuperQueue
{
protected:
    ll set[10000000];
    ll length;

public:
    SuperQueue()
    {
        length = 0;
    }
    void Enqueue(ll e, ll n = 1);
    void Dequeue(ll n = 1);
    string Peek();
};

void SuperQueue::Enqueue(ll e, ll n)
{
    // make n house offset
    for (ll i = length - 1; i >= 0; i--)
    {
        set[i + n] = set[i];
    }
    // filling offset with new elements
    for (ll i = 0; i < n; i++)
    {
        set[i] = e;
    }
    length += n;
};

void SuperQueue::Dequeue(ll n)
{
    if (length - n > 0)
        length -= n;
    else
        length = 0;
};

string SuperQueue::Peek()
{
    stringstream str;
    if (length > 0)
        return to_string(set[length - 1]);
    else
        return "empty";
}

int main(void)
{
    // {
    //     SuperQueue queue;
    //     ll q;
    //     cin >> q;
    //     string op = "";
    //     for (ll i = 0; i < q; i++)
    //     {
    //         char req;
    //         cin >> req;
    //         switch (req)
    //         {
    //         case '+':
    //         {
    //             ll t, d;
    //             cin >> t >> d;
    //             queue.Enqueue(t, d);
    //             break;
    //         }
    //         case '-':
    //         {
    //             ll t;
    //             cin >> t;
    //             queue.Dequeue(t);
    //             break;
    //         }
    //         case '?':
    //         {
    //             op += (queue.Peek() + "\n");
    //             break;
    //         }
    //         }
    //     }
    //     cout << op;
    // }
    ll q, length = 0;   // request numbers and set-length of queue
    string output = ""; // output result
    cin >> q;
    ll queue[q][2]; // set-queue array
    for (ll i = 0; i < q; i++)
    {
        char req; // type of request
        cin >> req;
        switch (req)
        {
        case '+':
        {
            ll d, t; // element and set-length
            cin >> d >> t;
            for (ll j = length - 1; j >= 0; j--)
            {
                queue[j + 1][0] = queue[j][0]; // set element
                queue[j + 1][1] = queue[j][1]; // set length
            }
            queue[0][0] = d;
            queue[0][1] = t;
            length += 1;
            break;
        }
        case '-':
        {
            ll t;
            cin >> t;
            while (length > 0 && t > 0) // till have dequeue to do and there is any set enqueued
            {
                if (queue[length - 1][1] > t) // set length be strictly more than dequeue times
                {
                    queue[length - 1][1] -= t;
                    t = 0;
                }
                else // dequeue times be more than or equal to set length
                {
                    t -= queue[length - 1][1]; // to dequeue from top set as many as possible
                    queue[length - 1][1] = 0;  // seems not necessary
                    length -= 1;               // logically dequeue the top/first set from the queue completely
                }
            }
            break;
        }
        case '?':
        {
            output += (length != 0 ? (to_string(queue[length - 1][0]) + '\n') : "empty\n");
            break;
        }
        }
    }
    cout << output;
    return 0;
};
