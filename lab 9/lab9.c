#include <stdio.h>

int Fibonacci1(int n)
{
    int f0 = 0, f1 = 1, fib, loop;

    printf("%d %d ", f0, f1);

    for (loop = 1; loop < n; loop++)
    {
        fib = f0 + f1;
        f0 = f1;
        f1 = fib;
        printf("%d ", fib);
    }
}

int Fibonacci(int n)
{

    if (n <= 1)
        return n;
    else
        return (Fibonacci(n - 1) + Fibonacci(n - 2));
}

int printv(int v[10], int a, int n)
{
    if (n <= 1)
        return v[a];
    else
        return printv(v, a+1, n-1);
}

int Hanoi(int disk,int source, int dest, int aux)
{
    if(disk == 1)
        printf("Move %d to %d",dest, source);
    else {

    Hanoi(disk -1, source, aux, dest);
    printf("Move %d to %d",dest, source);
    Hanoi(disk -1, aux, dest, source);
    }

}


int main()
{
    int n = 20;
    Fibonacci1(n);
    printf("\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", Fibonacci(i));
    }
    printf("\n");
    int v[10] = { 1,
                  2,
                  3,
                  4,
                  5,
                  6,
                  7,
                  8,
                  9,
                  0 };
    for (int i = 1; i <= 10; i++)
    {
        printf("%d ", printv(v,0,i));
    }

int source, dest, aux;
    for (int i = 1; i <= 10; i++)
    {
        printf("%d ", Hanoi(4,source,dest, aux));
    }
}