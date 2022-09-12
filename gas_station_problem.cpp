//011201125_PP2
#include <iostream>

using namespace std;

int main()
{
    int D, m, n, dis, i, j, temp_d, y;
    int Arr[100];

    cin >> D >> m >> n;

    y = m;

    for(i = 1; i <= n; i++)
    {
        Arr[0] = 0;
        cin >> Arr[i];
    }

    for (j = 1; j <= n; j++)
    {
        dis = (Arr[j+1] - Arr[j]);
        temp_d = temp_d + dis;

        if (m <= temp_d)
        {
            m -= dis;
            m += y;
            cout << "stop at gas station " << j << " ( " << Arr[j] << " miles)" << endl;
            temp_d = 0;
        }

        else
        {
            m -= dis;
        }
    }
    return 0;
}
/*
20 10 8
2
4
5
8
12
14
16
19

25 10 5
2
4
5
8
12

*/
