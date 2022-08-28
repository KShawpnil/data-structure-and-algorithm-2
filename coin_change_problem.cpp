
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
