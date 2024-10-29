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
    void method(vector<pair<int, int>> &v, int n){
        sort(all(v), [&](pair<int, int>& a, pair<int, int>& b){
            return a.second < b.second;
        });
        int ans = 0, end = 0;
        for(auto it: v){
            if(it.first >= end){
                ans++;
                end = it.second;
            }
        }
        cout<<ans<<endl;
    }
};

int32_t main(){
    int n;
    cin>>n;
    vector<pair<int, int>> v(n);
    rep(i,0,n){
        cin>>v[i].first>>v[i].second;
    }
    Kaarti *ob = new Kaarti;
    ob->method(v, n);
    return 0;
}