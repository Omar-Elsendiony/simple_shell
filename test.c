#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int t = 0;
	t = access("waay/rr", 7);
	if (t == 0)
	{
		printf("the file exit\n");
	}
	else
	{
		printf("error\n");
	}
	return (0);
}
