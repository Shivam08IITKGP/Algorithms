#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rep(i, start, end) for (ll i = start; i <= end; i++)
#define per(i, start, end) for (ll i = start; i >= end; i--)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define F first
#define S second
#define vll vector<ll>
#define pll pair<ll, ll>
#define vi vector<int>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;
#define int long long

vector<vector<int>> g;
vector<int> low, tin, vis;
int tim = 0;

vector<pll> ans;

void DFS(int node, int par)
{
    low[node] = tin[node] = ++tim;
    for (auto chi : g[node])
    {
        if (chi != par)
        {
            if (!vis[chi])
            {
                vis[chi] = 1;
                DFS(chi, node);
                low[node] = min(low[node], low[chi]);
                if (tin[node] < low[chi])
                {
                    ans.push_back({node, chi});
                }
            }
            else
            {
                low[node] = min(low[node], tin[chi]);
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    g.clear();
    ans.clear();
    g.resize(n + 1);
    low.clear();
    tin.clear();
    vis.clear();
    low.resize(n + 1);
    tin.resize(n + 1);
    vis.resize(n + 1);
    tim = 0;

    fr(i, m)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    rep(i, 1, n)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            DFS(i, -1);
        }
    }
    for (auto p : ans)
    {
        cout << p.F << " " << p.S << endl;
    }
}

int32_t main()
{
    FAST;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
