/* ============================================================================
 Name        : English to Goggamal translator
 Author      : Maria Hybinette
============================================================================ */
#include <stdlib.h>
#include <ctype.h> 	// for isalpha() 

int isConsonant( char ch )
{
	int aConsonant = 1;
	int notConsonant = 0;

        if( isalpha(ch) == 0 )
        {
                return notConsonant;
        }

	aConsonant = 0;
	if(       ch =='a'
		||ch=='A'
		||ch=='e'
		||ch=='E'
		||ch=='i'
		||ch=='I'
		||ch=='o'
		||ch=='O'
		||ch=='u'
		||ch=='U')
	{
		aConsonant = 0;
	}
	else
	{
		aConsonant = 1;
	}
	return aConsonant;
}

