/*
public class SelfAddMinus {
    public static void main(String[] args) {
        int a = 3;
        int b = ++a;

        int c = 3;
        int d = --c;

        System.out.println("after self add, its value equals: " + b);
        System.out.println("after self minus, its value equals: " + d);

    }
}
*/

public class SelfAddMinus {
    public static void main(String[] args) {
        int a = 5;
        int b = 5;
        int x = 2 * ++a;
        int y = 2 * b++;
        System.out.println("a = " + a + ", x = " + x);
        System.out.println("b = " + b + ", y = " + y);
    }
}
