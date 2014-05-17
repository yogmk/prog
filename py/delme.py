if __name__ == "__main__":
    import os, sys
    
    if os.environ.has_key("LANG"):
        print "lang is set to %s" % os.environ.get("LANG")