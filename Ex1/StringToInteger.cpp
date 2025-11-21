#include <bits/stdc++.h>
using namespace std;
long long myAtoi(string s)
{
    long long ans = 0;
    bool pos = 1;
    bool checkedSign = 0;
    long long n = s.size();
    for (long long i = 0; i < n; i++)
    {
        if (s[i] == ' ' && checkedSign == 0)
            continue;
        if (isdigit(s[i]))
            checkedSign = 1;
        if (s[i] == '-' && checkedSign == 0)
        {
            pos = 0;
            checkedSign = 1;
            continue;
        }
        if (s[i] == '+' && checkedSign == 0)
        {
            checkedSign = 1;
            continue;
        }
        if (isdigit(s[i]))
            ans = ans * 10 + (s[i] - '0');
        if (ans > INT_MAX)
            break;
        if (!isdigit(s[i]) && checkedSign == 1)
            break;
        if (!isdigit(s[i]))
            break;
    }
    long long result;
    pos == 1 ? result = ans : result = -ans;
    if (result > INT_MAX)
        return INT_MAX;
    if (result < INT_MIN)
        return INT_MIN;
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    cout << myAtoi(s);
    return 0;
}