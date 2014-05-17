#ifndef _OBJMAP_H_
# define _OBJMAP_H_

/**
 * This header stores all the objects definition.
 * Rules for supplying width are..
 * 1. DB2 SMALLINT is to be coded as 2 (bytes)
 * 2. DB2 INTEGER is to be coded as 4 (bytes)
 * 3. DB2 DECIMAL(p,s) is to be coded as (p,s). Program will calculate actual width in bytes.
 * 4. DB2 VARCHAR(n) is to be coded only as VARCHAR,n,0. You should *not* suppply the internal 
 *    length field separately as a SMALLINT.
 */

//#define NUM_OBJECTS 8

enum DATATYPE {
    E_CHAR = 0,
    E_DATE,
    E_TIME,
    E_VARCHAR,
    E_SMALLINT,
    E_INT,
    E_DECIMAL,
    E_SKIP,         /** to skip the field during processing*/
    E_ZONED         /** zoned decimal. pic s9(m)v9(n) usage display */
};

/** enum for length constants for each objects' input record. */
enum LENGTHS {
    L_OBJ24 = 359,
    L_OBJ33PL = 195,
    L_OBJ33BAL = 2981,
    L_OBJ53 = 366,
    L_OBJ60 = 273,
    L_OBJ67 = 410,
    L_INTRORD = 120,
    L_OBJ22OPN = 79,
    L_CCMAST = 71 
};

enum NO_FIELDS {
    N_OBJ24 = 16,
    N_OBJ33PL = 10,
    N_OBJ33BAL = 16,
    N_OBJ53 = 15,
    N_OBJ60 = 13,
    N_OBJ67 = 20,
    N_INTRORD = 14,
    N_OBJ22OPN = 12,
    N_CCMAST = 4
};

typedef struct {
    int datatype;  
    short width;
    short precision;
}FIELD;

char objects[][15] = { "OBJ24", "OBJ33PL" , "OBJ33BAL", "OBJ53", "OBJ67", "INTRORD" , "OBJ22OPN", "CCMAST", "OBJ60"};
int recLengths[] = {L_OBJ24, L_OBJ33PL, L_OBJ33BAL, L_OBJ53,  L_OBJ67, L_INTRORD, L_OBJ22OPN, L_CCMAST, L_OBJ60 };
int noFields[] = {N_OBJ24, N_OBJ33PL, N_OBJ33BAL, N_OBJ53,  N_OBJ67, N_INTRORD, N_OBJ22OPN, N_CCMAST , N_OBJ60};


/** Object22: Bank Open Items 
 *  M6-X6-ENTDAT, M6-X3-CURCOD, M6-X3-BATCH, M6-X6-SEQNO, M6-X2-JVNO,
 *  M6-X3-BANK, M6-S12V3-FORAMT, M6-S11V2-SRAMT, M6-X8-CHECKNO, M6-X2-ACTCOD,
 *  M6-X15-DESC, M6-X4-ACDT,
 */
const FIELD
struOBJ22OPN [] = {
                   {E_CHAR, 6,0}, {E_CHAR, 3,0}, {E_CHAR, 3,0}, {E_CHAR, 5,0}, {E_CHAR, 2,0},
                   {E_CHAR, 3,0}, {E_ZONED, 15,2}, {E_ZONED, 13,2}, {E_CHAR, 8,0}, {E_CHAR, 2,0},
                   {E_CHAR, 15,0}, {E_CHAR, 4,0},
                  };

/** Object 24: Vendor Masters 
 * VND_NO,           PTO_CNTRY,        PTO_NAME,         PTO_ADDR_1,       PTO_ADDR_2,       
 * PTO_ADDR_3,       PTO_ADDR_4,       PTO_CITY,         PTO_COUNTRY_STATE, PTO_POSTAL_CD,    
 * PTO_FAX_NO,       PTO_TELEX_NO,     PTO_CONT_NAME_1,  PTO_CONT_PHONE_1, PTO_CONT_PHONE_2, 
 * PTO_BNK_ACCT_NO   
 */ 
