#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
    {
        int n,m;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        int ch1[26];
        memset(ch1,0,sizeof(ch1));
        int ch2[26];
        memset(ch2,0,sizeof(ch2));
        for(int i=0;i<s1.length();i++)
        ch1[(int)(s1[i]-'a')]++;
        for(int i=0;i<s2.length();i++)
        ch2[(int)(s2[i]-'a')]++;
        string temp="";
        for(int i=0;i<26;i++)
        cout<<ch1[i]<<"\n";
        cout<<"\n";
        for(int i=0;i<26;i++)
        cout<<ch2[i]<<"\n";
        cout<<"\n";
        for(int i=0;i<26;i++)
        {
            if(ch1[i]!=0&&ch2[i]!=0)
            {
                int val=ch1[i]-ch2[i];
                if(val==0)
                temp+=(char)(i+97);
                else
                {
                if(val<0)
                val*=-1;
                val++;
                while(val--)
                temp+=(char)(i+97);
                }
            }
        }
        cout<<temp<<"\n";
    }
	return 0;
}