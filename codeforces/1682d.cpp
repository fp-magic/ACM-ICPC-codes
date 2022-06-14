#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ones = count(begin(s), end(s), '1');
    if (ones == 0 || ones % 2 != 0)
    {
        cout << "no\n";
        return;
    }
    cout << "yes\n";
    for (int p = 1; p < n; p++)
    {
        if (s[p - 1] == '0')
            continue;

        int i = (p + 1) % n;
        while (i != p)
        {
            int j = i;
            int prev = p;

            while (j != p)
            {
                cout << prev + 1 << ' ' << j + 1 << "\n";
                prev = j;
                j = (j + 1) % n;
                if (s[prev] == '1')
                    break;
            }
            i = j;
        }
        break;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}