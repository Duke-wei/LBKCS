package TestFile;

import java.io.File;
import java.io.IOException;

/**
 * Created by wengwei on 17-5-31.
 */
public class TestFileUtils {
    public static void main(String[] args){
        try {
            FileUtils.listDirectory(new File("."));
        }catch (IOException e){
            e.printStackTrace();
        }
    }
}

