#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,pattern;
  cout<<"Enter the string: ";
  cin>>s;
  cout<<"Enter the pattern: ";
  cin>>pattern;
  int n=s.length(),m=pattern.length();
  int h1=0,p=m-1;
  for(int i=0;i<m;i++)
    h1=h1+int(pattern[i])*pow(126,p--);
  int h2=0;
  p=m-1;
  for(int i=0;i<m;i++)
    h2=h2+int(s[i])*pow(126,p--);
  for(int i=m;i<=n;i++)
  {
    if(h2==h1)
    {
      int k;
      for(k=0;k<m;k++)
      {
        if(pattern[k]!=s[i-m+k])
          break;
      }
      if(k==m)
      {
        cout<<"Pattern matched at "<<i-m<<" index"<<endl;
        return 0;
      }
    }    
    h2=h2-int(s[i-m])*pow(126,m-1);
    h2=(h2*126+int(s[i]))%INT_MAX;
  }
  cout<<"Pattern not matched";
  return 0;
}
