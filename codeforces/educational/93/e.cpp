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

ll n, tp, d, sm, smk; 
map<ll, ll> mp;
set<ll> sk, s[2];

void g(){
    ll index = 0;
    if(s[0].empty() || *s[0].rbegin() < *s[1].rbegin()){
        index = 1;
    }
    ll tmp = *s[index].rbegin();
    s[index].erase(tmp);
    sk.insert(tmp);
    smk += tmp;
}

ll f(){
    ll res = sm + smk;

    if(s[1].empty() && !sk.empty()){
        res -= *sk.begin();
        if(!s[0].empty())res += *s[0].rbegin();
    }

    return res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, n){
        cin >> tp >> d;
        sm += d;

        if(d > 0){
            mp[d] = tp;

            if(tp == 0){
                sk.insert(d);

                ll tmp = *sk.begin(); sk.erase(tmp);
                smk += d - tmp;
                s[mp[tmp]].insert(tmp);
            }else{
                s[1].insert(d);

                g();
            }
        }else{
            d *= -1;

            if(tp == 1){
                ll tmp = *sk.begin(); sk.erase(tmp);
                smk -= tmp;
                s[mp[tmp]].insert(tmp);
            }

            if(sk.find(d) != sk.end()){
                smk -= d;
                sk.erase(d);

                g();
            }else{
                s[tp].erase(d);
            }

            mp.erase(d);
        }

        print(f())
        //for(auto it = sk.begin(); it != sk.end(); it++)cout << (*it) << " "; cout << endl;
        //for(auto it = s[0].begin(); it != s[0].end(); it++)cout << (*it) << " "; cout << endl;
        //for(auto it = s[1].begin(); it != s[1].end(); it++)cout << (*it) << " "; cout << endl;
    }

    return 0;
}