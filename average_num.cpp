#include <iostream>

using namespace std;

int main()
{
    double N, n, i;
    double sum = 0;
    double avg = 0;

    cout << "input numbers: " << endl;
    cin >> n;

    for(i = 0; i < n; i++)
    {
         cout << "Take input: ";
          cin >> N;
          sum = sum + N;
    }
    avg = sum/n;
    cout << "This is the output " << avg << endl;

    return 0;
}
