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
    ll a[n]; zep(i, 0, n)cin >> a[i];

    vector<ll> ans;
    zep(i, 0, n){
        if(a[i] != x){
            ans.push_back(a[i]);
        }
    }

    zep(i, 0, ans.size()){
        cout << ans[i] << " ";
    }cout << endl;
    
    return 0;
}