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
    void method(vvi& v, int n, int k){
        vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>());
        for(auto it: v){
            adj[it[0]].pb({it[1], it[2]});
        }
        vvi dist(n+1, vi());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        while(!pq.empty()){
            int currDist = pq.top().first, node = pq.top().second;
            pq.pop();
            if(dist[node].size() >= k) continue;
            dist[node].pb(currDist);
            for(auto it: adj[node]){
                int adjNode = it.first, edgeWeight = it.second;
                if(dist[adjNode].size() < k){
                    pq.push({currDist + edgeWeight, adjNode});
                }
            }
        }
        sort(all(dist[n]));
        for(auto it: dist[n]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin>>n>>m>>k;
    vvi v(m, vi(3));
    rep(i,0,m) cin>>v[i][0]>>v[i][1]>>v[i][2];
    Kaarti ob;
    ob.method(v, n, k);
    return 0;
}