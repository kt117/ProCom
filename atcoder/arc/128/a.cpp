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
    
    ll n; cin >> n;
    ll a[n]; zep(i, 0, n)cin >> a[i];

    ll at = 0;
    vector<ll> ans;
    
    zep(i, 0, n - 1){
        if(at == 0){
            if(a[i + 1] >= a[i]){
                ans.push_back(0);
            }else{
                ans.push_back(1);
                at = 1;
            }
        }else{
            if(a[i + 1] <= a[i]){
                ans.push_back(0);
            }else{
                ans.push_back(1);
                at = 0;
            }
        }
    }

    ans.push_back(at);

    zep(i, 0, n)cout << ans[i] << " "; cout << endl;

    return 0;
}