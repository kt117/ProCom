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

long long powmod(long long a, long long x){
    if(x == 0)return 1;
    long long r = powmod(a, x / 2);
    return (x%2)? (r * r % MOD) * a % MOD : r * r % MOD;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll a[n], b[n];
    zep(i, 0, n - 1){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    if(n == 2){print(2) return 0;}

    dijkstra dr(n);
    zep(i, 0, n - 1){
        dr.append(a[i], b[i], 1);
        dr.append(b[i], a[i], 1);
    }
    dr.run(0);

    ll l = -1;
    ll mxl = 0;
    zep(i, 0, n){
        if(dr.get(i) > mxl){
            l = i;
            mxl = dr.get(l);
        }
    }

    dijkstra dl(n);
    zep(i, 0, n - 1){
        dl.append(a[i], b[i], 1);
        dl.append(b[i], a[i], 1);
    }
    dl.run(l);

    ll r = -1;
    ll mxr = 0;
    zep(i, 0, n){
        if(dl.get(i) > mxr){
            r = i;
            mxr = dl.get(i);
        }
    }
    dr.run(r);

    ll ans = mxr * powmod(2, n - 1) % MOD;
    
    ll cnt[n]; memset(cnt, 0, sizeof(cnt));
    ll ok = 0;
    zep(i, 0, n){
        if(i != l && i != r){
            cnt[max(dl.get(i), dr.get(i))]++;
            ok = max(ok, min(dl.get(i), dr.get(i)));
        }
    }
    zep(i, 1, n)cnt[i] += cnt[i - 1];

    ll p[n]; memset(p, 0, sizeof(p));
    zep(i, ok, n)p[i] = powmod(2, cnt[i]);
    zep(i, ok, n){
        ans += (p[i] + MOD - p[i - 1]) % MOD * 2 * i % MOD;
        ans %= MOD;
    }
    
    print(ans)

    return 0;
}