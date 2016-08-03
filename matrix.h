/*
MatrixLib, a general matrix libary
	Copyright (C) 2016  Francisco Anderson Bezerra Rodrigues

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MATRIX_H
#define MATRIX_H

#include<stdbool.h>
#include<stdlib.h>

struct matrix
{
	bool isInvalid;
	int lines;
	int columns;
	int singleElementSize;
	void *elements;
};
typedef struct matrix Matrix;

enum comparison
{
	GREATER,
	GREATER_OR_EQUAL,
	EQUAL,
	LESS_OR_EQUAL,
	LESS
};
typedef enum comparison Comparison;

enum type
{
	INT16,
	INT32,
	INT64,
	UINT16,
	UINT32,
	UINT64,
	FLOAT,
	DOUBLE,
	LONG_DOUBLE
};
typedef enum type Type;

Matrix* NewMatrix(int lines, int columns, size_t elementSize);
Matrix* NewMatrixAndInitializeElements(int lines, int columns, size_t elementSize, void * defaultElement);
void DeleteMatrix(Matrix*);
Matrix* MatrixCopy(Matrix*);
Matrix* MatrixIdentity(int oneDimensionSize);
Matrix* MatrixAdd(Matrix*, Matrix*, bool resultInTheFirstMatrix, void*(*ElementAddFunction)(void*, void*));
Matrix* MatrixScalarMultiplication(void* scalar, bool resultInTheSameMatrix, void*(*ElementScalarMultFunction)(void* scalar, void* element));
Matrix* MatrixTranspose(Matrix*, bool resultInTheSameMatrix);
Matrix* MatrixMultiplication(Matrix*, Matrix*, bool resultInTheFirstMatrix, void*(*ElementMultFunction)(void* element1, void* element2));
Matrix* MatrixCompare(Matrix*, Matrix*, Comparison);
Matrix* MatrixElementBinaryOperation(Matrix* , Matrix*, void*(*ElementMultFunction)(void* element1, void* element2));
Matrix* MatrixElementUnaryOperation(Matrix* , Matrix*, void*(*ElementMultFunction)(void* element));
void* MatrixMaxElement(Matrix*);
void* MatrixMinElement(Matrix*);
void* MatrixGetElement(int line, int column);
void MatrixSetElement(int line, int column, void* Element);
Matrix* MatrixKroneckerProduct(Matrix*, Matrix*, bool resultInTheFirstMatrix);
Matrix* MatrixElementDivision(Matrix*, Matrix*, bool resultInTheFirstMatrix);
int MatrixColumnsNumber(Matrix*);
int MatrixLinesNumber(Matrix*);

#endif