const FIELD 
struOBJ24 [] = { {E_CHAR,8,0}, {E_CHAR,15,0}, {E_CHAR,40,0}, {E_CHAR,40,0}, {E_CHAR,40,0}, 
                 {E_CHAR,40,0}, {E_CHAR,40,0}, {E_CHAR,3,0}, {E_CHAR,6,0}, {E_CHAR,9,0}, 
                 {E_CHAR,15,0}, {E_CHAR,15,0}, {E_CHAR,15,0}, {E_CHAR,15,0}, {E_CHAR,40,0}, 
                 {E_CHAR,18,0}
               };

/** object 33: GL Balances (P&L accounts)
 *  fin.tebnoml.type,      fin.tebacct.acct,      fin.tedtran.tran_date, fin.tedtran.input_date, fin.tedtran.btch_ref,  
 *  fin.tedtran.btch_num,  fin.tedtran.btch_type, fin.tedtran.fncl_val,  fin.tedtran.anal,      fin.tedtran.descv      
 */
const FIELD
struOBJ33PL [] = { {E_CHAR, 1,0}, {E_CHAR,50,0}, {E_CHAR,10,0}, {E_CHAR,10,0}, {E_CHAR,4,0},
                   {E_INT, 4,0}, {E_CHAR,4,0}, {E_DECIMAL ,15,2}, {E_VARCHAR,60,0}, {E_VARCHAR,40,0},
                 };


/** object 33: GL Balances (Balance Sheet)
 *  TYPE, ACCT
 *  'dummy', BALANCE_1, BALANCE_2, BALANCE_3,
 *  BALANCE_4, BALANCE_5, BALANCE_6, BALANCE_7,
 *  BALANCE_8, BALANCE_9, BALANCE_10, BALANCE_11,
 *  BALANCE_12, PER_BAL(remaining)
 */
const FIELD
struOBJ33BAL [] = {{E_CHAR, 1,0}, {E_CHAR, 50, 0}, /* {E_VARCHAR, 2928,0} */
                   {E_SKIP,2,0}, {E_DECIMAL, 15,2}, {E_DECIMAL, 15,2}, {E_DECIMAL, 15,2},
                   {E_DECIMAL, 15,2}, {E_DECIMAL, 15,2}, {E_DECIMAL, 15,2}, {E_DECIMAL, 15,2},
                   {E_DECIMAL, 15,2}, {E_DECIMAL, 15,2}, {E_DECIMAL, 15,2}, {E_DECIMAL, 15,2},
                   {E_DECIMAL, 15,2}, {E_CHAR, 2832, 0}
                  };


/** Object 53: (QSP) Customer masters 
 *  FIN.TBCCUST.LEDGR,     FIN.TBCCUST.NAME,      FIN.TBCCUST.SHORT_NAME, FIN.TBCADDR.ADDR1,     FIN.TBCADDR.ADDR2,     
 *  FIN.TBCADDR.ADDR3,     FIN.TBCADDR.ADDR4,     FIN.TBCADDR.ADDR5,     FIN.TBCADDR.ADDR6,     FIN.TBCADDR.POST_CODE, 
 *  FIN.TBCADDR.TEL,       FIN.TBCADDR.TELEX,     FIN.TBCADDR.FAX,       FIN.TBCCUST.ACCT,      FIN.TBCCUST.PYMNT_TRM  
 */
const FIELD 
struOBJ53 [] = { {E_CHAR,2,0},  {E_CHAR,40,0}, {E_CHAR,15,0}, {E_CHAR,40,0}, {E_CHAR,40,0},
                 {E_CHAR,40,0}, {E_CHAR,40,0}, {E_CHAR,40,0}, {E_CHAR,40,0}, {E_CHAR,10,0}, 
                 {E_CHAR,15,0}, {E_CHAR,15,0}, {E_CHAR,15,0}, {E_CHAR,12,0}, {E_CHAR,2,0}
               };

/** Object 60: QSP SI open invoiced but no billed 
 *  FIN.TODDOC.TAX_DATE,   FIN.TODDOC.DOC_TYPE,  FIN.TODDOC.TRAN_DATE, FIN.TODDOC.GL_PER,    FIN.TODDOC.CURR,      
 *  FIN.TODDOC.DOC,        FIN.TODDOC.ACCT,      FIN.TODDOC.GROSS_VAL, FIN.TODDOCL.ITEM,     FIN.TODDOCL.GL_ANAL,  
 *  FIN.TODDOCL.CUST_ITEM, FIN.TODDOC.USR_DATA,  FIN.TODDOCL.PRC       
 */
