// Writer program for assignment 2
// Author: Vihar Vasavada

#include <string.h>
#include <stdio.h>
#include <syslog.h>

int main(int argc, char *argv[])
{
    openlog( "Writer", LOG_CONS, LOG_USER );
    if( argc != 3 )
    {
        syslog( LOG_ERR, "%s", "Incorrect arguments. Usage: ./writer <FILE_PATH> <TEXT>" );
        return 1;
    }

    char *filePath = argv[1];
    char *fileText = argv[2];
    FILE *filePtr;

    filePtr = fopen( filePath, "w" );
    if( filePtr == NULL )
    {
        syslog( LOG_ERR, "Error opening file %s", filePath );
        return 1;
    }

    syslog( LOG_DEBUG, "Writing %s to %s", fileText, filePath );
    fprintf( filePtr, "%s", fileText );

    fclose( filePtr );

    closelog();
    return 0;
}