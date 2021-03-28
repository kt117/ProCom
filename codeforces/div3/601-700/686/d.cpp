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

        vector<P> v;
        for(ll i = 2; i * i <= n; i++){
            if(n % i == 0){
                ll cnt = 0;
                while(n % i == 0){
                    n /= i;
                    cnt++;
                }
                v.push_back(P(cnt, i));
            }
        }

        if(v.empty()){
            print(1)
            print(n)
        }else{
            sort(v.begin(), v.end(), greater<>());
            print(v[0].first)

            zep(i, 0, v[0].first - 1){
                cout << v[0].second << " ";
            }

            ll lst = v[0].second * n;
            zep(i, 1, v.size()){
                zep(j, 0, v[i].first){
                    lst *= v[i].second;
                }
            }
            cout << lst << endl;
        }
    }
    
    return 0;
}