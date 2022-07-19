//011201125_PP2
#include <iostream>
using namespace std;

bool is_palindrome(int n)
{
    int reversing = 0;
    int temp = n;
    while (n > 0)
    {
        reversing *= 10;
        reversing += (n % 10);
        n = n / 10;
    }
    if (temp == reversing)
        return true;
    else
        return false;
}

int sum_palindrome(int X, int Y)
{
    int Z;
    if(X > Y)
    {
        return 0;
    }
    else if(is_palindrome(X))
    {
        Z = X + sum_palindrome(X + 1, Y);
        return Z;
    }
    else
    {
        return sum_palindrome(X + 1, Y);
    }
}

int main()
{
    int x, y;

    //enter integer numbers
    cin >> x >> y;

    //print all the palindrome numbers between x and y
    for(int i = x; i <= y; i++)
    {
        if(is_palindrome(i))
            cout<< i << " ";
    }
    cout << endl;

    //print the sum of palindrome numbers between x and y
    cout << "sum " << sum_palindrome(x, y);

    return 0;
}
