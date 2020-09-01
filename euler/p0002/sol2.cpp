#include <stdio.h>
#include <math.h>

int main( int argc, char *argv[] )
{
    long fibn=0, fibn1=1, fibn2=1, sum=0;

    while ( (fibn=fibn1+fibn2)<4000000 )
    {
        sum+=fibn;
        fibn2=fibn1+fibn;
        fibn1=fibn+fibn2;

    } 

    printf( "\nSum = %ld\n", sum );

    return( 0 );
}
