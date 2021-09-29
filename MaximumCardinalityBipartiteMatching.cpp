// problem: https://lightoj.com/problem/marriage-media
#include<bits/stdc++.h>
#define ll long long int
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

class MCBM
{
    vector<vector<int>> v;
    int n;
public:
    MCBM(int n)
    {
        this->n = n;
        v.resize(n);
    }

    void addEdge(int a, int b)
    {
        assert(a < v.size());
        v[a].push_back(b);
    }

    bool dfs(int src, vector<int> &vis, vector<int> &match)
    {
        if (src == -1)
            return true;
        for (int &i : v[src])
        {
            if (vis[i] == 0)
            {
                vis[i] = 1;
                if (dfs(match[i], vis, match))
                {
                    match[i] = src;
                    return true;
                }
            }
        }

        return false;
    }


    int maxMatching(int left)
    {
        vector<int> match(n, -1), vis(n);
        int ans = 0;
        for (int i = 0; i < left; i++)
        {
            fill(vis.begin(), vis.end(), 0);
            ans += dfs(i, vis, match);
        }

        return ans;
    }
};

int main()
{
    quick;

    int t;
    cin >> t;
    for (int hola = 0; hola < t; hola++)
    {
        cout << "Case " << hola + 1 << ": ";
        int n, m;
        cin >> n >> m;
        vector<array<int, 3>> man(n), women(m);
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            man[i] = {x, y, z};
        }

        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            women[i] = {x, y, z};
        }
        MCBM match(n + m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (abs(man[i][0] - women[j][0]) <= 12 and abs(man[i][1] - women[j][1]) <= 5 and man[i][2] == women[j][2])
                {
                    match.addEdge(i, j + n);
                }
            }
        }
        int ans = match.maxMatching(n);

        cout << ans << endl;

    }




    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
