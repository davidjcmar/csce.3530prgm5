#include "header.h"

int main (void)
{
	struct router_in* r_in;
	struct router_in* r_curr;
	char* buffer;
	FILE* fp;
	size_t n = 100;
	int i;
	vertices vertex;
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
		r_curr->dist = buffer[4] - 48;
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
	free (r_curr);
	r_curr = r_in;
	/* testing *//*
	while (r_curr != NULL)
	{
		printf ("%c %c %d\n", r_curr->source, r_curr->dest, r_curr->dist);
		r_curr = r_curr->next;
	}
	/* end testing */
	return 0;
}