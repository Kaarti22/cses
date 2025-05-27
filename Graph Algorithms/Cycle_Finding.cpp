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

class Kaarti {
public:
    void method(vvi& v, int n) {
        vi dist(n+1, 0);
        vi parent(n+1, -1);
        int x = -1;
        rep(i,0,n){
            x = -1;
            for(auto it: v){
                int u = it[0], v = it[1], wt = it[2];
                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                    parent[v] = u;
                    x = v;
                }
            }
        }
        if(x == -1){
            cout<<"NO"<<endl;
            return;
        }
        rep(i,0,n){
            x = parent[x];
        }
        vi cycle;
        int curr = x;
        do {
            cycle.pb(curr);
            curr = parent[curr];
        } while(curr != x);
        cycle.pb(x);
        reverse(all(cycle));
        cout<<"YES"<<endl;
        for(auto it: cycle){
            cout<<it<<" ";
        }
        cout<<endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin>>n>>m;
    vvi v(m, vi(3));
    rep(i,0,m) cin>>v[i][0]>>v[i][1]>>v[i][2];
    Kaarti ob;
    ob.method(v, n);
    return 0;
}