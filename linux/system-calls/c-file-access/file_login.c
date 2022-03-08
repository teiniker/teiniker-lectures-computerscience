#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_valid_user(char* username, char* password)
{
    char _username[256];
    char _password[256];
    FILE *fp;
    fp = fopen("application-users.config", "r");
    if (fp == NULL) 
    {
        fprintf(stderr, "Can't open application-users.config file!\n");
        return false;
    }
    
    while(fscanf(fp, "%s %s", _username, _password) != EOF)
    {
        if(strcmp(username,_username) == 0
            && strcmp(password,_password) == 0)
        {
            fclose(fp);
            return true;
        }
    }
    fclose(fp);
    return false;
}


int main()
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
