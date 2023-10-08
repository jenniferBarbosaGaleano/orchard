#include <stdio.h>
#define MAX 40

int main()
{
    char nom[MAX];
    int edad;

    int i = 0;
    printf("\nInserte nombre del usuario: \n");
    // fflush(stdin);

    // while((nom[i] = getchar()) != '\n' && i< MAX)
    // {
    //     i++;
    // }
    // nom[i] = '\0';
    fgets(nom, MAX, stdin);
    printf("\nEl nombre es %s\n", nom);
}