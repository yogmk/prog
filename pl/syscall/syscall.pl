#!/usr/bin/perl
    
##---------------------------------------------------------------##
## Description: Script to parse System Call from source code. 
## Author: Manoj Dixit, Hewlett Packard
## Date:  Feb 08 2011
##---------------------------------------------------------------##   


#push(@INC, "/root/test/perl/"); 


use Getopt::Std;
use File::Spec;
# Read System Call Rule file (csv)

my $file = 'sysrules.csv';
my @syslist;
my %syshash = ();
my %filehash = ();
my $DEBUG = 0;
my $dirtoget; #="/root/test/perl/src";
my $help = 0;


getopts('d:t:h:m:');

if(not($opt_d))
{
	Usage();
	exit;
}else{
	$dirtoget=$opt_d;
}
if($opt_t) {
	$DEBUG=1;
}
if($opt_h) {
	$help=1;		
}
if($opt_m){
	$mode=$opt_m;
}else{
	$mode="sys";
}



if( $help ) {
        Usage();
} else {
        print "Source Directory to parse is $dirtoget\n";
}

sub Usage {
	print "Usage: $0  -d <Source Directory> -m <sys | file | all> -t <track processing> -h <help>\n";
	print "	-d is mandatory which need path of source code directory\n";
	print "	-m is mode to generate report. \n";
	print "		sys: System Call based report which gives count of system call in code\n";
	print "		file: File wise System call report. Gives System call count for each file\n";
	print "		all: Run both mode. Default mode is sys mode\n";	
	print "	-h is for help\n";
	print "	-t is for debug mode\n";
	exit;
}

## Start Main####
$curpath = `pwd`;
#
$dirtoget = File::Spec->rel2abs($dirtoget);

#
chomp($curpath);
print "Script to check how system calls usage and impact for application\n";
print "Read Predefined list of System Calls\n";
&parseCSV();

if($mode ne "file") {
print "Parse source code to validate occurances of system calls\n";
&parseSRC_sys();

print "Generates statistics for system call\n";
&report_sys();
}

if($mode eq "all" or $mode eq "file") {
print "Parse source code to validate occurances of system calls to capture filewaise details\n";
&parseSRC_file();

print "Generates statistics for system call\n";
&report_file();
}
print "Completed Successfully\n";

###End of Script ###




sub parseCSV {
	open (CSV, "<", $file) or die $!;

	while (<CSV>) {
		@tmp = split(",", $_);
		push(@syslist,$tmp[0]);
	}
	close CSV;
}

sub parseSRC_sys {

	if ($DEBUG eq 1) { print "@syslist\n"; }
	foreach my $sys (@syslist)
	{
		chdir "$dirtoget";
		my @result = `grep -cir "$sys(" *`;
		my %filewise = ();
		foreach my $res (@result)
		{
			my @TMP = split(':', $res);
			my $ONE = $TMP[0];
			my $TWO = $TMP[1];	
			if ($DEBUG eq 1) {print "SYS=$sys  ONE=$ONE and TWO=$TWO\n"; }
			if ($TWO>0) {
				$filewise {$ONE} = $TWO;   # Get filewise system call count in hash
			}
		}		
		if ($DEBUG eq 1) {
			while ( my($k,$v) = each %filewise ) {     print "++++---->  $k => $v\n"; }
		}
		if ((keys %filewise)>0) {
			$syshash{$sys} = \%filewise;
		}
	}
}




sub parseSRC_file {

	# List all files in directory 

	process_files ($dirtoget);

}

sub printsysrep {
	my ($mytotcalls,$mycallname,$mycallcount) = @_;
if(not defined $index) {
$index =1;
}else {
$index++;
}



format MYFILE =
@>>>    @<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<          @>>>>>>>>>>>>>> 
$index  $mycallname                      												$mycallcount            
.

write MYFILE;

format MYFILE_TOP =
@|||||||||||||||||||||||||||||||||||||||||||||||||||||  Pg @<
"Report based on System Call count in source directory",                   $%
@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<		@>>>>>>>    
"Total no of System Calls used"     	$mytotcalls

System Call Details:
====================

No.    System Call Name                 System Call count 
---    ------------------               -----------------       
.

}

