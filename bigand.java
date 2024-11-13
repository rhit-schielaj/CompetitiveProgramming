import java.util.*;
import java.math.BigInteger;

public class bigand{
    public static void main(String... args){
        Scanner in = new Scanner(System.in);
        

        int nodes = in.nextInt();
        int and_value = in.nextInt();
        int led_value = in.nextInt();
        in.nextLine();

        PriorityQueue<BigInteger> pq = new PriorityQueue<BigInteger>(nodes);


        for(int i=0; i<nodes; i++){
            pq.add(new BigInteger((in.nextInt())+ ""));
        }

        BigInteger node1;
        BigInteger node2;
        // BigInteger holder = pq.peek();

        while(pq.size()>1){
            node1 = pq.poll();
            node2 = pq.poll();
            pq.add((node1.max(node2)).add(new BigInteger(and_value+"")));
        }

        System.out.println((pq.poll().add(new BigInteger(led_value+""))).toString());

        in.close();
    }

}