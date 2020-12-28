#include<bits/stdc++.h>
using namespace std;
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t,a,b;
        cin >> t;
        while(t--)
        {
            cin >> a >> b;
            if(a%b == 0)
            cout << "0";
            else
            if(a > b)
            {
                cout << ((a/b)+1)*b-a;
            }
            else
            cout << (b-a);
            cout << "\n"; 
        }
        return 0;
}
