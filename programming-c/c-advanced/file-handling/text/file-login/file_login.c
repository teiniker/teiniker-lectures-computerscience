#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_valid_user(char* username, char* password)
{
    char stored_username[256];
    char stored_password[256];
    
    FILE *fp = fopen("application-users.config", "r");
    if (fp == NULL) 
    {
        fprintf(stderr, "Can't open application-users.config file!\n");
        return false;
    }
    
    while(fscanf(fp, "%s %s", stored_username, stored_password) != EOF)
    {
        if(strcmp(username,stored_username) == 0
            && strcmp(password,stored_password) == 0)
        {
            fclose(fp);
            return true;
        }
    }
    fclose(fp);
    return false;
}


int main(void)
{
    char username[256];
    char password[256];

    printf("username> ");
    scanf("%s", username);
    printf("password> ");
    scanf("%s", password);

    if(is_valid_user(username, password))
    {
        printf("Welcome, %s!\n", username);
    }
    else
    {
        printf("Login rejected!\n");
    }
	return 0;
}
