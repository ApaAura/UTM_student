#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Element
{
    void* data;
    int index;
}Element;
Element* createElement(void* data)
{
    Element* element = (Element*)malloc(sizeof(Element));
    element->data = data;
    return element;
}
typedef struct Stack
{
    int top;
    unsigned capacity;
    Element* array;
}Stack;

Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (Element*)malloc(stack->capacity * sizeof(Element));
    return stack;
}
bool isFull(Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
bool isStEmpty(Stack* stack)
{
    return stack->top == -1;
}
bool push(Stack* stack, Element* item)
{
    if (isFull(stack))
    {
        printf("Stack Overflow \n");
        return false;
    }
    stack->top++;
    stack->array[stack->top] = *item;
    stack->array[stack->top].index = stack->top;
    return true;
}
Element* pop(Stack* stack)
{
    if (isStEmpty(stack))
    {
        printf("Stack is empty\n");
        return NULL;
    }
    return &stack->array[stack->top--];
}
Element* peek(Stack* stack)
{
    if (isStEmpty(stack))
    {
        printf("Stack is empty\n");
        return NULL;
    }
    return &stack->array[stack->top];
}
void emptyStack(struct Stack* stack)
{
    stack->top = -1;
}
void deleteStack(struct Stack* stack)
{
    emptyStack(stack);
    free(stack->array);
    free(stack);
}
void deleteElement(Element* element)
{
    free(element->data);
    free(element);
}