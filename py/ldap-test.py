import sys, ldap

host = 'ldap://ldap.hp.com:389'
base = 'o=hp.com'
scope = ldap.SCOPE_SUBTREE
#scope=''

filter = ('(uid=ymk@hp.com)')
attrs = ['cn', 'mail', 'uid']

l = ldap.initialize(host)
r = l.search_s (base, scope, filter, attrs)

for dn, entry in r:
    print 'dn=', repr(dn)

    for k in entry.keys():
        print '\t', k, '=', entry[k]

sys.exit(0)

