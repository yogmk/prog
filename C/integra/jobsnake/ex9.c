# ident "get system time & format it un different ways!"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
//# include <sys/time.h>

int
main(int argc, char **argv)
{
	time_t t; 					/* seconds since epoch 	*/
	struct tm *now;				/* broken down time */
	
	static char *day[] = 
		{ "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	static char *mon[] = 
		{ "Jan", "Feb", "Mar", "Apr", "May", "Jun",
		  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	
	char **format = NULL;
	char **reformat = NULL;
	char * tok = NULL;
	char delim[] = ".-/:";
	int i=0, n=0;
	char response[100];

	t = time(NULL);
	if (argc == 1)
	/* user did not specify format, print default & return */
	{
		puts(ctime(&t));
		return 0;
	}

	/* otherwise parse the format & display accordingly */

	if ((tok = strtok(argv[1], delim)) != NULL)
	{ 
		format = malloc(5*sizeof(*format));
		if((format[i]=malloc(strlen(tok)+1)) != NULL)
			strcpy(format[i], tok);
	}
	
	for (i=1; tok; i++)
	{
		if ((tok = strtok(NULL, delim)) != NULL)
//			if (reformat = realloc(format, (i+1)*sizeof(*format)) != NULL)
//			{
//				format = reformat;
				if((format[i] = malloc(strlen(tok)+1)) != NULL)
					strcpy(format[i], tok);
//			}
	}

	now = localtime(&t);
    n = --i;
	response[0]='\0';
	for (i=0; i < n; i++)
	{
		if (strcmp(format[i], "YYYY")==0)
			sprintf(response+strlen(response), "%d ", now->tm_year+1900);
		else if (strcmp(format[i], "YY")==0)
			sprintf(response+strlen(response), "%d ", now->tm_year-100);	/* 2 digit year */
		else if (strcmp(format[i], "MON")==0)
			sprintf(response+strlen(response), "%s ", mon[now->tm_mon]);
		else if (strcmp(format[i], "MM")==0)
			sprintf(response+strlen(response), "%d ", now->tm_mon);
		else if (strcmp(format[i], "DDD")==0)
			sprintf(response+strlen(response), "%s ", day[now->tm_wday]);
		else if (strcmp(format[i], "DD")==0)
			sprintf(response+strlen(response), "%d ", now->tm_mday);
	}

	puts(response);
/*
	puts(day[now->tm_wday]);
	puts(mon[now->tm_mon]);
	printf("%d\n", now->tm_year+1900);
	printf("%d:%d:%d\n", now->tm_hour, now->tm_min, now->tm_sec);
	puts(now->tm_zone);
*/


	/* clean-up */
    for (i=0; i<n; i++)
		free(format[i]);
	free(format);
	return 0;
}
