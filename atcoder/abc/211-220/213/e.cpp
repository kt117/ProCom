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

ll h, w;

bool ok(ll i, ll j){
    return i >= 0 && i < h && j >= 0 && j < w;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> h >> w;
    string s[h]; zep(i, 0, h)cin >> s[i];

    ll d[h][w];
    zep(i, 0, h)zep(j, 0, w)d[i][j] = INF;
    d[0][0] = 0;

    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> q;
    bool use[h][w]; memset(use, 0, sizeof(use));

    q.push({0, 0, 0});
    while(!q.empty()){
        auto v = q.top(); q.pop();
        ll c = v[0], i = v[1], j = v[2];

        if(!use[i][j]){
            use[i][j] = true;

            ll dh[] = {-1, 1, 0, 0};
            ll dw[] = {0, 0, -1, 1};

            zep(k, 0, 4){
                if(ok(i + dh[k], j + dw[k]) && s[i + dh[k]][j + dw[k]] == '.'){
                    if(c < d[i + dh[k]][j + dw[k]]){
                        d[i + dh[k]][j + dw[k]] = c;
                        q.push({c, i + dh[k], j + dw[k]});
                    }
                }
            }

            ll ndh[] = {-2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2};
            ll ndw[] = {-1, 0, 1, -2, -1, 0, 1, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2, -1, 0, 1};

            zep(k, 0, 20){
                if(ok(i + ndh[k], j + ndw[k])){
                    if(c + 1 < d[i + ndh[k]][j + ndw[k]]){
                        d[i + ndh[k]][j + ndw[k]] = c + 1;
                        q.push({c + 1, i + ndh[k], j + ndw[k]});
                    }
                }
            }
        }
    }

    print(d[h - 1][w - 1])

    return 0;
}