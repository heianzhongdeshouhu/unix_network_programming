public class TestPassByValue {
    public static void main(String[] args) {
        int num1 = 1;
        int num2 = 2;

        System.out.println("before exchanging, num1: " + num1 + " , num2: " + num2);

        swap(num1, num2);
        System.out.println("after exchanging, num1: " + num1 + " , num2: " + num2);
    }

    public static void swap(int n1, int n2) {
        System.out.println("\tin swap() method");    
        System.out.println("\tbefore exchanging, n1: " + n1 + " , n2: " + n2);
        
        int temp = n1;
        n1 = n2;
        n2 = temp;

        System.out.println("before exchanging, n1: " + n1 + " , n2: " + n2);
    }
}
