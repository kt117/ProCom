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

ll n, p[1000], m, a[200000], b[200000];
vector<map<ll, ll>> g;
bool flag, use[1000];
vector<ll> memo, ans;

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

void f(ll at, ll d){
    // cout << at <<  " " << d << " " << from << endl;
    use[at] = true;
    if(at == d){flag = true; return;}

    for(auto it = g[at].begin(); it != g[at].end(); it++){
        ll nx = (*it).first;
        if(!use[nx]){
            f(nx, d);
            if(flag){
                memo.push_back((*it).second);
                return;
            }
        }
    }
}

ll fd(ll x){
    zep(i, 0, n)if(p[i] == x)return i;
    return -1;
}

void sp(ll j){
    ll tmp = p[a[j]];
    p[a[j]] = p[b[j]];
    p[b[j]] = tmp;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, n){cin >> p[i]; p[i]--;}

    g.resize(n);
    union_find u(n);
    cin >> m;
    zep(j, 0, m){
        cin >> a[j] >> b[j]; a[j]--; b[j]--;
        if(!u.same(a[j], b[j])){
            u.unite(a[j], b[j]);
            g[a[j]][b[j]] = j;
            g[b[j]][a[j]] = j;
        }
    }

    zep(i, 0, n){
        if(!u.same(p[i], i)){print(-1) return 0;}
    }

    queue<ll> q;
    zep(i, 0, n)if(g[i].size() == 1)q.push(i);

    while(!q.empty()){
        ll x = q.front(); q.pop();

        flag = false;
        memset(use, 0, sizeof(use));
        f(fd(x), x);

        // vector<ll> r;
        for(auto it = g[x].begin(); it != g[x].end(); it++){
            ll y = (*it).first;
            // r.push_back(y);
            g[y].erase(x);
            if(g[y].size() == 1)q.push(y);
        }

        // while(!r.empty()){
        //     g[x].erase(r.back());
        //     r.pop_back();
        // }

        while(!memo.empty()){
            ans.push_back(memo.back());
            sp(memo.back());
            memo.pop_back();
        }
    }

    print(ans.size())
    zep(i, 0, ans.size())cout << ans[i] + 1 << " "; cout << endl;
    
    return 0;
}