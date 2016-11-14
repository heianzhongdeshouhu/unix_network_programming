/*
public class Test {
    public static void main(String args[]) {
        int a = 10;
        int b = 20;
        int c = 25;
        int d = 25;

        System.out.println("a + b = " + (a + b));
        System.out.println("a - b = " + (a - b));
        System.out.println("a * b = " + (a * b));
        System.out.println("b / a = " + (b / a));
        System.out.println("b % a = " + (b % a));
        System.out.println("c % a = " + (c % a));
        System.out.println("a++   = " + (a++));
        System.out.println("a-- = " + (a--));

        System.out.println("d++ = " + (d++));
        System.out.println("++d = " + (++d));
    }
}
*/

/*
public class Test {
    public static void main(String args[]) {
        int a = 10;
        int b = 20;

        System.out.println("a == b = " + (a == b));
        System.out.println("a != b = " + (a != b));
        System.out.println("a > b = " + (a > b));
        System.out.println("a < b = " + (a < b));
        System.out.println("b >= a = " + (b >= a));
        System.out.println("b <= a = " + (b <= a));
    }
}
*/

/*
public class Test {
    public static void main(String args[]) {
        boolean a = true;
        boolean b = false;
        
        System.out.println("a && b = " + (a&&b));
        System.out.println("a || b = " + (a||b));
        System.out.println("!(a&&b) = " + !(a&&b));
    }
}
*/

/*
public class Test {
    public static void main(String args[]) {
        int a = 10;
        int b = 20;
        int c = 0;

        c = a + b;
        System.out.println("c = a + b = " + c );

        c += a;
        System.out.println("c += a = " + c );

        c -= a;
        System.out.println("c -= a = " + c );

        c *= a;
        System.out.println("c *= a = " + c );

        a = 10;
        c = 15;
        c /= a;
        System.out.println("c /= a = " + c );

        a = 10;
        c = 15;
        c %= a;
        System.out.println("c %= a = " + c );

        c <<= 2;
        System.out.println("c <<= 2 = " + c );

        c >>= 2;
        System.out.println("c >>= 2 = " + c);

        c &= a;
        System.out.println("c &= 2 = " + c );

        c ^= a;
        System.out.println("c ^= a = " + c );

        c |= a;
        System.out.println("c |= a = " + c );

    }
}
*/

public class Test {
    public static void main(String args[]) {
        int a, b;
        a = 10;
        b = (a == 1) ? 20: 30;
        System.out.println("Value of b is: " + b);

        b = (a == 10) ? 20: 30;
        System.out.println("Value of b is: " + b);
    }
}
