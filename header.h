#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {u, v, w, x, y , z} vertices;
struct router_in{
	char source;
	char dest;
	unsigned int dist;
	struct router_in* next;
	struct router_in* prev;
};

int dijkstra ();
int dvector ();
#endif