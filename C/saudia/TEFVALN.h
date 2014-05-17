typedef struct {
char CMPY[ ];		/* CMPY */
char ASSET[10];		/* CHAR(10) */
char VER;		/* SMALLINT */
char BOOK;		/* CHAR(1) */
char SEQ;		/* SMALLINT */
char EFF-DATE[ ];		/* DATE */
char TRAN-REF[ ];		/* INTEGER */
char VALN-TYPE[2];		/* CHAR(2) */
char VALN-AMT[ ];		/* DECIMAL(15,2) */
char DEPN-PROV[ ];		/* DECIMAL(15,2) */
char RSDL-VAL[ ];		/* DECIMAL(15,2) */
char MTHD[3];		/* CHAR(3) */
char DEPN-RATE[ ];		/* DECIMAL(11,7) */
char DEPN-STRT-DATE[ ];		/* DATE */
char DEPN-STRT-YY[ ];		/* SMALLINT */
char DEPN-STRT-PER[ ];		/* SMALLINT */
char DEPN-END-DATE[ ];		/* DATE */
char DEPN-LAST-PER[ ];		/* DECIMAL(15,2) */
char DEPN-CURNT-YY[ ];		/* DECIMAL(15,2) */
char DEPN-PRIOR-YY[ ];		/* DECIMAL(15,2) */
char DEPN-LAST-YY[ ];		/* DECIMAL(15,2) */
char EXP-LIFE-IN-PER[ ];		/* SMALLINT */
char REM-LIFE-IN-PER[ ];		/* SMALLINT */
char REPL-VAL[ ];		/* DECIMAL(15,2) */
char INSUR-VAL[ ];		/* DECIMAL(15,2) */
char INSUR-PREM[ ];		/* DECIMAL(15,2) */
char CASH-ACQ-FLAG[ ];		/* FLAG */
char CPTL-RSRVS[ ];		/* DECIMAL(15,2) */
char CRTE-YY[ ];		/* SMALLINT */
char CRTE-PER[ ];		/* SMALLINT */
char INIT-STRT-YY[ ];		/* SMALLINT */
char INIT-STRT-PER[ ];		/* SMALLINT */
char INIT-LIFE-IN-PER[ ];		/* SMALLINT */
char INIT-DEPN-CURNT-YY[ ];		/* DECIMAL(15,2) */
char INIT-DEPN-PRIOR-YY[ ];		/* DECIMAL(15,2) */
char CRTE-USR[8];		/* CHAR(8) */
char CRTE-DATE[ ];		/* DATE */
char CRTE-TIME[ ];		/* TIME */
char LENQ-DATA[ ];		/* VARCHAR(80) */
} TDFVALN_REC;
