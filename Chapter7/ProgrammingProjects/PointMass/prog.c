/*
Name - Nikhil Ranjan Nayak
Regd No - 1641012040
Desc - Point mass in 3D
*/
#include <stdio.h>
void fget_point_mass(int, int[][3], int[], FILE*);
void center_grav(int[][3], int[], double[], int);
void fwrite_point_mass(int, int[][3], int[], FILE*);
void main()
{
	FILE *input = fopen("dataset.txt", "r"), *output = fopen("output.txt", "w");;
	int n, i;
	double center_of_gravity[3];
	
	fscanf(input, "%d", &n);
	int point_matrix[n][3], masses[n];
	
	fget_point_mass(n, point_matrix, masses, input);
	
	fwrite_point_mass(n, point_matrix, masses, output);
	
	center_grav(point_matrix, masses, center_of_gravity, n);
	
	printf("Center of gravity - ");
	for(i = 0; i < 3; i++)
	{
		printf("%lf ", center_of_gravity[i]);
	}
	
	printf("\n");
	
	fclose(input);
	fclose(output);
}

void fget_point_mass(int n, int point_matrix[][3], int masses[], FILE *input)
{
	int i, j;
	for(i = 0; i < n ; i++)
	{
		for(j = 0; j < 3 ; j++)
		{
			fscanf(input, "%d", &point_matrix[i][j]);
		}
		fscanf(input, "%d", &masses[i]);
	}
}

void center_grav(int point_matrix[][3], int masses[], double center_of_gravity[], int n)
{
	int i, j;
	double sum_of_masses = 0;
	
	for(i = 0; i < n ; i++)
	{
		sum_of_masses += masses[i];
	}
	
	for(i = 0; i < 3 ; i++)
	{
		center_of_gravity[i] = 0;
	}
	
	for(j = 0; j < 3 ; j++)
	{
		for(i = 0; i < n ; i++)
		{
			center_of_gravity[j] += masses[i] * point_matrix[i][j];
		}
	}
	
	for(i = 0; i < 3 ; i++)
	{
			center_of_gravity[i] /= sum_of_masses;
	}
	
}

void fwrite_point_mass(int n, int point_matrix[][3], int masses[], FILE *output)
{
	int i, j;
	
	fprintf(output, "location");
	
	for(i = 0; i < n; i++)
	{
		fprintf(output, "\n");
		for(j = 0; j < 3 ; j++)
		{
			fprintf(output, "%d ", point_matrix[i][j]);
		}
	}
	
	fprintf(output, "\n\nmass");
	for(i = 0; i < n; i++)
	{
		fprintf(output, "\n%d", masses[i]);
	}
	
	fprintf(output, "\n\nn - %d", n);
}
