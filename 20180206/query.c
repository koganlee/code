#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if( argc != 2)
	{
        printf("Error args\n");
		return -1;
	}
    MYSQL * con;
	MYSQL_RES *res;
	MYSQL_ROW row;

	char *server = "neverland";
	char *user = "root";
	char *password = "likemj0829";
	char *database = "worker";
	char query[300] = "'select * from Worker'";

	sprintf(query, "%s%s%s", query,argv[1], "'");
	strcpy(query, "select * from worker");
	puts(query);

	int t, r;
	con = mysql_init(NULL);
	if(!mysql_real_connect(con, server, user, password, database, 0, NULL, 0))
	{
		printf("Error connecting to database:%s\n", mysql_error(con));
	}
	else
	{
		printf("Connected...\n");
	}
	t = mysql_query(con, query);
	if( t )
	{
		printf("Error making query: %s\n", mysql_error(con));
	}
	else
	{
		res = mysql_use_result(con);
		if(res)
		{
			while((row = mysql_fetch_row(res)) != NULL)
			{
				for(t = 0; t < mysql_num_fields(res); t++)
				{
					printf("%8s", row[t]);
				}
				printf("\n");
			}
		}
		mysql_free_result(res);
	}
	mysql_close(con);
	return 0;
}
