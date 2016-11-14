public class InstanceCounter {
    private static int numInstance = 0;
    protected static int getCount() {
        return numInstance;
    }

    private static void addInstance() {
        numInstance++;
    }

    InstanceCounter() {
        InstanceCounter.addInstance();
    }

    public static void main(String[] arguments) {
        System.out.println("Starting with" +
            InstanceCounter.getCount() + " instances");
        for (int i = 0; i < 500; ++i) {
            new InstanceCounter();
        }    
        System.out.println("Created " + 
            InstanceCounter.getCount() + " instances");
    }
}
