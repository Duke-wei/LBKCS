package chapter_one;

import java.util.Date;
import java.util.concurrent.TimeUnit;

/**
 * Created by WW on 2017/6/8.
 */
public class P5FileClock implements Runnable{
    @Override
    public void run() {
        for(int i=0;i<10;++i){
            System.out.printf("%s\n",new Date());
            try{
                TimeUnit.SECONDS.sleep(1);
            } catch (InterruptedException e) {
                System.out.println("The FileClock has been interrupted");
            }
        }
    }

    public static void main(String[] args){
        P5FileClock clock = new P5FileClock();
        Thread thread = new Thread(clock);
        thread.start();
        try{
            TimeUnit.SECONDS.sleep(5);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        thread.interrupt();
    }
}
