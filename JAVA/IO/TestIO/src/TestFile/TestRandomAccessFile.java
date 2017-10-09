package TestFile;

import com.sun.xml.internal.ws.policy.privateutil.PolicyUtils;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.lang.reflect.Array;

/**
 * Created by wengwei on 17-5-31.
 */
public class TestRandomAccessFile {
    public static void main(String[] args){
        File demo = new File("Test");
        if(!demo.exists()){
            demo.mkdir();
        }
        File f = new File(demo,"Test.dat");
        if(!f.exists()){
            try{
                f.createNewFile();
            }catch (IOException e){
                e.printStackTrace();
            }
        }
        try{
            RandomAccessFile raf = new RandomAccessFile(f,"rw");
            System.out.println(raf.getFilePointer());
            raf.write('A');
            System.out.println(raf.getFilePointer());
            raf.write('B');
            int i = 0x7fffffff;
            raf.write(i>>24);
            raf.write(i>>16);
            raf.write(i>>8);
            raf.write(i);
            System.out.println(raf.getFilePointer());
            String s = "中";
            byte[] gbk = s.getBytes("utf-8");
            raf.write(gbk);
            System.out.println(raf.getFilePointer());
            raf.seek(0);
            byte[] buf = new byte[(int)raf.length()];
            raf.read(buf);
            System.out.print(buf.toString());
            for(byte b : buf){
                System.out.println(Integer.toHexString(b & 0xff));
            }
        }catch (IOException e){
            e.printStackTrace();
        }



    }
}
