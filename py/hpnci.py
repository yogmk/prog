import os
import sys
import string

def execute1(command):
    if(len(sys.argv)>2):
        args = string.join(sys.argv[2:])
    else:
        args = ''

    cin, cout ,cerr = os.popen3(command+' %s' % (args))


    while 1:
        text = cout.read()
        if text:
            print text
        else:
            break

    while 1:
        text = cerr.read()
        if text:
            print text
        else:
            break
    cin.close()
    cout.close()

if __name__ == '__main__':

    jy_classpath = ''
    if os.path.isfile('settings.py'):
        import settings
        jy_classpath=settings.getJythonClasspath()
    else:
        jy_classpath=os.getenv('HPNCI_PYTHON_JSERVER')
        if jy_classpath == None :
            print ' '
            print " Environment variable HPNCI_PYTHON_JSERVER is not set"
            raise SystemExit

    if len(sys.argv) <= 1 :
        print ' '
        print "Unknown number of arguments passed."
        raise SystemExit

    classpath='/opt/hp/jdbc/lib/hpt4jdbc.jar:/opt/apps/nci/lib/hpnci.jar:'+jy_classpath
    command = 'java -classpath '+ '"' + classpath + '"' + ' org.python.util.jython ' + sys.argv[1]
    execute1(command)

