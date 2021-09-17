#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>

#include <cmocka.h>

#include "vector/vector.h"

void test_initial_vector_state(void** state) {
    const int capacity = 2;
    ipm_vector_ptr v = ipm_vector_init(capacity);
    assert_int_equal(0,ipm_vector_size(v));
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_initial_vector_state)
    };
    return cmocka_run_group_tests(tests,NULL, NULL);
}