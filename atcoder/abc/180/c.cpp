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

    vector<ll> ans;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            ans.push_back(i);
            if(i * i != n)ans.push_back(n / i);
        }
    }
    sort(ans.begin(), ans.end());

    zep(i, 0, ans.size()){
        print(ans[i])
    }
    
    return 0;
}