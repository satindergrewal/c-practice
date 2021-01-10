#include "cJSON/cJSON.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	cJSON *root;
	cJSON *info;

	// root = cJSON_CreateObject();
	// cJSON_AddItemToObject(root, "userInfo", info = cJSON_CreateObject());
	
	info = cJSON_CreateObject();
	cJSON_AddStringToObject(info, "method", "live");
	cJSON_AddStringToObject(info, "id", "19e6443f0fb3a7d30d9ff7e696320d509eb263270f36d8a968ea407012fc438a");
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

// {
//     "method":    "live",
//     "id":    "19e6443f0fb3a7d30d9ff7e696320d509eb263270f36d8a968ea407012fc438a"
// }