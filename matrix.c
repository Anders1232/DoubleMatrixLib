#include "matrix.h"
#include <string.h>
#include <stdint.h>

Matrix* NewMatrix(int linesNumber, int columnsNumber, size_t elementSize)
{
	Matrix* ret= malloc(sizeof(Matrix));
	if(ret == NULL)
	{
		return NULL;
	}
	ret->isInvalid= true;
	ret->lines= linesNumber;
	ret->columns= columnsNumber;
	ret->singleElementSize= elementSize;
	ret->elements= malloc(linesNumber*columnsNumber*elementSize);
	if(ret->elements== NULL)
	{
		free(ret);
		return NULL;
	}
	return ret;
}

Matrix* NewMatrixAndInitializeElements(int lines, int columns, size_t elementSize, void * defaultElement)
{
	Matrix* ret= NewMatrix(lines, columns, elementSize);
	if(ret == NULL)
	{
		return NULL;
	}
	int cont, numberOfElements= lines*columns;
	void* aux= ret->elements;
	for(cont= 0; cont < numberOfElements; cont++)
	{
		memcpy(aux, defaultElement, elementSize);
		aux= ((uint8_t*)aux)+elementSize;
	}
	return ret;
}
