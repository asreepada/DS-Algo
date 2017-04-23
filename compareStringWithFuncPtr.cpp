#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define tgt_size 8

static int compareStrings(const void *p1, const void *p2){
    return strcmp(* (char * const *) p1, * (char * const *) p2);
}

int main(int argc, char *argv[]) {
	const char *tgt[]={
    	"bacon", "Bacon", "mIlk", "Milk", "spinach", "MILK", "milk", "eggs" 
	};	
		
    printf("Before sort:\n\t");
    for(int n=0; n<tgt_size; n++)
        printf("%s ", tgt[n]);
	
    qsort(tgt, tgt_size, sizeof(char *), compareStrings);

    printf("\nAfter sort:\n\t");
    for(int n=0; n<tgt_size; n++)
        printf("%s ", tgt[n]);

    return 0;
}
