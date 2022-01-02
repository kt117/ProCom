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
    
    ll n, x; cin >> n >> x;
    vector<vector<ll>> a(n);
    zep(i, 0, n){
        ll l; cin >> l;
        a[i].resize(l);
        zep(j, 0, l)cin >> a[i][j];
    }

    map<ll, ll> mp; mp[1] = 1;

    zep(i, 0, n){
        map<ll, ll> nmp;

        for(auto it = mp.begin(); it != mp.end(); it++){
            ll y = (*it).first;
            
            zep(j, 0, a[i].size()){
                ll z = y * a[i][j];
                // cout << z << " ";
                if(a[i][j] <= x / y && x % z == 0){
                    if(nmp.find(z) == nmp.end())nmp[z] = 0;
                    nmp[z] += (*it).second;
                }
            }
        }
        // cout << endl;

        mp.swap(nmp);
        // for(auto it = mp.begin(); it != mp.end(); it++)cout << (*it).first << " "; cout << endl;
    }

    if(mp.find(x) == mp.end()){
        print(0)
    }else{
        print(mp[x])
    }
    
    return 0;
}