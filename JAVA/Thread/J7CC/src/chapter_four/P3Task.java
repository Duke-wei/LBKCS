package chapter_four;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.*;

/**
 * Created by wengwei on 17-6-14.
 */

class Result{
    private String name;
    private int value;

    public Result() {
    }
    public Result(String name, int value) {
        this.name = name;
        this.value = value;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }
}
public class P3Task implements Callable<Result>{
    private String name;

    public P3Task(String name){
        this.name = name;
    }
    @Override
    public Result call() throws Exception {
        System.out.printf("%s: Staring\n",this.name);
        try{
            long duration = (long)(Math.random()*10);
            System.out.printf("%s: Warting %d seconds for results.\n",this.name,duration);
            TimeUnit.SECONDS.sleep(duration);
        }catch (InterruptedException e){
            e.printStackTrace();
        }
        int value = 0;
        for(int i=0;i<5;++i){
            value += (int)(Math.random()*100);
        }
        Result result = new Result();
        result.setName(this.name);
        result.setValue(value);
        System.out.println(this.name+": Ends");
        return result;
    }
    public static void main(String[] args){
        ExecutorService executor = (ExecutorService) Executors.newCachedThreadPool();
        List<P3Task> taskList = new ArrayList<>();
        for(int i=0;i<3;++i){
            P3Task task = new P3Task(i+"");
            taskList.add(task);
        }
        List<Future<Result>> resultList = null;
        try{
            resultList = executor.invokeAll(taskList);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        executor.shutdown();
        System.out.println("Main: Printing the results");
        for(int i=0;i<resultList.size();++i){
            Future<Result> future = resultList.get(i);
            try{
                Result result = future.get();
                System.out.println(result.getName()+": "+result.getValue());
            } catch (InterruptedException e) {
                e.printStackTrace();
            } catch (ExecutionException e) {
                e.printStackTrace();
            }
        }
    }
}
