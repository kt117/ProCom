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

ll h, w, ch, cw, dh, dw, dst[1010][1010];
string s[1010];

struct dijkstra{
    vector<long long> min_dst;
    vector<vector<pair<long long, long long>>> G;

    dijkstra(int n){
        min_dst.resize(n);
        G.resize(n);
    }

    void append(int u, int v, long long cost){G[u].push_back(make_pair(v, cost));}
    
    void run(int s){
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> que;
        fill(min_dst.begin(), min_dst.end(), -1);
        min_dst[s] = 0;
        que.push(make_pair(0, s));
        
        while(!que.empty()){
            auto p = que.top(); que.pop();
            int at = p.second;
            if(min_dst[at] < p.first){continue;}
            for(int i = 0; i < G[at].size(); i++){
                int to = G[at][i].first;
                long long cost = G[at][i].second;
                if(min_dst[to] == -1 || min_dst[at] + cost < min_dst[to]){
                    min_dst[to] = min_dst[at] + cost;
                    que.push(make_pair(min_dst[to], to));
                }
            }
        }	
    }
    
    long long get(int at){return min_dst[at];}
};

ll encode(ll x, ll y){
    return x * w + y;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> h >> w >> ch >> cw >> dh >> dw;
    zep(i, 0, h)cin >> s[i];
    ch--; cw--; dh--; dw--;

    dijkstra d(h * w);

    ll dx[4] = {-1, 1, 0, 0};
    ll dy[4] = {0, 0, -1, 1};
    zep(i, 0, h){
        zep(j, 0, w){
            zep(k, 0, 4){
                ll nx = i + dx[k], ny = j + dy[k];

                if(0 <= nx && nx < h && 0 <= ny && ny < w){
                    if(s[i][j] == '.' && s[nx][ny] == '.'){
                        d.append(encode(i, j), encode(nx, ny), 0);
                    }
                }
            }

            rep(k, -2, 2){
                rep(l, -2, 2){
                    ll nx = i + k, ny = j + l;

                    if(!(k == 0 && l == 0) && 0 <= nx && nx < h && 0 <= ny && ny < w){
                        if(s[i][j] == '.' && s[nx][ny] == '.'){
                            d.append(encode(i, j), encode(nx, ny), 1);
                        }
                    }
                }
            }
        }
    }

    d.run(encode(ch, cw));
    print(d.get(encode(dh, dw)))

    return 0;
}