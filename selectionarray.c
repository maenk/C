import java.util.*;
class demo
{
	public static void main(String args[])
	{
		int i,j,small,pos;
		int a[]= new int[10];
		Scanner sc= new Scanner(System.in);
	
		for (i=0;i<10;i++)
	    {
				a[i]=sc.nextInt();
	    }
		
		System.out.println("the array in unsorted form  is");
		
		for(i=0;i<10;i++)  
	    {
		    System.out.print("  "+a[i]);
	    }
		System.out.print("\n");

		
				for(i=0;i<10;i++)
					{small=a[i],pos=i;
						for (j=i+1;j<10;j++)  
							{
								if (a[small]> a[j]) 
									small=j,pos=j;
								a[pos]=a[i];
								a[i]=small;
									

							}
					}	
		System.out.println("the array in sorted form  is");
		
		for(i=0;i<10;i++)  
	    {
				System.out.print("  "+a[i]);
	    }        
		System.out.print("\n");
	}    
}

