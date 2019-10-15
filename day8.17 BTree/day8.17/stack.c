
#include "stack.h"

void StackInit(Stack* psl, size_t capicity)
{
	assert(psl);
	psl->capicity = capicity;
	psl->array = (SLDataType *)malloc(capicity * sizeof(SLDataType));
	assert(psl->array);

	psl->size = 0;
}
void StackDestory(Stack* psl)
{
	assert(psl);
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->size = 0;
		psl->capicity = 0;
	}
}
void CheckCapacity(Stack* psl)
{
	assert(psl);
	if (psl->size == psl->capicity)
	{
		psl->capicity *= 2;
		psl->array = (SLDataType *)realloc(psl->array, psl->capicity * sizeof(SLDataType));

	}
}
void StackPush(Stack* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);

	psl->array[psl->size] = x;
	psl->size++;
}
void StackPop(Stack* psl)
{
	assert(psl || psl->size);
	psl->size--;

}
SLDataType StackTop(Stack* psl)
{
	if (StackIsEmpty(psl))
	{
		return (SLDataType)0;
	}
	return psl->array[psl->size - 1];
}
int StackIsEmpty(Stack * psl)
{
	return psl->size == 0;
}