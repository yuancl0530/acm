#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char s[107];
void print(char a)
{
    switch(a){
    case 'A' : printf(".-"); break;
    case 'B' : printf("-..."); break;
    case 'C' : printf("-.-."); break;
    case 'D' : printf("-.."); break;
    case 'E' : printf("."); break;
    case 'F' : printf("..-."); break;
    case 'G' : printf("--."); break;
    case 'H' : printf("...."); break;
    case 'I' : printf(".."); break;
    case 'J' : printf(".---"); break;
    case 'K' : printf("-.-"); break;
    case 'L' : printf(".-.."); break;
    case 'M' : printf("--"); break;
    case 'N' : printf("-."); break;
    case 'O' : printf("---"); break;
    case 'P' : printf(".--."); break;
    case 'Q' : printf("--.-"); break;
    case 'R' : printf(".-."); break;
    case 'S' : printf("..."); break;
    case 'T' : printf("-"); break;
    case 'U' : printf("..-"); break;
    case 'V' : printf("...-"); break;
    case 'W' : printf(".--"); break;
    case 'X' : printf("-..-"); break;
    case 'Y' : printf("-.--"); break;
    case 'Z' : printf("--.."); break;
    case '0' : printf("-----"); break;
    case '1' : printf(".----"); break;
    case '2' : printf("..---"); break;
    case '3' : printf("...--"); break;
    case '4' : printf("....-"); break;
    case '5' : printf("....."); break;
    case '6' : printf("-...."); break;
    case '7' : printf("--..."); break;
    case '8' : printf("---.."); break;
    case '9' : printf("----."); break;
    }
}
int main()
{
    int n,nn,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%s",s);
            nn=strlen(s);
            for(int i=0;i<nn;i++)
            {
                s[i]=toupper(s[i]);
                print(s[i]);
            
                    printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
