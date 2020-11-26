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
const int N=1e3+3;
int par[N],sz[N];
int find_set(int a)
{
	if(par[a]==a)
	{
		return a;

	}
	return par[a]=find_set(par[a]);

}

void union_set(int a,int b)
{
	a=find_set(a);
	b=find_set(b);
	if(a!=b)
	{
		if(sz[a]>sz[b])
			swap(a,b);
		par[a]=b;
		sz[b]+=sz[a];



	}

}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    int n,m;
    cin>>n>>m;
    fab(0,n,i)
    {
    	par[i]=i;
    	sz[i]=1;
    }
    while(m--)
    {
    	int x,y;
    	cin>>x>>y;
    	x--;
    	y--;
    	union_set(x,y);
    	vector<int> ans;
    	fab(0,n,i)
    	{
    		if(par[i]==i)
    		{
    			ans.pb(sz[i]);
    		}

    	}
    	sort(all(ans));
    	for(auto i: ans)
    		cout<<i<<" ";
    	cout<<endl;
    }


	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}