/*
public class Test {
    
    public static void main(String[] args) {
        Integer x = 5;
        x = x + 10;
        System.out.println(x);
    }
}
*/

/*
public class Test {
    
    public static void main(String[] args) {
        Integer x = 5;

        System.out.println(x.byteValue());
        System.out.println(x.doubleValue());
        System.out.println(x.longValue());
    }
}
*/

/*
public class Test {
    public static void main(String[] args) {
        Integer x = 5;

        System.out.println(x.compareTo(3));
        System.out.println(x.compareTo(5));
        System.out.println(x.compareTo(8));
    }
}
*/

/*
public class Test {
    public static void main(String[] args) {
        Integer x = 5;
        Integer y = 10;
        Integer z = 5;
        short a = 5;

        System.out.println(x.equals(y));
        System.out.println(x.equals(z));
        System.out.println(x.equals(a));
    }
}
*/

/*
public class Test {
    public static void main(String[] args) {
        Integer x = Integer.valueOf(9);
        Double c = Double.valueOf(5);
        Float a = Float.valueOf("80");

        Integer b = Integer.valueOf("444", 16);

        System.out.println(x);
        System.out.println(c);
        System.out.println(a);
        System.out.println(b);
    }
}
*/

/*
public class Test {
    public static void main(String[] args) {
        Integer x = 5;

        System.out.println(x.toString());
        System.out.println(Integer.toString(12));
    }
}
*/

/*
public class Test {
    public static void main(String[] args) {
        int x = Integer.parseInt("9");
        double c = Double.parseDouble("5");
        int b = Integer.parseInt("444", 16);

        System.out.println(x);
        System.out.println(c);
        System.out.println(b);
    }
}
*/

/*
public class Test {
    public static void main(String[] args) {
        Integer a = -8;
        double d = -100;
        float f = -90;

        System.out.println(Math.abs(a));
        System.out.println(Math.abs(d));
        System.out.println(Math.abs(f));
    }
}
*/

/*
public class Test {
    public static void main(String[] args) {
        double d = 100.675;
        float f = -90;

        System.out.println(Math.ceil(d));
        System.out.println(Math.ceil(f));

        System.out.println(Math.floor(d));
        System.out.println(Math.floor(f));
    }
}
*/

/*
public class Test {
    public static void main(String[] args) {
        double d = 100.675;
        double e = 100.500;
        double f = 100.200;

        System.out.println(Math.rint(d));
        System.out.println(Math.rint(e));
        System.out.println(Math.rint(f));
    }
}
*/

/*
public class Test {
    public static void main(String[] args) {
        double d = 100.675;
        double e = 100.500;
        float f = 100;
        float g = 90f;

        System.out.println(Math.round(d));
        System.out.println(Math.round(e));
        System.out.println(Math.round(f));
        System.out.println(Math.round(g));
    }
}
*/

/*
public class Test {
    public static void main(String[] args) {
        System.out.println(Math.min(12.123, 12.456));
        System.out.println(Math.min(23.12, 23.0));

    }
}
*/

/*
public class Test {
    public static void main(String[] args) {
        System.out.println(Math.max(12.123, 12.456));
        System.out.println(Math.max(23.12, 23.0));
    }
}
*/

/*
public class Test {
    public static void main(String[] args) {
        double x = 11.635;
        double y = 2.76;

        System.out.printf("the value of e is: %.4f%n", Math.E);
        System.out.printf("exp(%.3f) is %.3f%n", x, Math.exp(x));
    }
}
*/

/*
public class Test {
    public static void main(String[] args) {
        double x = 11.635;
        double y = 2.76;

        System.out.printf("the value of e is: %.4f%n", Math.E);
        System.out.printf("log(%.3f) is: %.3f%n", x, Math.log(x));
    }
}
*/

/*
public class Test {
    public static void main(String[] args) {
        double x = 11.635;
        double y = 2.76;

        System.out.printf("the value of e is: %.4f%n", Math.E);
        System.out.printf("pow(%.3f, %.3f) is: %.3f%n", x, y, Math.pow(x, y));
    }
}
*/

public class Test {
    public static void main(String[] args) {
        double x = 11.635;
        double y = 2.76;

        System.out.printf("the value of e is: %.4f%n", Math.E);
        System.out.printf("sqrt(%.3f) is %.3f%n", x, Math.sqrt(x));
    }
}


/* todo sin() */
