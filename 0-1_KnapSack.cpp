#include<iostream>
using namespace std;

struct Item
{
    int w, v;
};

int knapsack(int W, Item items[], int n)
{
    int P[n+1][W+1];
    /// base case
    for (int w=0; w<=W; w++)
        P[0][w] = 0;
    for (int i=0; i<n; i++)
        P[i][0] = 0;
    for (int i=1; i<=n; i++)
    {
        // P[i][0] = 0;
        for (int w=1; w<=W; w++)
        {
            int wi = items[i-1].w;
            if (wi<=w)  /// we have two options: take it or not
            {

                if(items[i].v + P[i-1][w-wi] >  P[i-1][w])
                    P[i][w] = items[i].v +  P[i-1][w-wi];
            }
            else     /// can't take it
            {
                P[i][w] = P[i-1][w];
            }
        }
    }

    return P[n][W];
}

int main()
{
    Item items[] =
    {
        {2, 3},
        {4, 6},
        {1, 5},
        {4, 10},

    };
    int n = sizeof(items)/sizeof(items[0]);
    int W = 6;
    int profit = knapsack(W, items, n);
    cout << profit << endl;

    return 0;
}


