import java.io.*;

/*
public class Employee {
    public String name;
    private double salary;

    public Employee (String empName) {
        name = empName;
    }

    public void setSalary(double empSal) {
        salary = empSal;
    }

    public void printEmp() {
        System.out.println("name:   " + name);
        System.out.println("salary: " + salary);
    }

    public static void main(String args[]) {
        Employee empOne = new Employee("RUNOOB");
        empOne.setSalary(1000);
        empOne.printEmp();
    }
}
*/


public class Employee {
    private static double salary;
    public static final String DEPARTMENT = "developer";

    public static void main(String args[]) {
        salary = 10000;
        System.out.println(DEPARTMENT + "average salary: " + salary);
    }
}
