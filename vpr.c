#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

void pr_ext( const char *tpl, ... );

void pr_int( const char *tpl_1, va_list *ap_1, const char *tpl_2,
        va_list *ap_2 );

void vpr( const char *tpl, va_list ap );

int main( int argc, char *argv[] ) {
    pr_ext( "foo %i\n", 42 );

    return 0;
}

void pr_ext( const char *tpl, ... ) {
    va_list args;

    va_start( args, tpl );
    vpr( tpl, args );
    va_end( args );
}

void pr_int( const char *tpl_1, va_list *ap_1, const char *tpl_2,
        va_list *ap_2 )
{
    if ( ap_1 ) {
        vprintf( tpl_1, *ap_1 );
    } else {
        printf( tpl_1 );
    }

    if ( ap_2 ) {
        vprintf( tpl_2, *ap_2 );
    } else {
        printf( tpl_2 );
    }
}

void vpr( const char *tpl, va_list ap ) {
    pr_int( tpl, &ap, "bar\n", NULL );
}
