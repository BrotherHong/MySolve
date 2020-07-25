
import java.util.Scanner;


public class Hanoi {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        f(n, 1, 3);
    }
    
    public static void f(int n, int curr, int pur) {
        // curr to pur
        if (n == 0) return;
        f(n-1, curr, 6-(curr+pur));
        System.out.printf("Ring %d from %d to %d\n", n, curr, pur);
        f(n-1, 6-(curr+pur), pur);
    }
}
