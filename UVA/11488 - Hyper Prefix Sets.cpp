#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define pb push_back
#define pf push_front
#define MULTITEST
#define SZ(v) v.size()
#define mset(a, val) memset(a, val, sizeof(a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ff first
#define ss second
#define ll long long
#define INF 1e18l
#define ld long double
#define Mod 1000000007ll
#define Mod1 998244353ll
#define N (int)2e5 + 5
#define ull unsigned long long
#define sz(a) int((a).size())
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nlp(n, i) for (int(i) = 0; (i) < n; (i)++)
#define lp(k, n, i) for (int i = k; i < n; i++)
#define vi vector<int>
#define graph vector<vector<int>>
using namespace std;
using namespace __gnu_pbds;
class Trie
{ // we don't use it if length is long because it take a lot of memory using trie with map or linked list
private:
    // here u can control the number of children of each node
    Trie *child[2]; // array of child nodes of this node in the trie tree
    int cntPrefix;  // number of prefix that pass here
    int cntEnd;     // number of words that end here

public:
    Trie()
    {
        cntPrefix = 0;
        cntEnd = 0;
        memset(child, 0, sizeof(child));
    }

    void insert(string s)
    { // O(length of string)
        Trie *cur = this;
        for (char c : s)
        {
            if (cur->child[c - '0'] == NULL)
                cur->child[c - '0'] = new Trie();
            cur = cur->child[c - '0'];
            cur->cntPrefix++;
        }
        cur->cntEnd++;                                                                                                  
    }

    bool search(string s)
    { // O(length of string)
        Trie *cur = this;
        for (char c : s)
        {
            if (cur->child[c - '0'] == NULL)
                return false;
            cur = cur->child[c - '0'];
        }                                                                                               
        return cur->cntEnd > 0;
    }                                                                                                       

// trace all prefix and multiply number of prefixes and depth of child nodes function take ans and ans = max (ans,depth*number of prefix)
    void backtrack(int depth, int &ans)
    {
        for (int i = 0; i < 2; i++)
            if (child[i] != NULL){
                ans=max(ans,depth*child[i]->cntPrefix);
                child[i]->backtrack(depth + 1, ans);
            }
    }
};
void solve()
{
    int n, ans = 0;
    cin >> n;
    Trie trie;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        trie.insert(s);
    }
    trie.backtrack(1, ans);
    cout << ans <<endl;
}

int main()
{
    IOS int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
