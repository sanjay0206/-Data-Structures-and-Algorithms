import java.util.*;
public class Main {
 public static void main(String[] args) {
      Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int q = s.nextInt();
        int lastAns = 0;
        ArrayList<List> seqList = new ArrayList();
        for (int i=0; i<n;i++){
            seqList.add(new ArrayList<Integer>());
        }
        for (int i=0;i<q;i++)
        {
            int t=s.nextInt();
            int x=s.nextInt();
            int y=s.nextInt();
            
            List<Integer> seq = seqList.get((x^lastAns)%n);
                if (t==1){
                    seq.add(y);
                } 
                else{
                    lastAns = seq.get(y%(seq.size()));
                     System.out.println(lastAns);
                }
        }
    }
}
