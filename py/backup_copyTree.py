"""
 Pycopytree 
  Backs up source to destination
 
 - creates directories/subdirectories in destination location if they don't exist
 - if file/directory already exists in destination it will only be overwritten 
    if its modification date is different to the source file
 - checks for unneccessary files/directories in destination and deletes if not required
    
Author Bruce Dockeray
Date   Oct 05 
 
"""

import shutil
import os,os.path
from stat import *

def ModifiedDate(file1):
    'purpose is to report date file last modified  '
    stats=os.stat(file1)
    #print "stats are",file1,stats[8]
    modified=stats[8]
    
    #modified=os.stat(file1)[ST_MTIME]

    return modified


            
def Pycopytree(src, dst, symlinks=0):
    names = os.listdir(src)
    #listdir(      path)
    #Return a list containing the names of the entries in the directory. 
    #The list is in arbitrary order. It does not include the special entries '.' and '..' 
    #even if they are present in the directory. Availability: Macintosh, Unix, Windows.
    if not os.path.isdir(dst):
        os.mkdir(dst)
    # makes new directories in destination only if needed
    for name in names:
        # file from / file to
        srcname = os.path.join(src, name)
        dstname = os.path.join(dst, name)
        try:
            if os.path.isdir(srcname): # if the reference is a directory then recursively function calls itself
                Pycopytree(srcname, dstname)
            else:
                # does the file already exist in the destination
                if not os.path.isfile(dstname):
                    # ok we now know the file doesn't exist in destination directory so must copy
                    print "file doesn't exist .. backing up %s to the selected backup directory" % (dstname)
                    shutil.copy2(srcname, dstname)
                else:
                    # the else condition here picks up where the destination file exists
                    # now we want to establish if the modification date is different
                    if ModifiedDate(srcname)!= ModifiedDate(dstname):
                         print "file has changed hence .. backing up %s to the selected backup directory" % (dstname)
                         shutil.copy2(srcname, dstname)
        except (IOError, os.error), why:
            print "Can't copy %s to %s: %s" % (`srcname`, `dstname`, str(why))
            
def PyTidyUpDestination (src, dst, symlinks=0):
    names = os.listdir(dst)
    if not os.path.isdir(src):
        try:
            print "directory %s Not needed  - deleting  " % (dst)
            shutil.rmtree(dst)
        except:
            print "directory %s not Deleted" % (dst)
    for name in names:
        # 
        srcname = os.path.join(src, name)
        dstname = os.path.join(dst, name)
        try:
            if os.path.isdir(dstname): # if the reference is a directory then recursively function calls itself
                PyTidyUpDestination(srcname, dstname)
            else:
                pass
                # does the file already exist in the destination but not source ?
                if not os.path.isfile(srcname):
                    # check first to make sure it is still there & then delete
                    if os.path.isfile(dstname):
                        print "file in backup directory which isn't needed .. deleting %s " % (dstname)
                        os.remove(dstname)
                else:
                    pass
        except (IOError, os.error), why:
            print IOError
            #print "Synchronisation tidy up problems encountered  %s : %s" % ( `dstname`, str(why))

if __name__=='__main__':
    # 
    dest='c:/temp/'
    src='c:/xpdf/'
    Pycopytree(src,dest)
    PyTidyUpDestination(src,dest)
    #PyCleanUp(src,dest)
    #

