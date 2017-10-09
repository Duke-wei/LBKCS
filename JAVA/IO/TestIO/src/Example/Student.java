package Example;

import java.io.Serializable;

/**
 * Created by wengwei on 17-5-31.
 */
public class Student implements Serializable{
    private String stuno;
    private String stuname;
//设置transient 则该属性就不会被jvm默认序列化,但是可以自己序列化
    private transient int stuage;
//    private int stuage;

    public String getStuno() {
        return stuno;
    }

    public String getStuname() {
        return stuname;
    }

    public int getStuage() {
        return stuage;
    }

    public void setStuno(String stuno) {
        this.stuno = stuno;
    }

    public void setStuname(String stuname) {
        this.stuname = stuname;
    }

    public void setStuage(int stuage) {
        this.stuage = stuage;
    }

    @Override
    public String toString() {
        return "Student{" +
                "stuno='" + stuno + '\'' +
                ", stuname='" + stuname + '\'' +
                ", stuage=" + stuage +
                '}';
    }

    public Student(){

    }

    public Student(String stuno, String stuname, int stuage) {
        this.stuno = stuno;
        this.stuname = stuname;
        this.stuage = stuage;
    }
    //以下两个方法实现自己的序列化和反序列化
    //在反序列化中，如果对象的父类没有实现序列化接口，则所有的父类的构造函数会显示的被调用。
    private void writeObject(java.io.ObjectOutputStream s) throws java.io.IOException{
        s.defaultWriteObject();
        s.writeInt(stuage);
    }
    private void readObject(java.io.ObjectInputStream s) throws  java.io.IOException,ClassNotFoundException{
        s.defaultReadObject();
        this.stuage = s.readInt();
    }
}
