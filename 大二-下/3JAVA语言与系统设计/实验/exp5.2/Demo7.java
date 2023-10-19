import java.io.*;

public class Demo7 {
    private Isprim sushu = null;
    FileOutputStream fos = null;
    public Demo7() {
        try {
            fos = new FileOutputStream("D://prime.dat");
            sushu = new Isprim();
            for(int i=2;i<=200;i++)
            {
                if(sushu.isPrim(i)){
                    fos.write(i);
                    System.out.println(i);
                }
            }
            fos.close();
        } catch (FileNotFoundException e) {
            System.out.println("�Ҳ���ָ���ļ�"); System.exit(-1);
        }catch (IOException e){
            System.out.println("�ļ�д�����"); System.exit(-1);
        }
        System.out.println("�ļ�д����ϣ�");
    }
    public static void main(String[] args) {
        Demo7 tip = new Demo7();
    }
//����Isprime�������ж�һ�����Ƿ�������
    class Isprim {
        public Isprim(){
        }
        public boolean isPrim(int m)
        {
            int i=2;
            boolean flag=true;
            while(true)
            {
                if(m%i==0)
                {
                    flag=false;
                    break;
                }
                i++;
            }
            return flag;
        }

    }

}
