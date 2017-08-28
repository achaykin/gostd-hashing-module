#include "gosthash.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sha3/sph_gost.h"


void gost_hash(const char* input, char* output)
{
 
    sph_gost512_context      ctx_gost;


    //these uint512 in the c++ source of the client are backed by an array of uint32
    uint32_t hashA[16], hashB[16];

  

    sph_gost512_init(&ctx_gost);
    sph_gost512 (&ctx_gost, hashB, 64);
    sph_gost512_close(&ctx_gost, hashA);    
    


    memcpy(output, hashB, 32);

}

