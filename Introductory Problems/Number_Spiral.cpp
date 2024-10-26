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
    void method(int y, int x){
        int n = max(y, x);
        int left = (n-1) * (n-1) + 1;
        int right = n * n;
        bool f = 1;
        if(n & 1) f = 0;
        if(x == n){
            if(f){
                cout<<left + y - 1<<endl;
            } else {
                y = n - y + 1;
                cout<<left + (right - left)/2 + y - 1<<endl;
            }
        } else {
            if(f){
                x = n - x + 1;
                cout<<left + (right - left)/2 + x - 1<<endl;
            } else {
                cout<<left + x - 1<<endl;
            }
        }
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int y, x;
        cin>>y>>x;
        Kaarti *ob = new Kaarti;
        ob->method(y, x);
    }
    return 0;
}