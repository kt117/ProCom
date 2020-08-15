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

ll n, tp, d, k, sm, smk; 
map<int, bool> s;
priority_queue<int> sk, sf, sl;

ll f(){
    ll res = sm + smk;

    if(sl.empty() && !sk.empty()){
        res += sk.top();
        if(!sf.empty())res += sf.top();
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
            s[d] = (tp == 0);

            if(tp == 0){
                sk.push(-d);
                ll tmp = -sk.top(); sk.pop();
                smk += d - tmp;

                if(s[tmp]){
                    sf.push(tmp);
                }else{
                    sl.push(tmp);
                }
            }else{
                k++;
                sl.push(d);

                if(sf.empty() || sf.top() < sl.top()){
                    sk.push(-sl.top());
                    smk += sl.top();
                    sl.pop();
                }else{
                    sk.push(-sf.top());
                    smk += sf.top();
                    sf.pop();
                }
            }
        }else{
            d *= -1;

            if(!sk.empty() && d >= -sk.top()){
                smk -= d;

                if(sf.empty() || (!sl.empty() && sf.top() < sl.top())){
                    sk.push(-sl.top());
                    smk += sl.top();
                    sl.pop();
                }else{
                    sk.push(-sf.top());
                    smk += sf.top();
                    sf.pop();
                }
            }

            if(tp == 1){
                k--;

                ll tmp = -sk.top(); sk.pop();
                smk -= tmp;

                if(s[tmp]){
                    sf.push(tmp);
                }else{
                    sl.push(tmp);
                }
            }

            s.erase(d);
        }

        while(!sk.empty() && s.find(-sk.top()) == s.end())sk.pop();
        while(!sf.empty() && s.find(sf.top()) == s.end())sf.pop();
        while(!sl.empty() && s.find(sl.top()) == s.end())sl.pop();

        print(f())
    }

    return 0;
}