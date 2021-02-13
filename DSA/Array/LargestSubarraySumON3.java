package DSA.Array;
import java.util.Scanner;

public class LargestSubarraySumON3 {
public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    int n = scan.nextInt();
    int a[] = new int[n];
    for(int i=0;i<n;i++){
        a[i]= scan.nextInt();
    }
    int max= Integer.MIN_VALUE;

    for(int i=0; i<n; i++){
        for(int j=i;j<n;j++){
            int cursum=0;
            for (int k=i;k<j;k++){
                cursum+=a[k];
            }
            if(cursum>max) max = cursum;
        }
    }
 System.out.println("Largest subarray sum is: "+max);
}

}
