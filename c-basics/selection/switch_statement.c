#include <stdio.h>

const int MIN = 0;
const int MAX = 10;

int main(void)
{
    int grade = 4;      // User input 
    
    if (grade == 1)
    {
        printf("sehr gut\n");
    }
    else if(grade == 2)
    {
        printf("gut\n");
    }
    else if (grade == 3)
    {
        printf("befriedigend\n");
    }
    else if(grade == 4)
    {
        printf("genügend\n");
    }
    else if(grade == 5)
    {
        printf("nicht genügend\n");
    }
    else 
    {
        printf("Invalid grade!\n");
    }

    // Alternative Implementation 
    
    switch(grade)
    {
        case 1:
            printf("sehr gut\n");
            break;
            
        case 2:
            printf("gut\n");
            break;

        case 3:
            printf("befriedigend\n");
            break;

        case 4:
            printf("genügend\n");
            break;

        case 5:
            printf("nicht genügend\n");
            break;

        default:
            printf("Invalid grade!\n");
    }
    
    switch(grade)
    {
        case 1:
        case 2:
        case 3:
        case 4:
            printf("positiv\n");
            break;
        case 5:
            printf("negativ\n");
            break;
    }

	return 0;
}
