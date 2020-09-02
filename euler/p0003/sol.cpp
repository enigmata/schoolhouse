#include<stdio.h>
#include<math.h>

int main( int argc, char *argv[] )
{
    long n=600851475143, prime=3, i=0;

    do
    {
        while ( n%prime==0 )
        {
            printf( "\nprime factor=%ld, n=%ld\n", prime, n );
            n/=prime;
        }

        for ( prime+=1; prime<n; prime+=1 )
        {
            for ( i=2; i<=sqrt(prime); i+=1 )
                if ( prime%i==0 )
                    break;

            if ( i>sqrt(prime) )
                break;
        }
    } while ( prime < n );  

    printf( "\nprime factor=%ld, n=%ld\n", prime, n );

    return( 0 );
}

