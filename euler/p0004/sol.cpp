#include <cstring>
#include <stdio.h>
#include <math.h>

int main( int argc, char *argv[] )
{
    int x=999, y=999, z, i, j;
    char product[8];

    for ( x=999; x>99; x-=1 )
    {
        for ( y=x; y>99; y-=1 )
        {
            z=x*y;
            sprintf( &product[0], "%d", z );
            //printf( "%dx%d=\"%s\"\n", x,y,product );

            for ( i=0, j=(int)strlen(&product[0])-1; i<j; i+=1, j-=1 )
                if ( product[i]!=product[j] )
                    break;

            if ( i>=j )
            {
                printf( "%d  x=%d, y=%d\n", z, x,y );
                break;
            }
        }
    }

    return( 0 );
}
