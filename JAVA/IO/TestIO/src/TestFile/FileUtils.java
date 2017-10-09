package TestFile;

import java.io.File;
import java.io.IOException;

/**
 * Created by wengwei on 17-5-31.
 */
public class FileUtils {
    public static void listDirectory(File dir) throws IOException{
        if(!dir.exists()){
            throw new IllegalArgumentException("dir "+dir+"not exists");
        }
        if(!dir.isDirectory()){
            throw new IllegalArgumentException(dir + "is not dir");
        }
//        String[] filenames = dir.list();
//        for(String f:filenames){
//            System.out.println(f);
//        }
        File[] files = dir.listFiles();
        if(files!=null && files.length>0){
            for(File f:files){
                System.out.print("-");
                if(f.isDirectory()){
                    listDirectory(f);
                }else{
                    System.out.println(f.getName());
                }
            }
        }
    }
}
