#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct router_in{
	char source;
	char dest;
	unsigned int dist;
	struct router_in* next;
	struct router_in* prev;
};
#endif