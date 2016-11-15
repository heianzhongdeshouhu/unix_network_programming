
public class VirtualDemo {
    public static void main(String[] args) {
        Salary s = new Salary("employee a", "Beijing", 3, 3600.00);
        Employee e= new Salary("employee b", "Shanghai", 2, 2400.00);

        System.out.println("use Salary's reference to call mailCheck --");
        s.mailCheck();

        System.out.println("\nuse Employee's reference to call mailCheck --");
        e.mailCheck();
    }
}
