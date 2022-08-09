#include <iostream>
#include <iomanip>
using namespace std;
#define N 5

float f(float x)
{
    return 2*x*x+3*x+1;
}

void print(float X[N], float Y[N])
{
    cout << "Table:\n" << "X\t" << "Y\t\n";
    for (int i = 0; i < N; i++)
    {
        cout << X[i] << "\t" << Y[i] << endl;
    }
}

float Newton(float x[N], float y[N], float X)
{
    float answer = y[0], a, h;
    for (int i = 1; i < N; i++)
    {
        a = 0;
        for (int j = 0; j <= i; j++)
        {
            h = 1;
            for (int k = 0; k <= i; k++)
            {
                if (k != j)
                    h *= (x[j] - x[k]);
            }
            a += y[j] / h;
        }
        for (int j = 0; j < i; j++)
            a *= (X - x[j]);
        answer += a;
    }
    return answer;
}

int main()
{
    int c = 1;
    float x;
    float X[N] = { 1, 2, 3, 4, 5 };
    float Y[N]; //массив под функцию

    for (int i = 0; i < N; i++)
        Y[i] = f(X[i]);

    print(X, Y);
    cout << "\n\nEnter X:\nX = ";
    cin >> x;
    cout << "\nP(" << x << ") = " << Newton(X, Y, x) << endl;
    return 0;
}




