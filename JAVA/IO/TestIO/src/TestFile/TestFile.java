package TestFile;

import java.io.File;

/**
 * Created by wengwei on 17-5-31.
 */
//学习链接：http://www.cnblogs.com/longqingyang/p/5564839.html
public class TestFile {
    public static boolean createFile(String filename){
        File f = new File(filename);
        //以下这两个if没有必要写的
//        if(f.exists()){
//            System.out.println("File exists");
//            return true;
//        }
//        if(filename.endsWith(File.separator)){
//            System.out.println("Can not create dir");
//            return false;
//        }
        //这个也可以不用写
//        if(!f.getParentFile().exists()) {
//            //如果目标文件所在的目录不存在，则创建父目录
//            System.out.println("目标文件所在目录不存在，准备创建它！");
//            if(!f.getParentFile().mkdirs()) {
//                System.out.println("创建目标文件所在目录失败！");
//                return false;
//            }
//        }
        try{
            f.createNewFile();
            System.out.println("该分区大小 "+f.getTotalSpace()/(1024*1024*1024)+"G");
            f.mkdirs();
            //mkdirs可以在没有父目录的情况下创建文件
//            f.mkdir();
            System.out.println("文件名 "+f.getName());
            System.out.println("文件父目录字符串 "+f.getParent());
        }catch (Exception e){
            e.printStackTrace();
        }
        return true;
    }
//    public static void main(String[] args){
//        TestFile.createFile("Test/TestFile.txt");
//    }
}
