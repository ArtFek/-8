#include <stdio.h>
#define YES 1
#define NO 0
#define MAXLINE 1000
void process_line( char buffer[] );
void main( void )
{
    char line[MAXLINE];
    fgets( line, MAXLINE, stdin );
    process_line( line );
    puts( line );
}
void process_line( char buffer[] )
{
    char c;
    char prev_c;
    int flag;
    int found;
    char *buf_ptr;
    char *begin;
    char *end;
    flag = NO;
    found = NO;
    prev_c = 0;
    buf_ptr = buffer;
    begin = buffer;
    end = buffer;
    do
    {
        c = *buf_ptr;
        
        if((c < 'a' || c >'z') && (c < 'A' || c > 'Z'))
        {
            if( flag == YES )
            {
                end = buf_ptr - 1;
                if( found == YES )
                {
                    char *src = end+1;
                    char *dst = begin;
                    while( (*dst++ = *src++ ) != '\0' );
                    buf_ptr = begin;
                }
            }
            found = NO;
            flag = NO;
        }
        else
        {
            if( flag == NO )
                begin = buf_ptr;
            if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'u' || c == 'U' || c == 'i' || c == 'I' || c == 'o' || c == 'O')
            {
                if(prev_c == 0)
                {
                    prev_c = 1;
                }
                else
                {
                    found = YES;
                    prev_c = 0;
                }
            }
            else
            {
                prev_c = 0;
            }
            flag = YES;
        }
        buf_ptr++;
    }
    while( c != '\0' );
}
