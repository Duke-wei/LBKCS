package Example;

import java.io.*;

/**
 * Created by wengwei on 17-5-31.
 */
public class ObjectSeriaDemo {
    public static void SaveObject(Student stu,String file) throws IOException{
        ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(file));
        oos.writeObject(stu);
        oos.flush();
        oos.close();
    }
    public static void ReadObject(String file) throws IOException{
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream(file));
        Student stu = null;
        try {
            stu = (Student)ois.readObject();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        System.out.println(stu.toString());
        ois.close();
    }
    public static void main(String[] args) throws Exception{
       String file = "Test/obj.dat";
       Student stu = new Student("111","wengwei",20);
       ObjectSeriaDemo.SaveObject(stu,file);
       ObjectSeriaDemo.ReadObject(file);

    }
}
