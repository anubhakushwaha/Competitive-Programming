#include <bits/stdc++.h>
using namespace std;

int main() {
    //code
  
    string s1,s2;
    cin>>s1>>s2;
    int table[s1.length()][s2.length()];
    memset(table,0,sizeof(table));
    if(s1[0]==s2[0])
    table[0][0]=1;
    for(int i=1;i<s1.length();i++)
    {
        for(int j=1;j<s2.length();j++)
        {
            if(s1[i]==s2[j])
            table[i][j]=table[i-1][j-1];
            else
            table[i][j]=1+table[i-1][j-1];
        }
    }
    cout<<table[s1.length()-1][s2.length()-1];
    return 0;
}