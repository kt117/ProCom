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
    while(n > 0){
        if(n % 2 == 0){
            ans.push_back(1);
            n /= 2;
        }else{
            ans.push_back(0);
            n--;
        }
    }
    reverse(ans.begin(), ans.end());

    zep(i, 0, ans.size()){
        cout << (ans[i]? 'B' : 'A');
    }
    cout << endl;
    
    return 0;
}