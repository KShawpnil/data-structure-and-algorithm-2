#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Item
{
    string name;
    double v, w;
};

Item items;

bool comp(struct Item i1, struct Item i2)
{
    double item1 = (double)i1.v / (double)i1.w;
    double item2 = (double)i2.v / (double)i2.w;

    if(i1.w == 0)
    {
        item1 = 0;
    }
    if(i2.w == 0)
    {
        item2 = 0;
    }

    return item1 > item2;
}

double warehouse(struct Item items[], int n, double W, int k)
{
    sort(items, items + n, comp);

    double profit = 0.0;
    int i, j;

    for(i = 0; i < n; i++)
    {
        if(items[i].w == 0)
        {
            items[i+1];
        }
        else if(items[i].w <= W)
        {
            W = W - items[i].w;
            profit = profit + items[i].v;

            cout <<"Taking " << items[i].name << ":  " << items[i].w <<" kg " <<items[i].v <<" taka"<<endl;
            items[i].w = 0;
        }
        else
        {
            int minw = min(W, items[i].w);
            double fraction = (double)minw / (double)items[i].w;
            profit = profit + items[i].v * fraction;

            cout <<"Taking " << items[i].name << ":  " << minw <<" kg " <<items[i].v * fraction <<" taka "<< endl;

            items[i].w = items[i].w - minw;
            items[i].v = items[i].v - items[i].v * fraction;
            W = W - minw;

            cout <<"Profit: " << profit << endl;
            cout << endl;
            break;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    Item items[n];
    double v, w;

    for (int i=0; i<n; i++)
    {
        cin >> items[i].name >>items[i].w >> items[i].v;
    }

    int thief;
    cin >> thief;

    int W[thief];
    for (int i=0; i<thief; i++)
    {
        cin >> W[i];
    }

    for (int i=0; i<thief; i++)
    {
        cout << "Thief " << i+1 << ": " << endl;
        double profit = warehouse(items, n, W[i], thief);
    }
    cout << "Total " << thief << " thieves stole from the warehouse." << endl;

    return 0;
}
/*
4
silver 4 300
gold 8 2000
salt 10 80
sugar 10 89
4
8
10
6
10

4
silver 4 300
gold 8 2000
salt 10 80
sugar 10 89
2
15
15
*/
