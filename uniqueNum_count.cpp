#include <iostream>

using namespace std;

int main()
{
    int i, j;
    int n = 8;
    int arr[] = {2, 4, 256, 2, 4, 3, 3, 5};

    for(i = 0; i < n; i++)
    {
        int present = 0;
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                present = 1;
                break;
            }
        }
        if(!present)
        {
             int c = 0;
            for(j = 0; j <= i; j++)
            {
                if(arr[i] == arr[j])
                {
                  c++;
                }
            }
            cout << arr[i] << " occurs " << c << endl;
        }
    }

    return 0;
}
