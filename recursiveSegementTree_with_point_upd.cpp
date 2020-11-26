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
const int N=1e5+5;
int seg[4*N];
int a[N];
int n;


void build( int node, int l, int r)
{
    if(l==r)
    {
        seg[node]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    seg[node]=min(seg[2*node],seg[2*node+1]);
}

void update(int node, int l, int r,int ind, int val)
{
    if(l==r)
    {
        seg[node]=val;
        a[l]=val;
        return;
    }
    int mid=(l+r)>>1;
    if(mid>=ind)
        update(2*node,l,mid,ind,val);
    else
        update(2*node+1,mid+1,r,ind,val);

    seg[node]=min(seg[2*node],seg[2*node+1]);


}

int query( int node,int l, int r,int s, int e)
{
    if(s>r or l>e)
    {
        return 1e9+1;
    }
    if(s<=l and r<=e)
        return seg[node];
    int mid=(l+r)>>1;

    return min(query(2*node,l,mid,s,e),query(2*node+1,mid+1,r,s,e));
}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    int q;
    cin>>n>>q;
    fab(0,n,i)
    {
        cin>>a[i];
    }
    build(1,0,n-1);
   
    while(q--)
    {
        char type;
        cin>>type;
        if(type=='q')
        {
            int x,y;

            cin>>x>>y;
            
            x--;y--;
            cout<<query(1,0,n-1,x,y)<<endl;
        }
        else
        {
            int x,y;
            cin>>x>>y;
            assert(x<=n and x>=1 );
            update(1,0,n-1,x-1,y);
        }
    }

    

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
