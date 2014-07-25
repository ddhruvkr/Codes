#include<stdio.h>

int checkjob();
int allocate_check(int k);
void allocate( int k);
void deallocate(int k);

int n,r, resources[10], max_req[10][10], current[10][10], total[10],need[10][10], available[10],finish[10];

main()
{

	int i, j;
	printf("\n BANKERS ALGORITHM FOR DEADLOCK AVOIDANCE");
	printf("\n \n Enter the no. of processes:");
	scanf(" %d", &n);

	printf("\n Enter the no. of Resources shared by the given processes:");
	scanf(" %d", &r);

	printf("\n \n Enter the Maximum resource available: \n");

	for(i = 1; i <= r; i++)
		scanf(" %d", &resources[i]);

	printf("\n Enter the maximum requirement");
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= r; j++)
		{
			printf("\n Resource %d for Process %d :", j, i);
			scanf(" %d", &max_req[i][j]);
		}
	}

	printf("\n Enter the current allocated matrix:");
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= r; j++)
		{
			printf("\n Resources %d for Process %d :", j, i);
			scanf(" %d", &current[i][j]);

		}
	}

	for(i = 1; i <= r; i++)
	{
		for(j = 1; j <= n; j++)
		{
			total[i] = total[i]+ current[j][i];
			need[j][i] = max_req[j][i] - current[j][i];
		}
		available[i] = resources[i] - total[i];
	}

	printf("\n The Claim Matrix of the processes is: \n");

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= r; j++)
		{
			printf(" %d\t", max_req[i][j]);
		}
		printf("\n ");
	}
	printf("\n \n ");

	printf("\n The current allocated Matrix: \n");
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= r; j++)
		{
			printf(" %d\t", current[i][j]);
		}
		printf("\n ");
	}
	printf("\n \n ");

	printf("\n The Need Matrix is: \n");
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= r; j++)
		{
			printf(" %d\t", need[i][j]);
		}
		printf("\n ");
	}

	printf("\n \n ");

	printf("\n The total resources are: \n");
	for(i = 1; i <= r; i++)
		printf(" %d \t ", resources[i]);
	printf("\n \n ");

	printf("\n The total used resources : \n");
	for(i = 1; i <= r; i++)
		printf(" %d \t ", total[i]);
	printf("\n \n ");

	printf("\n The remaining resources available for allocation: \n");
	for(i = 1; i <= r; i++)
		printf(" %d \t ", available[i]);
	printf("\n \n ");

	printf("\n Allocation Begins... \n");

	while(checkjob(n)!=0)
	{
		for(i = 1; i <= n; i++)
		{
			if(finish[i] ==  0)
			{
				if(allocate_check(i))
				{
					printf("\n \n Allocated matrix \n");
					allocate(i);
					sleep(10);
					printf("\n \n Deallocated matrix \n");
					deallocate(i);
				}
			}
		}
	}
	printf("\n All the Processes are completed");
}


int checkjob()
{
	int i;
	for(i = 1; i <= n; i++)
	{
		if(finish[i] == 0)
			return 1;
	}
	return 0;
}

int allocate_check(int k)
{
	int i, j, flag = 0;
	for(i = 1; i <= r; i++)
	{
		if(available[i] < need[k][i])
		{
			flag = 1;
			break;
		}

	}
	if(flag == 0)
		return 1;

	return 0;
}


void allocate( int k)
{
	int i,j;
	for(i = 1; i <= r; i++)
	{
		available[i] = available[i] - need[k][i];
		current[k][i] = max_req[k][i];
	}

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= r; j++)
		{
			printf(" %d \t", current[i][j]);
		}

		printf("\n \n");
	}

	printf("\n \n");
	printf("\n Resources In hand after allocation:\n");
	for(i = 1; i <= r; i++)
		printf(" %d \t", available[i]);

}

void deallocate(int k)
{
	int i, j;
	for(i = 1; i <= r; i++)
	{
		available[i] = available[i] + current[k][i];
		current[k][i] = 0;
	}
 	finish[k] = 1;

	for( i = 1; i <= n; i++)
	{
		for(j = 1; j <= r; j++)
		{
			printf(" %d \t", current[i][j]);
		}
		printf("\n \n");
	}

	printf("\n \n");
	printf("\n Resources in hand after deallocation :\n");
	for(i = 1; i <= r; i++)
		printf(" %d \t", available[i]);

	printf("\n");
}
