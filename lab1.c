#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct hobbies
{
    char h[50];
};
typedef struct hobbies hobby;

struct me
{
    char *nume;
    char *prenume;
    char *oras;
    char *liceu;
    hobby p[10];
};

void afisare( char v[])
{
    for(int j=0; j<(strlen(v));j++)
        printf("%c", v[j]);
    printf("\n");
}

void sortare(hobby p[10])
{
    char x[50];
    for(int i=0; i<4;i++)
    {
        int o;
        o=i;
        for(int j=i+1;j<5;j++)
        {
            if(strcmp(p[j].h,p[o].h)>0)
                o=j;
            if(o!=i)
            {
                strcpy(x,p[o].h);
                strcpy(p[o].h,p[i].h);
                strcpy(p[i].h,x);
            }
        }
    }
}

int main()
{
    struct me a;
    a.nume = "Dumitrescu";
    a.prenume = "Denisa";
    a.oras = "Slobozia";
    a.liceu = "CNMV";
    
    afisare(a.nume);
    afisare(a.prenume);
    afisare(a.oras);
    afisare(a.liceu);
    
    strcpy(a.p[0].h,"tenis");
    strcpy(a.p[1].h,"citit");
    strcpy(a.p[2].h,"anime");
    strcpy(a.p[3].h,"basket");
    strcpy(a.p[4].h,"video-games");
    sortare(a.p);
    for(int i=0; i<5; i++)
    {
        printf("%s",a.p[i].h);
        printf(" ");
    }

}