#include <stdio.h>
#include <math.h>

#define MAX 100

int main( int argc, char *argv[] )
{
    int i, sumsq=0, sqsum=0;

    for ( i=1; i<=MAX; i+=1 )
    {
        sqsum+=i;
        sumsq+=pow(i, 2);
    }
    sqsum=pow(sqsum,2);
    printf( "\nsqsum=%d - sumsq=%d = %d\n", sqsum, sumsq, sqsum-sumsq );

    return( 0 );
}
