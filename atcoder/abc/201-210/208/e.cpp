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

vector<ll> v;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;

    while(n){
        v.push_back(n % 10);
        n /= 10;
    }

    ll ans = 0;
    map<P, ll> mp;
    mp[P(1, 0)] = 1;
    zep(i, 0, v.size()){
        map<P, ll> mq;
        
        zep(j, 0, 10){
            for(auto it = mp.begin(); it != mp.end(); it++){
                auto p = *it;
                ll x = p.first.first * j;

                ll f;
                if(j < v[i]){
                    f = 0;
                }else if(j == v[i]){
                    f = p.first.second;
                }else{
                    f = 1;
                }

                P y = P(x, f);
                if(mq.find(y) == mq.end())mq[y] = 0;
                mq[y] += p.second;
                // mq[y] %= MOD;

                
                if(j != 0 && x <= k && (i != v.size() - 1 || f == 0)){
                    ans += p.second;
                    // ans %= MOD;
                }
            }
        }

        mp.swap(mq);
    }

    print(ans)
    
    return 0;
}