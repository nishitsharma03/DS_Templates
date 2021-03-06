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
const int N = 1e6 + 6;
ll a[N];
ll n;

struct trienode {
	trienode *child[2];
	int cnt;

	trienode()
	{
		cnt = 0;
		child[0] = child[1] = NULL;

	}
};

//   head node
struct trienode *head;

void insert( ll n)
{
	auto temp = head;

	for ( int i = 31; i >= 0; i--)
	{
		//   check if the current bit is set.
		bool val = (n & (1LL << i));

		//  create new node.
		if (!temp->child[val])
		{
			temp->child[val] = new trienode();
		}

		temp = temp->child[val];

		//  Update the count.
		temp->cnt++;

	}


}


//    Count number of subarrays with xor >=k
ll search(ll n, ll k)
{
	ll ans = 0;
	auto temp = head;
	for (int i = 31; i >= 0; i--)
	{
		//  Check curr bit in K
		bool val = (k & (1LL << i));

		//  Check curr bit in N
		bool val2 = (n & (1LL << i));

		//    If the bit is unset in K, find the number of subarrays with
		//    curr bit set.
		if (!val and temp->child[(val2 ^ 1)]) {
			ans += temp->child[(val2 ^ 1)]->cnt;


		}

		//  Toggle.
		if (val)
			val2 ^= 1;


		if (!temp->child[val2])
		{

			return ans;
		}

		//    Move to child nodes.
		temp = temp->child[val2];



	}

	//  To include values equal to k.
	ans += temp->cnt;

	return ans;
}

int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	head = new trienode();
	ll k;
	cin >> n >> k;


	ll ans = 0;
	ll curr = 0;
	//   intial xor is 0.
	insert(0);
	fab(0, n, i)
	{
		cin >> a[i];

		//   curr xor.
		curr ^= a[i];

		//    insert into trie.
		insert(curr);

		//    Query the trie.
		ll val = search(curr, k);
		ans += val;
	}

	cout << ans << endl;



	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
