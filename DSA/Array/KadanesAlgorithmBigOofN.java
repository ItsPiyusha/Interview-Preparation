package DSA.Array;

import java.util.Scanner;

public class KadanesAlgorithmBigOofN {
    //Here is optimized solution for Largest sub-array sum in a given array
    //known as kadane's algorithm
    //time complexity = O(n)

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int arrayGiven[] = new int[n];
        for (int i = 0; i < n; i++) {
            arrayGiven[i] = scan.nextInt();
        }
        //above code was pretty basic template like
        //algorithm starts here
        //step=1
        int max= 0;
        int cursum=0;
        //for each element of array
        for(int i=0;i<n;i++){
            //step=2
            cursum+=arrayGiven[i];
            //step=3
            if(max<cursum) max=cursum;
            //step=4
            //if cursum is negative, that means this sum is not going to add profitable value in next terms
            //that's why we erase all terms till now with following statement
            if(cursum<0) cursum=0;
        }
        System.out.println("Largest subarray sum is: "+max);

    }
}
