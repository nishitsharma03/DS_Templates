#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

class segtree
{
public:
	vector<int> seg;
	vector<int> a;
	int n;
	int placeHolder;
	segtree(vector<int> &v)
	{
		n = v.size();
		a = v;
		placeHolder = 0;
		seg.resize(2 * n);
	}

	int merge(int a, int b)
	{
		return (a + b);
	}

//!-------- CAUTION this Tree works for [l,r) .... mind the open interval on r -------!
	void build( )
	{
		for (int i = 0; i < n; i++)
		{
			seg[i + n] = a[i];
		}
		for ( int i = n - 1; i > 0; i--)
		{
			seg[i] = merge(seg[2 * i] , seg[2 * i + 1]);
		}

	}

	void update( int ind , int val)
	{
		a[ind] = val;
		ind += n;
		seg[ind] = val;

		for ( ; ind > 1; ind >>= 1)
		{
			seg[ind >> 1] = merge(seg[ind] , seg[ind ^ 1]);
		}
	}
//!-------- CAUTION this function works for [l,r) .... mind the open interval on r -------!
	int query(int l, int r)
	{
		l += n;
		r += n;
		int ans = placeHolder;
		while (l < r)
		{
			if (l % 2)
			{
				ans = merge(ans, seg[l]);
				l++;
			}
			if (r % 2)
			{
				--r;
				ans =  merge(ans, seg[r]);
			}
			l >>= 1;
			r >>= 1;
		}
		return ans;

	}

};

int main()
{
    quick;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    segtree seg(a);
    seg.build();

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << seg.query(l, r + 1) << endl;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
