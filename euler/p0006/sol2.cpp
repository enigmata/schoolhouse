#include <stdio.h>
#include <math.h>

#define MAX 100

int main( int argc, char *argv[] )
{
    int i, sumsq=0, sqsum=0;

    sumsq=floor((MAX/6))*(2*MAX+1)*(MAX+1);
    sqsum=pow(((MAX*(MAX+1))/2),2);

    printf( "\nsqsum=%d - sumsq=%d = %d\n", sqsum, sumsq, sqsum-sumsq );

    return( 0 );
}
