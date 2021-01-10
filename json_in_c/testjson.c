#include "cJSON/cJSON.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	cJSON *root;
	cJSON *info;

	root = cJSON_CreateObject();

	cJSON_AddItemToObject(root, "userInfo", info = cJSON_CreateObject());
	cJSON_AddStringToObject(info, "userEmail", "satinder");
	cJSON_AddStringToObject(info, "userPassword", "verystrongpassword");
	char *info_to_string = NULL;
	info_to_string =  cJSON_Print(info);
	printf("%s\n", info_to_string);

	return 0;
}

// gcc testjson.c ./cJSON/build/libcjson.dylib -o testjson
// ./testjson
// {
// 	"userEmail":	"satinder",
// 	"userPassword":	"verystrongpassword"
// }