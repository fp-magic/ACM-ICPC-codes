#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, m, i, j, k, s, t, tt, ans;
    cin >> tt;
    while (tt--)
    {
        cin >> n >> k;
        map<int, int> cnt_tmp;
        vi cnt;
        s = k;
        rep(i, 0, n)
        {
            cin >> t;
            ++cnt_tmp[t];
        }
        for (auto p : cnt_tmp)
        {
            if (p.first <= k)
            {
                k++;
            }
            else
            {
                cnt.push_back(p.second);
            }
        }
        sort(cnt.begin(), cnt.end());
        ans = cnt.size();
        for (auto freq : cnt)
        {
            if (s >= freq)
            {
                s -= freq;
                ans--;
            }
            else
            {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
