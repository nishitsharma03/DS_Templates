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

//	adj list for graph and reverse graph
vector<vector<int>> v, vr;

void dfs(int src, vector<int> &visited, vector<int> &order)
{
	visited[src] = 1;
	for (int i : v[src])
	{
		if (visited[i] == 0)
		{
			dfs(i, visited, order);
		}

	}
	order.push_back(src);
}

void dfsOnRev(int src, vector<int> &visited, vector<int> &component)
{
	visited[src] = 1;
	component.push_back(src);
	for (int i : vr[src])
	{
		if (visited[i] == 0)
		{
			dfsOnRev(i, visited, component);

		}
	}
}

int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	v.resize(n + 1);
	vr.resize(n + 1);

	for ( int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		// 0 based indexing
		x--;
		y--;

		v[x].push_back(y);
		vr[y].push_back(x);
	}

	vector<int> visited(n + 1, 0);
	vector<int> order;
	for ( int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			dfs(i, visited, order);
		}

	}

	fill(visited.begin(), visited.end(), 0);

	vector<vector<int> > scc;
	for ( int i = 0; i < n; i++)
	{
		int currNode = order[n - i - 1];
		if (visited[currNode] == 0)
		{
			vector<int> temp;
			dfsOnRev(currNode, visited, temp);
			scc.push_back(temp);
		}
	}
	int c = 0, d = 0;
	for ( vector<int> i : scc)
	{
		if (i.size() % 2)
		{
			c += i.size();

		}
		else
			d += i.size();
	}
	cout << c - d << endl;




	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
