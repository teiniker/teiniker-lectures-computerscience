#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// Address alignment: Total size depends on the order of the fields!!

typedef struct
{
    char *street;   // 8 Bytes      
    int number;     // 4 Bytes    
    int zip_code;   // 4 Bytes
} address_t;

typedef struct 
{
    int id;             //  4 Bytes (+4 Byte allignment)
    char *username;     //  8 Bytes
    char *password;     //  8 Bytes    
    address_t address;  // 16 Bytes 
} user_t;


void dump_memory(const unsigned char *s, size_t bytes)
{
    printf("dump: ");
    for(size_t i=0; i<bytes; i++)
    {
        printf("%02x ", s[i]);
    }
    printf("\n");
}

int main(void)
{
    // Create a User on the stack (local variable)
    user_t homer;
    homer.id = 3;
    homer.username = "homer";
    homer.password = "Drink4DuffBeers!";

    homer.address.street = "Evergreen Terrace";
    homer.address.number = 742;         // 0x02E6
    homer.address.zip_code = 58008;     // 0xE298    

    assert(homer.id == 3);
    assert(strcmp("homer", homer.username) == 0);
    assert(strcmp("Drink4DuffBeers!", homer.password) == 0);

    assert(strcmp("Evergreen Terrace", homer.address.street) == 0);
    assert(homer.address.number == 742);
    assert(homer.address.zip_code == 58008);    

    printf("sizeof(address_t) = %d\n", sizeof(address_t));
    printf("sizeof(user_t) = %d\n", sizeof(user_t));
    dump_memory((unsigned char*) &homer, sizeof(user_t));

    return 0;
}
