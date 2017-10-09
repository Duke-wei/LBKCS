package Synchronized;

/**
 * Created by wengwei on 17-6-2.
 */
//http://www.cnblogs.com/GnagWang/archive/2011/02/27/1966606.html
//一、当两个并发线程访问同一个对象object中的这个synchronized(this)同步代码块时，一个时间内只能有一个线程得到执行。另一个线
//程必须等待当前线程执行完这个代码块以后才能执行该代码块。 
//
//二、然而，当一个线程访问object的一个synchronized(this)同步代码块时，另一个线程仍然可以访问该object中的非synchronized
//(this)同步代码块。 
//
//三、尤其关键的是，当一个线程访问object的一个synchronized(this)同步代码块时，其他线程对object中所有其它synchronized(this)
//同步代码块的访问将被阻塞。 
//
//四、第三个例子同样适用其它同步代码块。也就是说，当一个线程访问object的一个synchronized(this)同步代码块时，它就获得了这个
//object的对象锁。结果，其它线程对该object对象所有同步代码部分的访问都被暂时阻塞。 
//
//五、以上规则对其它对象锁同样适用
public class Test {
    public static void main(String[] args) {
        //-------------zero------------------
//        Thread0 t1 = new Thread0();
//        Thread0 t2 = new Thread0();
//        t1.setName("t1");
//        t2.setName("t2");
//        t1.start();
//        t2.start();
        //synchronized(this) 直接是this对象的锁，所以this要保持一致才能同步。因此通过接口定义线程

        //-------------one--------------------
//        Thread1 t1 = new Thread1();
//        Thread ta = new Thread(t1, "A");
//        Thread tb = new Thread(t1, "B");
//        ta.start();
//        tb.start();
        //--------------two----------------------
//        final Thread2 myt2 = new Thread2();
//        Thread t1 = new Thread(new Runnable() {  public void run() {  myt2.m4t1();  }  }, "t1"  );
//        Thread t2 = new Thread(new Runnable() {  public void run() { myt2.m4t2();   }  }, "t2"  );
//        t1.start();
//        t2.start();
        //-----------------three---------------
        //尽管线程t1获得了对Inner的对象锁，但由于线程t2访问的是同一个Inner中的非同步部分。所以两个线程互不干扰。
//        final Thread3 myt3 = new Thread3();
//        final Inner inner = new Inner();
//        Thread t1 = new Thread( new Runnable() {public void run() { myt3.m4t1(inner);} }, "t1");
//        Thread t2 = new Thread( new Runnable() {public void run() { myt3.m4t2(inner);} }, "t2");
//        t1.start();
//        t2.start();
        //-----------------three2---------------
        //将inner.m4t2定义为synchronized
        //尽管线程t1与t2访问了同一个Inner对象中两个毫不相关的部分,但因为t1先获得了对Inner的对象锁，所以t2对Inner.m4t2()的访问也被阻塞，因为m4t2()是Inner中的一个同步方法。
        final Thread3 myt3 = new Thread3();
        final Inner inner = new Inner();
        Thread t1 = new Thread( new Runnable() {public void run() { myt3.m4t1(inner);} }, "t1");
        Thread t2 = new Thread( new Runnable() {public void run() { myt3.m4t2(inner);} }, "t2");
        t1.start();
        t2.start();
    }
}
class Thread0 extends Thread{
    public void run() {
        synchronized(this) {
            for (int i = 0; i < 5; i++) {
                System.out.println(Thread.currentThread().getName() + " synchronized loop " + i);
            }
        }
    }
}
class Thread1 implements Runnable {
    public void run() {
        synchronized(this) {
            for (int i = 0; i < 5; i++) {
                System.out.println(Thread.currentThread().getName() + " synchronized loop " + i);
            }
        }
    }
}

class Thread2 {
    public void m4t1() {
        synchronized(this) {
            int i = 5;
            while( i-- > 0) {
                System.out.println(Thread.currentThread().getName() + " : " + i);
                try {
                    Thread.sleep(500);
                } catch (InterruptedException ie) {
                }
            }
        }
    }
    public void m4t2() {
        int i = 5;
        while( i-- > 0) {
            System.out.println(Thread.currentThread().getName() + " : " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException ie) {
            }
        }
    }
}

class Inner {
    protected void  m4t1() {
        int i = 5;
        while(i-- > 0) {
            System.out.println(Thread.currentThread().getName() + " : Inner.m4t1()=" + i);
            try {
                Thread.sleep(500);
            } catch(InterruptedException ie) {
            }
        }
    }
//    protected void m4t2() {
    protected synchronized void m4t2() {
        int i = 5;
        while(i-- > 0) {
            System.out.println(Thread.currentThread().getName() + " : Inner.m4t2()=" + i);
            try {
                Thread.sleep(500);
            } catch(InterruptedException ie) {
            }
        }
    }
}
class Thread3 {
    protected void m4t1(Inner inner) {
        synchronized (inner) { //使用对象锁
            inner.m4t1();
        }
    }
    protected void m4t2(Inner inner) {
        inner.m4t2();
    }
}

