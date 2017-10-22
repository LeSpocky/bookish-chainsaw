#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void ipr( int i, const char *tpl, ... );

int main( void )
{
    ipr( 1, "foo %i", 42 );
    ipr( 2, "bar %u", 23, 666 );
    ipr( 3, "baz %s" );

    return EXIT_SUCCESS;
}

void ipr( int i, const char *tpl, ... )
{
    va_list args;

    assert( tpl );

    (void) printf( "%i: ", i );

    va_start( args, tpl );
    vprintf( tpl, args );
    va_end( args );

    (void) printf( "\n" );
}
