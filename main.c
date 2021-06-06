/**
 * @file main.c
 * @author Anthony Rajiv Francis (anthonyrajiv.francis@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "unity.h"
#include "stack.h"
struct new_stack* ptr = NULL;
/**
 * @brief Set the Up object
 * Required by the unity test framework
 */
void setUp() {}

/**
 * @brief Release the objects that are setup for tests
 * Required by the unity test framework
 */
void tearDown() {}

void test_stack_creation()
{
  ptr = create_stack(3);
  TEST_ASSERT_NOT_EQUAL(NULL, ptr);
}

void test_stack_push()
{
  TEST_ASSERT_EQUAL(SUCCESS, push(ptr, 1));
  TEST_ASSERT_EQUAL(SUCCESS, push(ptr, 2));
  TEST_ASSERT_EQUAL(SUCCESS, push(ptr, 3));
  TEST_ASSERT_EQUAL(STACK_FULL, push(ptr, 4));
}

void test_stack_pop()
{
  TEST_ASSERT_EQUAL(SUCCESS, pop(ptr));
  TEST_ASSERT_EQUAL(SUCCESS, pop(ptr));
  TEST_ASSERT_EQUAL(SUCCESS, pop(ptr));
  TEST_ASSERT_EQUAL(STACK_EMPTY, pop(ptr));
}

void test_stack_peek()
{
  TEST_ASSERT_EQUAL(0, peek(ptr));
}

/**
 * @brief What this function does
 *
 * @return int
 */
int main(void)
{
  /* Initiate the Unity Test Framework */
  UNITY_BEGIN();

  /* Run Test functions */
  RUN_TEST(test_stack_creation);
  RUN_TEST(test_stack_push);
  RUN_TEST(test_stack_pop);
  RUN_TEST(test_stack_peek);
  /* Close the Unity Test Framework */
  return UNITY_END();
}
