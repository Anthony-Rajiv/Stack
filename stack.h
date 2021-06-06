/**
 * @file stack.h
 * @author Anthony Rajiv Francis (anthonyrajiv.francis@gmail.com)
 * @brief  Implementation of Stack
 * @version 0.1
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */



#ifndef _STACK_H_
#define _STACK_H_



#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"

typedef int stack_data_type;
typedef enum error_t
{
    SUCCESS,
    STACK_FULL,
    STACK_EMPTY,
    NULL_PTR
}error_t;

/**
 * @brief Creating a structure type stack for easy accessing
 * 
 */
struct new_stack
{
    unsigned int top;
    size_t size_of_stack;
    stack_data_type *data_array;
};

/**
 * @brief Create a stack object
 * 
 * @param size_of_stack 
 * @return struct new_stack* 
 */
struct new_stack* create_stack(size_t size_of_stack);

/**
 * @brief Push Operation for Stack
 * 
 * @param new_stack 
 * @param data 
 * @return error_t 
 */
error_t push(struct new_stack* new_stack, stack_data_type data);


/**
 * @brief Pop operation for Stack
 * 
 * @param new_stack 
 * @return error_t 
 */
error_t pop(struct new_stack* new_stack);

/**
 * @brief Peek Operation for
 * 
 * @param new_stack 
 * @return stack_data_type 
 */
stack_data_type peek(struct new_stack* new_stack);

#endif // _STACK_H_