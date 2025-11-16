#include <string.h>
#include <stdio.h>
#include <syslog.h>

// One difference from the write.sh instructions in Assignment 1:  You do not need to make your "writer" utility create directories which do not exist.  You can assume the directory is created by the caller.

// Setup syslog logging for your utility using the LOG_USER facility.

// Use the syslog capability to write a message “Writing <string> to <file>” where <string> is the text string written to file (second argument) and <file> is the file created by the script.  This should be written with LOG_DEBUG level.

// Use the syslog capability to log any unexpected errors with LOG_ERR level.

int main(int argc, char *argv[])
{
    // 1. Check if you have the right number of arguments
    //    (what should that be?)
    openlog( "Writer", LOG_CONS, LOG_USER );
    if( argc != 3 )
    {
        syslog( LOG_ERR, "%s", "Incorrect arguments. Usage: ./writer <FILE_PATH> <TEXT>" );
        return 1;
    }
    
    char *filePath = argv[1];
    char *fileText = argv[2];
    FILE *filePtr;
    
    // 3. Open/create the file for writing
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