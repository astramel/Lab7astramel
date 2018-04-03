// RandomUtilities.h
/*
 RandomUtilities.hpp
 Sash STramel
 Lab 7-Sorting Speed
 Cosc 2030 Data Structure
 2 April 2017
 */
// tom bailey 7 mar 03
// Random Variate generation.
// tom bailey   0900  21 feb 2012
// Revisions to match current version of rand().
// tom bailey   1420   23 mar 2012
// Revision of the definition of randomInt.


#ifndef _RANDOM_UTILITIES_H_
#define _RANDOM_UTILITIES_H_

#include <cmath>
#include <ctime>
#include <algorithm>


void randomizeSeed()
{
    static bool called = false;
    if( ! called )
    {
        srand( long( std::time(NULL) ) );
        called = true;
    }
}


double randUniform()
{
    double r = double( rand() ) / ( RAND_MAX + 1.0 );
    r = ( double( rand() ) + r ) / ( RAND_MAX + 1.0 );
    r = ( double( rand() ) + r ) / ( RAND_MAX + 1.0 );
    r = ( double( rand() ) + r ) / ( RAND_MAX + 1.0 );
    return  r;
};


double randReal( double minReal, double maxReal )
{
    return minReal
    + ( maxReal - minReal ) * randUniform();
}

int randInt( int minInt, int maxInt )
{
    return int( minInt
               + ( maxInt - minInt ) * randUniform() );
}


double randExpon()
{
    double unif = randUniform();
    double expon = -log( unif );
    return expon;
}

double randTriangle( double minimum, double mode, double maximum )
{
    double larger( randUniform() );
    double other( randUniform() );
    if( larger < other )
    {
        larger = other;
    }
    
    if( randUniform() * ( maximum - minimum ) < ( mode - minimum ) )
    {
        return minimum + larger * ( mode - minimum );
    }
    else
    {
        return maximum + larger * ( mode - maximum );
    }
}


double randErlang( short k )
{
    double sum = 0.0;
    for( short i=0; i<k; i++ )
    {
        sum += randExpon();
    }
    return sum / double( k );
}

#endif
