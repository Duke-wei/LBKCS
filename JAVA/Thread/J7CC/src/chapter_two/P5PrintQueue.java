package chapter_two;

import chapter_one.P5FileClock;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * Created by WW on 2017/6/12.
 */
public class P5PrintQueue{
    private final Lock queueLock = new ReentrantLock();
    public void printJob(Object document){
        queueLock.lock();
        try{
            Long duration = (long)(Math.random()*10000);
            System.out.println(Thread.currentThread().getName()+":PrintQueue:Printing a job during"+(duration/1000)+" second");
            Thread.sleep(duration);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }finally {
            queueLock.unlock();
        }
    }
}

class Job implements Runnable{
    private P5PrintQueue printQueue;
    public Job(P5PrintQueue printQueue){
        this.printQueue = printQueue;
    }

    @Override
    public void run() {
       System.out.printf("%s: Going to print a ducument\n",Thread.currentThread().getName());
       printQueue.printJob(new Object());
       System.out.printf("%s: The document has been printed\n",Thread.currentThread().getName());
    }
    public static void main(String[] args){
        P5PrintQueue printQueue = new P5PrintQueue();
        Thread[] threads = new Thread[10];
        for(int i=0;i<10;++i){
            threads[i] = new Thread(new Job(printQueue),"Thread"+i);
        }
        for(int i=0;i<10;++i){
            threads[i].start();
        }
    }
}
