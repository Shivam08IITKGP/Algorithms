const int V = 2e5 + 5;
graph g(V);
vi low, tin, parent, vis, AP;
int n;

int tim = 0;
void DFS(int node, int par)
{
    int child = 0;
    low[node] = tin[node] = ++tim;
    for (auto chi : g[node])
    {
        if (chi != par)
        {
            if (!vis[chi])
            {
                child++;
                parent[chi] = node;
                vis[chi] = 1;
                DFS(chi, node);
                remin(low[node], low[chi]);
                if (par == -1 and child > 1)
                {
                    AP[node] = 1;
                }
                if (par != -1 and low[chi] >= tin[node])
                {
                    AP[node] = 1;
                }
            }
            else if (parent[node] != chi)
            {
                remin(low[node], tin[chi]);
            }
        }
    }
}

void solve()
{
    int m;
    cin >> n >> m;
    g.clear();
    g.resize(n + 1);
    low.clear();
    tin.clear();
    parent.clear();
    vis.clear();
    AP.clear();
    low.resize(n + 1);
    tin.resize(n + 1);
    parent.assign(n + 1, -1);
    vis.assign(n + 1, 0);
    AP.assign(n + 1, 0);
    tim = 0;
    fr(i, m)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    rep(i, 1, n) if (!vis[i])
    {
        vis[i] = 1;
        DFS(i, -1);
    }
    for (int i = 1; i <= n; i++)
    {
        if (AP[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
