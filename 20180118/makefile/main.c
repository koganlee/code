#include <stdio.h>
#include <stdlib.h>
#include "a.h"
extern void function_two();
extern void function_three();
int main()
 {
    printf("hello\n");
	function_two();
    function_three();
    exit(EXIT_SUCCESS);
}					

