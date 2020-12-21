#include <stdio.h>


struct db {
	char *filename;
};

int main(void)
{
	struct db *db;
	char *filename = "test.db";
	int a = *filename;
	db->filename = "test2.db";
	printf("hello world\n");
	printf("%s\n", filename);
	printf("%d\n", a);
}

// gcc pointer_test.c