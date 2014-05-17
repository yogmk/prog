function createProfileAndImportAndConvertScript
{
    #mfdasOutFile=`awk 'BEGIN {printf("/tmp/mfdas.out.%d.%d.tmp", PROCINFO["uid"], PROCINFO["ppid"])}'`;
    mfdasOutFile=`awk 'BEGIN {printf("./dcbinfo.txt", PROCINFO["uid"], PROCINFO["ppid"])}'`;
    >${mfdasOutFile} mfdas catdcb ${input}

    if [ $? -eq 0 ]
    then
        awk -v input=${input} -v strFile=${strFile} --re-interval -F, '
        function quote(str)
        {
            SINGLE_QUOTE = 0x27;
            return(sprintf("%c%s%c", SINGLE_QUOTE, str, SINGLE_QUOTE));
        }
    
        function trim(str)
        {
            return(gensub("(^  *|  *$)", "", "1", str));
        }
    
        function insertQualifier(dsName, dsOrg, qualifier)
        {
            if (dsName ~ /^.*[.]G[0-9]{4}V[0-9]{2}/)
            {
                memberName = gensub("[.]G[0-9]{4}V[0-9]{2}$", "", "1", dsName);
                generation = gensub("^.*[.]", "", "1", dsName);
                qualifiedName = sprintf("%s.%s.%s", memberName, qualifier, generation);
            }
            else
            {
                qualifiedName = sprintf("%s.%s", dsName, qualifier);
                if (dsOrg == "KSDS")
                    qualifiedName = sprintf("%s.%s", qualifiedName, "DAT");    
            }
    
            return(qualifiedName);
        }
    
        function createProfile(ebcFileName, ascFileName, dsOrg, recFm, minRecLength, maxRecLength, keyPosition, keyLength)
        {

            printf("") > profile;
    
            printf("DataTools Profile Version  V09.B02.05\n") >> profile;
            printf("\n") >> profile;
            printf("Batch-Process: Convert-file\n") >> profile;
            printf("                   ***************************************************\n") >> profile;
            printf("                   *           <Twin>                  <Single>      *\n") >> profile;
            printf("                   * Options:  Convert-File            Rebuild-index *\n") >> profile;
            printf("                   *           Rebuild-index-and-data  None          *\n") >> profile;
            printf("                   ***************************************************\n") >> profile;
            printf("Strt-file:              %s\n", ((strFile ~ /^$/) ? "No-structure" : strFile)) >> profile;
            printf("Edit-Mode:     Full\n") >> profile;
            printf("                   * Options:  Quick/Full                            *\n") >> profile;
            printf("--------------------------------------------------------------------------------\n") >> profile;
            printf("Input-File     %s\n", ebcFileName) >> profile;
            printf("   Format:         Micro-Focus\n") >> profile;
            printf("                       * Options:  Micro-Focus         IDXFORMAT(4)  *\n") >> profile;
            printf("                       *           Btrieve             C-ISAM        *\n") >> profile;
            printf("                       *           LEVEL-II            ESDS          *\n") >> profile;
            printf("   Organization:   %s\n", dsOrg) >> profile;
            printf("                       * Options:  Sequential  Line-Sequential       *\n") >> profile;
            printf("                       *           Indexed     Mainframe-Report-ANSI *\n") >> profile;
            printf("                       *           Relative    Mainframe-Report-mach *\n") >> profile;
            printf("                       *           VRECGEN     PC-Print              *\n") >> profile;
            printf("   Record-Format:  %s\n", recFm) >> profile;
            printf("                       * Options:  Fixed/Variable                    *\n") >> profile;
            printf("   Character-Set:  EBCDIC\n") >> profile;
            printf("                       * Options:  ASCII/EBCDIC                      *\n") >> profile;
            printf("   Floating-Point: 370\n") >> profile;
            printf("                       * Options:  IEEE/370                          *\n") >> profile;
            printf("   Compression:    Off\n") >> profile;
            printf("                       * Options:  On/Off                            *\n") >> profile;
            printf("   Min-Rec-Length: %05d\n", minRecLength) >> profile;
            printf("   Max-Rec-Length: %05d\n", maxRecLength) >> profile;

            if (dsOrg == "Indexed")
            {
                printf("                       * Key to settings                             *\n") >> profile;
                printf("                       *       d=      allow duplicates              *\n") >> profile;
                printf("                       *       s=      sparse character set          *\n") >> profile;
                printf("                       *       Compression                           *\n") >> profile;
                printf("                       *           cd= on duplicates                 *\n") >> profile;
                printf("                       *           cl= on leading spaces             *\n") >> profile;
                printf("                       *           ct= on trailing spaces            *\n") >> profile;
                printf("   Prime-key :   %05d:%05d\n", keyPosition, keyLength) >> profile;
            }

            printf("--------------------------------------------------------------------------------\n") >> profile;
            printf("\n") >> profile;

            printf("Output-File    %s\n", ascFileName) >> profile;
            printf("   Format:         Micro-Focus\n") >> profile;
            printf("   Organization:   %s\n", dsOrg) >> profile;
            printf("   Record-Format:  %s\n", recFm) >> profile;
            printf("   Character-Set:  ASCII\n") >> profile;
            printf("   Floating-Point: 370\n") >> profile;
            printf("   Compression:    Off\n") >> profile;
            printf("   Min-Rec-Length: %05d\n", minRecLength) >> profile;
            printf("   Max-Rec-Length: %05d\n", maxRecLength) >> profile;
    
            if (dsOrg == "Indexed")
            {
                printf("                       * Key to settings                             *\n") >> profile;
                printf("                       *       d=      allow duplicates              *\n") >> profile;
                printf("                       *       s=      sparse character set          *\n") >> profile;
                printf("                       *       Compression                           *\n") >> profile;
                printf("                       *           cd= on duplicates                 *\n") >> profile;
                printf("                       *           cl= on leading spaces             *\n") >> profile;
                printf("                       *           ct= on trailing spaces            *\n") >> profile;
                printf("   Prime-key :   %05d:%05d\n", keyPosition, keyLength) >> profile;
            }
        }

        function createImportConvertScript(importConvertScript, input, profile, importCmd)
        {
            printf("\nrm -f %s.err\n", input) >> importConvertScript;
            printf("echo - Importing %s ...\n", input) >> importConvertScript;
            printf("%s\n", importCmd) >> importConvertScript;
            printf("if [ ${returnCode} -eq 0 ]\n") >> importConvertScript;
            printf("then\n") >> importConvertScript;
            printf("    echo - Converting %s ...\n", input) >> importConvertScript;
            printf("    run dfconv %s; returnCode=$?\n", profile) >> importConvertScript;
            printf("    if [ ${returnCode} -ne 0 ]\n") >> importConvertScript;
            printf("    then\n") >> importConvertScript;
            printf("        echo - Converting failed for [%s] with: [${returnCode}] | tee %s.err\n", input, input) >> importConvertScript;
            printf("    fi\n") >> importConvertScript;
            printf("else\n") >> importConvertScript;
            printf("    echo - Importing failed for [%s] with: [${returnCode}] | tee %s.err\n", input, input) >> importConvertScript;
            printf("fi\n") >> importConvertScript;
        }
    
        BEGIN {
            memberPattern = sprintf("^Name=%s *$", input);
            gdgPattern = sprintf("^Name=%s.G[0-9]{4}V[0-9]{2} *$", input);
            importConvertScript = sprintf("%s.ic.sh", input);
            processingFailed = 0;
    
            printf("export PATH=\"/cygdrive/c/Program Files/Micro Focus/Studio Enterprise Edition 6.0/Base/Bin\":$PATH\n") > importConvertScript;
        }
    
        {
            if ($1 ~ memberPattern || $1 ~ gdgPattern)
            {
                fileName = trim(gensub(".*=", "", "1", $1));
                dsOrg = trim(gensub(".*=", "", "1", $3));
                recFm = trim(gensub(".*=", "", "1", $4));
                recl = int(trim(gensub(".*=", "", "1", $6)));
                averageRecl = int(trim(gensub(".*=", "", "1", $7)));
                maxRecl = int(trim(gensub(".*=", "", "1", $8)));
                keyPosition = int(trim(gensub(".*=", "", "1", $9)));
                keyLength = int(trim(gensub(".*=", "", "1", $10)));
    
                ebcFileName = insertQualifier(fileName, dsOrg, "EBC");
                ascFileName = insertQualifier(fileName, dsOrg, "ASC");

                profile = sprintf("%s.cp.pro", ebcFileName);
    
                switch (dsOrg)
                {
                case "QSAM":
                    dsOrgForProfile = "Sequential";
    
                    switch (recFm)
                    {
                    case "FB":
                    case "FBA":
                        recFmForProfile = "Fixed";
                        minRecLength = recl;
                        maxRecLength = recl;
                        break;
    
                    case "VB":
                    case "VBA":
                        recFmForProfile = "Variable";
                        minRecLength = 0;
                        maxRecLength = recl - 4;
                        break;
    
                    default:
                        printf("Unexpected transfer of control to default case in switch - 1\n") > "/dev/stderr";
                        processingFailed++;
                    }
    
                    importCmd = sprintf("mfdas import binary %s from qsam %s; returnCode=$?\n", quote(ebcFileName), quote(fileName));

                    break;
    
                case "KSDS":
                    dsOrgForProfile = "Indexed";
                    recFmForProfile = (averageRecl == maxRecl) ? "Fixed" : "Variable";
    
                    minRecLength = (recFmForProfile == "Fixed") ? maxRecl : (keyPosition + keyLength);
                    maxRecLength = maxRecl;
    
                    importCmd = sprintf("mfdas import %s from %s %s; returnCode=$?\n",
                        quote(ebcFileName),
                        ((recFmForProfile == "Fixed") ? "ksds-fixed" : "ksds"), quote(fileName));

                    break;
    
                default:
                    printf("Unexpected transfer of control to default case in switch - 2\n") > "/dev/stderr";
                    processingFailed++;
                }
    
                if (!processingFailed)
                {
                    createProfile(ebcFileName, ascFileName, dsOrgForProfile, recFmForProfile, minRecLength, maxRecLength, keyPosition, keyLength);
                    createImportConvertScript(importConvertScript, input, profile, importCmd);
                }
            }
        }' ${mfdasOutFile}
    else
        echo "Unable to obtain DCB information for ${input} from the mainframe. Exiting..."
        return -1   # added 24.8.2011 [yogesh]
    fi
    
    #rm -f ${mfdasOutFile}
}

function executeImportAndConvertScript
{
    if [ -r ${input}.ic.sh ]
    then
        chmod +x ${input}.ic.sh
        ${PWD}/${input}.ic.sh
    fi
}

input=$1
strFile=`cygpath -w -a $2 | sed -e 's,\\\\,\\\\\\\\,g'`

echo "DEBUG: impcnv input=$1, strFile=$strFile"

createProfileAndImportAndConvertScript
executeImportAndConvertScript

# sourced or executed?
if [ "$0" == '-sh' ]
then
  return 0
else
  exit 0
fi

