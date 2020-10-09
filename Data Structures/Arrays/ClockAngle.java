import java.util.*;
public class Main
{
    public  static double clockAngle(int hour, int minutes) {
            final double MINUTES_PER_HOUR = 60;
            final double DEGREES_PER_MINUTE = 360 / MINUTES_PER_HOUR;
            final double DEGREES_PER_HOUR = 360 / 12;
         
            int minuteAngle = minutes * (int)DEGREES_PER_MINUTE;
            double hourAngle = (hour * MINUTES_PER_HOUR + minutes) * DEGREES_PER_HOUR/MINUTES_PER_HOUR;
         
            double angle = Math.abs(minuteAngle - hourAngle);
            if (angle > 180)
                return 360 - angle;
            return angle;
        }
        
        public static double  IST(int hours, double degree)  
         {  
        double IST = (hours* degree * 1.0) / 360;  
        int int_IST = (int)IST;  
        int float_IST = (int)Math.ceil((int)((IST - int_IST) * 60));  
        return clockAngle(int_IST,float_IST);
         }  
  
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		double degree=s.nextDouble();
		double ans=IST(n,degree);
		System.out.println(ans);
	}
}
