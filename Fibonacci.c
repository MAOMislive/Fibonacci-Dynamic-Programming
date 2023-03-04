#include<stdio.h>
#include<time.h>

int fib_array[100];

int Fib_dynamic(int n)
{
    if (n <= 1)
    {
        return n; // base case
    }
    if (fib_array[n] != -1)
    {
        return fib_array[n]; // return the calculated value
    }
    else
    {
        fib_array[n] = Fib_dynamic(n-1) + Fib_dynamic(n-2);
        return fib_array[n];
    }
}

int Fib_normal(int n)
{
    if(n <= 0) //Base condition
        return 0;
    else if(n == 1) //Base condition
        return 1;
    else
        return Fib_normal(n-1) + Fib_normal(n-2);
}

int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for(int i=0; i<=n; i++)
    {
        fib_array[i]= -1;
    }


    clock_t start, end;
    float time_taken;

    start = clock();

    //int nth = Fib_normal(n); //By using normal programming
    int nth = Fib_dynamic(n); //By using dynamic programming

    end = clock();

    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("The %d-th Fibonacci number is %d\n", n, nth);

    printf("Time taken: %f", time_taken);

    return 0;
}

