import os, sys
import sqlite3.dbapi2


conn = sqlite3.dbapi2.Connection (':memory:')

curs = conn.cursor()

curs.execute ("create table t1 (id integer primary key, name varchar(50), email varchar(50))")

curs.execute ('insert into t1 values (null, "yogesh kul", "ymk@hp.com")')
curs.execute ('insert into t1 values (null, "b debasis", "deb@hp.com")')

print curs.lastrowid

conn.commit()

curs.execute ('insert into t1 values (null, "bheem subba", "sub@hp.com")')
conn.rollback()

