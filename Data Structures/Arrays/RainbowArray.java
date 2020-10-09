import java.util.*;
public class Main{
	public static void main (String[] args) {
		Scanner s=new Scanner(System.in);
		int tc=s.nextInt();
		while(tc-->0)
		{
		  int RainbowSize=s.nextInt();
		  int Rainbow[]=new int[RainbowSize];
		  int count=0;
		  for(int i=0; i<RainbowSize; i++)
		      Rainbow[i]=s.nextInt();
		        
		  for(int i=0; i <= RainbowSize/2; i++)
		  {
		        if(Rainbow[i] != Rainbow[RainbowSize-i-1])
		          break;
		        if(Rainbow[i] != count && Rainbow[i] != count+1)
		         break;
		      count=Rainbow[i];
		  }
		  String ans=(count==7)?"yes":"no";
		  System.out.println(ans);
		}		        
	}
}	