#include <stdio.h>
#include <math.h>

void init_zero_matrix(float matrix[3][3]);
void print_matrix(const float matrix[3][3]);
void printPoint(float point[]);
void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);
void init_identity_matrix(float matrix[3][3]);
void scalar_multiply_matrix(float matrix[3][3], float scalar);
void transform_point (float matrix[3][3], float point[3], float finalPoint[3]);
void scale (float matrix[3][3], float point[3], float finalPoint[3], float S[2]);
void shift (float matrix[3][3], float point[3], float finalPoint[3], float S[2]);
void rotate (float matrix[3][3], float point[3], float finalPoint[3], double angle);

int main(int argc, char* argv[])
{
	float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
	float b[3][3];
	float c[3][3];

    init_zero_matrix(b);
    b[1][1] =  8.0f;
    b[2][0] = -3.0f;
    b[2][2] =  5.0f;

    print_matrix(a);
	printf("\n");
    print_matrix(b);
	printf("\n");
    
    add_matrices(a, b, c);
	print_matrix(c);
	printf("\n");
	float scalar = 6.0;
	scalar_multiply_matrix(a, scalar);
    print_matrix(a);
	printf("\n");
	float point[3]={
	2.0f, 3.0f, 1.0f
	};
	float finalPoint[3]={
	0.0f, 0.0f, 0.0f
	};
	transform_point(a, point, finalPoint);
	printPoint(finalPoint);
	for(int i=0;i<3;i++)
		finalPoint[i]=0;
	float S[2] = {5.0f, 3.0f};
	double angle = 45.0f;
	scale(a, point, finalPoint, S);
	printPoint(finalPoint);
	for(int i=0;i<3;i++)
		finalPoint[i]=0;
	shift(a, point, finalPoint, S);
	printPoint(finalPoint);
	for(int i=0;i<3;i++)
		finalPoint[i]=0;
	rotate(a, point, finalPoint, angle);
	printPoint(finalPoint);
	

	return 0;
}

void init_zero_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}


void print_matrix(const float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%4.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printPoint(float point[]){
	for (int i = 0; i < 3; i++){
		printf("%4.4f ", point[i]);
	}
	printf("\n");
	
}

void add_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void init_identity_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            if (i == j) {
                matrix[i][j] = 1.0f;
            } else {
                matrix[i][j] = 0.0f;
            }
        }
    }
}

void scalar_multiply_matrix(float matrix[3][3], float scalar)
{
    int i;
	int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = matrix[i][j] * scalar;
        }
    }
}

void multiply_matrix(float A[3][3], float B[3][3], float C[3][3])
{
	int i;
	int j;
	int k;
	
	
	for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
			C[i][j] = 0.0;
			for (k = 0; k < 3; ++k)
				C[i][j] += A[i][k] * B[k][j];
			}
    }

}

void transform_point (float matrix[3][3], float point[3], float finalPoint[3])
{
	int i,k;
	
	for (i = 0; i < 3; ++i) {
        finalPoint[i] = 0.0;
        for (k = 0; k < 3; ++k) {
            finalPoint[i] += matrix[i][k] * point[k];
        }
    }
}

void scale (float matrix[3][3], float point[3], float finalPoint[3], float S[2])
{
	int i,k;
	
	init_identity_matrix(matrix);
	
	matrix[0][0]=S[0];
	matrix[1][1]=S[1];
	
	for (i = 0; i < 3; ++i) {
        finalPoint[i] = 0.0;
        for (k = 0; k < 3; ++k) {
            finalPoint[i] += matrix[i][k] * point[k];
        }
    }
	
}

void shift (float matrix[3][3], float point[3], float finalPoint[3], float S[2])
{
	int i,k;
	
	init_identity_matrix(matrix);
	
	matrix[0][2]=S[0];
	matrix[1][2]=S[1];
	
	for (i = 0; i < 3; ++i) {
        finalPoint[i] = 0.0;
        for (k = 0; k < 3; ++k) {
            finalPoint[i] += matrix[i][k] * point[k];
        }
    }
	
}

void rotate (float matrix[3][3], float point[3], float finalPoint[3], double angle)
{
	int i,k;
	
	init_identity_matrix(matrix);
	
	matrix[0][0]=cos(angle);
	matrix[0][1]=-sin(angle);
	matrix[1][0]=sin(angle);
	matrix[1][1]=cos(angle);
	
	for (i = 0; i < 3; ++i) {
        finalPoint[i] = 0.0;
        for (k = 0; k < 3; ++k) {
            finalPoint[i] += matrix[i][k] * point[k];
        }
    }
	
}

