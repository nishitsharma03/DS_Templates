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


vector<int> getLPS(string &p)
{
    int m = p.length();
    int i = 1;
    int j = 0;
    vector<int> pref(m);
    while (i < m)
    {
        if (p[i] == p[j])
        {
            pref[i] = j + 1;
            i++;
            j++;

        }
        else
        {
            if (j > 0)
            {
                j = pref[j - 1];

            }
            else
            {
                pref[i] = j;
                j = 0;
                i++;
            }

        }

    }


    return pref;

}

int kmp(string &s, string &p)
{

    if (s.length() < p.length())
        return 0;

    int n = s.length(), m = p.length();

    vector<int> lps = getLPS(p);

    int i = 0, j = 0;

    int ans = 0;
    while (i < n)
    {
        if (s[i] == p[j])
        {
            i++;
            j++;

            if (j == m)
            {
                ans++;
                j = lps[m - 1];
            }

        }
        else
        {
            if (j > 0)
            {
                j = lps[j - 1];
            }
            else
                i++;

        }
    }

    return ans;
}

int main()
{   quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    string s, t;
    cin >> s >> t;

    cout << kmp(t, s) << endl;


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}