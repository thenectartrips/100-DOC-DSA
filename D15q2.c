void setZeroes(int** matrix, int matrixSize, int* matrixColSize) 
{
    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    int row[200] = {0};
    int col[200] = {0};
    
    int i, j;
    
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            if(matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            if(row[i] == 1 || col[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
