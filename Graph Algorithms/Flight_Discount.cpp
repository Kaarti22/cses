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
    void dijkstra(vector<vector<pair<int, int>>>& adj, vi& dist, int src){
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while(!pq.empty()){
            int currDist = pq.top().first, node = pq.top().second;
            pq.pop();
            if(currDist > dist[node]) continue;
            for(auto it: adj[node]){
                int adjNode = it.first, edgeWeight = it.second;
                if(dist[node] + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dist[node] + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
    }

public:
    void method(vvi &v, int n){
        vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>());
        vector<vector<pair<int, int>>> radj(n+1, vector<pair<int, int>>());
        for(auto it: v){
            adj[it[0]].pb({it[1], it[2]});
            radj[it[1]].pb({it[0], it[2]});
        }
        vi forwardDist(n+1, LLONG_MAX);
        dijkstra(adj, forwardDist, 1);
        vi backwardDist(n+1, LLONG_MAX);
        dijkstra(radj, backwardDist, n);
        int ans = LLONG_MAX;
        for(auto it: v){
            int u = it[0], v = it[1], wt = it[2];
            if(forwardDist[u] == LLONG_MAX || backwardDist[v] == LLONG_MAX) continue;
            ans = min(ans, forwardDist[u] + wt / 2 + backwardDist[v]);
        }
        cout<<ans<<endl;
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