#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int M=1e9+7;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int W,H,n,m;
    cin>>W>>H>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    unordered_set<int> setB;
    for(int i=0;i<m;i++){
        setB.insert(b[i]);
    }
    
    unordered_map<int,int> mpX;
    unordered_set<int> sideY;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            mpX.insert({abs(a[i]-a[j]),1});
        }
    }
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            sideY.insert(abs(b[i]-b[j]));
        }
    }
    
    
    int ans1=0;
    auto itY=sideY.begin();
    while(itY!=sideY.end()){
        if(mpX.find(*itY)!=mpX.end()){
            mpX[*itY]=0;
            ans1++;
        }
        ++itY;
    }
    
    
    int ans2=0;
    for(int i=0;i<=H;i++){
        int count=0;
        if(setB.find(i)==setB.end()){
            unordered_set<int> new_sideY;
            unordered_set<int> deleted;
            deleted.clear();
            new_sideY.clear();
            for(int j=0;j<m;j++){
                int side=abs(i-b[j]);
                new_sideY.insert(side);
            }
            auto it=new_sideY.begin();
            while(it!=new_sideY.end()){
                if(mpX.find(*it)!=mpX.end()){
                    if(mpX[*it]==1){
                        mpX[*it]=0;
                        deleted.insert(*it);
                        count++;
                    }
                }
                it++;
            }
            it=deleted.begin();
            while(it!=deleted.end()){
                mpX[*it]=1;
                it++;
            }
            ans2=max(ans2,count);
        }
    }
    cout<<ans1+ans2;
}