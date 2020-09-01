#include <stdio.h>
#include <math.h>

int main( int argc, char *argv[] )
{
    long fibn=0, fibn1=1, fibn2=1, sum=0;

    do
    {
        fibn=fibn1+fibn2;
        fibn2=fibn1;
        fibn1=fibn;

        if (( fibn%2 ) == 0 )
            sum+=fibn;

    } while ( fibn<4000000 );

    printf( "\nSum = %ld\n", sum );

    return( 0 );
}
