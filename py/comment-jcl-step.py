#!/usr/bin/python

banner = "//*             **QMF step detected - GDOL replace please**              DELLins";

def comment_line(line):
    _line = ("//*" + line[2:71].rstrip('\n')).ljust(72) + "DELLdel".rjust(8)
    return _line;


def main(jcl):
    inStep = False
    import re
    with open(jcl) as f:
        for line in f:
             if re.search(" EXEC ", line) :                    # a step has EXEC
                 if re.search(" EXEC +QMFPROC[,]?", line) :    # is this a QMF step?
                     print "Line matched RegEx"
                     inStep = True
                     print banner
                     print "%s" % comment_line(line)
                 else:                                  # not a step we want
                     inStep = False
                     print line
             elif inStep:
                 print "%s" % comment_line(line)
             elif not inStep:
                 #print line.rstrip('\n')
                 sys.stdout.write(line)


if __name__ == "__main__":
  import sys
  if len(sys.argv) < 2:
    print "Need one argument (Name of JCL)"
    exit
  else:
    import os.path
    if not os.path.exists(sys.argv[1]):
      print "Could not find: %s" % sys.argv[1]

    main(sys.argv[1])

# --end--
