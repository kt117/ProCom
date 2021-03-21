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
    string s; cin >> s;

    map<P, ll> mp;
    mp[P(0, 0)] = 1;

    P cur = P(0, 0);
    ll ans = 0;

    zep(i, 0, n){
        if(s[i] == 'A'){cur.first++;}
        if(s[i] == 'T'){cur.first--;}
        if(s[i] == 'C'){cur.second++;}
        if(s[i] == 'G'){cur.second--;}
        
        if(mp.find(cur) != mp.end()){
            ans += mp[cur];
        }else{
            mp[cur] = 0;
        }

        mp[cur]++;
    }
    print(ans)

    return 0;
}