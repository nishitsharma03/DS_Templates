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
#define vll vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int MOD = 1e9 + 7;
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}

using namespace std;
const int N = 1e5 + 5;
ll seg[4 * N], lazy[4 * N], a[N];

void build( int node, int s, int e)
{
	if (s == e)
	{
		seg[node] = a[s];
		return;
	}
	int mid = (s + e) / 2;
	build(2 * node, s, mid);
	build(2 * node + 1, mid + 1, e);
	seg[node] = min(seg[2 * node], seg[2 * node + 1]);
}

void updateRange(int node, int s, int e, int l, int r, int val)
{
	if (s > e)
	{
		return;
	}
	if (lazy[node] != 0)
	{
		seg[node] += lazy[node];
		if (s != e)
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];

		}
		lazy[node] = 0;

	}
	if (s > r or e < l)
	{
		return;
	}

	if (s >= l and e <= r)
	{
		seg[node] += val;
		if (s != e)
		{
			lazy[2 * node] += val;
			lazy[2 * node + 1] += val;
		}
		return;
	}
	int mid = (s + e) / 2;

	updateRange(2 * node, s, mid, l, r, val);
	updateRange(2 * node + 1, mid + 1, e, l, r, val);
	seg[node] = min(seg[2 * node], seg[2 * node + 1]);
}

ll query( int node, int s, int e, int l, int r)
{
	if (s > e or s > r or e < l)
	{
		return 1e18 + 2;
	}
	if (lazy[node] != 0)
	{
		seg[node] += lazy[node];
		if (s != e)
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];

		}
		lazy[node] = 0;

	}
	if (s >= l and e <= r)
	{
		return seg[node];
	}

	int mid = (s + e) / 2;
	ll lf = query(2 * node, s, mid, l, r);
	ll rt = query(2 * node + 1, mid + 1, e, l, r);

	return min(lf, rt);

}

void init(int n)
{
	for ( int i = 0; i < 4 * n + 2; i++)
	{
		seg[i] = 0;
		lazy[i] = 0;
	}
}


int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	// int t;
	// cin >> t;
	// while (t--)
	{
		int n;
		cin >> n;
		init(n);
		int q;
		cin >> q;

		for ( int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		build(1, 0, n - 1);


		while (q--)
		{
			char tp;
			cin >> tp;
			int l, r;
			cin >> l >> r;

			if (tp == 'u')
			{
				ll change = r - a[l - 1];
				a[l - 1] = r;
				updateRange(1, 0, n - 1, l - 1, r - 1, change);

			}
			else
			{
				ll val = query(1, 0, n - 1, l - 1, r - 1);
				cout << val << endl;
			}
		}

	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
