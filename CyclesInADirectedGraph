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
const int N = 2e5 + 5;
vector<int> v[N];
bool done[N + 1];
int tot = 0;
bool dfs( int src, bool vis[])
{
	vis[src] = 1;
	done[src] = 1;
	for (auto i : v[src])
	{
		if (vis[i])
		{
			tot += 1;
			return true;

		}
		else
		{
			if (dfs(i, vis))
			{
				tot++;
				return true;
			}

		}
	}
	vis[src] = 0;
	return false;

}



int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n ;
		fab(0, n + 1, i)
		{	v[i].clear();
			done[i] = 0;
		}
		int a[n], b[n];
		map<int, int> m;
		fab(0, n, i)
		{
			cin >> a[i];
			m[a[i]] = i;

		}
		fab(0, n, i)

		{
			cin >> b[i];
			v[m[b[i]]].pb(i);
		}
		bool vis[n + 1] = {0};
		int val = 0;
		int left = n;
		fab(1, n + 1, i)
		{
			if ( !done[i])
			{
				tot = 0;;
				dfs(i, vis);
				// if cycle is present it's size if "tot". else tot is 0
				if (tot > 0)
					val += tot - 1;

			}

		}

		int ans = val;

		cout << ans << endl;
	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
