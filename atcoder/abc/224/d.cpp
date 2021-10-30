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

ll encode(vector<ll> v){
    ll res = 0;
    zep(i, 0, v.size()){
        res *= 10;
        res += v[i];
    }
    return res;
}

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

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll m; cin >> m;
    ll u[m], v[m]; zep(i, 0, m){cin >> u[i] >> v[i]; u[i]--; v[i]--;}
    ll p[8]; zep(i, 0, 8){cin >> p[i]; p[i]--;}
    
    map<ll, ll> mp;
    vector<ll> a = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    ll cnt = 0;
    do{
        mp[encode(a)] = cnt;
        cnt++;
    }while(next_permutation(a.begin(), a.end()));
    
    dijkstra d(cnt + 1);

    do{
        zep(i, 0, m){
            if(a[u[i]] == 8){
                vector<ll> b(a.size());
                copy(a.begin(), a.end(), b.begin());
                b[u[i]] = a[v[i]];
                b[v[i]] = 8;
                d.append(mp[encode(a)], mp[encode(b)], 1);
            }
            if(a[v[i]] == 8){
                vector<ll> b(a.size());
                copy(a.begin(), a.end(), b.begin());
                b[v[i]] = a[u[i]];
                b[u[i]] = 8;
                d.append(mp[encode(a)], mp[encode(b)], 1);
            }   
        }
    }while(next_permutation(a.begin(), a.end()));

    vector<ll> c(9, 8);
    zep(i, 0, 8)c[p[i]] = i;
    d.run(mp[encode(c)]);

    print(d.get(mp[encode(a)]))

    return 0;
}