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

ll n, p[2 * 101 * 1001], db[20][2 * 101 * 1001], iv[2 * 101 * 1001], dep[2 * 101 * 1001], Q;
vector<ll> v, ans;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 1, n){cin >> p[i]; p[i]--;}

    vector<vector<ll>> g(n);
    zep(i, 1, n)g[p[i]].push_back(i);
    //zep(i, 0, n){zep(j, 0, g[i].size())cout << g[i][j] << " "; cout << endl;}
    queue<ll> q;
    iv[0] = v.size();
    q.push(0);
    v.push_back(0);

    while(!q.empty()){
        ll at = q.front(); q.pop();
        
        db[0][iv[at]] = v.size();
        zep(i, 0, g[at].size()){
            iv[g[at][i]] = v.size();
            v.push_back(g[at][i]);
            q.push(g[at][i]);
            dep[g[at][i]] = dep[at] + 1;
        }
    }
    db[0][n] = v.size();

    zep(j, 1, 20){
        rep(i, 0, n){
            db[j][i] = db[j - 1][db[j - 1][i]];
        }
    }
    
    cin >> Q;
    while(Q--){
        ll u, d; cin >> u >> d; u--;
        d -= dep[u];
        
        if(d < 0){
            ans.push_back(0); continue;
        }

        ll l = iv[u], r = iv[u] + 1;
        rrep(j, 19, 0){
            if(d & (1LL << j)){
                l = db[j][l];
                r = db[j][r];
            }
        }
        ans.push_back(r - l);
    }

    zep(i, 0, ans.size())print(ans[i])
    
    return 0;
}