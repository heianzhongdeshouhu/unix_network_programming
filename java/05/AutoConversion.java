public class AutoConversion {
    public static void main(String []args) {
        char c1 = 'a';
        int i1 = c1;
        System.out.println("char auto convert to int equals: " + i1);

        char c2 = 'A';
        int i2 = c2 + 1;
        System.out.println("char type and int, after calculate equals: " + i2);
    }
}
