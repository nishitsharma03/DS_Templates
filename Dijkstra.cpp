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

const int N = 1e5 + 3;

const ll INF = 1e18;

void dijkstra(ll src, vector<ll> &d, vector<pll> v[])
{
	fill(d.begin(), d.end(), INF);
	d[src] = 0LL;
	priority_queue<pll, vector<pll>, greater<pll>> q;
	q.push({0LL, src});

	while (!q.empty())
	{
		auto p = q.top();
		q.pop();

		ll s = p.se;
		ll w = p.f;
		if (w != d[s])
			continue;

		for (auto i : v[s])
		{
			if (d[s] + i.se < d[i.f])
			{
				d[i.f] = d[s] + i.se;
				q.push({d[i.f], i.f});

			}

		}
	}

}

int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	ll n, m, k;
	cin >> n >> m >> k;
	vector<pll> v[n], v1[n];
	fab(0, m, i)
	{
		ll x, y, w;
		cin >> x >> y >> w;
		x--, y--;
		v[x].pb({y, w});
		v1[y].pb({x, w});

	}

	vector<ll> d1(n), d2(n);
	dijkstra(0LL, d1, v);
	dijkstra(n - 1, d2, v1);

	ll ans = INF;
	fab(0, n, i)
	{
		for (auto j : v[i])
		{
			ll val = d1[i] + d2[j.f] + (j.se / k);
			ans = min(ans, val);

		}
	}
	assert(ans != INF);
	cout << ans << endl;



	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
