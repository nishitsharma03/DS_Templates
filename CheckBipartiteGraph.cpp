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
#define endl "\n"
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

bool dfs( int src, vector<int> v[], vector<int> &color, int col)
{
	color[src] = col;
	bool ok = 1;
	for ( int i : v[src])
	{
		if (color[i] != -1 and color[i] == col)
		{
			return false;
		}
		else if (color[i] == -1)
		{
			ok &= dfs(i, v, color, 1 ^ col);
		}

	}
	return ok;

}

int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> v[n];
		for ( int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			//x--,y--;
			v[x].pb(y);
			v[y].pb(x);
		}
		vector<int> color(n , -1);
		bool ok = 1;
		for ( int i = 0; i < n; i++)
		{
			if (color[i] == -1)
			{
				ok &= dfs(i, v, color, 0);
			}
		}
		cout << ok << endl;

	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
