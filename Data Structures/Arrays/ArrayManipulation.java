import java.util.Scanner;

public class ArrayManipulation {
   public static long arrayManipulation(int n,int m, int[][] queries) {
     long outputArray[] = new long[n + 2];
        for (int i = 0; i < m; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            int k = queries[i][2];
            outputArray[a] = outputArray[a]+ k;
            outputArray[b+1] = outputArray[b+1]-k;
        }   
        long maximum = getMax(outputArray);
        return maximum;
    }

    
    public static long getMax(long[] outputArray) {
        long max = Long.MIN_VALUE;
        long sum = 0;
        for (int i = 0; i < outputArray.length; i++) {
            sum = sum + outputArray[i];
            max = Math.max(max, sum);
        }
        return max;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int queries[][] = new int[m][3];

        for (int i = 0; i < m; i++) {
            queries[i][0] = sc.nextInt();
            queries[i][1] = sc.nextInt();
            queries[i][2] = sc.nextInt();
        }
        long maximum = arrayManipulation(n,m, queries);
        System.out.println(maximum);
    }
}
