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

void test_insert_case1_left() {
    RBNode *n1 = add_rbnode(7);
    RBNode *n2 = add_rbnode(5);
    RBNode *n3 = add_rbnode(10);
    RBNode *z = add_rbnode(6);
    RBNode *root = n1;

    root->color = BLACK;

    // Establish relationships
    n1->left = n2;
    n1->right = n3;
    n2->p = n1;
    n3->p = n1;

    insert(&root, z);

    // Test
    TEST_ASSERT_EQUAL_PTR(n2, z->p);
    TEST_ASSERT_EQUAL_PTR(z, n2->right);
    TEST_ASSERT_EQUAL_CHAR(BLACK, n1->color);
    TEST_ASSERT_EQUAL_CHAR(BLACK, n2->color);
    TEST_ASSERT_EQUAL_CHAR(BLACK, n3->color);
    TEST_ASSERT_EQUAL_CHAR(RED, z->color);

    free(n1);
    free(n2);
    free(n3);
    free(z);
}

void test_insert_case2_left() {
    RBNode *n1 = add_rbnode(7);
    RBNode *n2 = add_rbnode(5);
    RBNode *n3 = add_rbnode(10);
    RBNode *n4 = add_rbnode(4);
    RBNode *n5 = add_rbnode(6);
    RBNode *n6 = add_rbnode(2);
    RBNode *z = add_rbnode(3);
    RBNode *root = n1;

    root->color = BLACK;

    // Establish relationships
    n1->left = n2;
    n1->right = n3;
    n2->p = n1;
    n3->p = n1;

    n2->left = n4;
    n4->p = n2;
    n2->right = n5;
    n5->p = n2;

    n6->p = n4;
    n4->left = n6;

    // colorings
    n3->color = BLACK;
    n4->color = BLACK;
    n5->color = BLACK;

    insert(&root, z);

    // Test relationships
    TEST_ASSERT_EQUAL_PTR(n6, z->left);
    TEST_ASSERT_EQUAL_PTR(z, n6->p);
    TEST_ASSERT_EQUAL_PTR(n2, z->p);
    TEST_ASSERT_EQUAL_PTR(z, n2->left);
    TEST_ASSERT_EQUAL_PTR(n4, z->right);
    TEST_ASSERT_EQUAL_PTR(z, n4->p);

    // Test colorings
    TEST_ASSERT_EQUAL_CHAR(BLACK, n1->color);
    TEST_ASSERT_EQUAL_CHAR(RED, n2->color);
    TEST_ASSERT_EQUAL_CHAR(RED, n4->color);
    TEST_ASSERT_EQUAL_CHAR(RED, n6->color);
    TEST_ASSERT_EQUAL_CHAR(BLACK, z->color);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    free(z);
}

void test_insert_case3_left() {
    RBNode *n1 = add_rbnode(7);
    RBNode *n2 = add_rbnode(5);
    RBNode *n3 = add_rbnode(10);
    RBNode *n4 = add_rbnode(3);
    RBNode *n5 = add_rbnode(6);
    RBNode *n6 = add_rbnode(2);
    RBNode *z = add_rbnode(1);
    RBNode *root = n1;

    root->color = BLACK;

    // Establish relationships
    n1->left = n2;
    n1->right = n3;
    n2->p = n1;
    n3->p = n1;

    n2->left = n4;
    n4->p = n2;
    n2->right = n5;
    n5->p = n2;

    n6->p = n4;
    n4->left = n6;

    // colorings
    n3->color = BLACK;
    n4->color = BLACK;
    n5->color = BLACK;

    insert(&root, z);

    // Test relationships
    TEST_ASSERT_EQUAL_PTR(n6, n2->left);
    TEST_ASSERT_EQUAL_PTR(n2, n6->p);
    TEST_ASSERT_EQUAL_PTR(z, n6->left);
    TEST_ASSERT_EQUAL_PTR(n6, z->p);
    TEST_ASSERT_EQUAL_PTR(n4, n6->right);
    TEST_ASSERT_EQUAL_PTR(n6, n4->p);

    // Test colorings
    TEST_ASSERT_EQUAL_CHAR(BLACK, n1->color);
    TEST_ASSERT_EQUAL_CHAR(RED, n2->color);
    TEST_ASSERT_EQUAL_CHAR(RED, n4->color);
    TEST_ASSERT_EQUAL_CHAR(BLACK, n6->color);
    TEST_ASSERT_EQUAL_CHAR(RED, z->color);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    free(z);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_rotate_left);
    RUN_TEST(test_rotate_right);
    RUN_TEST(test_insert_case1_left);
    RUN_TEST(test_insert_case2_left);
    RUN_TEST(test_insert_case3_left);
    return UNITY_END();
}