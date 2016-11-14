/*
public class Test {

    public static void main(String args[]) {
        int x = 10;

        if (x < 20) {
            System.out.println("this is if stament.");
        }
    }
}
*/

/*
public class Test {
    
    public static void main(String args[]) {
        int x = 30;

        if (x < 20) {
            System.out.println("this is if statement.");
        } else {
            System.out.println("this is else statement.");
        }
    }
}
*/

/*
public class Test {
    public static void main(String args[]) {
        int x = 30;

        if (10 == x) {
            System.out.println("Value of x is 10");
        } else if (20 == x) {
            System.out.println("Value of x is 20");
        } else if (30 == x) {
            System.out.println("Value of x is 30");
        } else {
            System.out.println("this is else statement.");
        }
    }
}
*/

/*
public class Test {
    
    public static void main(String args[]) {
        int x = 30;
        int y = 10;

        if (30 == x) {
            if (10 == y) {
                System.out.println("x = 30 and y = 10 ^_^");
            }
        }
    }
}
*/

public class Test {
    public static void main(String args[]) {
        char grade = 'C';

        switch (grade) {
            case 'A': {
                System.out.println("excellent");
                break;
            }
            case 'B':
            case 'C': {
                System.out.println("well");
                break;
            }
            case 'D': {
                System.out.println("pass a test");
                break;
            }
            case 'F': {
                System.out.println("you need to study harder");
                break;
            }
            default: {
                System.out.println("unknown grade");
                break;
            }
        }

        System.out.println("your grade is " + grade);

    }
}
