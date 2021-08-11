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

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll h[n], w[n]; zep(i, 0, n)cin >> h[i] >> w[i];

        zep(i, 0, n){
            if(h[i] < w[i]){
                ll tmp = h[i];
                h[i] = w[i];
                w[i] = tmp;
            }
        }

        map<ll, P> mp;
        zep(i, 0, n){
            if(mp.find(-h[i]) == mp.end()){
                mp[-h[i]] = P(INF, -1);
            }

            if(mp[-h[i]].first > w[i]){
                mp[-h[i]] = P(w[i], i);
            }
        }

        P mn = P(INF, -1);
        for(auto it = mp.rbegin(); it != mp.rend(); it++){
            if((*it).second.first < mn.first){
                mn = (*it).second;
            }
            mp[(*it).first] = mn;
            // cout << mn.first << endl;
        }

        zep(i, 0, n){
            auto it = mp.upper_bound(-h[i]);
            if(it != mp.end() && (*it).second.first < w[i]){
                cout << (*it).second.second + 1 << " ";
            }else{
                cout << -1 << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}