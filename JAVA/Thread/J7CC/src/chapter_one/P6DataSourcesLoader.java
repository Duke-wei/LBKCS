package chapter_one;

import java.util.Date;
import java.util.concurrent.TimeUnit;

/**
 * Created by WW on 2017/6/8.
 */
public class P6DataSourcesLoader implements Runnable{
    @Override
    public void run() {
        System.out.printf("Beginning data sources loading: %s\n",new Date());
        try{
            TimeUnit.SECONDS.sleep(4);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.printf("Data sources loading has finished:%s\n",new Date());
    }
    public static void main(String[] args){
        P6DataSourcesLoader dsloader = new P6DataSourcesLoader();
        Thread thread1 = new Thread(dsloader,"DataSourceThread");
        NetworkConnectionsLoader ncloader = new NetworkConnectionsLoader();
        Thread thread2 = new Thread(ncloader,"NetworkConnectionload");
        thread1.start();
        thread2.start();
        try{
            thread1.join();
            //调度都是随机的，看来不会按这个顺序执行。
            System.out.println("thread1 has running end!!!");
            thread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.printf("Main: Configuration has been loader: %s\n",new Date());
    }
}
class NetworkConnectionsLoader implements Runnable{

    @Override
    public void run() {
        System.out.printf("NetworkConnectionsLoader start: %s\n",new Date());
        try{
            TimeUnit.SECONDS.sleep(6);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.printf("NetworkConnectionsLoader has finished:%s\n",new Date());
    }
}
