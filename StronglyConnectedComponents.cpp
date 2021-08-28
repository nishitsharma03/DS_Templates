// Problem: CSES coin collector https://cses.fi/problemset/task/1686/
#include<bits/stdc++.h>
#define endl "\n"
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

#define int long long int
class SCC
{
public:
    vector<vector<int>> v, vRev, components, condV;
    vector<int> compValue, nodeValue;
    int n;

    // Constructor 1
    SCC(int n)
    {
        this->n = n;
        v.resize(n);
        vRev.resize(n);
    }

    // Constructor 2 (number of nodes, value of nodes)
    SCC(int n, vector<int> &a)
    {
        this->n = n;
        v.resize(n);
        vRev.resize(n);
        nodeValue = a;
    }

    // Constructor 2(adjacency list)
    SCC(vector<vector<int>> &adj)
    {
        v = adj;
        this->n = adj.size();
        vRev.resize(n);
        for (int i = 0; i < n; i++)
        {
            for (int &j : adj[i])
            {
                vRev[j].push_back(i);
            }
        }
    }

    // 0-based indexing
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


    // 0- based indexing
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
        assert(order.size() == n);
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



    void getCondensedGraph()
    {
        int connComps = this->components.size();
        condV.resize(connComps);
        compValue.resize(connComps);
        vector<int> comp(n);
        for (int i = 0; i < this->components.size(); i++)
        {
            for (int &j : this->components[i])
            {
                comp[j] = i;
                compValue[i] += nodeValue[j];
            }
        }

        vector<int> used(connComps);

        for (int i = 0; i < this->components.size(); i++)
        {
            for (int &j : this->components[i])
            {

                for (int &k : this->v[j])
                {
                    int otherComp = comp[k];

                    if (!used[otherComp] and otherComp != i)
                    {
                        condV[i].push_back(otherComp);
                        used[otherComp] = 1;
                    }

                }
            }
            for (int &j : this->components[i])
            {

                for (int &k : this->v[j])
                {
                    int otherComp = comp[k];
                    used[otherComp] = 0;

                }
            }
        }

    }


};


int32_t main()
{
    quick;
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    SCC scc(n, a);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        scc.insertEdge(a - 1, b - 1);
    }


    scc.getSCC();
    scc.getCondensedGraph();


    int nNew = scc.condV.size();

    vector<int> inDeg(nNew);

    for (auto &i : scc.condV)
    {
        for (auto &j : i)
        {
            inDeg[j]++;
        }

    }

    vector<int> dp(nNew);
    queue<int> q;

    for (int i = 0; i < nNew; i++)
    {
        dp[i] = scc.compValue[i];

        if (inDeg[i] == 0)
            q.push(i);
    }


    while (q.empty() == false)
    {
        int p = q.front();
        q.pop();

        for (int &i : scc.condV[p])
        {
            dp[i] = max(dp[i], dp[p] + scc.compValue[i]);
            inDeg[i]--;
            if (inDeg[i] == 0)
                q.push(i);
        }
    }


    int ans = 0;
    for (int &i : dp)
        ans = max(ans, i);

    cout << ans << endl;






    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
