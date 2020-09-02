
#include <stdio.h>
#include <math.h>

int main( int argc, char *argv[] )
{
    long prime = 0, ceiling, sumtotal; 
    long double divisor = 0.0, dprime = 0.0, sqrtdprime = 0.0;

    if ( argc != 2 )
    {
        printf( "\nUsage: sol <number>" );
        printf( "\n - computes the sum of primes below <number>\n\n" );
    }
    else
    {
        ceiling = atol( argv[1] );

        printf( "Sum of primes below %ld is ... ", ceiling );

        sumtotal=2;

        for ( prime=3; prime<ceiling; prime+=2 )
        {
            dprime = (long double)prime; 
            sqrtdprime = sqrt(dprime);

            for ( divisor = 2.0; ((divisor <= sqrtdprime) && (fmod(dprime,divisor) != 0.0)); divisor += 1.0 ) ;

            if ( divisor > sqrtdprime )
                sumtotal+=prime;
        }

        printf( "%ld\n", sumtotal );
    }

    return( 0 );

}
