#include <stdio.h>
#include <math.h>

long sum( long p, long n )
{
    long max = (long)floor((double)n/(double)p);
    return( p * ((max * (max+1)) / 2) );
}

int main( int argc, char *argv[] )
{
    printf( "\nsum = %ld\n", sum(3,999)+sum(5,999)-sum(15,999) );

    return( 0 );
}
