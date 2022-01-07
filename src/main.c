#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>
#include <mosquitto.h>


int CJSON_CDECL main(void)
{
    int rc, msg_len; 
    struct mosquitto *mosq; 
    char *msg; 
   /* Declare the JSON items  */
    cJSON *root = NULL;
    cJSON *data = NULL; 

    /* print the version */
    printf("Version: %s\n", cJSON_Version());
 
    root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "Action", "led_cfg");
    cJSON_AddItemToObject(root, "Data", data = cJSON_CreateObject());
    cJSON_AddNumberToObject(data, "Pin", 17);
    msg = cJSON_PrintUnformatted(root); 
    msg_len = size_t(msg); 

    /* connect to MQTT and publis JSON */ 
    mosquitto_lib_init(); 
    mosq = mosquitto_new("publisher-test", true, NULL); 

    rc = mosquitto_connect(mosq, "localhost", 1883, 60); 
    if ( rc != 0) {
        printf("Client could not connect to broker! Error Code: %d", rc); 
        mosquitto_destroy(mosq); 
        return -1; 
    }
    printf("we are now connected to the broker!\n"); 
    mosquitto_publish(mosq, NULL, "test/t1", 10, msg, 0, false); 
    mosquitto_disconnect(mosq); 
    mosquitto_destroy(mosq); 
    mosquitto_lib_cleanup(); 
    free(msg); 
    
    return 0; 
}