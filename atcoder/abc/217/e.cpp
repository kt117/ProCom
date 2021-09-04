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
    
    ll q; cin >> q;

    queue<ll> Q;
    priority_queue<ll, vector<ll>, greater<ll>> PQ;

    while(q--){
        ll c; cin >> c;

        if(c == 1){
            ll x; cin >> x;
            Q.push(x);
        }else if(c == 2){
            if(PQ.empty()){
                print(Q.front())
                Q.pop();
            }else{
                print(PQ.top())
                PQ.pop();
            }
        }else{
            while(!Q.empty()){
                PQ.push(Q.front());
                Q.pop();
            }
        }   
    }
    
    return 0;
}