sub printfilrep {
	my ($myfilname,$callsinfile,$callsdetails) = @_;
	if(not defined $inde1) {
		$inde1 =1;
	}else {
		$inde1++;
	}
format MYREP =
@>>    @<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   	@>>>>>>>>>>>>>>> 	@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
$inde1 $myfilname                      											$callsinfile  		$callsdetails
.

write MYREP;

format MYREP_TOP =
@|||||||||||||||||||||||||||||||||||||||||||||||||||||  Pg @<
"Report based on System Call count in source directory",                   $%
@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<         @>>>>>>>
"Total no of System Calls used"         $mytotcalls

System Call Details:
====================

No.    File Name                 	System Call count	System Call Details
---    ----------------------           -----------------	-------------------
.

}

sub report_file {
	my $filecount = keys %filehash;

	print "==> FILEWISE SYSTEM CALL SUMMARY REPORT GENERATED ..";
	$rptfile2 = $curpath . "/" . "filecall.rep";
	open(MYREP,">$rptfile2") or (print "Can't open up final.rep file $rptfile2 $!\n" and die);
	foreach my $file (keys %filehash) {
		my %syscnt = %{$filehash{$file}};
		my $count4call = 0;
		my $listallcall = "";
		foreach my $sys (keys %syscnt) {
			$listallcall = $listallcall . "$sys:$syscnt{$sys}, ";
			$count4call = $count4call + $syscnt{$sys};
		}
		printfilrep($file,$count4call,$listallcall);
	}
	close(MYREP);
	print ". SEE $rptfile2 FOR DETAILS <==\n";

}


sub report_sys {
	my $syscount = keys %syshash;  
	print "==> SYSTEM CALLWISE SUMMARY REPORT GENERATED ..";
	$rptfile = $curpath . "/" . "syscall.rep";
	open(MYFILE,">$rptfile") or (print "Can't open up final.rep file $rptfile $!\n" and die);
	foreach my $call (keys %syshash) {
		my %filecnt = %{$syshash{$call}};
		my $count4call = 0;
		foreach my $file (keys %filecnt) {
			$count4call = $count4call + $filecnt{$file};
		}
		printsysrep($syscount,$call,$count4call);
	}
	close(MYFILE);
	print ". SEE $rptfile FOR DETAILS <==\n";
}

# Accepts one argument: the full path to a directory.
# Returns: nothing.
sub process_files {
    my $path = shift;
    chomp($path);
    # Open the directory.
    opendir (DIR, $path)
        or die "Unable to open $path: $!  \nPlease give absolute directory path \n";

    # Read in the files.
    # You will not generally want to process the '.' and '..' files,
    # so we will use grep() to take them out.
    # See any basic Unix filesystem tutorial for an explanation of the

    my @files = grep { !/^\.{1,2}$/ } readdir (DIR);

    # Close the directory.
    closedir (DIR);

    # At this point you will have a list of filenames without full paths ('filename' rather than
    #  '/home/count0/filename', for example) You will probably have a much easier time if you make
    #  sure all of these files include the full path,  so here we will use map() to tack it on.
    #  (note that this could also be chained with the grep   mentioned above, during the readdir() ).

   @files = map { $path . '/' . $_ } @files;

    for (@files) {

        # If the file is a directory
        if (-d $_) {
            # Here is where we recurse.
            # This makes a new call to process_files()
            # using a new directory we just found.
            process_files ($_);

        # If it isn't a directory, lets just do some
        # processing on it.
        } else {
		chdir "$dirtoget";
		my %callwise = ();
		# Chekc if file is .c, .h or .pc only 
		my $line  = $_;
		$line =~ s/^\s+//g;
        	$line =~ s/\s+$//;
		if (($line =~ m/\.c$/) | ($line =~ m/\.h$/) | ($line =~ m/\.pc$/) | ($line =~ m/\.cpp$/)) {

			foreach my $sys (@syslist) {
				my $cnt = `grep -ci "$sys(" $line`;
				chomp($cnt);
				if ($cnt > 0) {
					#print "$line, $cnt, $sys\n";
					$callwise{$sys} = $cnt;
				}
			}
		}		
		if ((keys %callwise)>0) {
                        $filehash{$line} = \%callwise;
                }

        }
    }
}

