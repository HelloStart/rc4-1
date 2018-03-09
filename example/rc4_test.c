#include <stdlib.h>
#include <stdio.h>

#include "rc4.h"

// https://tools.ietf.org/html/rfc6229#section-2
int main()
{
    int i;
    uint8_t input[] = {0x00};
    uint8_t output[1];

    uint8_t key[] = {0x01, 0x02, 0x03, 0x04, 0x05};

    rc4_state_t *state = rc4_create(key, 5);

	printf("KEY = ");
	for (i = 0; i < 5; i++)
	{
		printf("%02x",key[i]);
	}
	printf("\r\n");

	printf("Key Stream(64 bytes for example) = \r\n");
    for (i = 0; i < 64; i++) 
	{
		if(i!= 0 && i % 16 == 0) printf("\r\n");
        rc4_crypt(state, input, output, 1);
        printf("%02x ",output[0]);
	    
    }
	printf("\r\n");
    rc4_destroy(state);
	return 0;
}

