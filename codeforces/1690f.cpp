#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void getnext1(vector<int> &next1, string &s) {
    int m = s.length();
    next1.clear();
    next1.resize(m + 1);
    next1[0] = -1;
    int j = 0;
    int k = -1;
    while (j < m) {
        if (k == -1 || s[j] == s[k])
            next1[++j] = ++k;
        else
            k = next1[k];
    }
}

int cnt(string &s) {
    vector<int> next1;
    getnext1(next1, s);
    int t = s.length() - next1[s.length()];
    return s.length() % t == 0 ? t : s.length();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    vector<int> a;
    string s;
    int n, i, k, tt;
    ll ans;
    vector<bool> vit;
    cin >> tt;
    while (tt--) {
        cin >> n;
        cin >> s;
        a.resize(n);
        for (i = 0; i < n; ++i)cin >> a[i], --a[i];
        ans = 1;
        vit.clear();
        vit.resize(n, false);
        for (i = 0; i < n; ++i) {
            if (vit[i])continue;
            vit[i] = true;
            k = i;
            string cur = "";
            cur += s[i];
            while (a[k] != i) {
                k = a[k];
                vit[k] = true;
                cur.push_back(s[k]);
            }
            ll p = cnt(cur);
            //cout << i << " " << p << endl;
            ans = ans * p / __gcd(ans, p);
        }
        cout << ans << "\n";
    }
    return 0;
}