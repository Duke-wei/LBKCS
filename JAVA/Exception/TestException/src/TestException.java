/**
 * Created by wengwei on 17-5-30.
 */
//学习地址：http://blog.csdn.net/hguisu/article/details/6155636
import java.io.IOException;

public class TestException {
    public static void main(String args[]) {
        int i = 0;
        String greetings[] = { " Hello world !", " Hello World !! ",
                " HELLO WORLD !!!" };
        while (i < 4) {
            try {
                // 特别注意循环控制变量i的设计，避免造成无限循环
                System.out.println(greetings[i++]);
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("数组下标越界异常");
                //注意这里就算有return 但是finally的语句还是被执行来
                return ;
            } finally {
                System.out.println("--------------------------");
            }
        }
    }
    void method1() throws IOException {}  //合法

    //编译错误，必须捕获或声明抛出IOException
    //void method2(){
    //    method1();
    //}

    //合法，声明抛出IOException
    void method3()throws IOException {
        method1();
    }

    //合法，声明抛出Exception，IOException是Exception的子类
    void method4()throws Exception {
        method1();
    }

    //合法，捕获IOException
    void method5(){
        try{
            method1();
        }catch(IOException e){

        }
    }

    //编译错误，必须捕获或声明抛出Exception
//    void method6(){
//        try{
//            method1();
//        }catch(IOException e){throw new Exception();}
//    }

    //合法，声明抛出Exception
    void method7()throws Exception{
        try{
            method1();
        }catch(IOException e){throw new Exception();}
    }
}
