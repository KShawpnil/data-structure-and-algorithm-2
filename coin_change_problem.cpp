//011201125_Online-3_Set_A
#include <iostream>
using namespace std;

int dp [100];

int sugar(int W,int c[],int n)
{
    for(int i = 1; i <= W; i++)
    {
        int minkg = INT_MAX;
        for(int j = 0; j < n; j++)
        {
            if(i >= c[j])
            {
                if(dp[i - c[j]] + 1 < minkg)
                {
                    minkg = dp[i - c[j]] + 1;
                }
            }
        }
        dp[i] = minkg;
    }
    return dp[W];
}

int main()
{
    int n, W;
    cin >> n;
    int w[n] = {1,23,25,12,10};
   /* int w[];
    for(int i = 0; i <= n; i++)
    {
        i = w[i];
    }
    w[0] = 0;*/

    cin>>W;

    cout << "minimum " << sugar(W, w, n) << " containers needed"<< endl;
    //cout << sugar(W, w, n)<< endl;

    return 0;
}












/*struct Item
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


int Coin_DPTab(int M,int c[],int n)
{
    for(int i=1; i<=M; i++){
        int minCoin = INT_MAX;
        for(int j=0; j<n; j++){
            if(i>=c[j]){
                if(dp[i-c[j]]+1 < minCoin){
                    minCoin = dp[i-c[j]]+1;
                }
            }
        }
        dp[i]=minCoin;
    }
    return dp[M];
}

int main()
{
    int c[4] = {1,3,21,22};
    int m;
    cin>>m;
//    for(int i=0; i<=m; i++){
//        dp[i]=-1;
//    }
    dp[0]=0;
//    cout<<Coin_dp(m,c,4);
    cout<<Coin_DPTab(m,c,4);
}

*/
