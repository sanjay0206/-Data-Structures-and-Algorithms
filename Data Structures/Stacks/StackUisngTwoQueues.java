import java.util.*;

class StackUsingTwoQueues {
    Deque<Integer> q1 = new LinkedList<>();
    Queue<Integer> q2 = new LinkedList<>();
    
    public void push(int x) {
        q1.add(x);
    }
    
    public int pop() {
        int popedItem = 0, lastElementFromQ1, firstElementFromQ2;
        if(q2.isEmpty()) {
            if(!q1.isEmpty()) {
                lastElementFromQ1 = q1.pollLast();
                q2.add(lastElementFromQ1);
                firstElementFromQ2 = q2.poll();
                popedItem = firstElementFromQ2;
            }
            else
                popedItem = -1;
        }
        return popedItem;
    }
}
class Test {
    public static void main(String[] args) {
       Scanner s = new Scanner(System.in);
           StackUsingTwoQueues sq = new StackUsingTwoQueues();
           sq.push(2);
           sq.push(3);
           System.out.println(sq.pop());
           sq.push(4);
           System.out.println(sq.pop());
    }
}