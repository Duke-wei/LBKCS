package TestArrays;
//Arrays是操作数组的——排序，拷贝，填充，二插搜索等
//Collections是操作集合类的——排序，拷贝，填充，二插搜索等
/**
 * Created by wengwei on 17-6-1.
 */
import java.io.ObjectInputStream;
import java.util.Arrays;
import java.util.Comparator;

class Stu{
    int num;
    String S;
    public Stu(){
    }
    public Stu(int num){
        this.num = num;
    }
    public Stu(int num,String s){
        this.num = num;
        this.S = s;
    }
    @Override
    public String toString(){
        return "Stu_num_"+num+"_S_"+S;
    }

    @Override
    public int hashCode() {
        int result = num;
        result = 31 * result + S.hashCode();
        return result;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Stu)) return false;

        Stu stu = (Stu) o;

        if (num != stu.num) return false;
        return S.equals(stu.S);
    }
    //    @Override
//    public boolean equals(Object obj) {
//        if(this==obj) return true;
//        if((obj==null)||(obj.getClass()!=this.getClass())) return false;
//        Stu test = (Stu)obj;
//        return num==test.num&&S.equals(test.S);
//    }
}
public class Test {
    public static void testone(){
        int[] num = new int[10];
        Arrays.fill(num,5);
        printv(num);
    }
    public static void testtwo(){
        int[] num = new int[10];
        printv(num);
        int[] num2 = Arrays.copyOf(num,num.length);
        printv(num2);
        if(num==num2){
            System.out.println("ok,address is same,not deep copy");
        }else{
            System.out.println("ok,address is not same ,deep copy");
        }
        num2[0] = 1;
        printv(num2);
        printv(num);
        if(num.equals(num2)){
            System.out.println("ok,same val");
        }
    }
    public static void testthree(){
        int[] num = new int[10];
        for(int i=0;i<10;++i){
            num[i] = 10-i;
        }
        printv(num);
        Arrays.sort(num);
        printv(num);

    }
    public static void testfour(){
        Stu[] num = new Stu[10];
        for(int i=0;i<num.length;++i){
            num[i] = new Stu(10-i,i+"");
        }
        for(Stu s:num){
            System.out.println(s);
        }
        System.out.println("==================================");
        Arrays.sort(num, new Comparator<Stu>() {
            @Override
            //返回-1才会更换元素
            //o1 是后一个o2是前一个
            public int compare(Stu o1, Stu o2) {
                if(o1.num < o2.num){
                    return -1;
                }
                return 0;
            }
        });
        for(Stu s:num){
            System.out.println(s);
        }
    }
    public static void printv(int[] num){
        for(Object o:num){
            System.out.print(o+" ");
        }
        System.out.println();
    }
    public static void main(String[] args){
//        Test.testone();
//        Test.testtwo();
//        Test.testthree();
        Test.testfour();
    }
}

