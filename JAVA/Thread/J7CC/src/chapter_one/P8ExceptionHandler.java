package chapter_one;

/**
 * Created by wengwei on 17-6-10.
 */
public class P8ExceptionHandler implements Thread.UncaughtExceptionHandler{

    @Override
    public void uncaughtException(Thread t, Throwable e) {
        System.out.printf("An exception has been captured\n");
        System.out.printf("Thread: %s\n",t.getId());
        System.out.printf("Exception: %s:%s\n",e.getClass().getName(),e.getMessage());
        e.printStackTrace(System.out);
        System.out.printf("Thread status: %s\n",t.getState());
    }
    public static void main(String[] args){
        Task task = new Task();
        Thread thread = new Thread(task);
        thread.setUncaughtExceptionHandler(new P8ExceptionHandler());
        thread.start();
    }
}

class Task implements Runnable{

    @Override
    public void run() {
        int numero = Integer.parseInt("TTT");
    }
}


