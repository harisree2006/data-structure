#include <stdio.h>

void SparseMatrixRepresentation(int mat[20][20], int row, int col, int sp[50][3])
{
    int i, j, k = 1;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (mat[i][j] != 0)
            {
                sp[k][0] = i;
                sp[k][1] = j;
                sp[k][2] = mat[i][j];
                k++;
            }
        }
    }

    sp[0][0] = row;
    sp[0][1] = col;
    sp[0][2] = k - 1;
}

void DisplaySparse(int sp[50][3])
{
    int i, n;
    n = sp[0][2];
    printf("\nRow\tCol\tValue\n");
    for (i = 0; i <= n; i++)
    {
        printf("%d\t%d\t%d\n", sp[i][0], sp[i][1], sp[i][2]);
    }
}

void SparseTranspose(int sp1[50][3], int tr[50][3])
{
    int i, j, k = 1;
    tr[0][0] = sp1[0][1];
    tr[0][1] = sp1[0][0];
    tr[0][2] = sp1[0][2];

    for (i = 0; i < sp1[0][1]; i++)
    {
        for (j = 1; j <= sp1[0][2]; j++)
        {
            if (sp1[j][1] == i)
            {
                tr[k][0] = sp1[j][1];
                tr[k][1] = sp1[j][0];
                tr[k][2] = sp1[j][2];
                k++;
            }
        }
    }
}

void SparseAddition(int sp1[50][3], int sp2[50][3], int sp3[50][3])
{
    int i = 1, j = 1, k = 1;
    if (sp1[0][0] != sp2[0][0] || sp1[0][1] != sp2[0][1])
    {
        printf("\nMatrices are not of same order and cannot be added.\n");
        return;
    }

    while (i <= sp1[0][2] && j <= sp2[0][2])
    {
        if (sp1[i][0] == sp2[j][0] && sp1[i][1] == sp2[j][1])
        {
            int sum = sp1[i][2] + sp2[j][2];
            if (sum != 0)
            {
                sp3[k][0] = sp1[i][0];
                sp3[k][1] = sp1[i][1];
                sp3[k][2] = sum;
                k++;
            }
            i++;
            j++;
        }
        else if (sp1[i][0] < sp2[j][0] ||
                (sp1[i][0] == sp2[j][0] && sp1[i][1] < sp2[j][1]))
        {
            sp3[k][0] = sp1[i][0];
            sp3[k][1] = sp1[i][1];
            sp3[k][2] = sp1[i][2];
            i++;
            k++;
        }
        else
        {
            sp3[k][0] = sp2[j][0];
            sp3[k][1] = sp2[j][1];
            sp3[k][2] = sp2[j][2];
            j++;
            k++;
        }
    }

    while (i <= sp1[0][2])
    {
        sp3[k][0] = sp1[i][0];
        sp3[k][1] = sp1[i][1];
        sp3[k][2] = sp1[i][2];
        i++;
        k++;
    }

    while (j <= sp2[0][2])
    {
        sp3[k][0] = sp2[j][0];
        sp3[k][1] = sp2[j][1];
        sp3[k][2] = sp2[j][2];
        j++;
        k++;
    }

    sp3[0][0] = sp1[0][0];
    sp3[0][1] = sp1[0][1];
    sp3[0][2] = k - 1;
}

int main()
{
    int x[20][20], y[20][20];
    int sp1[50][3], sp2[50][3], sp3[50][3], tr[50][3];
    int r, c, i, j;

    printf("\nEnter the number of rows and columns: ");
    scanf("%d%d", &r, &c);

    printf("\nEnter elements of first matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &x[i][j]);

    printf("\nEnter elements of second matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &y[i][j]);

    SparseMatrixRepresentation(x, r, c, sp1);
    SparseMatrixRepresentation(y, r, c, sp2);

    printf("\nSparse Representation of Matrix 1:\n");
    DisplaySparse(sp1);

    printf("\nSparse Representation of Matrix 2:\n");
    DisplaySparse(sp2);

    SparseAddition(sp1, sp2, sp3);
    printf("\nSparse Matrix after Addition:\n");
    DisplaySparse(sp3);

    SparseTranspose(sp1, tr);
    printf("\nTranspose of Matrix 1 (Sparse form):\n");
    DisplaySparse(tr);

    return 0;
}
