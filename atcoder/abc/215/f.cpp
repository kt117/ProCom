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

ll n;
vector<P> v;

bool f(ll mid){
    ll mx = -INF, mn = INF;
    queue<P> q;

    zep(i, 0, n){
        while(!q.empty() && q.front().first + mid <= v[i].first){
            mx = max(mx, q.front().second);
            mn = min(mn, q.front().second);
            q.pop();
        }

        if(mx - v[i].second >= mid)return true;
        if(v[i].second - mn >= mid)return true;
        q.push(v[i]);
    }
    return false;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    ll x[n], y[n];
    zep(i, 0, n)cin >> x[i] >> y[i];

    zep(i, 0, n)v.push_back(P(x[i], y[i]));
    sort(v.begin(), v.end());

    ll ok = 0, ng = INF;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;

        if(f(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    print(ok)
    
    return 0;
}