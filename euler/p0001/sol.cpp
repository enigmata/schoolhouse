#include <stdio.h>
#include <math.h>

int main( int argc, char *argv[] )
{
    int sum, i;

    for ( i=1; i<1000; i+=1 )
    {
        if (( i%3==0 ) || ( i%5==0 ))
        {
            sum+=i;
        }
    }
            
    printf( "\nSum = %d\n", sum );

    return( 0 );
}
