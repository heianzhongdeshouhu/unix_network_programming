/*
class RunnableDemo implements Runnable {
    private Thread t;
    private String threadName;

    RunnableDemo(String name) {
        threadName = name;
        System.out.println("creating " + threadName);
    }

    public void run() {
        System.out.println("running " + threadName);

        try {
            for (int i = 4; i > 0; i--) {
                System.out.println("thread: " + threadName + ", " + i);

                // let the thread sleep for a while
                Thread.sleep(50);
            }
        } catch (InterruptedException e) {
            System.out.println("Thread " + threadName + " interrupted.");
        }

        System.out.println("thread " + threadName + " is exiting.");
    }

    public void start() {
        System.out.println("starting " + threadName);
        if (null == t) {
            t = new Thread(this, threadName);
            t.start();
        }
    }
}

public class TestThread {
    public static void main(String[] args) {
        RunnableDemo R1 = new RunnableDemo("Thread-1");
        R1.start();

        RunnableDemo R2 = new RunnableDemo("Thread-2");
        R2.start();

    }
}
*/

class ThreadDemo extends Thread {
    private Thread t;
    private String threadName;

    ThreadDemo(String name) {
        threadName = name;
        System.out.println("creating " + threadName);
    }

    public void run() {
        System.out.println("running " + threadName);

        try {
            for (int i = 4; i > 0; i--) {
                System.out.println("thread " + threadName + ", " + i);

                // let the thread sleep for a while.
                Thread.sleep(50);
            }
        } catch (InterruptedException e) {
            System.out.println("thread " + threadName + " interrupted.");
            
        }

        System.out.println("thread " + threadName + " is exiting.");
    }

    public void start() {
        System.out.println("starting " + threadName);
        if (t == null) {
            t = new Thread(this, threadName);
            t.start();
        }
    }
}

public class TestThread {
    public static void main(String[] args) {
        ThreadDemo T1 = new ThreadDemo("thread-1");
        T1.start();

        ThreadDemo T2 = new ThreadDemo("thread-2");
        T2.start();
    }
}
