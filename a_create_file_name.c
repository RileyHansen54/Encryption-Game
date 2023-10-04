#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFYSIZE 256
#define FIFO_NAME_BEGIN "/tmp/my_tmp_"

char *create_file_name() 
{
    char fifo_name[BUFFYSIZE];
    const char *user_name = getenv("USER");
    
    if( user_name == NULL ) 
    {
        fprintf(stderr, "Failed to get USER environment variable.\n");
        return NULL;
    }
    printf("User is %s\n", user_name);

    int ret = snprintf( fifo_name, sizeof(fifo_name), "%s%s", FIFO_NAME_BEGIN, user_name );
    if( ret < 0 || ret >= sizeof(fifo_name) ) 
    {
        fprintf(stderr, "Failed to create the FIFO name.\n");
        return NULL;
    }
    printf("Created tempfile: %s\n\n", fifo_name);
    return strdup(fifo_name);
}
