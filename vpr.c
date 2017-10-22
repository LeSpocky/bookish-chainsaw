#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

/*  https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html#Common-Function-Attributes   */
__attribute__ ((format (__printf__, 1, 2)))
void pr_ext( const char *tpl, ... );

void pr_int( const char *tpl_1, va_list *ap_1, const char *tpl_2,
        va_list *ap_2 );

__attribute__ ((format (__printf__, 1, 0)))
void vpr( const char *tpl, va_list ap );

int main( void )
{
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
        printf( "%s", tpl_1 );
    }

    if ( ap_2 ) {
        vprintf( tpl_2, *ap_2 );
    } else {
        printf( "%s", tpl_2 );
    }
}

void vpr( const char *tpl, va_list ap ) {
    va_list ap2;

    va_copy( ap2, ap );
    pr_int( tpl, &ap2, "bar\n", NULL );
    va_end( ap2 );
}
