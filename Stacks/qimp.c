#include "q.h"
#include <ctype.h>

stack *stack_initialize(int size)
{
    struct stack *stack_holder = (struct stack *)malloc(sizeof(struct stack));

    if (!stack_holder)
        return NULL;

    stack_holder->top = -1;
    stack_holder->arr = (int *)malloc(size * sizeof(int));

    if (!stack_holder->arr)
        return NULL;

    return stack_holder;
}

void stack_push(stack *ptr_stack, int key)
{
    ptr_stack->arr[++ptr_stack->top] = key;
}

void stack_pop(stack *ptr_stack)
{
    --ptr_stack->top;
}

int stack_is_empty(stack *ptr_stack)
{
    if (ptr_stack->top != -1)
        return 1;
    return 0;
}

int stack_peek(stack *ptr_stack)
{
    return ptr_stack->arr[ptr_stack->top];
}

void stack_destroy(stack *ptr_stack)
{
    free(ptr_stack);
}

int check_priority(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    if (ch == '*' || ch == '/')
    {
        return 2;
    }
    return 0;
}

void convert_infix_to_postfix(const char *source_infix, char *target_postfix)
{

    stack *stack_holder = stack_initialize(100);

    int var1 = 0, var2 = 0, var3 = 0;
    while (*(source_infix + var1) != '\0')
    {
        switch (*(source_infix + var1))
        {
        case '(':
        case '{':
        case '[':
            stack_push(stack_holder, *(source_infix + var1));
            break;
        case ')':
            while ((var2 = stack_peek(stack_holder)) != '(')
            {
                *(target_postfix + (var3++)) = var2;
                stack_pop(stack_holder);
            }
            stack_pop(stack_holder);
            break;
        case '}':
            while ((var2 = stack_peek(stack_holder)) != '{')
            {
                *(target_postfix + (var3++)) = var2;
                stack_pop(stack_holder);
            }
            stack_pop(stack_holder);
            break;
        case ']':
            while ((var2 = stack_peek(stack_holder)) != '[')
            {
                *(target_postfix + (var3++)) = var2;
                stack_pop(stack_holder);
            }
            stack_pop(stack_holder);
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            while (!(stack_is_empty(stack_holder)) && check_priority(var2 = stack_peek(stack_holder)) >= check_priority(*(source_infix + var1)))
            {
                *(target_postfix + (var3++)) = var2;
                stack_pop(stack_holder);
            }
            stack_push(stack_holder, *(source_infix + var1));
            break;
        default:
            if (isalnum(var2 = *(source_infix + var1)))
                *(target_postfix + (var3++)) = var2;
            else
            {
                while (!(stack_is_empty(stack_holder)))
                {
                    *(target_postfix + (var3++)) = stack_peek(stack_holder);
                    stack_pop(stack_holder);
                }
                *(target_postfix + (var3)) = '\0';
                return;
            }
        }
        var1++;
    }
}