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
    void method(vi &h, int n, vi& t, int m){
        multiset<int>s;
        for(auto it: h) s.insert(it);
        for(auto it: t){
            auto ub = s.upper_bound(it);
            if(ub == s.begin()){
                cout<<-1<<endl;
            } else {
                ub--;
                cout<<*ub<<endl;
                s.erase(ub);
            }
        }
    }
};

int32_t main(){
    int n, m;
    cin>>n>>m;
    vi h(n);
    inpvec(h, n);
    vi t(m);
    inpvec(t, m);
    Kaarti *ob = new Kaarti;
    ob->method(h, n, t, m);
    return 0;
}