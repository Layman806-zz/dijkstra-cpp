#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define edge pair < int, int>
#define infinite 32767

vector < pair < int, edge > > G;
vector<int> key, rel;
int N, E;

void init_keys()
{
	key.resize(N);
	key[0]=0;
	for(int i=1; i<N; i++)
	{
		key[i]=infinite;
	}
}

void dijkstra()
{
	rel.resize(N);
	int count=0;
	sort(G.begin(), G.end());
	while(count<E)
	{
		if((key[G[count].first]+G[count].second.second)<key[G[count].second.first])
		{
			rel[G[count].second.first]=G[count].first;
			key[G[count].second.first]=key[G[count].first]+G[count].second.second;
			
		}
		count++;
	};
}

int main()
{
    int x, y, cost;
    cin>>N>>E;
    for(int i=0; i<E; i++)
    {
        cin>>x>>y>>cost;
        G.push_back(pair <int, edge>(x-1, edge(y-1, cost)));
    }
    init_keys();
    dijkstra();
    cout<<"Shortest path: \n 1 is ROOT\n";
    for(int i=1; i<N; i++)
    {
		cout<<"( "<<i+1<<", "<<rel[i]+1<<" )\n";
	}
	cout<<"Shortest path for? : ";
	cin>>x;
	cout<<"\nShortest path from 1 to "<<x<<" is "<<key[x-1];
    return 0;
}

/*
 * I/P in format: lesser node should always be given in left
5 6
1 2 2
2 3 6
1 4 4
4 5 7
2 4 1
3 5 5 
* O/P:
Shortest path: 
 1 is ROOT
( 2, 1 )
( 3, 2 )
( 4, 2 )
( 5, 4 )
Shortest path for? : 5

Shortest path from 1 to 5 is 10
* 
*I/P:
6 11
1 2 2
1 4 1
1 5 3
2 3 6
2 4 4
2 5 11
2 6 8
3 5 7
3 6 10
4 5 5
5 6 9
* O/P:
Shortest path: 
 1 is ROOT
( 2, 1 )
( 3, 2 )
( 4, 1 )
( 5, 1 )
( 6, 2 )
Shortest path for? : 6

Shortest path from 1 to 6 is 10
* */
