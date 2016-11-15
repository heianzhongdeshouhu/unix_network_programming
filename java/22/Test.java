
public class Test {
    public static void main(String[] args) {
        Penguin p = new Penguin("penguin_meng", 101);
        p.introduction();
        p.eat();
        p.sleep();

        System.out.println();
        Mouse m = new Mouse("mouse_meng", 102);
        m.introduction();
        m.eat();
        m.sleep();
    }
}
