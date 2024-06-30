#include <CUnit/Basic.h>
#include "calc.h"

void test_add(void) {
    int status;
    double result = calculate(5, 3, "--add", &status);
    CU_ASSERT_DOUBLE_EQUAL(result, 8, 0.0001);
    CU_ASSERT(status == 0);
}

void test_divide_zero(void) {
    int status;
    calculate(5, 0, "--divide", &status);
    CU_ASSERT(status == 1);
}

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

int main() {
    CU_pSuite pSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    pSuite = CU_add_suite("Calculator Test Suite", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "Test Add Function", test_add)) ||
        (NULL == CU_add_test(pSuite, "Test Divide by Zero", test_divide_zero))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
