#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void wcexe(char *filename,char s);
int main()
{
	char filename[]="input.txt"; 
	printf("������-c��-v��"); 
	char s=scanf("������-c��-v��"); 
	wcexe(filename,s);
	return 0;
	
}

void wcexe(char *filename,char s)
{
	FILE *fp;
	char c;
	char buffer[1000];
	int bufferlen;
	int isLastBlank=1;
	int wordCount=0;
	int charCount=0;
	int i;
	
	if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("�ļ����ܴ�");
		exit(0);
	}
	
	while(fgets(buffer,1000,fp)!=NULL)
	{
		bufferlen=strlen(buffer);
		for(i=0;i<bufferlen;i++)
		{
			c=buffer[i];
			if(c==' ' || c=='\t' || c=='\n')
			{
				charCount++;
			}
			
			if(c==' ' || c==',')
			{
				if(isLastBlank==0)
				{
					wordCount++;
				}
				isLastBlank=1;
			}
			
			if(c!=' ' && c!=',' && c!='\t' && c!='\n')
			{
				isLastBlank=0;
			}
		}
		
		if(isLastBlank==0)
		{
			wordCount++;
		}
		fclose(fp);
		if(s=='-c'){
		printf("��������%d\n",wordCount);
	}else{
		printf("�ַ�����%d\n",charCount);
	}
	}
	
	
	
	
	
}
