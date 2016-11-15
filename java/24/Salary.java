
public class Salary extends Employee {
    private double salary;

    public Salary(String name, String address, int number, double salary) {
        super(name, address, number);
        setSalary(salary);
    }

    public void mailCheck() {
        System.out.println("the mailCheck() method in class:Salary ");
        System.out.println("post the check to: " +  getName() + " , salary: " + salary);
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double newSalary) {
        if (newSalary >= 0.0) {
            salary = newSalary;
        }
    }

    public double computerPay() {
        System.out.println("calculate the salary with " + getName());
        return salary/52;
    }
}
