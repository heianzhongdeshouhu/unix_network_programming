
public class Salary extends Employee {
    private double salary;

    public double computePay() {
        //System.out.println("Computing salary pay for " + getName());
        System.out.println("Computing salary pay for " + " temporary usage.");
        return salary/52;
    }
}
