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

class Trie{ // we don't use it if length is long because it take a lot of memory using trie with map or linked list 
    private:
        // here u can control the number of children of each node
        Trie *child[3]; // array of child nodes of this node in the trie tree
        bool isEnd=0;

    public:
    Trie(){
        isEnd=0;
        memset(child,0,sizeof(child));
    }


    void insert(string s){ // O(length of string)
        Trie *cur=this;
        for(char c:s){
            if(cur->child[c-'a']==NULL)
                cur->child[c-'a']=new Trie();
            cur=cur->child[c-'a'];
        }
        cur->isEnd=true;
    }


// dfs for search for string 
    bool dfs(string &s,int idx,Trie *cur,int change){ // O(length of string)
        if(change>1||cur==NULL||idx>s.size()) return false;
        if(idx==s.size())
            return cur->isEnd>0&&change==1;
        bool found = false;
        for(int i=0;i<3&&!found;++i)
            if(cur->child[i]!=NULL)
                found|=dfs(s,idx+1,cur->child[i],change+(i!=s[idx]-'a'));
        return found;
    }

    // delete trie 
    void deleteTrie(){ // O(# nodes)
        for(int i=0;i<3;i++){
            if(child[i]!=NULL){
                child[i]->deleteTrie();
                delete child[i];
                child[i]=NULL;
            }
        }
    }
};
void solve()
{
    int n,m;cin>>n>>m;
    Trie *root = new Trie();
    for(int i=0;i<n;i++){
        string s;cin>>s;
        root->insert(s);
    }
    for(int i=0;i<m;i++){
        string s;cin>>s;
        Trie *cur = root;
        bool flag=0;
        int idx=0;
        if(root->dfs(s,idx,cur,0))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}

int main()
{
    IOS int T = 1;
    // cin >> T;
    for(int i=1;i<=T;i++){
        // cout<<"Case "<<i<<":\n";
        solve();
    }
    return 0;
}
