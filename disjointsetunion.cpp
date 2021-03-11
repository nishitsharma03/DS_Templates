//#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define ll long long int
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
//#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define vll vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}
ll lcm(ll x, ll y) { ll res = x / __gcd(x, y); return (res * y);}
class DSU
{
public:
    vector<int> parent, sz;
    int n;


    DSU( int n)
    {
        this->n = n;
        parent.resize(n);
        sz.resize(n);
    }

    void init()
    {
        for ( int i = 0; i < n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find_set(int a)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find_set(parent[a]);
    }


    int union_set( int a, int b)
    {
        a = find_set(a);
        b = find_set(b);

        if (a == b)
        {
            return -1;
        }

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = parent[a];
        sz[a] += sz[b];

        return a;

    }


};

int main()
{   quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        DSU dsu(n + 1);
        dsu.init();

        for ( int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            int val = dsu.union_set(x, y);

        }




        vector<int> ans;
        for ( int i = 1; i <= n; i++)
        {
            if (dsu.parent[i] == i)
            {
                ans.push_back(i);
            }

        }

        cout << ans.size() - 1 << endl;
        for ( int i = 0; i < ans.size() - 1; i++)
        {
            cout << ans[i] << " " << ans[i + 1] << endl;

        }

    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
