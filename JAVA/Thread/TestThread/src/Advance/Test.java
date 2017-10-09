package Advance;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
//http://blog.csdn.net/gf771115/article/details/51682561
/**
 * Created by wengwei on 17-6-2.
 */
public class Test {
    public static void main(String[] args) throws Exception {
        //通过关键字定义线程执行顺序
//        Object a = new Object();
//        Object b = new Object();
//        Object c = new Object();
//        MyThreadPrinter2 pa = new MyThreadPrinter2("A", c, a);
//        MyThreadPrinter2 pb = new MyThreadPrinter2("B", a, b);
//        MyThreadPrinter2 pc = new MyThreadPrinter2("C", b, c);
//
//        new Thread(pa).start();
//        Thread.sleep(100);  //确保按顺序A、B、C执行
//        new Thread(pb).start();
//        Thread.sleep(100);
//        new Thread(pc).start();
//        Thread.sleep(100);
        //通过class传输数据
        Thread thread = new MyThread3(new Work());
        thread.start();
    }
}
class Data
{
    public int value = 0;
}
class Work
{
    public void process(Data data, List<Integer> numbers)
    {
        for (int n : numbers)
        {
            data.value += n;
        }
    }
}
class MyThread3 extends Thread
{
    private Work work;
    public MyThread3(Work work)
    {
        this.work = work;
    }
    public void run()
    {
        java.util.Random random = new java.util.Random();
        Data data = new Data();
        int n1 = random.nextInt(1000);
        int n2 = random.nextInt(2000);
        int n3 = random.nextInt(3000);
        work.process(data,new ArrayList<Integer>(Arrays.asList(n1,n2,n3))); // 使用回调函数
        System.out.println(String.valueOf(n1) + "+" + String.valueOf(n2) + "+"
                + String.valueOf(n3) + "=" + data.value);
    }
}
class MyThreadPrinter2 implements Runnable {

    private String name;
    private Object prev;
    private Object self;

    public MyThreadPrinter2(String name, Object prev, Object self) {
        this.name = name;
        this.prev = prev;
        this.self = self;
    }

    @Override
    public void run() {
        int count = 10;
        while (count > 0) {
            synchronized (prev) {
                synchronized (self) {
                    System.out.print(name);
                    count--;
                    //notify()唤醒其他等待该self的锁资源线程并执行其中一个（时间片或优先级）。
                    //notifyall()会让线程进入阻塞等待队列，然后在队列中随机或优先级选取线程执行。
                    self.notify();
                }
                try {
                    //wait() 会释放prev的锁，并让线程进入阻塞等待队列，直到超时或则notify
                    prev.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

}