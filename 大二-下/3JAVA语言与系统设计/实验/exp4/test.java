import java.util.Random;

class FileCreateThread extends Thread{
    public Object start;
    private String fileName;
    Random r=new Random();
    int t=r.nextInt(10000);
    public FileCreateThread(String fileName){
        this.fileName=fileName;
    }
    public void run(){
        System.out.println("����"+fileName);
        try{
            Thread.sleep(t);
        }
        catch(Exception ex){}
        System.out.println(fileName+"������ϣ�");
    }

}
public class test{
    public static void main(String[]args)throws Exception{
        FileCreateThread f1=new FileCreateThread("�ļ�1");
        FileCreateThread f2=new FileCreateThread("�ļ�2");
        FileCreateThread f3=new FileCreateThread("�ļ�3");
        f1.start();
        f2.start();
        f3.start();
    }
}
