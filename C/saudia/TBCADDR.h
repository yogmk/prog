# ifndef _TBCADDR_H_

# define _TBCADDR_H_

# include "typedefs.h"

typedef struct { */
    char CMPY[2];			/*  CHAR(2) */
    char LEDGR[2];			/*  CHAR(2) */
    char ACCT[12];			/*  CHAR(12) */
    short ADDR-NUM;  		/*  SMALLINT */
    char ADDR1[40];			/*  CHAR(40) */
    char ADDR2[40];			/*  CHAR(40) */
    char ADDR3[40];			/*  CHAR(40) */
    char ADDR4[40];			/*  CHAR(40) */
    char ADDR5[40];			/*  CHAR(40) */
    char ADDR6[40];			/*  CHAR(40) */
    char POST-CODE[10];		/*  CHAR(10) */
    char TEL[15];			/*  CHAR(15) */
    char TELEX[15];			/*  CHAR(15) */
    char FAX[15];			/*  CHAR(15) */
    char DSBLD;			/*  CHAR(1) */
    char UPDT-DATE[4]; 		/*  DATE */
    char UPDT-TIME[3];		/*  TIME */
    char UPDT-USR[8];		/*  CHAR(8) */
    char CRTE-DATE[4];		/*  DATE */
} TBCADDR_REC;


# endif
