package chapter_two;

import java.sql.BatchUpdateException;
import java.util.LinkedList;
import java.util.Random;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

/**
 * Created by WW on 2017/6/12.
 */
//http://ifeve.com/basic-thread-synchronization-8/
public class P8FileMock {
    private String[] content;
    private int index;

    public P8FileMock(int size,int length){
        content = new String[size];
        for(int i=0;i<size;++i){
            StringBuffer buffer = new StringBuffer(length);
            for(int j=0;j<length;++j){
                int indice = (int)Math.random()*255;
                buffer.append((char)indice);
            }
            content[i] = buffer.toString();
        }
        index = 0;
    }
    public boolean hasMoreLines(){
        return index<content.length;
    }
    public String getLine(){
        if(this.hasMoreLines()){
            System.out.println("Mock: "+(content.length-index));
            return content[index++];
        }
        return null;
    }
}

class Buffer{
    private LinkedList<String> buffer;
    private int maxSize;
    private ReentrantLock lock;
    private Condition lines;
    private Condition space;
    private boolean pendingLines;
    public Buffer(int maxSize){
        this.maxSize = maxSize;
        buffer = new LinkedList<>();
        lock = new ReentrantLock();
        lines = lock.newCondition();
        space = lock.newCondition();
        pendingLines = true;
    }
    public void insert(String line){
        lock.lock();
        try{
            while(buffer.size() == maxSize){
                space.await();
            }
            buffer.offer(line);
            System.out.printf("%s: Inserted Line: %d\n",Thread.currentThread().getName(),buffer.size());
            lines.signalAll();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }finally {
            lock.unlock();
        }
    }
    public String get(){
        String line = null;
        lock.lock();
        try{
            while((buffer.size()==0)&&(hasPendingLines())){
//                这里调用await方法，会自动放弃锁资源
                lines.await();
            }
            if(hasPendingLines()){
                line = buffer.poll();
                System.out.printf("%s: Line Reader: %d\n",Thread.currentThread().getName(),buffer.size());
                space.signalAll();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }finally {
            lock.unlock();
        }
        return line;
    }
    public void setPendingLines(boolean s){
        this.pendingLines = s;
    }
    public boolean hasPendingLines(){
        return pendingLines||buffer.size()>0;
    }
}

class Producer implements Runnable{
    private P8FileMock mock;
    private Buffer buffer;
    public Producer(P8FileMock mock,Buffer buffer){
        this.mock = mock;
        this.buffer = buffer;
    }
    @Override
    public void run() {
        buffer.setPendingLines(true);
        while(mock.hasMoreLines()){
            String line = mock.getLine();
            buffer.insert(line);
        }
        buffer.setPendingLines(false);
    }
}

class Consumer implements Runnable{
    private Buffer buffer;
    public Consumer(Buffer buffer){
        this.buffer = buffer;
    }
    @Override
    public void run() {
        while(buffer.hasPendingLines()){
            String line = buffer.get();
            processLine(line);
        }
    }

    private void processLine(String line) {
        System.out.println(line);
        try{
            Random random = new Random();
            Thread.sleep(random.nextInt(100));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Main2{
    public static void main(String[] args){
        P8FileMock mock = new P8FileMock(100,10);
        Buffer buffer = new Buffer(20);
        Producer producer = new Producer(mock,buffer);
        Thread threadProcuder = new Thread(producer,"Producer");
        Consumer[] comsumers = new Consumer[3];
        Thread[] threadConsumers = new Thread[3];
        for(int i=0;i<3;++i){
            threadConsumers[i] = new Thread(comsumers[i],"Consumer"+i);
        }
        threadProcuder.start();
        for(int i=0;i<3;++i){
            threadConsumers[i].start();
        }
    }
}
