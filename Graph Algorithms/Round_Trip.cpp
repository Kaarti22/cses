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
    void dfs(int node, int parent, vvi& adj, vi& vis, unordered_map<int, int>& par, int& st, int& end){
        for(auto it: adj[node]){
            if(end != -1) return;
            if(vis[it] == 1 && it != parent){
                st = it;
                end = node;
                return;
            }
            if(vis[it] == 0){
                vis[it] = 1;
                par[it] = node;
                dfs(it, node, adj, vis, par, st, end);
            }
        }
    }

public:
    void method(vvi& v, int n){
        vvi adj(n+1, vi());
        for(auto it: v){
            adj[it[0]].pb(it[1]);
            adj[it[1]].pb(it[0]);
        }
        vi vis(n+1, 0);
        unordered_map<int, int> par;
        int end = -1, st = -1;
        rep(i,1,n+1){
            if(end != -1) break;
            if(vis[i] == 0){
                vis[i] = 1;
                dfs(i, -1, adj, vis, par, st, end);
            }
        }
        if(end == -1){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        vi path;
        path.pb(st);
        path.pb(end);
        int curr = end;
        while(curr != st){
            int parent = par[curr];
            path.pb(parent);
            curr = parent;
        }
        reverse(all(path));
        cout<<path.size()<<endl;
        for(auto it: path){
            cout<<it<<" ";
        }
        cout<<endl;
    }
};

int32_t main(){
    int n, m;
    cin>>n>>m;
    vvi v(m, vi(2));
    rep(i,0,m) cin>>v[i][0]>>v[i][1];
    Kaarti ob;
    ob.method(v, n);
    return 0;
}