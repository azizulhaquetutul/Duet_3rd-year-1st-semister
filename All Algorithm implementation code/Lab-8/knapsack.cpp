#include <bits/stdc++.h>
using namespace std;
int main(){
int dp[100][100];
int n, p[100],w[100],cap;
bool picked[100];
cout<<"pls enter the servival value , weight ; \n";
cin>>n>>cap;
for(int i=1; i<=n;i++)cin>>p[i];
for(int i=1; i<=n;i++)cin>>w[i];

for(int i=0; i<=n ;i++){
    for(int cur =0; cur<=cap; cur++){
        if(i==0||cur==0){dp[i][cur]=0;}
        else if( w[i]<= cur){
            dp[i][cur]= max(p[i]+ dp[i-1][cur-w[i]], dp[i-1][cur]);
        }
        else dp[i][cur]= dp[i-1][cur];
    }
}
int ans= dp[n][cap];
int ww=cap;
for(int i= n; i>0; i--){
    if(dp[i][ww]!=dp[i-1][ww]){
        picked[i]= true;
        ww-=w[i];
    }else picked[i]=0;
}
cout<<"ans = "<<ans<<endl;
for(int i=1; i<=n; i++){
    if(picked[i]){
cout<<"Item = "<<i<<" value = "<<p[i]<<" weight = "<<w[i]<<endl;
    }}}



