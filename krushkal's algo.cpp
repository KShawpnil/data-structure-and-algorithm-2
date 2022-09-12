#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,w;
};
vector< int > representative;
void make_set(int vertices)
{
    for(int i=0;i<vertices;i++)
        representative[i] = i;
}
int find_set(int x)
{
    if(representative[x]==x) return x;
    else representative[x] = find_set(representative[x]);
}
bool Union(int u, int v)
{
    int representative_of_u = find_set(u);
    int representative_of_v = find_set(v);
    if(representative_of_u!=representative_of_v)
    {
        representative[representative_of_v] = representative_of_u;
        return true;
    }
    else
        return false;
}
int main()
{
    freopen("input.txt","r",stdin);
    int vertices, edges; cin >> vertices >> edges;

    vector< edge > adjacentList(edges);
    for(int i=0;i<vertices;i++)
    {
        cin >> adjacentList[i].u >> adjacentList[i].v >> adjacentList[i].w;
    }
    sort(adjacentList.begin(),adjacentList.end(),[&](edge &a, edge &b)
         {
             return a.w<b.w;
         });

    representative.resize(vertices);
    make_set(vertices);

    int mst = 0;
    vector< edge > edges_in_mst;
    for(int i=0;i<adjacentList.size();i++)
    {
        int u = adjacentList[i].u;
        int v = adjacentList[i].v;
        int w = adjacentList[i].w;

        if(Union(u,v))
        {
            mst+=w;
            edges_in_mst.push_back(adjacentList[i]);
        }
    }

    cout << mst << "\n";


    for(edge e : edges_in_mst)
        cout << e.u << " " << e.v << "\n";
    return 0;
}
