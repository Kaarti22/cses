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
private:
    void dfs(int node, vvi& adj, vector<bool>& vis){
        vis[node] = true;
        for(auto it: adj[node]){
            if(!vis[it]) dfs(it, adj, vis);
        }
    }

public:
    void method(vvi& v, int n){
        vvi adj(n+1), radj(n+1);
        for(auto it: v){
            adj[it[0]].pb(it[1]);
            radj[it[1]].pb(it[0]);
        }
        vi dist(n+1, -1e18);
        dist[1] = 0;
        rep(i,0,n-1){
            for(auto it: v){
                if(dist[it[0]] + it[2] > dist[it[1]]){
                    dist[it[1]] = dist[it[0]] + it[2];
                }
            }
        }
        vector<bool> inCycle(n+1, false);
        for(auto it: v){
            if(dist[it[0]] + it[2] > dist[it[1]]){
                inCycle[it[1]] = true;
            }
        }
        vector<bool> fromStart(n+1, false), toEnd(n+1, false);
        dfs(1, adj, fromStart);
        dfs(n, radj, toEnd);
        rep(i,1,n+1){
            if(inCycle[i] && fromStart[i] && toEnd[i]){
                cout<<-1<<endl;
                return;
            }
        }
        cout<<dist[n]<<endl;
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