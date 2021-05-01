#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

struct union_find {
    vector<int> par, siz;
    union_find(int n) {
        par.resize(n);
        siz.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            siz[i] = 1;
        }
    }
    
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
 
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)return;
        if (siz[x] < siz[y]) {
            par[x] = y;
            siz[y] += siz[x];
        }
        else {
            par[y] = x;
            siz[x] += siz[y];
        }
    }
    
    long long size(int x){
        return siz[find(x)];
    }

    bool same(int x, int y) {
        return (find(x) == find(y));
    }
};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    ll a[m]; zep(j, 0, m)cin >> a[j];
    
    set<ll> s; zep(j, 0, m)s.insert(a[j]);
    vector<P> b; zep(i, 1, n)if(s.find(i) == s.end())b.push_back(P(i, i));

    ll x = 0, p = 1;
    while(p != n){x++; p *= 2;}
    //print(x)
    //printa(b, 0, b.size() - 1)
    set<ll> use;
    rrep(k, x - 1, 0){
        sort(b.begin(), b.end(), greater<>());
        while(!b.empty() && b.back().first == 0)b.pop_back();

        if(!b.empty() && (b[0].first & (1LL << k))){
            use.insert(b[0].second);
            rrep(i, b.size() - 1, 0){
                if(b[i].first & (1LL << k)){
                    b[i].first ^= b[0].first;
                }
            }
        }else{
            print(-1) return 0;
        }
        //printa(b, 0, b.size() - 1)
        //zep(i, 0, b.size())cout << b[i].first << " "; cout << endl;
        //zep(i, 0, b.size())cout << b[i].second << " "; cout << endl;
    }

    vector<ll> v; for(auto it = use.begin(); it != use.end(); it++)v.push_back(*it);
    //rrep(i, v.size() - 1, 0)zep(j, i + 1, v.size())v[j] ^= v[i];

    union_find u(n);
    
    zep(k, 0, v.size()){
        zep(i, 0, n){
            if(!u.same(i, (i ^ v[k]))){
                cout << i << " " << (i ^ v[k]) << endl;
                u.unite(i, (i ^ v[k]));
            }
        }
    }

    return 0;
}