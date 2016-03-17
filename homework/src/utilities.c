
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilities.h"

/**
 * Safe freeing
 * free an address and set it to NULL to prevent double freeing
 */
void UTLFree(void **paddress)
{
	void *address = *paddress;

	if (address == NULL) goto BACK;

	/**printf("freeing array at %p\n", address);**/
	free(address);
	address = NULL; /** prevents double freeing **/

	BACK:
	*paddress = address;
}


/** print vector **/
void UTLShowVector(int n, double *vector)
{
	int j;

	for (j = 0; j < n; j++){
		printf(" %g", vector[j]);
	}
	printf("\n");
}


char *Ggettimestamp(void)
{
  time_t timestamp;

  timestamp = time(0);
  return (char *) ctime(&timestamp);
}




#ifdef WIN32

int rand_r (unsigned int *seed)
{
	int result;
	unsigned int next = *seed;

	next = next * 1103515245 + 12345;
	result = (int)(next >> 16) & RAND_MAX; /** result =  (int)(next / 65536) % 32768; **/

	*seed = next;
	return result;
}

#endif

