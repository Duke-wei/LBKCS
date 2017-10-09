package TestIOstream;

import com.sun.xml.internal.ws.policy.privateutil.PolicyUtils;

import java.io.*;

/**
 * Created by wengwei on 17-5-31.
 */
public class IOUtils {
    public static void printHex(String filname){
        try {
            FileInputStream in = new FileInputStream(filname);
            int b;
            int i= 1;
            while((b=in.read())!=-1){
                if(b<=0xf){
                    System.out.print("0");
                }
                System.out.print(Integer.toHexString(b)+" ");
                if(i++%10==0) System.out.println();
            }
            in.close();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void printHexByByteArray(String filename) throws IOException{
        FileInputStream in = new FileInputStream(filename);
        byte[] buf = new byte[20 *1024];
        int bytes = in.read(buf,0,buf.length);
        int j=0;
        for(int i=0;i<bytes;++i){
            if(buf[i]<=0xf){
                System.out.print("0");
            }
            System.out.print(Integer.toHexString(buf[i])+"  ");
            if(j++%10==0)
                System.out.println();
        }
        in.close();
    }
    public static void writeHex(String file) throws IOException{
        //如果文件存在，删除后创建，不存在，直接创建
        //如果追加内容，则后面加true参数。
        FileOutputStream out = new FileOutputStream(file);
        //注意这里一次写入一个字节，即八位的数据。
        out.write('A');
        out.write('B');
        int a = 10;
        //>>> 为无符号右移操作
        out.write(a >>> 24);
        out.write(a >>> 16);
        out.write(a >>> 8);
        out.write(a);
    }
    public static void copyFile(File srcFile,File destFile) throws IOException{
        if(!srcFile.exists()){
            throw new IllegalArgumentException("文件不存在");
        }
        if(!srcFile.isFile()){
            throw new IllegalArgumentException("文件不能copy");
        }
        FileInputStream in = new FileInputStream(srcFile);
        FileOutputStream out = new FileOutputStream(destFile);
        byte[] buf = new byte[8*1024];
        int b;
        while((b=in.read(buf,0,buf.length))!=-1){
            out.write(buf,0,b);
            out.flush();
        }
        in.close();
        out.close();
    }
    //使用DataInputStream
    public static void printDIS(String file) throws IOException{
        DataInputStream di = new DataInputStream(new FileInputStream(file));
        di.readInt();
        di.readChar();
        di.readUTF();
        di.close();
    }
    //使用DataOutputStream
    public static void writeDOS(String file) throws IOException{
        DataOutputStream dou = new DataOutputStream(new FileOutputStream(file));
        dou.writeInt(10);
        dou.writeInt(-110);
        dou.writeUTF("士大夫");
        dou.close();
    }
    public static void copyFileByBuff(File srcFile,File destFile) throws IOException{
        if(!srcFile.exists()){
            throw new IllegalArgumentException("File not exit");
        }
        if(!srcFile.isFile()){
            throw new IllegalArgumentException("File is not a File");
        }
        BufferedInputStream i = new BufferedInputStream(new FileInputStream(srcFile));
        BufferedOutputStream o = new BufferedOutputStream(new FileOutputStream(destFile));
        int c;
        while((c=i.read())!=-1){
            o.write(c);
            //o.flush();
        }
        i.close();
        o.close();
    }
    public static void copyFileByBuff2(File srcFile,File destFile) throws IOException{
        if(!srcFile.exists()){
            throw new IllegalArgumentException("File not exit");
        }
        if(!srcFile.isFile()){
            throw new IllegalArgumentException("File is not a File");
        }
        BufferedInputStream i = new BufferedInputStream(new FileInputStream(srcFile));
        BufferedOutputStream o = new BufferedOutputStream(new FileOutputStream(destFile));
        byte[] buf = new byte[4096];
        int ii;
        while((ii=i.read(buf,0,buf.length))!=-1){
            o.write(buf,0,ii);
            //o.flush();
        }
        i.close();
        o.close();
    }
    public static void main(String[] args){
//        IOUtils.printHex("src/TestIOstream/IOUtils.java");
//        try {
//            IOUtils.printHexByByteArray("src/TestIOstream/IOUtils.java");
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
        try {
            IOUtils.copyFile(new File("src/TestIOstream/IOUtils.java"),new File("Test/IOUtils.java"));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
