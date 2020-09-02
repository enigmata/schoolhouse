#include <stdio.h>
#include <math.h>

int main( int argc, char *argv[] )
{
    int a, b, c;

    for ( a=4; a<330; a+=1 )
    {
        b=(int)((500000-1000*a)/(1000-a));
        c=1000-b-a;

        printf( "a = %d, b = %d, c = %d\n", a, b, c );

        if ( pow( a, 2 ) + pow( b, 2 ) == pow( c, 2 ) )
            break;
    }

    printf( "\nAnswer = %d\n", a*b*c );

    return( 0 );
}

