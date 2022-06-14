#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
map<int, deque<int>> mp;
multiset<int> cur;
vector<int> a;
vector<pair<int, int>> p, q;
vector<int> f;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, m, i, s, t, tt, ans;
    cin >> tt;
    while (tt--)
    {
        cin >> n >> m;
        a.clear();
        a.resize(n);
        for (i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        p.clear();
        q.clear();
        p.resize(m);
        q.resize(m);
        for (i = 0; i < m; ++i)
        {
            cin >> p[i].first >> p[i].second;
            p[i].first--;
            p[i].second--;
            q[i].second = p[i].first;
            q[i].first = p[i].second;
        }
        sort(p.begin(), p.end());
        sort(q.begin(), q.end());
        mp.clear();
        cur.clear();
        f.clear();
        f.resize(n, n);
        int l = 0;
        int r = 0;
        int R = 0;
        int L = n;
        for (i = 0; i < n; ++i)
        {
            auto &v = mp[a[i]];
            if (!cur.empty())
            {
                s = *cur.begin();
                cout<<"!"<<s<<endl;
                if (v.size() >= 1)
                {
                    auto loc = lower_bound(v.begin(), v.end(), s);
                    if (*loc <= v[v.size() - 1])
                    {
                        // t = min(v[v.size() - 2] - *loc + 1, v[v.size() - 1] - *(loc + 1) + 1);
                        // f[v[v.size()-2]]=min(f[v[v.size()-2],*loc]);
                        // f[v[v.size()-1]]=min(f[v[v.size()-1]],*(loc+1));
                        f[i] = *(loc);
                        R = max(R, v[v.size() - 1]);
                        loc++;
                        if (*loc)
                            L = min(L, *(loc));
                        // f[i]=min(f[i-1],*(loc+1));//i==0 would not have 2 nums and get into here.
                        // ans = max(ans, t);
                        //  cout << v[v.size() - 1] << " " << *loc << " " << *(loc + 1) << ":" << s << endl;
                    }
                }
            }
            v.push_back(i);
            while (r < m && p[r].first == i)
            {
                cur.insert(p[r].first);
                r++;
            }
            while (l < m && q[l].first == i)
            {
                cur.erase(q[l].second);
                l++;
            }
        }
        l = -1;
        ans = n;
        for (i = n - 1; i >= R; --i)
        {
            L = min(L, f[i]);
            ans = min(ans, max(0, i - L + 1));
        }
        cout << ans << endl;
    }
    return 0;
}
