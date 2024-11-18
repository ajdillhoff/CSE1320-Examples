#include "unity.h"
#include "rb_utils.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_rotate_left() {
    RBNode *alpha = calloc(1, sizeof(RBNode));
    RBNode *beta = calloc(1, sizeof(RBNode));
    RBNode *gamma = calloc(1, sizeof(RBNode));
    RBNode *x = calloc(1, sizeof(RBNode));
    RBNode *y = calloc(1, sizeof(RBNode));
    RBNode *root = x;

    beta->p = y;
    gamma->p = y;
    y->left = beta;
    y->right = gamma;
    y->p = x;
    x->right = y;
    alpha->p = x;
    x->left = alpha;

    rotate_left(&root, x);

    // x tests
    TEST_ASSERT_EQUAL_PTR(x, alpha->p);
    TEST_ASSERT_EQUAL_PTR(x, beta->p);
    TEST_ASSERT_EQUAL_PTR(alpha, x->left);
    TEST_ASSERT_EQUAL_PTR(beta, x->right);
    TEST_ASSERT_EQUAL_PTR(y, x->p);

    // y tests
    TEST_ASSERT_EQUAL_PTR(y, gamma->p);
    TEST_ASSERT_EQUAL_PTR(gamma, y->right);
    TEST_ASSERT_EQUAL_PTR(x, y->left);
    TEST_ASSERT_NULL(y->p);

    free(alpha);
    free(beta);
    free(gamma);
    free(x);
    free(y);
}

void test_rotate_right() {
    RBNode *alpha = calloc(1, sizeof(RBNode));
    RBNode *beta = calloc(1, sizeof(RBNode));
    RBNode *gamma = calloc(1, sizeof(RBNode));
    RBNode *x = calloc(1, sizeof(RBNode));
    RBNode *y = calloc(1, sizeof(RBNode));
    RBNode *root = y;

    alpha->p = x;
    beta->p = x;
    x->left = alpha;
    x->right = beta;
    x->p = y;
    y->right = gamma;
    gamma->p = y;
    y->left = x;

    rotate_right(&root, y);

    // x tests
    TEST_ASSERT_EQUAL_PTR(x, alpha->p);
    TEST_ASSERT_EQUAL_PTR(alpha, x->left);
    TEST_ASSERT_EQUAL_PTR(y, x->right);
    TEST_ASSERT_EQUAL_PTR(x, y->p);
    TEST_ASSERT_NULL(x->p);

    // y tests
    TEST_ASSERT_EQUAL_PTR(y, beta->p);
    TEST_ASSERT_EQUAL_PTR(y, gamma->p);
    TEST_ASSERT_EQUAL_PTR(gamma, y->right);
    TEST_ASSERT_EQUAL_PTR(beta, y->left);

    free(alpha);
    free(beta);
    free(gamma);
    free(x);
    free(y);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_rotate_left);
    RUN_TEST(test_rotate_right);
    return UNITY_END();
}