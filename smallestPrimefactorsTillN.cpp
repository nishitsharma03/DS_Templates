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

int primefac[N];
void getsmallestprimefactors()
{
	primefac[1]=1;
	for ( ll i = 2; i < N; i++)
	{
		if (!primefac[i])
		{
			primefac[i] = i;
			for ( ll j = i * i; j < N; j += i)
			{
				if (!primefac[j])
					primefac[j] = i;
			}
		}
	}

}


vector<int> getprimefactors(int n)
{
	//	Use this to get the result in a map.
	// map<int,int> fac;

	vector<int> fac;

	while (n > 1)
	{
		//	Use this when using a map
		//fac[primefac[n]]++;

		fac.push_back(primefac[n]);
		n /= primefac[n];

	}

	return fac;
}

int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif


	getsmallestprimefactors();
  
  // Result can be obtained in a map as well.
  vector<int> ans = getprimefactors(37);
	




	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
