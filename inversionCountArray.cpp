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

class inversion
{
public:
	vector<int> a;
	int count;
	inversion(vector<int> &b)
	{
		a = b;
		count = 0;
	}
	void merge(int l, int mid, int r)
	{

		vector<int> left(a.begin() + l, a.begin() + mid + 1);
		vector<int> right(a.begin() + mid + 1, a.begin() + r + 1);
		int ind = l;
		int leftptr = 0, rightptr = 0;


		while (leftptr < left.size() and rightptr < right.size() )
		{
			if (left[leftptr] <= right[rightptr])
			{
				a[ind] = left[leftptr];
				leftptr++;
				count += rightptr;
				ind++;
			}
			else
			{
				a[ind] = right[rightptr];
				rightptr++;
				ind++;

			}

		}


		while (leftptr < left.size())
		{
			a[ind] = left[leftptr];
			leftptr++;
			count += rightptr;
			ind++;

		}

		while (rightptr < right.size())
		{
			a[ind] = right[rightptr];
			rightptr++;
			ind++;

		}

	}

	void mergeSort(int l, int r)
	{
		if (l < r)
		{
			int mid = (l + r) / 2;
			mergeSort(l, mid);
			mergeSort(mid + 1, r);

			merge(l, mid, r);

		}
	}

	int countInversions()
	{
		mergeSort(0, a.size() - 1);
		return count;
	}


};

int main()
{
	quick;

	int n;
	cin >> n;
	vector<int> a(n);
	fab(0, n, i) {
		cin >> a[i];
	}

	inversion temp(a);

	int ans = temp.countInversions();

	cout << ans << endl;




	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
