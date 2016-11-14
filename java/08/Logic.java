public class Logic {
    public static void main(String[] args) {
        int a = 5;
        boolean b = (a < 4) && (a++ < 10);
        System.out.println("its values equals: " + b);
        System.out.println("a equals: " + a);
    }
}
