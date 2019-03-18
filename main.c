#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592f

typedef struct
{
	float x;
	float y;
	float r;
} Circle;

int main()
{
	int n;
	Circle * Outputs;
	printf("Enter Circles count: ");
	scanf("%d", &n);
	while(n < 1)
	{
		printf("Invalid input, enter again: ");
		scanf("%d", &n);	
	}
	Outputs = (Circle *)malloc(sizeof(Circle)*n);
	int i;
	for(i = 0; i < n; i++)
	{
		printf("#%d)Circle(x,y,r): ", i);
		scanf("%f%f%f", &Outputs[i].x, &Outputs[i].y, &Outputs[i].r);
		while(Outputs[i].r < 0.0f)
		{
			printf("Radius can't be negative, enter again: ");
			scanf("%f", &Outputs[i].r);
		}
	}
	int Flag, j;
	float Dist, Vecx, Vecy;
	for(i = 0; i < n; i++)
	{
		printf("\n#%d) Circle( %f %f, %f);\n", i, Outputs[i].x, Outputs[i].y, Outputs[i].r);
		printf("p = %f;\n", 2.0f*PI*Outputs[i].r);
		printf("Intersections with:");
		Flag = 1;
		for(j = 0; j < n; j++)
		{
			if(j == i)
				continue;
			Vecx = Outputs[i].x - Outputs[j].x;
			Vecy = Outputs[i].y - Outputs[j].y;
			Dist = Vecx*Vecx + Vecy*Vecy;
			if(Dist <= (Outputs[i].r+Outputs[i].r)*(Outputs[j].r+Outputs[j].r))
			{
				Flag = 0;
				printf(" %d", j);
			}
		}
		if(Flag)
			printf(" no one;\n");
		else
			printf(";\n");
	}
	free(Outputs);
	return 0;
}
