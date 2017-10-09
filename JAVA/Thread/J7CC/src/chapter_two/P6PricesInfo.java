package chapter_two;

import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

/**
 * Created by WW on 2017/6/12.
 */
public class P6PricesInfo {
    private double price1;
    private double price2;
    private ReadWriteLock lock;
    public P6PricesInfo(){
        price1 = 0;
        price2 = 0;
        lock = new ReentrantReadWriteLock();
    }

    public double getPrice1(){
        lock.readLock().lock();
        double value = price1;
        lock.readLock().unlock();
        return value;
    }
    public double getPrice2(){
        lock.readLock().lock();
        double value = price2;
        lock.readLock().unlock();
        return value;
    }
    public void setPrice(double price1,double price2){
        lock.writeLock().lock();
        this.price1 = price1;
        this.price2 = price2;
        lock.writeLock().unlock();
    }
    public static void main(String[] args){
        P6PricesInfo pricesInfo = new P6PricesInfo();
        Reader[] readers = new Reader[5];
        Thread[] threads = new Thread[5];
        for(int i=0;i<5;++i){
            readers[i] = new Reader(pricesInfo);
            threads[i] = new Thread(readers[i]);
        }
        Writer writers = new Writer(pricesInfo);
        Thread threadWriter = new Thread(writers);
        for(int i=0;i<5;++i){
            threads[i].start();
        }
        threadWriter.start();
    }
}

class Reader implements Runnable{
    private P6PricesInfo pricesInfo;
    public Reader(P6PricesInfo p6PricesInfo){
        this.pricesInfo = p6PricesInfo;
    }
    @Override
    public void run() {
       for(int i=0;i<10;++i){
           System.out.printf("%s: Price 1: %f\n",Thread.currentThread().getName(),pricesInfo.getPrice1());
           System.out.printf("%s: Price 2: %f\n",Thread.currentThread().getName(),pricesInfo.getPrice2());
       }
    }
}
class Writer implements Runnable{
    private P6PricesInfo pricesInfo;
    public Writer(P6PricesInfo p6PricesInfo){
        this.pricesInfo = p6PricesInfo;
    }
    @Override
    public void run() {
        for(int i=0;i<3;++i){
           System.out.printf("Writer: attempt to modify the prices.\n");
           pricesInfo.setPrice(Math.random()*10,Math.random()*10);
           System.out.printf("Writer: Prices have been modified.\n");
           try{
               Thread.sleep(2);
           } catch (InterruptedException e) {
               e.printStackTrace();
           }
        }
    }
}
