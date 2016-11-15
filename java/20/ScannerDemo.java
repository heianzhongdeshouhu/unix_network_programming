/*
import java.util.Scanner;

public class ScannerDemo {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.println("next method receives: ");
        if (scan.hasNext()) {
            String str1 = scan.next();
            System.out.println("the input data is: " + str1);
        }
    }
}
*/

/*
import java.util.Scanner;

public class ScannerDemo {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.println("nextLine method receiving:");
        if (scan.hasNextLine()) {
            String str0 = scan.nextLine();
            System.out.println("the data inputted is: " + str0);
        }
    }
}
*/

/*
import java.util.Scanner;

public class ScannerDemo {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int i = 0;
        float f = 0.0f;
        System.out.print("input integer: ");
        if (scan.hasNextInt()) {
            i = scan.nextInt();
            System.out.println("integer data: " + i);
        } else {
            System.out.println("the input data is not integer!");
        }

        System.out.print("please input float: ");
        if (scan.hasNextFloat()) {
            f = scan.nextFloat();
            System.out.println("float data is: " + f);
        } else {
            System.out.println("the input is not float!");
        }

    }
}
*/

import java.util.Scanner;

class ScannerDemo {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        double sum = 0;
        int m = 0;

        while (scan.hasNextDouble()) {
            double x = scan.nextDouble();
            m = m + 1;
            sum = sum + x;
        }

        System.out.println(m + " " + sum);
        System.out.println(m + " " + (sum/m));

    }
}
