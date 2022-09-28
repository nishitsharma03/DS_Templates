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
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}

using namespace std;
const int N = 3e5 + 5;
const int L = ceil(log2(N));
vector<int> v[N];
int in[N], out[N];
int a[N][L + 1];
int tim = 0;
void init(int n)
{
	for ( int i = 0; i <= n; i++)
	{
		v[i].clear();
		in[i] = 0;
		out[i] = 0;
		for ( int j = 0; j <= L; j++)
		{
			a[i][j] = 0;
		}
	}
	tim = 0;

}
void dfs( int src, int par)
{
	in[src] = tim++;

	a[src][0] = par;
	for ( int i = 1; i <= L; i++)
	{
		//	Get the s={ 2**(i-1) parent} and then find the 2**(i-1) parent of s.
		a[src][i] = a[a[src][i - 1]][i - 1];
	}

	for ( auto i : v[src])
	{
		if (i ^ par)
		{
			dfs(i, src);
		}
	}

	out[src] = tim++;
}

bool isancestor(int u, int v)
{
	return (in[u] <= in[v] and out[u] >= out[v]);
}

int getlca( int u, int v)
{
	if (isancestor(u, v))
	{
		return u;
	}
	if (isancestor(v, u))
	{
		return v;
	}

	for ( int i = L; i >= 0; i--)
	{
		if (!isancestor(a[u][i], v))
		{
			u = a[u][i];
		}
	}

	return a[u][0];
}

int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	init(n);

	for ( int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		//x--, y--;
		v[x].pb(y);
		v[y].pb(x);

	}

	dfs(0, 0);
	int m;
	cin >> m;
	int ans = -1;
	for ( int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		if (ans == -1)
		{
			ans = x;
			continue;
		}

		ans = getlca(ans, x);
	}
	cout << ans << endl;



	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
