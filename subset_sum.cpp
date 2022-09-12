#include <iostream>
using namespace std;

int subset_sum_recursion(int A[], int X, int n)
{
    //base case
    if(X == 0)
        return 1; //true
    if(n == 0)
        return 0; //false

    if(A[n-1] > X)
        return subset_sum_recursion(A, X, n-1);
    else
        return max(subset_sum_recursion(A, X, n-1), subset_sum_recursion(A, X - A[n-1], n-1));

}

int subset_sum_tabulation(int A[], int X, int n)
{
    int P[n+1][X+1];
    int i, j;

    //base case
    for (i=0; i<=n; i++)
        P[i][0] = 1; //true

    for (j=1; j<=X; j++)
        P[0][j] = 0; //false

    for (i=1; i<=n; i++)
    {
        for (j=1; j<=X; j++)
        {
            if (j < A[i-1])
            {
                P[i][j] = P[i-1][j];
            }
            else
            {
                P[i][j] = max(P[i-1][j], P[i-1][j-A[i-1]]);
            }
        }
    }
    //return P[n][X];
    if(P[n][X])
    {
        cout<< X <<" is a subset sum"<<endl;

        int siz = n, sum = X;

        for(int m = siz; m > 0;)
        {
            for(int b = X; b > 0;)
            {
                if(P[m-1][b] == 1)
                {
                    m--;
                }
                else
                {
                    cout << A[m-1]<<" + ";
                    b = b - A[m-1];
                    m--;
                }
            }
            break;
        }
        cout<< " = " << X;
    }
    else
    {
        cout << "There is no subset sum." << endl;
    }
}

int main()
{
    /*
    int A[] = {2, 4, 6, 5, 8};
    int X = 15;
    int n = sizeof(A) / sizeof(A[0]);*/

    int n;
    cin >> n;

    int A[n];
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }

    int X;
    cin >> X;

    //subset_sum_recursion(A, X, n);

    subset_sum_tabulation(A, X, n);

    return 0;
}
/*
5
2
4
6
5
8
15
*/
