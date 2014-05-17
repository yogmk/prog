# include <stdio.h>
# include <stdlib.h>

# include <sqlite3.h>


static int
callback (void* NotUsed, int argc, char** argv, char** ColName)
{
    int i=0;
    for (i-0; i < argc; i++)
    {
        printf ("%s = %s\n", ColName[i], argv[i] ? argv[i] : "NULL");
    }
    putchar ('\n');

    return 0;
}



int
main (int c, char** v)
{
    sqlite3* db = NULL;
    char* errmsg = 0;
    int rc = 0;


    if (c != 3) {
        fprintf (stderr, "usage: %s DATABASE SQL-STATEMENT\n", v[0]);
        exit (1);
    }

    if ((rc = sqlite3_open (v[1], db)) != 0)
    {
        fprintf (stderr, "couldn't open database %s. Error was: %s\n", v[1], sqlite3_errmsg(db));
        sqlite3_close (db);
        exit (1);
    }

    if ((rc = sqlite3_exec (db, v[2], callback, 0, &errmsg)) != SQLITE_OK)
    {
        fprintf (stderr, "SQL error: %s\n", errmsg);
        sqlite3_free (errmsg);
    }
    sqlite3_close (db);
    return 0;
}
