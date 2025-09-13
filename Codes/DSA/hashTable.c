#include <stdio.h>
#include <string.h>
#define tableSize 20
#define MAX_NAME 156

typedef struct
{
    char *name;
    int age;
} person;

unsigned int hash(char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % tableSize;
    }
    return hash_value;
}

int main()
{
    printf("wish => %d", hash("wish"));
    return 0;
}
