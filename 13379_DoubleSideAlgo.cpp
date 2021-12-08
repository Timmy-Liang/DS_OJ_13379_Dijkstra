#include<iostream>
#include<algorithm>

#define Max 4000000000
#define maxN 2010
using namespace std;

long long tunnel[maxN][maxN];
long long dist[maxN];
bool s[maxN];
long long Edist[maxN];
int Bri[20010][3];
int main(void){
    int N,S,E;
    cin>>N;
    cin>>S;
    cin>>E;
    int t_num,b_num;
    long long no1,no2,le;
    cin>>t_num;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j)tunnel[i][j]=0;
            else tunnel[i][j]=Max;
        }
    }
    for(int i=0;i<t_num;i++){
        cin>>no1>>no2>>le;
        tunnel[no1][no2]=le;
        tunnel[no2][no1]=le;
    }
    cin>>b_num;
    for(int i=0;i<b_num;i++){
        cin>>no1>>no2>>le;
        Bri[i][0]=no1;
        Bri[i][1]=no2;
        Bri[i][2]=le;
    }
    for(int i=1;i<=N;i++){
        s[i]=false;
        dist[i]=tunnel[S][i];
    }
    s[S]=true;
    for(int i=0;i<N-1;i++){
        long long dis=Max;
        int u=0;
        for(int j=1;j<=N;j++){
            if(s[j]==false&&dist[j]<dis){
                dis=dist[j];
                u=j;
            }
        }
        s[u]=true;
        for(int w=1;w<=N;w++){
            if(s[w]==false&&dist[u]+tunnel[u][w]<dist[w]){
                dist[w]=dist[u]+tunnel[u][w];
            }
        }  
    }
    //cout<<dist[E]<<endl;
    for(int i=1;i<=N;i++){
        s[i]=false;
        Edist[i]=tunnel[E][i];
    }
    s[E]=true;
    for(int i=0;i<N-1;i++){
        long long dis=Max;
        int u;
        for(int j=1;j<=N;j++){
            if(s[j]==false&&Edist[j]<dis){
                dis=Edist[j];
                u=j;
            }
        }
        s[u]=true;
        for(int w=1;w<=N;w++){
            if(s[w]==false&&Edist[u]+tunnel[u][w]<Edist[w]){
                Edist[w]=Edist[u]+tunnel[u][w];
            }
        }  
    }
    long long ans=dist[E];
    for(int i=0;i<b_num;i++){
        int n1=Bri[i][0];
        int n2=Bri[i][1];
        long long d=Bri[i][2];
        long long t=min(dist[n1]+Edist[n2]+d , dist[n2]+Edist[n1]+d);
        ans=min(ans,t);
    }

    
    cout<<ans<<endl;
    return 0;
}