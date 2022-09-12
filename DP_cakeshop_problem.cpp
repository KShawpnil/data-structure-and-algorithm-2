#include <iostream>
//#define INF 9999999
using namespace std;

int RC[200];

int cakeShop_recursion(int p[],int n)
{
    if(n == 0)
        return 0;

    int q = INT_MIN;

    for(int i=0; i<n; i++)
    {
        q = max(q, p[i] + cakeShop_recursion(p, n-i-1));
    }
    RC[n] = q;
    return RC[n];
}

int cakeShop_tabulation(int p[], int n)
{
    RC[0] = 0;
    int i, j;
    for(j=1; j<=n; j++)
    {
        int q = INT_MIN;

        for(i=0; i<j; i++)
        {
            q = max(q, p[i] + RC[j-i-1]);
        }
        RC[j] = q;
    }
    return RC[n];
    /*cout << "Income: " << RC[n] << " taka" <<endl;

    for(i=0; i<n; i++)
    {
        cout<< p[i] <<" pieces together " << p[i+1] << " taka" << endl;
    }*/
}

int main()
{
    //int p[] = {2, 6, 9, 10, 12};
    //int n = sizeof(p) / sizeof(p[0]);

    int n;
    cin >> n;

    int p[n];
    for(int i=0; i<n; i++)
    {
        cin >> p[i];
    }

 //int result2 = cakeShop_recursion(p, n);
 //cout << "Income: " << result2 << " taka" <<endl;

    int result = cakeShop_tabulation(p, n);
    cout << "Income: " << result << " taka" <<endl;

    for(int i=0; i<n; i++)
    {
        cout<< p[i] <<" pieces together " << p[i+1] << " taka" << endl;
    }

    return 0;
}

