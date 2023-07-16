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
        Trie *child[26]; // array of child nodes of this node in the trie tree
        int cntPrefix;   // number of prefix that pass here
        int cntEnd;      // number of words that end here

    public:
    Trie(){
        cntPrefix = 0;
        cntEnd = 0;
        memset(child,0,sizeof(child));
    }


    void insert(string s){ // O(length of string)
        Trie *cur=this;
        for(char c:s){
            if(cur->child[c-'a']==NULL)
                cur->child[c-'a']=new Trie();
            cur=cur->child[c-'a'];
            cur->cntPrefix++;
        }
        cur->cntEnd++;
    }

    int search(string s){ // O(length of string)
        Trie *cur=this;
        for(char c:s){
            if(cur->child[c-'a']==NULL)
                return 0;
            cur=cur->child[c-'a'];
        }
        return cur->cntEnd;
    } 


// construct strings that have prefix given 
    void construct(string s,int &len,vector<string>&ans){ // O(length of string)
        Trie *cur=this;
        for(char c:s){
            if(cur->child[c-'a']==NULL)
                return;
            cur=cur->child[c-'a'];
        }
        dfs(s,len,cur,ans);
    }
    void dfs(string s,int &len,Trie *cur,vector<string>&ans){ // O(# nodes)
        if(cur->cntEnd>0&&s.size()>len){
            ans.push_back(s);
        }
        for(int i=0;i<26;i++){
            if(cur->child[i]!=NULL){
                dfs(s+(char)(i+'a'),len,cur->child[i],ans);
            }
        }
    }





    // delete trie 
    void deleteTrie(){ // O(# nodes)
        for(int i=0;i<26;i++){
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
    int n;cin>>n;
    Trie trie;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        trie.insert(s);
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        vector<string>ans;
        int len=sz(s);
        trie.construct(s,len,ans);
        cout << "Case #" << i << ":\n";
        if(ans.empty()) cout<<"No match.\n";
        else{
            for(auto i:ans){
                cout<<i<<'\n';
            }
        }
    }
    trie.deleteTrie();
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
