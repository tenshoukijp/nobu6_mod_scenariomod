#include <stdio.h>
#include <stdlib.h>

size_t ODSfwrite(const void *buf, size_t size, size_t n, FILE *fp);
int ODSfputs( const char *str , FILE *fp );
int ODSputs( const char *str );
int ODSputc( int c, FILE *stream );
int ODSfprintf( FILE *stream, char *format, ... );
int ODSprintf( char *format, ... );

