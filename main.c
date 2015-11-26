#include "header.h"

int dijkstra(int cost_matrix[][6])
{
	int i, j;
	/* testing */ /*
	for (i=0; i<6; i++)
	{	
		for (j=0; j<6; j++)
			printf ("%d\t", cost_matrix[i][j]);
		printf ("\n");
	}
	/* end testing */
	return 0;
}

int main (void)
{
	struct router_in* r_in;
	struct router_in* r_curr;
	char* buffer;
	FILE* fp;
	size_t n = 100;
	int i,j;
	int cost_mat[6][6];

	fp = fopen("router.txt", "r");
	buffer = (char*) malloc(sizeof (char) * 100);
	memset (buffer, '\n', 100);
	r_in = (struct router_in*) malloc(sizeof(struct router_in));
	r_in->next = NULL;
	r_curr = r_in;
	while (getline(&buffer, &n, fp) != -1)
	{
		r_curr->source = buffer[0];
		r_curr->dest = buffer[2];
		r_curr->dist = buffer[4] - 48; // 48 is ascii value of 0
		r_curr->next = (struct router_in*) malloc(sizeof(struct router_in));
		if (r_curr == r_in)
			r_curr->prev = NULL;
		else
			r_curr->next->prev = r_curr;
		r_curr = r_curr->next;
		r_curr->next = NULL;
	}
	while (1)
	{
		if (r_curr->next != NULL)
			continue;
		r_curr->prev->next = NULL;
		break;
	}
	fclose(fp);
	free (r_curr);
	r_curr = r_in;
	for (i=0; i<6; i++)
		for (j=0; j<6; j++)
		{
			if (i==j)
				cost_mat[i][j] = 0;
			else
				cost_mat[i][j] = -1;
		}

	while (r_curr != NULL)
	{
		//printf ("%c %c %d\n", r_curr->source, r_curr->dest, r_curr->dist);
		//printf ("i,j: %d %d %d\n", r_curr->source, r_curr->dest, r_curr->dist);
		cost_mat[r_curr->source-117][r_curr->dest-117] = r_curr->dist; // 117 is ascii value of u
		cost_mat[r_curr->dest-117][r_curr->source-117] = r_curr->dist; // 117 is ascii value of u
		r_curr = r_curr->next;
	}
	dijkstra(cost_mat);
	/* testing *//*
	for (i=0; i<6; i++)
	{
		for (j=0; j<6; j++)
			printf ("%d ", cost_mat[i][j]);
		printf ("\n");
	}
	/* end testing */

	return 0;
}