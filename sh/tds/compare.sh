#!/usr/bin/sh

if [ $# -ne 3 ]
then
  echo "Usage: $0 <Data-Set-Name> <Absolute-PATH-Data-Set-Name1> <Absolute-PATH-Data-Set-Name2>"
  exit
fi

export PATH="/cygdrive/c/Program Files/Micro Focus/Mainframe Access/Bin":$PATH

#---------------------------------------------
# Generate catdcb output and save it in a file.
#---------------------------------------------

#mfdas catdcb $1 > dcbinfo.txt    #yogesh 1.9.2011 we do this in impcnv

#Validating the dcbinfo.txt
val=`grep -i "Invalid" ./dcbinfo.txt | wc -l`   #added ./

if [ $val -gt 0 ]
then
  echo " DCB information of the $1 Invalid!!! ";
  echo " Check the Data Set Name given ";
  exit
fi

#--------------------------------------------
# Generate Specification file
#-------------------------------------------

perl ./gen-cntl.pl ./dcbinfo.txt         #added ./

#-------------------------------------------
cd /cygdrive/c/SimoLIBR/
export PATH="/cygdrive/c/Program Files/Micro Focus/Studio Enterprise Edition 6.0/Base/Bin":$PATH

echo "***************************************************";
echo "**** Generating COBOL program for Comparision ****";
echo "***************************************************";

./ZapsCOMP.CMD "$(cygpath -w /usr/tmp/SYSCNTL.txt)" SYSCOBOL.cbl SYSUT3

#-------------------------------------------
# Identifying if its a variable or Fixed
#------------------------------------------

#value=`grep -i "VARIABLE" "$(cygpath -w /usr/tmp/SYSCNTL.txt)" | wc -l`
#checkvsam=`grep -i "INDEXED" "$(cygpath -w /usr/tmp/SYSCNTL.txt)" | wc -l`
#if [ $checkvsam -gt 0 ]
#then
#	value=0;
#fi
#
#case $value in
#  1|2) echo " Inserting RECORDING MODE IS V in COBOL program generated "
#    ;; #./add-rmv "SYSCOBOL.cbl" ;;
#  0) echo " Proceeding with Compilation......... " ;;
#  *) echo " Invalid Choice ";
#esac

#--------------------------------
# Compile the generated Cobol File
#---------------------------------

CBLLINK -UDEFAULT.DIR SYSCOBOL.cbl

#------------------
# Run the cobol exe
#------------------

file1=$(cygpath -m $2)
file2=$(cygpath -m $3)
export ITCOMPD1="$file1"
export ITCOMPD2="$file2"
COMP_LOG=${COMP_LOG:="./COMP_LOG"}          #did $COMP_LOG propagate from the parent shell?
if [ ! -d "./$COMP_LOG" ]; then
    mkdir "$COMP_LOG"
fi
run SYSCOBOL > "./$COMP_LOG/$1_compare.log"

#clean up
#rm SYSCOBOL*
