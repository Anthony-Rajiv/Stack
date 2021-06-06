/**
 * @file stack.c
 * @author Anthony Rajiv Francis (anthonyrajiv.francis@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "stack.h"
#include "stdlib.h"
#include "string.h"

/**
 * @brief Create a stack object
 * 
 * @param size_of_stack 
 * @return struct new_stack* 
 */
struct new_stack* create_stack(size_t size_of_stack)
{
    struct new_stack* stack = (struct new_stack*)calloc(size_of_stack, sizeof(stack_data_type));
    stack -> size_of_stack = size_of_stack;
    stack -> top = 0;
    stack -> data_array = (stack_data_type *)calloc(size_of_stack, sizeof(stack_data_type));
    return stack;
}

/**
 * @brief Checks whether the Stack is FULL
 * 
 * @param new_stack 
 * @return true 
 * @return false 
 */
static bool is_full(struct new_stack* new_stack)
{
    return new_stack -> top == new_stack -> size_of_stack;
}

/**
 * @brief Checks whether the Stack is EMPTY
 * 
 * @param new_stack 
 * @return true 
 * @return false 
 */
static bool is_empty(struct new_stack* new_stack)
{
    return new_stack -> top == 0;
}

/**
 * @brief Push Operation for Stack
 * 
 * @param new_stack 
 * @param data 
 * @return error_t 
 */
error_t push(struct new_stack* new_stack, stack_data_type data)
{
    error_t ret_val = SUCCESS;
    if(!is_full(new_stack))
    {
        memcpy((stack_data_type *)&(new_stack -> data_array[new_stack -> top]), &data, sizeof(stack_data_type));
        new_stack->top++;
    }
    else
    {
        ret_val = STACK_FULL;
    }

    return ret_val;
}

/**
 * @brief Pop operation for Stack
 * 
 * @param new_stack 
 * @return error_t 
 */
error_t pop(struct new_stack* new_stack)
{
    if(is_empty(new_stack))
    {
        return STACK_EMPTY;
    }
    else
    {
        new_stack -> data_array[new_stack -> top--];
        return SUCCESS;
    }
}

/**
 * @brief Peek Operation for
 * 
 * @param new_stack 
 * @return stack_data_type 
 */
stack_data_type peek(struct new_stack* new_stack)
{
    if(is_empty(new_stack))
    {
        return 0;
    }
    else
    {
        return new_stack -> data_array[new_stack -> top];
    }
}
