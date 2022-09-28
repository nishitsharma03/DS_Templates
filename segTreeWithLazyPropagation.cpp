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

using namespace std;

const int MOD = 1e9 + 7;

ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}
ll lcm(ll x, ll y) { ll res = x / __gcd(x, y); return (res * y);}

#define int ll
class segmentTree
{
public:
	vector<int> seg, a, lazy;
	int n;
	int placeHolder;

	segmentTree(vector<int> &v)
	{
		a = v;
		n = v.size();
		seg.resize(4 * n);
		lazy.resize(4 * n);
		placeHolder = 0;
		fill(lazy.begin(), lazy.end(), placeHolder);
	}

	int merge(int x, int y)
	{
		return x + y;
	}

	void build(int node, int l, int r)
	{
		if (l == r)
		{
			seg[node] = a[l];
			return;
		}

		int mid = (l + r) / 2;
		build(2 * node, l, mid);
		build(2 * node + 1, mid + 1, r);

		seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
	}


	void rangeUpdate(int node, int l, int r, int mergeValue, int left, int right)
	{
		if (l > r)
			return;

		if (lazy[node] != placeHolder)
		{
			seg[node] = merge(lazy[node], seg[node]);
			if (l != r)
			{
				lazy[2 * node] = merge(lazy[2 * node], lazy[node]);
				lazy[2 * node + 1] = merge(lazy[2 * node + 1], lazy[node]);
			}
			lazy[node] = placeHolder;
		}

		if (left > r or right < l)
			return;

		if (l >= left and right >= r)
		{
			seg[node] = merge(seg[node], mergeValue);
			if (l != r)
			{
				lazy[2 * node] = merge(mergeValue, lazy[2 * node]);
				lazy[2 * node + 1] = merge(mergeValue, lazy[2 * node + 1]);
			}
			return;
		}

		int mid = (l + r) / 2;
		rangeUpdate(2 * node, l, mid, mergeValue, left, right);
		rangeUpdate(2 * node + 1, mid + 1, r, mergeValue, left, right);
		seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
	}


	int query(int node, int l, int r, int left, int right)
	{
		if (l > r)
			return placeHolder;
		if (lazy[node] != placeHolder)
		{
			seg[node] = merge(seg[node], lazy[node]);
			if (l != r)
			{
				lazy[2 * node] = merge(lazy[2 * node], lazy[node]);
				lazy[2 * node + 1] = merge(lazy[2 * node + 1], lazy[node]);
			}
			lazy[node] = placeHolder;
		}

		if (left > r or right < l)
			return placeHolder;

		if (left <= l and right >= r)
		{
			return seg[node];
		}
		int mid = (l + r) / 2;
		int lRes = query(2 * node, l, mid, left, right), rRes = query(2 * node + 1, mid + 1, r, left, right);

		return merge(lRes, rRes);

	}

};
void dfs(int src, int par, vector<vector<int>> &v, vector<int> &euler, vector<int> &in, vector<int> &out, vector<int> &a, int currSum)
{
	in[src] = euler.size();
	currSum += a[src];
	euler.push_back(currSum);

	for (int &i : v[src])
	{
		if (i ^ par)
		{
			dfs(i, src, v, euler, in, out, a, currSum);
		}
	}
	out[src] = euler.size();
	euler.push_back(currSum);
}

int32_t main()
{
	quick;
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	fab(0, n, i)
	{
		cin >> a[i];
	}
	vector<vector<int>> v(n);
	fab(1, n, i)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		v[x].pb(y);
		v[y].pb(x);
	}

	vector<int> euler, in(n), out(n);
	dfs(0, -1, v, euler, in, out, a, 0);

	segmentTree seg(euler);
	int k = 2 * n;
	seg.build(1, 0, k - 1);


	while (m--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int node, val;
			cin >> node >> val;
			node--;
			// do something
			int curr = a[node];
			int diff = val - curr;
			a[node] = val;
			seg.rangeUpdate(1, 0, k - 1, diff, in[node], out[node]);
		}
		else
		{
			int node;
			cin >> node;
			node--;
			int ans = seg.query(1, 0, k - 1, in[node], in[node]);
			cout << ans << endl;
		}
	}




	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
