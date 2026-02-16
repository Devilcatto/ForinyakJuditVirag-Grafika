#include <stdio.h>
#include <math.h>

struct matrix {
	int col;
	int row;
	int m[][];
};

matrix bekerMatrix(){

struct matrix m1;
printf("Add meg az oszlopot:");
scanf("%d", m1.col);
printf("Add meg a sort:");
scanf("%d", m1.row);

for(i=0;i<=m1.row-1;i++)
	{
		for(j=0;j<=m1.col-1;j++)
		{
			printf("Add meg a mátrix ezen elemét: %d %d\n",i,j);
			scanf("%d",m1.m[i][j]);
		}
	}
	
kiirMatrix(matrix* m1)

}

void kiirMatrix(matrix* m1)
{
for(i=0;i<=m1.row-1;i++)
	{
		for(j=0;j<=m1.col-1;j++)
		{
			printf("%d",m1.m[i][j]);
			
		}
	}


}

int main()
{

return 0;
}