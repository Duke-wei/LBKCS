package TestCollection;
import java.util.*;
import java.util.Map.Entry;

/**
 * Created by wengwei on 17-6-1.
 */
class Student{
    public Student(){}
    public Student(int x){
        val = x;
    }
    public void Setval(int x){
        val = x;
    }
    public int Getval(){
        return val;
    }
    @Override
    public String toString(){
        return "Student_vla_"+val;
    }
    private int val;
}
public class Test {
    public static void testLinkedList() {
        List li = new LinkedList();
//        List li = new LinkedList<Integer>();
        li.add(1);
        li.add("adfasdf");
        li.add(2);
        li.add(3);
        li.add(4);
        li.add(5);
        testPrint(li);
        li.remove(1);
        testPrint(li);
//        for(Integer i:li){
//            System.out.print(i);
//        }
    }
    public static void testArraylist(){
        List li = new ArrayList();
        li.add(1);
        li.add("adf");
        li.add('a');
        li.add(new Student());
        testPrint(li);
        List<Integer> lii = new ArrayList<>();
        lii.add(34);
        lii.add('A'-'B');
        testPrint(lii);
        lii.remove(Integer.valueOf(34));
        testPrint(lii);
        lii.clear();
        testPrint(lii);
    }
    public static void testSet(){
        Set s = new HashSet();
        s.add(1);
        s.add(1);
        testPrint(s);
    }
    public static void testTreeSet(){
        Set s = new TreeSet();
        s.add(1);
        s.remove(1);
        s.clear();
        if(s.contains(1)){
            System.out.println("OK,......");
        }
    }
    public static void testMap(){
        Map m = new HashMap();
        m.put(1,"1");
        m.put(2,"2");
        m.put(3,"3");
        String t = (String)m.get(2);
        System.out.println(t);
        m.remove(2);
        String r = (String)m.replace(3,"4");
        System.out.println("old val is "+r);
        testPrintM(m);
    }
    public static void testPrint(Collection co){
        Iterator io = co.iterator();
        while(io.hasNext()){
            System.out.print(io.next()+" ");
        }
        System.out.println();
    }
    public static void testPrintM(Map m){
        for(Object o:m.keySet()){
            System.out.println(o+":"+m.get(o));
        }
        System.out.println();
    }
    public static void testIPrint(Iterator io){
        while(io.hasNext()){
            System.out.print(io.next()+" ");
        }
        System.out.println();
    }
    public static void main(String[] args){
//        Test.testLinkedList();
//        Test.testArraylist();
//        testSet();
        testMap();
    }
}
