#include<bits/stdc++.h>
#define endl "\n"
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

class rabinKarp
{
    vector<int> powers;
    int mod, prime;
public:
    rabinKarp(int n)
    {
        this->powers.resize(n);
        mod = 1e9 + 7;
        prime = 31;
        this->powers[0] = 1;
        for (int i = 1; i < n; i++)
        {
            powers[i] = (1ll * powers[i - 1] * prime) % mod;
        }
    }

    int hashString(string &s)
    {
        int value = 0;
        for (int i = 0; i < s.length(); i++)
        {
            value = (1ll * value + 1ll * s[i] * powers[i]) % mod;
        }
        return value;
    }

    vector<int> getPrefixHash(string &s)
    {
        int n = s.length();
        vector<int> prefHash(n);
        prefHash[0] = s[0];
        for (int i = 1; i < n; i++)
        {
            prefHash[i] = (prefHash[i - 1] + 1ll * powers[i] * s[i]) % mod;
        }

        return prefHash;
    }

    // find occurrences of p in s
    // p = pattern
    // s = text
    vector<int> findPatterns(string &s, string &p)
    {

        int n = s.length(), m = p.length();
        vector<int> ans;
        if (n < m)
            return ans;
        assert(n <= powers.size());
        int hashValue = hashString(p);
        vector<int> prefHash = getPrefixHash(s);
        for (int i = 0; i + m - 1 < n; i++)
        {
            int currValue = (1ll * prefHash[i + m - 1] - (i > 0 ? 1ll * prefHash[i - 1] : 0ll) + mod) % mod;
            if (1ll * currValue == (1ll * hashValue * powers[i]) % mod)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};


int main()
{
    quick;

    int t;
    cin >> t;
    while (t--)
    {
        string s, p;
        cin >> s >> p;
        rabinKarp r(s.length());
        auto ans = r.findPatterns(s, p);

        if (ans.empty())
        {
            cout << "Not Found\n" << endl;
            continue;
        }

        cout << ans.size() << endl;
        for (int &i : ans)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
        cout << endl;
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
