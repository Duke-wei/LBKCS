package BaseThread;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.FutureTask;

//http://www.cnblogs.com/wxd0108/p/5479442.html
/**
 * Created by wengwei on 17-6-1.
 */
class RunnableDemo implements Runnable{
    private Thread t;
    private String threadName;

    public RunnableDemo(String name){
        threadName = name;
        System.out.println("Creating "+threadName);
    }

    @Override
    public void run() {
        System.out.println("Running "+threadName);
        try{
            for(int i=4;i>0;--i){
                System.out.println("Thread: "+threadName+", "+i);
                Thread.sleep(50);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Thread "+threadName+ "exiting.");
    }

    public void start(){
        System.out.println("Starting "+threadName);
        if(t == null){
            t = new Thread(this,threadName);
            t.start();
        }
    }
}
class ThreadDemo extends Thread{
    private String threadname;
    public ThreadDemo(String s){
        threadname = s;
        System.out.println("Creating "+threadname);
    }
    @Override
    public void run(){
       System.out.println("Running "+threadname);
       try{
           for(int i=4;i>0;--i){
               System.out.println("Thread: "+threadname+" ,"+i);
               Thread.sleep(50);
           }
       } catch (InterruptedException e) {
           e.printStackTrace();
       }
       System.out.println("Thread "+threadname+" exiting.");
    }
//    public void start(){
//        System.out.println("Starting "+threadname);
//        this.start();
//    }
}
class DisplayMessage implements Runnable{
    private String message;
    public DisplayMessage(String message){
        this.message = message;
    }
    @Override
    public void run() {
       while(true){
           System.out.println(message);
       }
    }
}
class GuessANumber extends Thread{
    private int number;
    public GuessANumber(int number){
        this.number = number;
    }
    @Override
    public void run(){
        int counter = 0;
        int guess = 0;
        do{
            guess = (int)(Math.random()*100 + 1);
            System.out.println(this.getName() + " guesses "+guess);
            counter++;
        }while(guess!=number);
        System.out.println("** Correct!" + this.getName()+" in "+counter+"guesses.**");
    }
}

class CallableThreadTest implements Callable<Integer> {
    @Override
    public Integer call() throws Exception
    {
        int i = 0;
        for(;i<100;i++)
        {
            System.out.println(Thread.currentThread().getName()+" "+i);
        }
        return i;
    }
}

public class CreateThread {
    public static void testOne(){
        RunnableDemo one = new RunnableDemo("Thread_one");
        one.start();
        RunnableDemo two = new RunnableDemo("Thread_two");
        two.start();
    }
    public static void testTwo(){
        ThreadDemo td0 = new ThreadDemo("thread0");
        ThreadDemo td1 = new ThreadDemo("thread1");
        td0.start();
        td1.start();
    }
    public static void testThree(){
        Runnable hello = new DisplayMessage("Hello");
        Thread thread1 = new Thread(hello);
        thread1.setDaemon(true);
        thread1.setName("hello");
        System.out.println("Starting hello thread...");
        thread1.start();

        Runnable bye = new DisplayMessage("Goodbye");
        Thread thread2 = new Thread(bye);
        thread2.setPriority(Thread.MIN_PRIORITY);
        thread2.setDaemon(true);
        System.out.println("Starting goodbye thread...");
        thread2.start();

        System.out.println("Starting thread3...");
        Thread thread3 = new GuessANumber(27);
        thread3.start();
        try{
            //执行该语句t.join的线程阻塞，转去执行t线程，直到t线程完成或超时。
            thread3.join();

        } catch (InterruptedException e) {
            System.out.println("Thread interrupted.");
        }
        System.out.println("Starting thead4...");
        Thread thread4 = new GuessANumber(75);
        thread4.start();
        System.out.println("main() is ending....");
    }
    public static void testFour(){
        CallableThreadTest ctt = new CallableThreadTest();
        FutureTask<Integer> ft = new FutureTask<>(ctt);
        for(int i = 0;i < 100;i++)
        {
            System.out.println(Thread.currentThread().getName()+" 的循环变量i的值"+i);
            if(i==20)
            {
                new Thread(ft,"有返回值的线程").start();
            }
        }
        try
        {
            System.out.println("子线程的返回值："+ft.get());
        } catch (InterruptedException e){
            e.printStackTrace();
        } catch (ExecutionException e){
            e.printStackTrace();
        }
    }
    public static void main(String[] args){
//        CreateThread.testOne();
//        CreateThread.testTwo();
//        CreateThread.testThree();
        CreateThread.testFour();
    }

}
