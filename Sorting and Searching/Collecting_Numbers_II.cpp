#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define MOD 1000000007
#define pb push_back
#define popb pop_back
#define rep(i,a,b) for(int i=a; i<b; i++)
#define all(v) v.begin(),v.end()

void inparr(int arr[], int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void disarr(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void inpvec(vi &v, int n){
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
}

void disvec(vi v, int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

int madd(int a,int b) {
    return (a+b)%MOD;
}

int msub(int a,int b){
    return (((a-b)%MOD)+MOD)%MOD;
}

int mmul(int a,int b){
    return ((a%MOD)*(b%MOD))%MOD;
}

class Kaarti{
public:
    void method(vi &v, vector<pair<int, int>>& q, int n, int m){
        unordered_map<int, int>mp;
        rep(i,0,n){
            mp[v[i]] = i;
        }
        int ans = 1;
        rep(i,2,n+1){
            if(mp[i] < mp[i-1]) ans++;
        }
        for(auto it: q){
            int i = it.first - 1, j = it.second - 1;
            int a = 1;
            if(v[i]-1 > 0){
                if(mp[v[i]] < mp[v[i]-1]) a++;
            }
            int b = 1;
            if(v[i]+1 <= n){
                if(mp[v[i]+1] < mp[v[i]]) b++;
            }
            int c = 1;
            if(v[j]-1 > 0){
                if(mp[v[j]] < mp[v[j]-1]) c++;
            }
            int d = 1;
            if(v[j]+1 <= n){
                if(mp[v[j]+1] < mp[v[j]]) d++;
            }
            int org = a + b + c + d;
            cerr<<"org: "<<org<<endl;
            mp[v[i]] = j;
            mp[v[j]] = i;
            a = 1;
            if(v[i]-1 > 0){
                if(mp[v[i]] < mp[v[i]-1]) a++;
            }
            b = 1;
            if(v[i]+1 <= n){
                if(mp[v[i]+1] < mp[v[i]]) b++;
            }
            c = 1;
            if(v[j]-1 > 0){
                if(mp[v[j]] < mp[v[j]-1]) c++;
            }
            d = 1;
            if(v[j]+1 <= n){
                if(mp[v[j]+1] < mp[v[j]]) d++;
            }
            int final = a + b + c + d;
            cerr<<"final: "<<final<<endl;
            int diff = org - final;
            cerr<<"diff: "<<diff<<endl;
            cout<<ans - diff<<endl;
            ans -= diff;
        }
    }
};

int32_t main(){
    int n, m;
    cin>>n>>m;
    vi v(n);
    inpvec(v, n);
    vector<pair<int, int>>q(m);
    rep(i,0,m){
        cin>>q[i].first>>q[i].second;
    }
    Kaarti *ob = new Kaarti;
    ob->method(v, q, n, m);
    return 0;
}