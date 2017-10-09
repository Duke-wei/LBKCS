package TestIOwrter;

import java.io.*;

/**
 * Created by wengwei on 17-5-31.
 */
//InputStreamReader
//OutputStreamWriter
public class IOutils {
    public static void TestOne(String filename) throws IOException{
        FileInputStream in = new FileInputStream(filename);
        InputStreamReader inr = new InputStreamReader(in,"UTF-8");
        int c;
        while((c=inr.read())!=-1){
            System.out.print((char)c);
        }
        char[] buffer = new char[8*2014];
        int cc;
        while((cc=inr.read(buffer,0,buffer.length))!=-1){
            String s = new String(buffer,0,cc);
            System.out.println(s);
        }
        inr.close();
        in.close();
    }
    public static void TestTwo(String filename) throws IOException{
        FileOutputStream ou = new FileOutputStream(filename);
        OutputStreamWriter ouw = new OutputStreamWriter(ou,"UTF-8");
        ouw.write(10);
        ouw.write("I like java");
        ouw.close();
        ou.close();
    }
    public static void TestThree(String src,String dest) throws IOException{
        //这里可以追加参数true，进行追加内容
        //注意不能定义编码方式
        FileWriter fw = new FileWriter(dest);
        FileReader fr = new FileReader(src);
        char[] buffer = new char[2056];
        int c;
        while((c=fr.read(buffer,0,buffer.length))!=-1){
            fw.write(buffer,0,c);
//            fw.flush();
        }
        fr.close();
        fw.close();
    }
    public static void TestFour(String src,String dest) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(src),"UTF-8"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(dest),"UTF-8"));
        //printWriter 还有构造函数实现自动刷新的功能 。
        PrintWriter pw = new PrintWriter(dest);
        String line;
        //注意BufferedReader使用的readLine读出的数据没有换行
        while((line=br.readLine())!=null){
//            System.out.println(line);
            bw.write(line);
            bw.newLine();
            bw.flush();
            pw.print(line);
            pw.println(line);
            pw.flush();
        }
    }
    public static void main(String[] args){

    }
}
