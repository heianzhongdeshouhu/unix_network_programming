/*
public class Test {
    public static void main(String args[]) {
        int x = 10;
        while ( x < 20 ) {
            System.out.print("value of x : " + x );
            x++;
            System.out.print("\n");
        }
    }
}
*/

/*
public class Test {
    public static void main(String args[]) {
        int x = 10;

        do {
            System.out.print("value of x : " + x);
            x++;
            System.out.print("\n");
        } while(x < 20);
    }
}
*/

/*
public class Test {
    public static void main(String args[]) {
        for (int x = 10; x < 20; x = x+1) {
            System.out.print("value of x : " + x );
            System.out.print("\n");
        }
    }
}
*/

/*
public class Test {
    public static void main(String args[]) {
        int [] numbers = {10, 20, 30, 40, 50};

        for (int x: numbers ) {
            System.out.print(x);
            System.out.print(",");
        }
        System.out.print("\n");

        String [] names = {"James", "Larry", "Tom", "Lacy"};
        for (String name: names ) {
            System.out.print(name);
            System.out.print(",");
        }
    }
}
*/

/*
public class Test {
    public static void main(String args[]) {
        int [] numbers = {10, 20, 30, 40, 50};

        for (int x : numbers ) {
            if (30 == x) {
                break;
            }
            System.out.print(x);
            System.out.print("\n");
        }
    }
}
*/

public class Test {
    public static void main(String args[]) {
        int [] numbers = {10, 20, 30, 40, 50};

        for (int x : numbers ) {
            if ( x == 30 ) {
                continue;
            }
            System.out.print(x);
            System.out.print("\n");
        }
    }
}
