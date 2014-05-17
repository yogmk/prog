import sys

def main():
    if sys.argv[1] is none:
        print ("script requires one argument")
    else:
        print (exc(argv[1]))


def exc (param):
    if param == "" :
        return none
    else:
        return eval(param)

if __name__ == "__main__":
    main()
    