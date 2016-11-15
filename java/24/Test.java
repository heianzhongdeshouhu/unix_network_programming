public class Test {
    public static void main(String[] args) {
        show(new Cat());
        show(new Dog());

        Animal a = new Cat();
        a.eat();
        Cat c = (Cat)a;
        c.work();
    }

    public static void show(Animal a) {
        a.eat();
        if (a instanceof Cat) {
            Cat c = (Cat)a;
            c.work();
        } else if (a instanceof Dog) {
            Dog c = (Dog)a;
            c.work();
        }
        System.out.println();
    }
}


abstract class Animal {
    abstract void eat();
}

class Cat extends Animal {
    public void eat() {
        System.out.println("eat fish");
    }

    public void work() {
        System.out.println("catch the mouse");
    }
}

class Dog extends Animal {
    public void eat() {
        System.out.println("eat bones");
    }

    public void work() {
        System.out.println("keep the house");    
    }
}
