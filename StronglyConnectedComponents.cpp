#include<bits/stdc++.h>
#define ll long long int
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

class SCC
{
public:
    vector<vector<int>> v, vRev, components;
    int n;
    SCC(int n)
    {
        this->n = n;
        v.resize(n);
        vRev.resize(n);
    }

    void insertEdge(int a, int b)
    {
        v[a].push_back(b);
        vRev[b].push_back(a);
    }

    void dfs(int src, vector<int> &vis, vector<int> &order, bool onRev = 0)
    {
        vis[src] = 1;
        if (onRev)
        {
            for (int &i : vRev[src])
            {
                if (!vis[i])
                    dfs(i, vis, order, onRev);
            }
        }
        else
        {
            for (int &i : v[src])
            {
                if (!vis[i])
                    dfs(i, vis, order, onRev);
            }
        }

        order.push_back(src);
    }

    void getSCC()
    {
        vector<int> vis(n);
        vector<int> order;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, order);
            }
        }
        assert(int(order.size()) == n);
        fill(vis.begin(), vis.end(), 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int node = order[i];
            if (!vis[node])
            {
                vector<int> comp;
                dfs(node, vis, comp, 1);
                components.push_back(comp);
            }
        }
    }


};


int main()
{
    quick;
    int n, m;
    cin >> n >> m;
    SCC scc(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        scc.insertEdge(a, b);
    }

    scc.getSCC();

    if (scc.components.size() == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        assert(scc.components.size() > 1);
        cout << "NO" << endl;
        vector<int> vis(n), order;
        int u = scc.components[0][0], v = scc.components[1][0];
        scc.dfs(u, vis, order);
        if (vis[v])
            swap(u, v);
        cout << u + 1 << " " << v + 1 << endl;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
