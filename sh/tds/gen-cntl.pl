#!/usr/bin/perl

open FILE, "<", "$ARGV[0]" or die $!;
@array=<FILE>;

#Reading and spilting the line from the csv file into an array
#############################
for $val (@array)
	{
	 @temp=split(',',$val);
	 for $t (@temp)
		{
		 push(@values,$t);
		}
	}

gen_file();

#------------------------------
#------------------------------

sub gen_file
{
#	$filepath = $ARGV[1];
	#open WFILE, ">", "$filepath/SYSCNTL.txt"; 

	open WFILE, ">", "/usr/tmp/SYSCNTL.txt"; 
	open CFILE, ">", "/usr/tmp/SYSUT3.txt"; 
	print WFILE "/Dialect    MF\n";
	print WFILE "/progid     ITCOMPC1\n";
	if($values[2] =~ /QSAM/i)
	{
	 print "Generating a QSAM control/specification file ........\n";
	 $sflag = 1;
	 $org="SEQUENTIAL";
	}
	elsif($values[2] =~ /KSDS/i)
	{
	
	 print "Generating a VSAM control/specification file ........\n";
	 $vflag = 1;
	 $org="INDEXED";
	 $keyp=$values[8];
	 $keyp =~ s/\D//g;
	 $keyp = int($keyp);
	 $keyl=$values[9];
	 $keyl =~ s/\D//g;
	 $keyl = int($keyl);  
	}
	else
	{	
	 $sflag = 0;
	 $vflag = 0;
	}

	$rlen = $values[5];
	$rlen =~ s/\D//g;
	$rlen = int($rlen);
	if($rlen == 0)
	{
	 $maxlen = $values[7];
	 $maxlen =~ s/\D//g;
	 $rlen = int($maxlen);
	}

	$_ = $values[3];
	if (/RECFM=/)
	{
	$Check_format = $';
	}


	if($Check_format =~ /F.[A-Z]*/i)
	{
	 $recfm="FIXED";
	 if ($vflag == 1)
		{
		print WFILE "/SYSUT1    NAME=ITCOMPD1 ORG=$org RECFM=$recfm RLEN=$rlen KLEN=$keyl KPOS=$keyp RECMODE\n";
		print WFILE "/SYSUT2    NAME=ITCOMPD2 ORG=$org RECFM=$recfm RLEN=$rlen KLEN=$keyl KPOS=$keyp RECMODE\n";
		print WFILE "/SYSUT3    NAME=ITCOMPD3 ORG=ASCII/TEXT RECFM=VARIABLE RLEN=080\n";
		}
	else
		{
		 print WFILE "/SYSUT1    NAME=ITCOMPD1 ORG=$org RECFM=$recfm RLEN=$rlen RECMODE\n";
		 print WFILE "/SYSUT2    NAME=ITCOMPD2 ORG=$org RECFM=$recfm RLEN=$rlen RECMODE\n";
		 print WFILE "/SYSUT3    NAME=ITCOMPD3 ORG=ASCII/TEXT RECFM=VARIABLE RLEN=080\n";
		}
	}
	elsif($Check_format =~ /V.[A-Z]*/i)
	{
	 $recfm ="VARIABLE";
	 $minlen = 1;
	 $maxlen = $values[7];
	 $maxlen =~ s/\D//g;
	 $maxlen = int($maxlen);
	 if ($maxlen == 0)
	  {
	   $maxlen = $rlen;
	  }	
	 if ($vflag == 1)
	    {
 		print WFILE "/SYSUT1    NAME=ITCOMPD1 ORG=$org RECFM=$recfm RLEN=$rlen KLEN=$keyl KPOS=$keyp RECMODE\n";
		print WFILE "/SYSUT2    NAME=ITCOMPD2 ORG=$org RECFM=$recfm RLEN=$rlen KLEN=$keyl KPOS=$keyp RECMODE\n";
		print WFILE "/SYSUT3    NAME=ITCOMPD3 ORG=ASCII/TEXT RECFM=VARIABLE RLEN=080\n";
	    }
	else
	   {
 		print WFILE "/SYSUT1    NAME=ITCOMPD1 ORG=$org RECFM=$recfm RMIN=$minlen RMAX=$maxlen RECMODE\n";
	 	print WFILE "/SYSUT2    NAME=ITCOMPD2 ORG=$org RECFM=$recfm RMIN=$minlen RMAX=$maxlen RECMODE\n";
		print WFILE "/SYSUT3    NAME=ITCOMPD3 ORG=ASCII/TEXT RECFM=VARIABLE RLEN=080\n";
	   }
	 }
	else
	{
		$avglen =$values[6];
	 	$avglen =~ s/\D//g;
		$maxlen =$values[7];
		$maxlen =~ s/\D//g;
		$avglen = int($avglen);
		$maxlen = int($maxlen);
		if ($avglen == $maxlen)
		{
		 $recfm ="FIXED";
		 if($vflag == 1 )
		    {
		        print WFILE "/SYSUT1    NAME=ITCOMPD1 ORG=$org RECFM=$recfm RLEN=$rlen KLEN=$keyl KPOS=$keyp RECMODE\n";
	      	  print WFILE "/SYSUT2    NAME=ITCOMPD2 ORG=$org RECFM=$recfm RLEN=$rlen KLEN=$keyl KPOS=$keyp RECMODE\n";
		  print WFILE "/SYSUT3    NAME=ITCOMPD3 ORG=ASCII/TEXT RECFM=VARIABLE RLEN=080\n";
		    }
		 else
		    {
      		  print WFILE "/SYSUT1    NAME=ITCOMPD1 ORG=$org RECFM=$recfm RMIN=$minlen RMAX=$maxlen RECMODE\n";
	      	  print WFILE "/SYSUT2    NAME=ITCOMPD2 ORG=$org RECFM=$recfm RMIN=$minlen RMAX=$maxlen RECMODE\n";
		  print WFILE "/SYSUT3    NAME=ITCOMPD3 ORG=ASCII/TEXT RECFM=VARIABLE RLEN=080\n";
	    	    }
		}
		else
		{
		 $recfm= "VARIABLE";
		 if($vflag == 1 )
		   {
      		  print WFILE "/SYSUT1    NAME=ITCOMPD1 ORG=$org RECFM=$recfm RLEN=$rlen KLEN=$keyl KPOS=$keyp RECMODE\n";
		        print WFILE "/SYSUT2    NAME=ITCOMPD2 ORG=$org RECFM=$recfm RLEN=$rlen KLEN=$keyl KPOS=$keyp RECMODE\n";
		        print WFILE "/SYSUT3    NAME=ITCOMPD3 ORG=ASCII/TEXT RECFM=VARIABLE RLEN=080\n";
		    }
		else
		   {
      		  print WFILE "/SYSUT1    NAME=ITCOMPD1 ORG=$org RECFM=$recfm RMIN=$minlen RMAX=$maxlen RECMODE\n";
		        print WFILE "/SYSUT2    NAME=ITCOMPD2 ORG=$org RECFM=$recfm RMIN=$minlen RMAX=$maxlen RECMODE\n";
		        print WFILE "/SYSUT3    NAME=ITCOMPD3 ORG=ASCII/TEXT RECFM=VARIABLE RLEN=080\n";
		   }

		}
	
 }
print WFILE "*\n";
print WFILE "/DELTAMAX EOF EOF\n";
print WFILE "*\n";
if($vflag == 1)
{
print WFILE "/KEYFIELD  SYSUT1 pos  $keyp len  $keyl SYSUT2 pos  $keyp len  $keyl\n";
print WFILE "*\n";
#print $recfm;
}

if ($rlen > 1024)
{
 $pvalue = 1;
 $tbyte = 1024;
 $count=$rlen/int($tbyte);
 $rbyte =$rlen %$tbyte;
 while($count != 0 )
 	{
	 print CFILE "/COMPARE   SYSUT1 pos  $pvalue len $tbyte   SYSUT2 pos  $pvalue len  $tbyte \n";
	 $count =int($count) - 1;
         $pvalue =int($pvalue) + 1024;
	}
  if ($rbyte > 0 )
	{
	print CFILE "/COMPARE   SYSUT1 pos  $pvalue len $rbyte   SYSUT2 pos  $pvalue len  $rbyte \n";
	} 
}
else
{
 print CFILE "/COMPARE   SYSUT1 pos  1 len  $rlen SYSUT2 pos  1 len $rlen\n";
} 
print WFILE "*\n";
print WFILE "/DFORMAT   ASC HEX NOEBC\n";
print WFILE "*\n";
print WFILE "/END\n";
}
