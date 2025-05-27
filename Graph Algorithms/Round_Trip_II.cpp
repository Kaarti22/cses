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
    bool dfs(int node, vvi& adj, vi& vis, vi& pathVis, vi& par, int& start, int& end){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it: adj[node]){
            if(vis[it] == 0){
                par[it] = node;
                if(dfs(it, adj, vis, pathVis, par, start, end)){
                    return true;
                }
            } else if(pathVis[it] == 1){
                end = node;
                start = it;
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }

public:
    void method(vvi& v, int n){
        vvi adj(n+1, vi());
        for(auto it: v){
            adj[it[0]].pb(it[1]);
        }
        vi vis(n+1, 0), pathVis(n+1, 0);
        vi par(n+1, -1);
        int st = -1, end = -1;
        rep(i,1,n+1){
            if(vis[i] == 0){
                if(dfs(i, adj, vis, pathVis, par, st, end)){
                    break;
                }
            }
        }
        if(st == -1){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        vi cycle;
        cycle.pb(st);
        int curr = end;
        while(curr != st){
            cycle.pb(curr);
            curr = par[curr];
        }
        cycle.pb(st);
        reverse(all(cycle));
        cout<<cycle.size()<<endl;
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
    vvi v(m, vi(2));
    rep(i,0,m) cin>>v[i][0]>>v[i][1];
    Kaarti ob;
    ob.method(v, n);
    return 0;
}