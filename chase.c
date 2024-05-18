#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void upcase(FILE* stream);
void locase(FILE* stream);
void icase(FILE* stream);
void printh(void);
void printtryh(void);

int main(int argc, char** argv)
{
	if(argc<2||argc>3)
	{
		fputs("Invalid number of arguments\n", stdout);
		fputs("Try \'chase -h\' for help\n", stdout);
		return 1;
	}
	FILE* file;
	char c=getopt(argc, argv, "hu:l:i:");
	switch(c)
	{
		case 'h':
			printh();
			break;
			
		case 'u':
			file=fopen(optarg,"r");
			if(file==NULL)
			{
				fclose(file);
				printf("Coudn\'t open %s\n", optarg);
				return 1;
			}
			upcase(file);
			fclose(file);
			break;
			
		case 'l':
			file=fopen(optarg,"r");
			if(file==NULL)
			{
				fclose(file);
				printf("Coudn\'t open %s\n", optarg);
				return 1;
			}
			locase(file);
			fclose(file);
			break;
			
		case 'i':
			file=fopen(optarg,"r");
			if(file==NULL)
			{
				fclose(file);
				printf("Coudn\'t open %s\n", optarg);
				return 1;
			}
			icase(file);
			fclose(file);
			break;
			
		case '?':
			fputs("Try \'chase -h\' for help\n", stdout);
			return 1;
			
	}
	return 0;
}

void upcase(FILE* stream)
{
	char c;
	while((c=fgetc(stream))!=EOF)
	{
		printf("%c", c-(32*((c>96)&&(c<123))));
	}
	return;
}

void locase(FILE* stream)
{
	char c;
	while((c=fgetc(stream))!=EOF)
	{
		printf("%c", c+(32*((c>64)&&(c<91))));
	}
	return;
}

void icase(FILE* stream)
{
	char c;
	while((c=fgetc(stream))!=EOF)
	{
		printf("%c", c+(32*((c>64)&&(c<91)))-(32*((c>96)&&(c<123))));
	}
	return;
}

void printh(void)
{
	fputs("Usage: chase OPTION FILE\n", stdout);
	fputs("CHange cASE of the ASCII text file FILE and write it to stdout.\n", stdout);
	fputs("\n", stdout);
	fputs("Options:\n", stdout);
	fputs("\t-h\tdisplays this help and exits\n", stdout);
	fputs("\t-l\tchanges characters to lower case\n", stdout);
	fputs("\t-u\tchanges characters to upper case\n", stdout);
	fputs("\t-i\tinvert case of each character\n", stdout);
	return;
}

void printtryh(void)
{
	fputs("Try \'chase -h\' for help\n", stdout);
	return;
}
