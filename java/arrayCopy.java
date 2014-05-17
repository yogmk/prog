import java.lang.String;
import java.lang.System;

class arrayCopy {
	public static void
	main (String v[])
	{
	    char from[] = {'d', 'e', 'c', 'a', 'f', 'f', 'e', 'i', 'n', 'a', 't', 'e', 'd'};
	    char to[] = new char[7];

          String firstString = "This is";
          String secondString = " a concatenated string.";
          //String thirdString = firstString+secondString;
          System.out.println(firstString + secondString);

	    System.arraycopy (from, 2, to, 0,7 );
	    System.out.println (new String (to));
	}
}