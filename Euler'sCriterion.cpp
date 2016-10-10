#include <bits/stdc++.h>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
    {
        long a,m;
        cin>>a>>m;
        if(m==2||a==0)
        {
            cout<<"YES\n";
            continue;
        }
        long k=(m-1)/2;
        long ans=1;
        while(k)
        {
            if(k%2){ans=(a*ans)%m;}
           
            {a=(a*a)%m;}
           k=k/2;
        }
        if(ans==1)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
    return 0;
}
