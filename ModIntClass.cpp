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

class Mint {
private:
    const static int mod = 1e9 + 7;
    int val;
public:
    Mint () {val = 0;}

    Mint(long long _val) {val = (_val < mod ? _val : _val % mod);}

    Mint& operator += (const Mint &o) {val = (val + o.val < mod ? val + o.val : val + o.val - mod); return *this;}
    template <typename T> Mint& operator += (const T &o) {return *this += Mint(o);}

    Mint& operator -= (const Mint &o) {val = (val < o.val ? val - o.val + mod : val - o.val); return *this;}
    template <typename T> Mint& operator -= (const T &o) {return *this -= Mint(o);}

    Mint& operator *= (const Mint &o) {return *this = (1LL * val * o.val >= mod ? (1LL * val * o.val) % mod : val * o.val);}
    template <typename T> Mint& operator *= (const T &o) {return *this *= Mint(o);}

    friend bool operator == (const Mint &o1, const Mint &o2) {return (o1.val == o2.val);}
    template <typename T> friend bool operator == (const Mint &o1, const T &o2) {return (o1 == Mint(o2));}
    template <typename T> friend bool operator == (const T &o1, const Mint &o2) {return (Mint(o1) == o2);}

    friend bool operator != (const Mint &o1, const Mint &o2) {return (o1.val != o2.val);}
    template <typename T> friend bool operator != (const Mint &o1, const T &o2) {return (o1 != Mint(o2));}
    template <typename T> friend bool operator != (const T &o1, const Mint &o2) {return (Mint(o1) != o2);}

    friend Mint operator + (const Mint &o1, const Mint &o2) {return Mint(o1) += o2;}
    template <typename T> friend Mint operator + (const Mint &o1, const T &o2) {return Mint(o1) += o2;}
    template <typename T> friend Mint operator + (const T &o1, const Mint &o2) {return Mint(o1) += o2;}

    friend Mint operator - (const Mint &o1, const Mint &o2) {return Mint(o1) -= o2;}
    template <typename T> friend Mint operator - (const Mint &o1, const T &o2) {return Mint(o1) -= o2;}
    template <typename T> friend Mint operator - (const T &o1, const Mint &o2) {return Mint(o1) -= o2;}

    friend Mint operator * (const Mint &o1, const Mint &o2) {return Mint(o1) *= o2;}
    template <typename T> friend Mint operator * (const Mint &o1, const T &o2) {return Mint(o1) *= o2;}
    template <typename T> friend Mint operator * (const T &o1, const Mint &o2) {return Mint(o1) *= o2;}

    Mint power(long long y) {
        Mint ans = 1;
        Mint x = *this;

        while (y > 0) {
            if (y & 1) ans *= x;
            y >>= 1;
            x *= x;
        }
        return ans;
    }

    Mint inverse () {return power(mod - 2);}

    Mint& operator /= (const Mint &o) {return *this *= Mint(o).inverse();}
    template <typename T> Mint& operator /= (const T &o) {return *this *= Mint(o).inverse();}

    friend Mint operator / (const Mint &o1, const Mint &o2) {return Mint(o1) /= o2;}
    template <typename T> friend Mint operator / (const Mint &o1, const T &o2) {return Mint(o1) /= o2;}
    template <typename T> friend Mint operator / (const T &o1, const Mint &o2) {return Mint(o1) /= o2;}

    bool operator ~ () const {return ~(this -> val);}
    bool operator ! () const {return (this -> val == 0);}
    void operator ++ () {*this += 1;}
    void operator -- () {*this -= 1;}
    void operator ++ (int) {*this += 1;}
    void operator -- (int) {*this -= 1;}

    friend ostream &operator << (ostream &os, const Mint &o) {os << o.val; return os;}
};



int main()
{   quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    int x, y;
    cin >> x >> y;

    Mint ans = x + y;
    cout << ans << endl;



    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
