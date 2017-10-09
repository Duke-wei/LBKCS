package chapter_one;

import java.util.Date;
import java.util.concurrent.TimeUnit;

/**
 * Created by wengwei on 17-6-10.
 */
public class P9SafeTask implements Runnable{
    private static ThreadLocal<Date> startDate = new ThreadLocal<Date>(){
        protected Date initialValue(){
            return new Date();
        }
    };
    @Override
    public void run() {
        System.out.printf("Starting Thread: %s:%s\n",Thread.currentThread().getId(),startDate.get());
        try{
            TimeUnit.SECONDS.sleep((int)Math.rint(Math.random()*10));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.printf("Finish Thread: %s:%s\n",Thread.currentThread().getId(),startDate.get());
    }

    public static void main(String[] args){
        P9SafeTask task = new P9SafeTask();
        for(int i=0;i<10;++i){
            Thread thread = new Thread(task);
            thread.start();
            try{
                TimeUnit.SECONDS.sleep(2);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