const FIELD
struOBJ60 [] = {{E_CHAR, 10, 0}, {E_CHAR, 2,0}, {E_CHAR, 10,0}, {E_SMALLINT, 2, 0}, {E_CHAR, 3, 0},
                {E_CHAR, 16, 0}, {E_CHAR, 12, 0}, {E_DECIMAL, 15, 2}, {E_CHAR, 20, 0}, {E_CHAR, 60, 0},
                {E_CHAR, 20, 0}, {E_VARCHAR, 100, 0}, {E_DECIMAL, 15, 5}
               };

/** Object 67: Fixed Asset Master 
 *  FIN.TFDASST.DESCR,          FIN.TFDASST.SER_REG_NUM,    FIN.TFDASST.USR_ASSET_NUM,  FIN.TFDASST.DATE_OF_ACQ,    FIN.TFMDISPL.DATE_SALE,     
 *  'dummy',                    FIN-273_DATE,               FIN.TFDASSTU.USR_DATA1 (remaining, 5th byte onwards),
 *  FIN.TFDASST.DEPT,           FIN.TFDASST.LOCTN,          FIN.TFDASST.ASSET_FUNC,     FIN.TFDASST.ASSET,          FIN.TFDASST.GRP,
 *  FIN.TFDASST.CATEG,          FIN.TFDASST.PURCH_PRC,      FIN.TFEVALN.MTHD,           FIN.TFEVALN.EXP_LIFE_IN_PER,FIN.TFEVALN.DEPN_PRIOR_YY,
 *  FIN.TFEVALN.DEPN_CURNT_YY,  fin.tfdasst.mgmt_code       
 */
const FIELD 
struOBJ67 [] = { {E_CHAR,40,0}, {E_CHAR,20,0}, {E_CHAR,10,0}, {E_CHAR,10,0}, {E_CHAR,10,0},
               /** Special case: TFDASSTU.USR_DATA1 (VARCHAR 240) stores in firt 4 bytes, date in packed-decimal */
                 {E_SKIP,2,0}, {E_DECIMAL,8,0}, {E_CHAR,236,0}, 
                 {E_CHAR,4,0}, {E_CHAR,8,0}, {E_CHAR,2,0}, {E_CHAR,10,0}, {E_CHAR,2,0}, 
                 {E_CHAR,3,0}, {E_DECIMAL,15,2}, {E_CHAR,3,0}, {E_SMALLINT,2,0}, {E_DECIMAL,15,2}, 
                 {E_DECIMAL,15,2}, {E_CHAR,20,0}
               }; 

/** Internal Work Orders 
 *  REC_TYPE,  PROJ_TITLE,  COST_CENTRE,  LOCATION,  WORK_ORDER,
 *  COM_STATUS,  PAY_STATUS,  CORD_NAME,  APPROVAL_YR,  CORD_TEL,
 *  DIV_CODE,  CO_CORD_TEL,  ORI_YEAR,  TOTAL_APPROVD_AMT
 */
const FIELD
struINTRORD [] = {{E_CHAR, 1,0}, {E_CHAR, 36,0}, {E_CHAR, 3,0}, {E_CHAR, 3,0}, {E_CHAR, 5,0},
                  {E_CHAR, 1,0}, {E_CHAR, 1,0}, {E_CHAR, 36,0}, {E_CHAR, 6,0}, {E_CHAR, 7,0},
                  {E_CHAR, 1,0}, {E_CHAR, 7,0}, {E_CHAR, 6,0}, {E_DECIMAL, 13,0}
                 };

/** Cost centre Master data 
 *  FIN.TFCC.CC_NBR, FIN.TFCCLOC.LOC_NBR, FIN.TFCC.CC_NM, FIN.TLOC.LOC_ENG_NAME
 */
const FIELD
struCCMAST [] = {{E_CHAR, 3, 0}, {E_CHAR, 3, 0}, {E_CHAR, 35, 0}, {E_CHAR, 30, 0} };

FIELD *objectArray[] = {struOBJ24, struOBJ33PL, struOBJ33BAL, struOBJ53, struOBJ67, struINTRORD, struOBJ22OPN, struCCMAST, struOBJ60}; 

#endif

