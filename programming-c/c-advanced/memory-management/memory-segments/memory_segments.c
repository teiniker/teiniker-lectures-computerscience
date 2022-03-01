#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int global_variable;
int global_variable_initialized = 0;

int main(void)
{
    int local_variable;
    static int static_variable;
    static int static_variable_initialized = 0;
    int *heap_ptr = malloc(sizeof(int));

    // stack segment
    printf("stack segment:\n");
    printf("\tlocal_variable at %p\n", &local_variable);

  	// heap segment
  	printf("heap segment:\n");
  	printf("\theap_ptr at %p\n", heap_ptr);

  	// bss segment
  	printf("bss segment:\n");
  	printf("\tglobal_variable at %p\n", &global_variable);
  	printf("\tstatic_variable at %p\n", &static_variable);

	// data segment
	printf("data segment:\n");
	printf("\tglobal_variable_initialized at %p\n", &global_variable_initialized);
	printf("\tstatic_variable_initialized at %p\n", &static_variable_initialized);

	// code segment
	printf("code segment:\n");
    printf("\tmain() at %p\n", &main);

    free(heap_ptr);

    return 0;
}


