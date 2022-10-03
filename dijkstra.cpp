

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;


const double PI = acos(-1);


#define PB push_back
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (abs(a*b)/gcd(a,b))
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int inf=1e9;

const int mx_size = 1e5+123;

vector<pair<int,int>>adj[mx_size];
int distnc[mx_size];

void dijkstra(int source,int numOfnode)
{
    for (int i=1; i<=numOfnode;i++ )
    {
        distnc[i]= inf;

    }

    priority_queue< pair<long,long> ,vector<pair<long,long>>,greater<pair<long,long>>>pq;
          distnc[source]=0;
         pq.push({0,source});

         while(!pq.empty())
         {
             int currentweight= pq.top().first;
             int u= pq.top().second;


             pq.pop();

             if(distnc[u]<currentweight) continue;

             for(auto p:adj[u])
             {
                    int v= p.first;
                    int w= p.second;
                    if(currentweight+w<distnc[v])
                    {

                         distnc[v] =currentweight+w;

                         pq.push({distnc[v],v});
                    }

             }




         }


}






int main()
{
    /*
    simple graph
 7 8 //node and edge
1 2 45
1 3 33
2 5 23
3 6 56
3 4 13
5 6 36
5 7 90
6 7 65

    */


    /*
    multi graph
 7 11 //node and edge
1 2 45
1 2 5
1 2 65
1 3 33
2 5 23
3 6 56
3 4 13
3 4 3
5 6 36
5 7 90
6 7 65

    */

    int numOfVertex,numOfEdge;
    cout<< " enter Num of node and edge"<<endl;

    cin>>numOfVertex>>numOfEdge;
    cout<<"enter all edge"<<endl;

    for (int i=1; i<=numOfEdge;i++ )
    {
        int u,v,w;
        cin>>v>>u>>w;
        adj[v].push_back({u,w});
        adj[u].push_back({v,w});

    }


   /* for (int i=1; i<=numOfVertex;i++ )
    {
        cout<< "The adjecency list of "<< i<<endl;
        for(auto m: adj[i]) cout<< "node: "<< m.first<< "   weght : "<< m.second<< " -->";
            cout<<endl;
    }

*/

dijkstra(1,numOfVertex);

for (int i=1; i<=numOfVertex;i++ )
{
    cout<< i<<" --->>"<<distnc[i]<<endl;

}






return 0;
}
