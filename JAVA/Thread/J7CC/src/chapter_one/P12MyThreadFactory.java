package chapter_one;

import java.util.ArrayList;
import java.util.Date;
import java.util.Iterator;
import java.util.List;
import java.util.concurrent.ThreadFactory;
import java.util.concurrent.TimeUnit;

/**
 * Created by wengwei on 17-6-10.
 */
public class P12MyThreadFactory implements ThreadFactory{
    private int counter;
    private String name;
    private List<String> states;
    public P12MyThreadFactory(String name){
        counter = 0;
        this.name = name;
        states = new ArrayList<String>();
    }
    @Override
    public Thread newThread(Runnable r) {
        Thread t = new Thread(r,name+"-Thread-"+counter);
        counter++;
        states.add(String.format("created thread %d with name %s on %s\n",t.getId(),t.getName(),new Date()));
        return t;
    }

    public String getStates(){
        StringBuffer buffer = new StringBuffer();
        Iterator<String> it = states.iterator();
        while(it.hasNext()){
            buffer.append(it.next());
            buffer.append("\n");
        }
        return buffer.toString();
    }
    public static void main(String[] args){
        P12MyThreadFactory factory = new P12MyThreadFactory("MyThreadFactory");
        Task2 task = new Task2();
        Thread thread;
        System.out.printf("Starting the Threads\n");
        for(int i=0;i<10;++i){
            thread = factory.newThread(task);
            thread.start();
        }
        System.out.printf("Factory states:\n");
        System.out.printf("%s\n",factory.getStates());
    }
}

class Task2 implements Runnable{
    @Override
    public void run() {
        try{
            TimeUnit.SECONDS.sleep(1);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
