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


enum DATATYPE {
    E_CHAR = 0,
    E_DATE,
    E_TIME,
    E_VARCHAR,
    E_SMALLINT,
    E_INT,
    E_DECIMAL,
    E_SKIP,         /** to skip the field during processing*/
    E_ZONED         /** zoned decimal. pic s9(m)v9(n) display */
};

/** enum for length constants for each objects' input record. */
enum LENGTHS {
    L_OBJ22OPN = 79,
    L_OBJ24 = 359,
    L_OBJ33PL = 193,
    L_OBJ33BAL = 2981,
    L_OBJ53 = 366,
    L_OBJ67 = 410,
    L_INTRORD = 120,
    L_CCMAST = 71 
};

typedef struct {
    int datatype;  
    short width;
    short precision;
}FIELD;

/** Object22: Bank Open Items */
const FIELD
struOBJ22OPN [] = {
                   {E_CHAR, 6,0}, {E_CHAR, 3,0}, {E_CHAR, 3,0}, {E_CHAR, 5,0}, {E_CHAR, 2,0},
                   {E_CHAR, 3,0}, {E_ZONED, 15,2}, {E_ZONED, 13,2}, {E_CHAR, 8,0}, {E_CHAR, 2,0},
                   {E_CHAR, 15,0}, {E_CHAR, 4,0},
                  };

/** Object 24: Vendor Masters */
const FIELD 
struOBJ24 [] = { {E_CHAR,8,0}, {E_CHAR,15,0}, {E_CHAR,40,0}, {E_CHAR,40,0}, {E_CHAR,40,0}, 
                 {E_CHAR,40,0}, {E_CHAR,40,0}, {E_CHAR,3,0}, {E_CHAR,6,0}, {E_CHAR,9,0}, 
                 {E_CHAR,15,0}, {E_CHAR,15,0}, {E_CHAR,15,0}, {E_CHAR,15,0}, {E_CHAR,40,0}, 
                 {E_CHAR,18,0}
               };

/** object 33: P&L accounts */
const FIELD
struOBJ33PL [] = { {E_CHAR, 1,0}, {E_CHAR,50,0}, {E_CHAR,10,0}, {E_CHAR,10,0}, {E_CHAR,4,0},
                   {E_SMALLINT,2,0}, {E_CHAR,4,0}, {E_DECIMAL ,15,2}, {E_VARCHAR,60,0}, {E_VARCHAR,40,0},
                 };


/** object 33: GL Balances */
const FIELD
struOBJ33BAL [] = {{E_CHAR, 1,0}, {E_CHAR, 50, 0}, /* {E_VARCHAR, 2928,0} */
                   {E_SKIP,2,0}, {E_DECIMAL, 15,2},{E_DECIMAL, 15,2},{E_DECIMAL, 15,2},
                   {E_DECIMAL, 15,2},{E_DECIMAL, 15,2},{E_DECIMAL, 15,2},{E_DECIMAL, 15,2},
                   {E_DECIMAL, 15,2},{E_DECIMAL, 15,2},{E_DECIMAL, 15,2},{E_DECIMAL, 15,2},
                   {E_DECIMAL, 15,2}, {E_CHAR, 2832, 0}
                  };


/** Object 53: Customer masters */
const FIELD 
struOBJ53 [] = { {E_CHAR,2,0},  {E_CHAR,40,0}, {E_CHAR,15,0}, {E_CHAR,40,0}, {E_CHAR,40,0},
                 {E_CHAR,40,0}, {E_CHAR,40,0}, {E_CHAR,40,0}, {E_CHAR,40,0}, {E_CHAR,10,0}, 
                 {E_CHAR,15,0}, {E_CHAR,15,0}, {E_CHAR,15,0}, {E_CHAR,12,0}, {E_CHAR,2,0}
               };

/** Object 67: Fixed Asset Master */
const FIELD 
struOBJ67 [] = { {E_CHAR,40,0}, {E_CHAR,20,0}, {E_CHAR,10,0}, {E_CHAR,10,0}, {E_CHAR,10,0},
               /** Special case: TFDASSTU.USR_DATA1 (VARCHAR 240) stores in firt 4 bytes, date in packed-decimal */
                 {E_SKIP,2,0},     
                 {E_DECIMAL,8,0},
                 {E_CHAR,236,0}, {E_CHAR,4,0}, {E_CHAR,8,0}, {E_CHAR,2,0},
                 {E_CHAR,10,0}, {E_CHAR,2,0}, {E_CHAR,3,0}, {E_DECIMAL,15,2}, {E_CHAR,3,0},
                 {E_SMALLINT,2,0}, {E_DECIMAL,15,2}, {E_DECIMAL,15,2}, {E_CHAR,20,0}
               }; 

/** Intrnal Work Orders */
const FIELD
struINTRORD [] = {{E_CHAR, 1,0},{E_CHAR, 36,0},{E_CHAR, 3,0},{E_CHAR, 3,0},{E_CHAR, 5,0},
                  {E_CHAR, 1,0},{E_CHAR, 1,0},{E_CHAR, 36,0},{E_CHAR, 6,0},{E_CHAR, 7,0},
                  {E_CHAR, 1,0},{E_CHAR, 7,0},{E_CHAR, 6,0},{E_DECIMAL, 13,0}
                 };

/** Cost centre Master data */
const FIELD
struCCMAST [] = {{E_CHAR, 3, 0},{E_CHAR, 3, 0},{E_CHAR, 35, 0},{E_CHAR, 30, 0} };

#endif

