#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFSIZEX 256

extern char     *create_file_name(void);

int main( void )
  {
  int fd, count;

  char buffer[BUFSIZEX];

  char *FIFO_NAME = create_file_name();  

  // Create fifo at shell level 
  printf( "create a file in /tmp/ directory as follows:\nmkfifo %s\n",  FIFO_NAME );

  if( (fd = open( FIFO_NAME, O_RDWR )) < 0 )
  {
   	fprintf( stderr, "Cannot open port\n" );
	exit(1);
  }

  while( 1 )
  {
     // reads from standard input and sends information through the FIFO
     count = read( fd, buffer, BUFSIZEX );
     write( 1, buffer, count );
  }


return 0;
} /* main */


