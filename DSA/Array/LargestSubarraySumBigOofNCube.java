package DSA.Array;
import java.util.Scanner;

public class LargestSubarraySumBigOofNCube {
public static void main(String[] args){
    //template like actions on array
    Scanner scan = new Scanner(System.in);
    int n = scan.nextInt();
    int arrayGiven[] = new int[n];
    for(int i=0;i<n;i++){
        arrayGiven[i]= scan.nextInt();
    }
    //Initialised final max value to the smallest int possible
    int max= Integer.MIN_VALUE;
    //outer loop i indicates starting value of sub-array
    for(int i=0; i<n; i++){
        //inner loop j indicates all possible sub-arrays with initial index i
        for(int j=i;j<n;j++){
            int cursum=0;
            //this for loop is intended for summations of sub-arrays
            for (int k=i;k<j;k++){
                cursum+=arrayGiven[k];
            }
            //if current summation is greater than final max value, replace final max value with current sum
            if(cursum>max) max = cursum;
        }
    }
 System.out.println("Largest subarray sum is: "+max);
}

}
