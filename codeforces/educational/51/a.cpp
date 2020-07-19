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
        string s; cin >> s;
        ll n = s.size();

        ll tag[n];

        zep(i, 0, n){
            if('a' <= s[i] && s[i] <= 'z'){
                tag[i] = 0;
            }else if('A' <= s[i] && s[i] <= 'Z'){
                tag[i] = 1;
            }else{
                tag[i] = 2;
            }
        }

        ll bit = 0;
        zep(i, 0, n)bit |= (1LL << tag[i]);
        
        ll cnt[3]; memset(cnt, 0, sizeof(cnt));
        zep(i, 0, n)cnt[tag[i]]++;

        if(bit == 7){
            print(s)
        }

        if(bit == 6){
            ll rp = (cnt[1] > 1)? 1 : 2;

            zep(i, 0, n){
                if(tag[i] == rp){
                    s[i] = 'a';
                    break;
                }
            }

            print(s)
        }

        if(bit == 5){
            ll rp = (cnt[0] > 1)? 0 : 2;

            zep(i, 0, n){
                if(tag[i] == rp){
                    s[i] = 'A';
                    break;
                }
            }

            print(s)
        }

        if(bit == 3){
            ll rp = (cnt[0] > 1)? 0 : 1;

            zep(i, 0, n){
                if(tag[i] == rp){
                    s[i] = '0';
                    break;
                }
            }

            print(s)
        }

        if(bit == 4){
            s[0] = 'a';
            s[1] = 'A';
            print(s)
        }

        if(bit == 2){
            s[0] = 'a';
            s[1] = '0';
            print(s)
        }

        if(bit == 1){
            s[0] = '0';
            s[1] = 'A';
            print(s)
        }
    }
    
    return 0;
}