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
 
 
 
int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int a, b;
	cin >> a >> b;
	if (a > b)
		swap(a, b);
	int p = a;
	a = b;
 
	vector<vector<int>> dp(a + 3, vector<int> (b + 3, 1e9));
	for ( int i = 1; i <= a; i++)
	{
		dp[i][i] = 0;
 
	}
	for ( int i = 2; i <= b; i++)
	{
		dp[1][i] = i - 1;
		dp[i][1] = i - 1;
	}
 
	for ( int i = 2; i <= a; i++)
	{
		for ( int j = 2; j <= b; j++)
		{
 
			for ( int k = 1; k < j; k++ )
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
 
			}
			for ( int k = 1; k < i; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1) ;
			}
		}
	}
 
 
	cout << dp[p][b] << endl;
 
 
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
