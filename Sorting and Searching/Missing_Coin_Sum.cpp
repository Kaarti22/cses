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
    void method(vi &v, int n){
        sort(all(v));
        vi sum(n+1);
        sum[0] = 0;
        rep(i,0,n){
            sum[i+1] = sum[i] + v[i];
        }
        rep(i,0,n){
            if(v[i] > sum[i] + 1){
                cout<<sum[i] + 1<<endl;
                return;
            }
        }
        cout<<sum[n]+1<<endl;
    }
};

int32_t main(){
    int n;
    cin>>n;
    vi v(n);
    inpvec(v, n);
    Kaarti *ob = new Kaarti;
    ob->method(v, n);
    return 0;
}