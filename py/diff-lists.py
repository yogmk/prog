#!/usr/bin/env python

included_hdrs_list = "./all-unq-hdrs.list"
found_hdrs_list = "./all-hdrs-found.list"

fi = open(included_hdrs_list, 'r')
included_hdrs = fi.readlines()
fi.close()


ff = open(found_hdrs_list, 'r')
found_hdrs = ff.readlines()
ff.close()

# Headers declared/used in code, but not found on the drive
#diff_list = [hdr for hdr in included_hdrs if hdr not in found_hdrs]

# Headers dumped on the drive, but not used anywhere in code (extra to be ignored)
diff_list = [hdr for hdr in found_hdrs if hdr not in included_hdrs]

for h in diff_list:
    print h
