import java.io.Serializable;
import java.lang.reflect.*;
import java.util.ArrayList;

/**
 * Created by wengwei on 17-6-4.
 */
public class Test implements Serializable{
    private static final long serialVersionUID = -2862585049955236662L;
    private String proprety = null;
    public void reflect1(){
        System.out.println("java reflect1");
    }
    public void reflect2(String name){
        System.out.println("java reflect2");
        System.out.println("name :"+name);
    }
    // 修改数组大小
    public static Object arrayInc(Object obj, int len) {
        Class<?> arr = obj.getClass().getComponentType();
        Object newArr = Array.newInstance(arr, len);
        int co = Array.getLength(obj);
        System.arraycopy(obj, 0, newArr, 0, co);
        return newArr;
    }
    // 打印
    public static void print(Object obj) {
        Class<?> c = obj.getClass();
        if (!c.isArray()) {
            return;
        }
        System.out.println("数组长度为： " + Array.getLength(obj));
        for (int i = 0; i < Array.getLength(obj); i++) {
            System.out.print(Array.get(obj, i) + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) throws Exception{


        //=============通过对象获得类的属性
//        Test t = new Test();
//        System.out.println(t.getClass().getName());
//        System.out.println(t.getClass().getCanonicalName());


        //=============实例化class类对象
//        Class<?> class1 = null;
//        Class<?> class2 = null;
//        Class<?> class3 = null;
//        class1 = Class.forName("Test");
//        class2 = new Test().getClass();
//        class3 = Test.class;
//        System.out.println("类名称： "+class1.getName());
//        System.out.println("类名称： "+class2.getName());
//        System.out.println("类名称： "+class3.getName());


        //==============获取一个对象的父类和实现的接口
//        Class<?> claszz = Class.forName("Test");
//        Class<?> parentClass = claszz.getSuperclass();
//        System.out.println("claszz parent class: "+parentClass.getName());
//        Class<?> intes[] = claszz.getInterfaces();
//        System.out.println("claszz实现的接口有：");
//        for(Class<?> t : intes){
//            System.out.println(t.getName());
//        }


        //==============通过反射机制获得类实例以及构造函数和其参数
//        Class<?> class1 = null;
//        class1 = Class.forName("User");
//        // 第一种方法，实例化默认构造方法，调用set赋值
//        User user = (User) class1.newInstance();
//        user.setAge(20);
//        user.setName("Rollen");
//        System.out.println(user);
//        // 结果 User [age=20, name=Rollen]
//        // 第二种方法 取得全部的构造函数 使用构造函数赋值
//        Constructor<?> cons[] = class1.getConstructors();
//        // 查看每个构造方法需要的参数
//        for (int i = 0; i < cons.length; i++) {
//            //参数也是类型，所以使用Class<?>
//            Class<?> clazzs[] = cons[i].getParameterTypes();
//            System.out.print("cons[" + i + "] (");
//            for (int j = 0; j < clazzs.length; j++) {
//                if (j == clazzs.length - 1)
//                    System.out.print(clazzs[j].getName());
//                else
//                    System.out.print(clazzs[j].getName() + ",");
//            }
//            System.out.println(")");
//        }
//        // 结果
//        // cons[2] (java.lang.String)
//        // cons[1] (int,java.lang.String)
//        // cons[0] ()
//        user = (User) cons[2].newInstance("Rollen");
//        System.out.println(user);
//        // 结果 User [age=0, name=Rollen]
//        user = (User) cons[1].newInstance(20, "Rollen");
//        System.out.println(user);
//        // 结果 User [age=20, name=Rollen]


        //=====================获得所有的属性
//        Class<?> clazz = Class.forName("Test");
//        System.out.println("===============本类属性===============");
//        // 取得本类的全部属性
//        Field[] field = clazz.getDeclaredFields();
//        for (int i = 0; i < field.length; i++) {
//            // 权限修饰符
//            int mo = field[i].getModifiers();
//            String priv = Modifier.toString(mo);
//            // 属性类型
//            Class<?> type = field[i].getType();
//            System.out.println(priv + "\n" + type.getName() + "\n" + field[i].getName() + ";");
//        }
//
//        System.out.println("==========实现的接口或者父类的属性==========");
//        // 取得实现的接口或者父类的属性
//        Field[] filed1 = clazz.getFields();
//        for (int j = 0; j < filed1.length; j++) {
//            // 权限修饰符
//            int mo = filed1[j].getModifiers();
//            String priv = Modifier.toString(mo);
//            // 属性类型
//            Class<?> type = filed1[j].getType();
//            System.out.println(priv + " " + type.getName() + " " + filed1[j].getName() + ";");
//        }


        //==============获得所有方法
//        Class<?> clazz = Class.forName("User");
//        Method method[] = clazz.getMethods();
//        for (int i = 0; i < method.length; ++i) {
//            Class<?> returnType = method[i].getReturnType();
//            Class<?> para[] = method[i].getParameterTypes();
//            int temp = method[i].getModifiers();
//            System.out.print(Modifier.toString(temp) + " ");
//            System.out.print(returnType.getName() + "  ");
//            System.out.print(method[i].getName() + " ");
//            System.out.print("(");
//            for (int j = 0; j < para.length; ++j) {
//                System.out.print(para[j].getName() + " " + "arg" + j);
//                if (j < para.length - 1) {
//                    System.out.print(",");
//                }
//            }
//            Class<?> exce[] = method[i].getExceptionTypes();
//            if (exce.length > 0) {
//                System.out.print(") throws ");
//                for (int k = 0; k < exce.length; ++k) {
//                    System.out.print(exce[k].getName() + " ");
//                    if (k < exce.length - 1) {
//                        System.out.print(",");
//                    }
//                }
//            } else {
//                System.out.print(")");
//            }
//            System.out.println();
//        }


        //========================通过反射机制调用方法和属性
//        Class<?> clazz = Class.forName("Test");
//        // 调用TestReflect类中的reflect1方法
//        Method method = clazz.getMethod("reflect1");
//        method.invoke(clazz.newInstance());
//        // Java 反射机制 - 调用某个类的方法1.
//        // 调用TestReflect的reflect2方法
//        method = clazz.getMethod("reflect2", String.class);
//        method.invoke(clazz.newInstance(), "张三");
//        System.out.println("==========================");
//        Object obj = clazz.newInstance();
//        Field field = clazz.getDeclaredField("proprety");
//        field.setAccessible(true);
//        field.set(obj,"JAVA");
//        System.out.println(field.get(obj));


        //=====================反射的使用
        ArrayList<Integer> list = new ArrayList<Integer>();
        Method method = list.getClass().getMethod("add", Object.class);
        method.invoke(list, "Java反射机制实例。");
        System.out.println(list.get(0));
        //---------------------------------
        int[] temp = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int[] newTemp = (int[]) arrayInc(temp, 15);
        print(newTemp);
        String[] atr = { "a", "b", "c" };
        String[] str1 = (String[]) arrayInc(atr, 8);
        print(str1);
    }
}
class User {
    private int age;
    private String name;
    public User() {
        super();
    }
    public User(String name) {
        super();
        this.name = name;
    }
    public User(int age, String name) {
        super();
        this.age = age;
        this.name = name;
    }
    public int getAge() {
        return age;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    @Override
    public String toString() {
        return "User [age=" + age + ", name=" + name + "]";
    }
}
