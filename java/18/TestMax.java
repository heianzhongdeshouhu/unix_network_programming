public class TestMax {
    public static void main(String[] args) {
        int i = 5;
        int j = 2;
        int k = max(i, j);
        System.out.println(i + " and " + j + ", the maximum is: " + k);
    }


    /** return the larger one between the two integer variables. */
    public static int max(int num1, int num2) {
        int result;
        if (num1 > num2) {
            result = num1;
        } else {
            result = num2;
        }

        return result;
    }
}
