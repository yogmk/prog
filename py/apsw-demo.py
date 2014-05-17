import os, sys, time
import apsw


print "using APSW file: ", apsw.__file__
print "APSW version: ", apsw.apswversion()
print "SQLite version: ", apsw.sqlitelibversion()
print "SQLite header version: ", apsw.SQLITE_VERSION_NUMBER


connection = apsw.Connection("yogeshmk.db")
cursor = connection.cursor()

cursor.execute("create table tt (a, b, c)")

cursor.execute("insert into tt values (?, ?, ?)", (1, 1.1, None))    # int, float, NULL
cursor.execute("insert into tt (a) values(?)", ("abc",))             # single element tuple
cursor.execute("insert into tt (a) values(?)", (buffer("abc\xff\xfe"), ))

# multiple statements
cursor.execute("delete from tt; insert into tt values(1,2,3); create table bar(a,b,c) ; insert into tt values(4, 'five', 6.0)")


# iterator

for a, b, c in cursor.execute("select a, b, c from tt"):
    print cursor.getdescription()           # show column names and datatypes
    print a, b, c


cursor.execute("insert into tt (:aplha, :beta, :gamma)", {'beta': 2, 'aplha':1, 'gamma':3})
cursor.execute("insert into tt values (?, ?, ?99)", ('one', 'two'))

