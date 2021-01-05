#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

float strTOfloat(char* input)
{
	float output=0;
	int lenght=strlen(input);
	for (int i = 0; i < lenght; ++i)
	{
		output*=10;
		output+=input[i]-'0';
	}

	return output;
}

int main(int argc, char *argv[])
{
	char *input=(char*)malloc(2000*sizeof(char));
	if (!argv[1])
	{
		printf("give me coords: ");
		scanf("%s",input);
	}
	else
		strcpy(input,argv[1]);
	printf("you entred: %s\n",input);
	float min , max ;
	printf("give me the min resolution: ");
	scanf("%f",&min);
	printf("give me the max resolution: ");
	scanf("%f",&max);
	char *piece=strtok(input,",");
	while(piece)
	{
		printf("%.0f,",strTOfloat(piece)*(min/max));
		piece=strtok(NULL,",");
	}
	printf("\n1: Exit\n");
	printf("Type:");
	int answer ;

	// getchar();
	scanf("%d",&answer);
	if (answer==2)
		exit(1);

	return 0;
}