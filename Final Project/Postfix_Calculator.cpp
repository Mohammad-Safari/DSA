#include <bits/stdc++.h>
#define ll long long
#define MAX 1000000007
using namespace std;

list<char> input;
auto cursor = input.begin();
map<string, ll> cache = {};
map<char, int> priority = {
    {'*', 3},
    {'+', 2},
    {'-', 2},
    {'(', 1}};

list<char>::iterator copy_cursor()
{
    auto cursor_dup = input.begin();
    for (; cursor_dup != cursor; cursor_dup++)
        ;
    return cursor_dup;
}
void f_move_cursor()
{
    if (cursor != input.end())
        cursor++;
}
void b_move_cursor()
{
    if (cursor != input.begin())
        cursor--;
}
void append_char()
{
    char in;
    cin >> in;
    if (in == '+' || in == '-' || in == '*' || in == '(' || in == ')' || isdigit(in))
        input.insert(cursor, in);
}
void remove_char()
{
    auto pre = copy_cursor();
    if (pre != input.begin())
    {
        pre--;
        input.erase(pre);
    }
}
ll eval(char op, ll a, ll b)
{
    switch (op)
    {
    case '*':
        return (a * b)%MAX;
    case '+':
        return (a + b)%MAX;
    case '-':
        return (a - b)%MAX;

    default:
        return 0;
    }
}
ll postfix_eval(string postfix_exp)
{
    stack<ll> operand_stack;
    char *postfix_token = strtok(&postfix_exp[0], " ");
    // char *postfix_token = strtok(postfix_exp, " ");
    // istringstream iss(postfix_exp);
    // while (getline(iss, postfix_token, '-'))
    // {
    //     if(postfix_token=="")
    //     continue;
    //     cout << postfix_token << endl;
    // }
    while (postfix_token != NULL)
    {
        if (postfix_token == "")
            continue;
        else if (isdigit(postfix_token[0]))
            operand_stack.push((ll)(atoi(postfix_token)));
        else
        {
            ll b = operand_stack.top();
            operand_stack.pop(); 
            ll a = operand_stack.top();
            operand_stack.pop();
            ll result = eval(postfix_token[0], a, b);
            operand_stack.push(result);
        }
        postfix_token = strtok(NULL, " ");
    }
    ll final_res = operand_stack.top();
    return final_res;
}
string infix_to_postfix()
{
    stack<char> opstack;
    string postfix_exp = "";
    for (auto infix = input.begin(); infix != input.end(); infix++)
    {
        char ch = *infix;
        if (isdigit(ch))
            postfix_exp += ch;
        else if (ch == '(')
        {
            postfix_exp.append(" ");
            opstack.push(ch);
        }
        else if (ch == ')')
        {
            postfix_exp.append(" ");

            char top_input = opstack.top();
            opstack.pop();

            while (top_input != '(')
            {
                postfix_exp.push_back(top_input);
                postfix_exp.append(" ");

                top_input = opstack.top();
                opstack.pop();
            }
        }
        else // if an operation char
        {
            postfix_exp.append(" ");
            while (!opstack.empty())
            {
                if (priority[opstack.top()] < priority[ch])
                    break;

                postfix_exp.push_back(opstack.top());
                postfix_exp.append(" ");
                opstack.pop();
            }
            opstack.push(ch);
        }
    }
    while (!opstack.empty())
    {
        postfix_exp.append(" ");
        postfix_exp += (opstack.top());
        opstack.pop();
    }
    // cout << postfix_exp << endl;
    return postfix_exp;
}
void calculate_string()
{
    string str = "";
    for (auto it = input.begin(); it != input.end(); it++)
        str += (*it);

    if (cache.find(str) != cache.end())
        cout << cache.at(str) << endl;
    else
    {
        string postfix_exp = infix_to_postfix();
        ll result = postfix_eval(postfix_exp);
        result = result < 0 ? result + MAX: result;
        cache.insert({str, result});
        cout << result << endl;
    }
}
void print_string()
{
    auto reader = input.begin();
    for (; reader != input.end(); reader++)
        if (reader == cursor)
            cout << "|" << *reader;
        else
            cout << *reader;

    if (reader == cursor)
        cout << "|";
    cout << endl;
}
int main()
{
    ll query;
    cin >> query;

    string init;
    cin >> init;
    input.clear();
    for (auto ch = init.begin(); ch != init.end(); ch++)
        if (*ch == '+' || *ch == '-' || *ch == '*' || *ch == '(' || *ch == ')' || isdigit(*ch))
            input.push_back(*ch);

    cursor = input.begin();

    for (ll q = 0; q < query; q++)
    {
        char op;
        cin >> op;
        switch (op)
        {
        case '>':
            f_move_cursor();
            break;
        case '<':
            b_move_cursor();
            break;
        case '+':
            append_char();
            break;
        case '-':
            remove_char();
            break;
        case '!':
            calculate_string();
            break;
        case '?':
            print_string();
            break;
        default:
            continue;
        }
    }
}