#include<iostream>
#include<vector>
using namespace std;

void dijkstra(int v, const vector<vector<int>>& cost,vector<int>& dist, int n)
{
 vector<bool> S(n+1, false);
  for(int i=1; i<=n; i++){
      dist[i]=cost[v][i];
  }

  S[v]=true;
  dist[v]=0;

  for(int num=2 ; num<=n; num++){
      int u= -1;
      int minDist=INT_MAX;

      for(int i=1; i<=n; i++){
            if(!S[i] && dist[i] < minDist){
                  minDist=dist[i];
                  u=i;
            }
      }
      if(u==- 1)
            break;
      S[u]= true;

      for(int w=1; w<=n; w++){
            if(!S[w] && cost[u][w] != INT_MAX && dist[u] +cost[u][w] <dist[w]){
                  dist[w]= dist[u] + cost [u][w];
            }
      }
  }
}

int main()

{
   int n=7;
   int v=1;


   vector<vector<int>>cost={
	{0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 7, INT_MAX, 12, INT_MAX, INT_MAX},
        {0, INT_MAX, 0, INT_MAX, 2, INT_MAX, INT_MAX, INT_MAX},
        {0, INT_MAX, 3, 0,-1, 2, INT_MAX, INT_MAX},
        {0, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 2, INT_MAX},
        {0, -4, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, -7},
        {0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 2},
        {0, INT_MAX, INT_MAX, INT_MAX, 1, INT_MAX, INT_MAX, 0}


} ;


   vector<int> dist (n+1, INT_MAX);
   dijkstra(v,cost,dist,n);


   //output the shortest distance
   cout<<"shortest distances from vertex : " << v << "A : \n" ;
   for(int i=1; i<=n; i++){
      if(dist[i]==INT_MAX)
            cout<< "vertex " << i << " : INF\n ";
      else
            cout<< "vertex " << i << " : " <<dist [i] << '\n';
   }
   return 0;
}

