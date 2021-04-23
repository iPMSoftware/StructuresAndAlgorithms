
#include "vector/vector.h"

int main(void) {
    //ipm_vector_ptr v = ipm_vector_init();
    ipm_vector_ptr v = ipm_vector_init(2);
    ipm_vector_push_back(v,100);
    ipm_vector_push_back(v,200);
    ipm_vector_push_back(v,300);
    ipm_vector_push_back(v,400);
    ipm_vector_print(v);
}