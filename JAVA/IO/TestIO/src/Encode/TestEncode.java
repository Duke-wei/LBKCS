package Encode;

import java.io.UnsupportedEncodingException;

/**
 * Created by wengwei on 17-5-31.
 */
public class TestEncode {
    public static void main(String[] args){
        String s = "慕慕课网ABC";
        byte[] bytes1 = s.getBytes();
        for(byte b:bytes1){
            System.out.print(Integer.toHexString(b & 0xff)+" ");
        }
        System.out.println();
        try {
            byte[] bytes2 = s.getBytes("gbk");
            for (byte b : bytes2) {
                System.out.print(Integer.toHexString(b & 0xff) + " ");
            }
            System.out.println();
            byte[] bytes3 = s.getBytes("utf-8");
            for (byte b : bytes3) {
                System.out.print(Integer.toHexString(b & 0xff) + " ");
            }
        }catch (UnsupportedEncodingException e){
            e.printStackTrace();
        }
    }
}
