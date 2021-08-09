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
    
    ll h, w, n; cin >> h >> w >> n;
    ll a[n], b[n]; zep(i, 0, n){cin >> a[i] >> b[i]; a[i]--; b[i]--;}

    set<ll> usea, useb;
    zep(i, 0, n){
        usea.insert(a[i]);
        useb.insert(b[i]);
        //  = true;
    }

    ll cnt = 1;
    map<ll, ll> mpa, mpb;
    for(auto it = usea.begin(); it != usea.end(); it++){
        mpa[(*it)] = cnt;
        cnt++;
    }
    cnt = 1;
    for(auto it = useb.begin(); it != useb.end(); it++){
        mpb[(*it)] = cnt;
        cnt++;
    }

    zep(i, 0, n){
        cout << mpa[a[i]] << " " << mpb[b[i]] << endl;
    }


    return 0;
}