#include <stdio.h>
#include <string.h>
int prefix[100]={0};
void PrefixTable(char pat[]){
	int i=0,j;
	prefix[0]=0;
	for(j=1;j<strlen(pat);j++)
	{
		while((i>0)&&(pat[i]!=pat[j]))
			i = prefix[i-1];
		if(pat[i]==pat[j])
			i=i+1;
		prefix[j]=i;
	}
		for(i=0;i<strlen(pat);i++)
			printf("%d  ",i);
		printf("\n");
		for(i=0;i<strlen(pat);i++)
			printf("%c  ",pat[i]);
		printf("\n");
		for(i=0;i<strlen(pat);i++)
			printf("%d  ",prefix[i]);
		printf("\n");
}
void KMP(char pat[], char txt[]){
	int i=0,j,flag=0;
 	for (j = 0; j <strlen(txt); j++){
        while((i>0)&&(pat[i]!=txt[j]))
        	i = prefix[i-1];
        if(pat[i]==txt[j])
        	i=i+1;
        if (strlen(pat) == i){
        	printf("Pattern found at index %d \n", i);
			flag=1;
        	break;
		}
	}
	if(flag==0)
    		printf("Pattern not found \n");
}
void search(char* pat, char* txt){
    int M = strlen(pat);
    int N = strlen(txt);
    for (int i = 0; i <= N - M; i++)
	{
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            printf("Pattern found at index %d \n", i);
    }
}
int main()
{
	char txt[100],pat[30];
    printf("Enter the text string: ");
    scanf("%s",txt);
    printf("Enter the pattern: ");
    scanf("%s",pat);
    PrefixTable(pat);
    KMP(pat, txt);
    search(pat,txt);
}
