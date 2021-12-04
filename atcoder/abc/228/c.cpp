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
    
    ll n, k; cin >> n >> k;
    ll p[n][3]; zep(i, 0, n)zep(j, 0, 3)cin >> p[i][j];

    vector<vector<ll>> v;
    zep(i, 0, n){
        v.push_back({p[i][0] + p[i][1] + p[i][2] + 300, 1, i});
        v.push_back({p[i][0] + p[i][1] + p[i][2], 0, i});
    }
    sort(v.begin(), v.end(), greater<>());

    bool ans[n];
    ll cnt = 0;
    zep(i, 0, v.size()){
        if(v[i][1] == 1){
            ans[v[i][2]] = cnt < k;
        }else{
            cnt++;
        }
    }

    zep(i, 0, n)print(ans[i]? "Yes" : "No")
    
    return 0;
}