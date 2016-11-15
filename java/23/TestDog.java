/*
class Animal {
    public void move() {
        System.out.println("the animls can move around.");
    }
}

class Dog extends Animal {
    public void move() {
        System.out.println("the dog can run and walk.");
    }
}

public class TestDog {
    public static void main(String[] args) {
        Animal a = new Animal();
        Animal b = new Dog();

        a.move();
        b.move();
    }
}
*/

/*
class Animal {
    public void move() {
        System.out.println("the animls can move around.");
    }
}

class Dog extends Animal {
    public void move() {
        System.out.println("the dog can run and walk.");
    }

    public void bark() {
        System.out.println("the dog can bark.");
    }
}

public class TestDog {
    public static void main(String[] args) {
        Animal a = new Animal();
        Animal b = new Dog();

        a.move();
        b.move();
        b.bark();
    }
}
*/

class Animal {
    public void move() {
        System.out.println("the animls can move around.");
    }
}

class Dog extends Animal {
    public void move() {
        super.move();
        System.out.println("the dog can run and walk.");
    }
}

public class TestDog {
    public static void main(String[] args) {
        Animal b = new Dog();
        b.move();
    }
}

