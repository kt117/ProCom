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

ll n, m, cnt[200][2];
vector<vector<P>> g(200);
bool use[200];

bool f(ll a, ll b, ll c, ll d){
    if(abs(a) % 2 != abs(b) % 2)return false;
    if(abs(a) % 2 != abs(c) % 2)return false;
    if(abs(a) % 2 != abs(d) % 2)return false;
    if(d < a || b < c)return false;
    return true;
}

ll f2(ll i){
    memset(use, 0, sizeof(use));
    memset(cnt, 0, sizeof(cnt));

    queue<ll> q;
    use[i] = true; q.push(i);

    while(!q.empty()){
        //zep(i, 0, n)cout << cnt[i][0] << " "; cout << endl;
        //zep(i, 0, n)cout << cnt[i][1] << " "; cout << endl;
        ll at = q.front(); q.pop();
        //print(at)
        zep(j, 0, g[at].size()){
            P nx = g[at][j];

            ll dcnt[2] = {0, 0};
            if(nx.second == 0){dcnt[0]--; dcnt[1]++;} 
            if(nx.second == -1){dcnt[0]--; dcnt[1]--;}
            if(nx.second == 1){dcnt[0]++; dcnt[1]++;}
            
            if(!use[nx.first]){
                use[nx.first] = true; q.push(nx.first);

                cnt[nx.first][0] = cnt[at][0] + dcnt[0];
                cnt[nx.first][1] = cnt[at][1] + dcnt[1];
            }else{
                if(!f(cnt[nx.first][0], cnt[nx.first][1], cnt[at][0] + dcnt[0], cnt[at][1] + dcnt[1]))return -1;

                cnt[nx.first][0] = max(cnt[nx.first][0], cnt[at][0] + dcnt[0]);
                cnt[nx.first][1] = min(cnt[nx.first][1], cnt[at][1] + dcnt[1]);
            }
        }
    }

    ll res = -INF;
    zep(i, 0, n)res = max(res, cnt[i][1]);
    return res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;
    zep(j, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back(P(b, c));
        g[b].push_back(P(a, - c));
    }

    bool ok = false;
    ll ans = 0;
    ll ansi = 0;
    //print(f2(0))
    //return 0;
    zep(i, 0, n){
        ll res = f2(i);
        
        if(res >= ans){
            ok = true;
            ans = res;
            ansi = i;
        }
    }

    if(ok){
        print("YES")
        print(ans)

        f2(ansi);

        zep(i, 0, n)cout << cnt[i][1] << " ";
        cout << endl;
    }else{
        print("NO")
    }
    
    return 0;
}