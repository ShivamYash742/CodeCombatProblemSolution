#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int A[N], B[M];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < M; i++)
        cin >> B[i];
    int i = 0, j = 0;
    bool count = false;
    while (i < N && j < M)
    {
        if (A[i] == B[j])
        {
            cout << A[i] << " ";
            count = true;
        }
        if (A[i] < B[j])
            i++;
        else
            j++;
    }

    if (!count)
        cout << "-1";

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
