#!/usr/bin/sh

if [ "$0" == "-sh" ]
then
    echo "This script must be executed not sourced."
    return
fi

# constants
DRIVE="/cygdrive/p"
ZOS="zos"
LINUX="linux"
STR_LOC="/cygdrive/q/STR/"
LOG="./data-compare_$(date +%y%m%d_%H%M).log"
COMP_LOG="$DRIVE/COMP_LOG"; export COMP_LOG

usage()
{
  echo "$0 [-n [[-d DATASET -s STRUCTURE]] -l Linux_datafile] [-f LIST] [-h]
where:
  -d Name of the z/OS DATASET
  -s The full path/name of the STRUCTURE file
  -l full path/name of output data file from Linux
  -f the path/name of the file that contains the list of [zOS_DATASET, STR_FILE, LINUX_FILE]
  -n convert only. Do not perform comparison with linux file. Ignores '-l'.
  -h help"
}

help()
{
  echo '
Top level script to compare z/OS output file/s with MicroFocus/Linux output file/s.
Uses:
* impcnv.sh
* compare.sh
Pre-requisits:
* Cygwin environment
* MicroFocus Net Express environment with MFA
* SimoTime comparison tools [SimoZAPS]
* Output file/s from Linux pre-copied in the specified directory
'
}

if [ $# -eq 0 ]
then
    usage
    exit -1
fi

LIST=""
STR_FILE=""
DATASET=""
CONV_ONLY="F"

while getopts "f:d:s:l:hn" opt
do
  case $opt in
    h) help; exit
    ;;
    f) LIST="$OPTARG"
    ;;
    s) STR_FILE="$OPTARG"
    ;;
    d) DATASET="$OPTARG"
    ;;
    l) LINUX_FILE="$OPTARG"
    ;;
    n) CONV_ONLY="T"
    ;;
  esac
done

if [ "$LIST" == "" ]
then
    if [ -z "$STR_FILE" ] || [ -z "$DATASET" ] || [ -z "LINUX_FILE" ] 
    then
       echo "Incorrect usage. see below."
       usage
       exit -1
    fi
fi

imp_conv()
{
  echo "DEBUG: ./impcnv.sh $DATASET $(cygpath -a -u $STR_LOC/$STR_FILE)" | tee -a "$LOG"

  ! [ -f "$DATASET" ] && ./impcnv.sh $DATASET $(cygpath -a -u "$STR_LOC/$STR_FILE")
  if [ $? -ne 0 ]
  then
    echo "The import & convert script returned error. Will now exit." | tee -a "$LOG"
    exit -1
  fi

  [ -f "$DATASET.ic.sh" ] && PRO_FILE=$(grep "mfdas *import" "$DATASET.ic.sh" | cut -d' ' -f4 | sed "s/'//g").cp.pro

  [ -f "$PRO_FILE" ] && CNVRTD_ASC=$(grep 'Output-File' "$PRO_FILE" | awk '{print $2}') && 
     $(mv "$CNVRTD_ASC" "$DRIVE/$ZOS/$CNVRTD_ASC")
}

compare()
{
  echo "DEBUG: Linux Output file name is $LINUX_FILE" | tee -a "$LOG"
  echo "DEBUG: converted ASCII file name is $CNVRTD_ASC" | tee -a "$LOG"

  if [ "$CONV_ONLY" == "T" ] 
  then
    echo "Convert only. Skipping compare." | tee -a "$LOG"
  else
    echo "DEBUG: ./compare.sh $DATASET $(cygpath -a "$DRIVE/$ZOS/$CNVRTD_ASC") \
        $(cygpath -a $DRIVE/$LINUX/$LINUX_FILE)" | tee -a "$LOG"
    echo "DEBUG: compare log will go to $COMP_LOG" | tee -a "$LOG"
    ./compare.sh $DATASET $(cygpath -a "$DRIVE/$ZOS/$CNVRTD_ASC") $(cygpath -a "$DRIVE/$LINUX/$LINUX_FILE")
  fi
}

if [ -s "$LIST" ]
then
  DELIM=","          #configurable
  while read line
  do
    DATASET=$(echo "$line" | cut -d$DELIM -f1 | sed 's/^ *//;s/ *$//')
    STR_FILE=$(echo "$line" | cut -d$DELIM -f2 | sed 's/^ *//;s/ *$//') 
    LINUX_FILE=$(echo "$line" | cut -d$DELIM -f3 | sed 's/^ *//;s/ *$//') 

    if [ ! -f "$DRIVE/$LINUX/$LINUX_FILE" ] || [ ! -f "$STR_LOC/$STR_FILE" ]
    then
       echo "Linux file or STR file not found. Skipping" | tee -a "LOG"
       continue
    fi
     
    imp_conv
    compare
  done < "$LIST"
else
  imp_conv
  compare
fi

exit 0

