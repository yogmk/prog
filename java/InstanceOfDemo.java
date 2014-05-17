import java.lang.System;


class parent {}

interface myInter {}

class child extends parent implements myInter {}

class InstanceOfDemo
{
	public static void
	main (String v[])
	{
		parent obj1 = new parent ();
		parent obj2 = new child ();
		
		System.out.println ("obj1 instance of parent:" + (obj1 instanceof parent));
		System.out.println ("obj1 instance of child:" + (obj1 instanceof child));
		System.out.println ("obj1 instance of myInter:" + (obj1 instanceof myInter));
		System.out.println ("obj2 instance of parent:" + (obj2 instanceof parent));
		System.out.println ("obj2 instance of child:" + (obj2 instanceof child));
		System.out.println ("obj2 instance of myInter:" + (obj2 instanceof myInter));
	}
}
