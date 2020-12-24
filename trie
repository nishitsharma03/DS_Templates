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
int n, k;
class trieNode
{
public:

    // child nodes
    trieNode* child[26];
    // no of prefixes
    int cnt;
    // mark end of string
    bool isEnd;

    trieNode()
    {
        cnt = 0;
        isEnd = 0;
        for ( int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }


};


//  Insert a string into the trie.
void insert(string &s, trieNode *head)
{
    trieNode *temp = head;
    for ( char i : s)
    {
        int val = i - 'a';
        if (!temp->child[val])
        {
            temp->child[val] = new trieNode();

        }
        temp = temp->child[val];
        temp->cnt++;

    }
    temp->isEnd = true;
}

// check for complete string.
bool search(string &s, trieNode *head)
{
    trieNode *temp = head;

    for ( char i : s)
    {
        int val = i - 'a';
        if (!temp->child[i - 'a'])
        {
            return false;

        }
        temp = temp->child[val];
    }

    return temp->isEnd;

}

// Check for prefix
bool isPrefix(string &s, trieNode *head)
{
    trieNode *temp = head;

    for ( char i : s)
    {
        int val = i - 'a';
        if (!temp->child[i - 'a'])
        {
            return false;

        }
        temp = temp->child[val];
    }

    return true;
}


//  Count the number of nodes in the trie
int countNodes(trieNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int subTreeNodes = 1;

    //    Iterate through the children of the current node.
    for (int i = 0; i < 26; i++)
    {
        subTreeNodes += countNodes(root->child[i]);
    }

    return subTreeNodes;
}


int main()
{   quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> k;

        vector<string> v(n);
        fab(0, n, i)
        {
            cin >> v[i];
        }
        trieNode *head = new trieNode();
        for (string &i : v)
        {
            insert(i, head);
        }


        cout << get(head) << endl;


    }



    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
