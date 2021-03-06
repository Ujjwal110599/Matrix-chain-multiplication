#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

void lcs(string s1, string s2, int m, int n){
    int cache[m+1][n+1];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                cache[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]){
                cache[i][j] = 1 + cache[i-1][j-1];
            }
            else{
                cache[i][j] = max(cache[i-1][j],cache[i][j-1]);
            }
        }
    }
    string str = "";
    int i=m,j=n;
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            str += s1[i-1];
            i--; j--;
        }
        else if(cache[i-1][j] > cache[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(str.begin(),str.end());
    cout << "LCS of " << s1 << " and " << s2 << " is " << str << endl;
    cout << "Length of LCS: " << str.length() << endl;
    cout << "Cache Table for reference:" << endl;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout << cache[i][j] << " ";
        }
        cout << endl;
    }
    
}

int main(){    
    string s1,s2;
    cout << "Enter vertical string" << endl;
    cin >> s1;
    cout << "Enter horizontal string" << endl;
    cin >> s2;
    lcs(s1,s2,s1.length(),s2.length());
   
    return 0;
}
