#include <stdio.h>
#include "vector/vector.h"


int main(int arc, char** argv) {
    ipm_vector_ptr v = ipm_vector_init(2);
    printf("size = %d\n",ipm_vector_size(v));
    return 0;
}
