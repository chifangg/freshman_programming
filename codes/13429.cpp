#include "function.h"



void Init(Matrix *self, int _rowLength, int _colLength)


{
    self->rowLength = _rowLength;
    self->colLength = _colLength;
    //int total = _rowLength * _colLength;
    int ptr;
    ptr = (int)malloc(sizeof(int)*(_rowLength*_colLength));
    self->values = ptr;

}



void Add(Matrix m1, Matrix m2)

{
    Matrix m3 = MATRIX_INITIALIZER;
    m3.rowLength = m1.rowLength;
    m3.colLength = m2.colLength;
    int ptr;
    ptr = (int)malloc(sizeof(int)*(m1.rowLength*m1.colLength));
    m3.values = ptr;

    if(m1.rowLength == m2.rowLength && m1.colLength == m2.colLength)
    {
        for(int i = 0; i < m1.rowLength; i++)
        {
            for(int j = 0; j < m1.colLength; j++)
            {
                 m3.values[i * (m3).colLength + j] = m1.values[i * (m1).colLength + j] + m2.values[i * (m2).colLength + j];
            }
        }
        printf("Matrix 1 + Matrix 2:\n");
        Print(m3);
    }
    else
    {
        printf("Matrix 1 + Matrix 2:\n");
        printf("Uncalculable\n");
    }

}



void Sub(Matrix m1, Matrix m2)


{
    Matrix m3 = MATRIX_INITIALIZER;
    m3.colLength = m1.colLength;
    m3.rowLength = m1.rowLength;
    int ptr;
    ptr = (int)malloc(sizeof(int)*(m1.rowLength*m1.colLength));
    m3.values = ptr;

    if(m1.rowLength == m2.rowLength && m1.colLength == m2.colLength)
    {
        for(int i = 0; i < m1.rowLength; i++)
        {
            for(int j = 0; j < m1.colLength; j++)
            {
                 m3.values[i * (m3).colLength + j] = m1.values[i * (m1).colLength + j] - m2.values[i * (m2).colLength + j];
            }
        }
        printf("Matrix 1 - Matrix 2:\n");
        Print(m3);
    }
    else
    {
        printf("Matrix 1 - Matrix 2:\n");
        printf("Uncalculable\n");
    }



}



void Mul(Matrix m1, Matrix m2)


{
    Matrix m3 = MATRIX_INITIALIZER;
    m3.rowLength = m1.rowLength;
    m3.colLength = m2.colLength;
    int ptr;
    ptr = (int)malloc(sizeof(int)*(m1.rowLength*m2.colLength));
    m3.values = ptr;
    if(m1.colLength == m2.rowLength)
    {
        for(int i = 0; i < m1.rowLength; i++)
        {
            for(int j = 0; j < m2.colLength; j++)
            {
                int sum = 0;
                //sum = ((m1.values[i * (m1).colLength])*(m2.values[j]));
                for(int k = 0; k < m1.colLength; k++)
                {
                    //printf("ijk%d%d%d %d %d\n", i, j, k, m1.values[i * (m1).colLength + (k)], m2.values[(k) * (m2).colLength + j]);
                    sum += (m1.values[i * (m1).colLength + (k)])*(m2.values[(k) * (m2).colLength + j]);
                }
                    m3.values[i * m2.colLength + j] = sum;
            }
        }
        printf("Matrix 1 * Matrix 2:\n");
        Print(m3);
    }
    else
    {
        printf("Matrix 1 * Matrix 2:\n");
        printf("Uncalculable\n");
    }


}



void Print(Matrix m)


{


    if (m.rowLength != 0 && m.colLength != 0)


    {


        printf("[ ");


        for (int i = 0; i < m.rowLength; i++)


        {


            if (i != 0)


                printf("  ");



            for (int j = 0; j < m.colLength; j++)


            {


                printf("%d", m.values[i * m.colLength + j]);


                if (j == m.colLength - 1)


                {


                    if (i != m.rowLength - 1)


                        printf("\n");


                }


                else


                    printf(" ");


            }


        }


        printf(" ]\n");


    }


}
