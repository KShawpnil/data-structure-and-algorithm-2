
#include <iostream>
using namespace std;

bool is_prime(int X)
{
    if(X == 0 || X == 1) //0 or 1 are not prime numbers
    {
        return false;
    }

    if (X > 0)
    {
        for (int i = 2; i <= X/2; i++)
        {
            if (X % i == 0)
            {
                return false;
                // break;
            }
        }
    }
    return true;
}

int count_prime(int A[], int x)
{
    int counts = 0;

    for (int i = 0; i <= x; i++)
    {
        if(is_prime(A[i]))
        {
            counts++;
        }
    }
    return counts;
    //cout << "primes= " << counts << endl;
}

int main()
{
    int n;
    //int A[100];

    //Enter how many prime numbers
    cout << "Enter how many prime numbers: ";
    cin >> n;

    int A[n];

    //Enter positive integer numbers
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    //print the prime numbers
    for(int i = 0; i < n; i++)
    {
        if (is_prime(A[i]))
        {
            cout << A[i] << " ";
            //cout << A[i] << " is a prime number" << endl;
        }
        //else
        //cout << A[i] << " is not a prime number" << endl;
    }
    cout << endl;
    //print how many primes
    int cnt = count_prime(A, n);
    cout << "primes= " << cnt << endl;

    return 0;
}

