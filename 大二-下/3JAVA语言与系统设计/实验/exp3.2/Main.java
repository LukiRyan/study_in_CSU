import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // ����һ�� Graduate ���� stu1
        Graduate stu1 = new Graduate("zhangsan", "��", 23);

        // ����һ�� Scanner �������ڶ�ȡ����
        Scanner input1 = null;
        try {
            input1 = new Scanner(System.in);
            System.out.println("������" + stu1.name + "��ÿ�¹���(12)��ÿѧ��ѧ��(2)��");
            // ��ȡ����Ĺ��ʺ�ѧ��
            int pay = input1.nextInt(); //����
            int fee = input1.nextInt(); //ѧ��

            // ���� Graduate ����Ĺ��ʺ�ѧ��
            stu1.setpay(pay);
            stu1.setfee(fee);

            // ���㣺����-ѧ��
            int subs = stu1.income() - stu1.tuition();
            System.out.println(stu1.income() + "-" + stu1.tuition() + "=" + subs);

            // �ж��Ƿ���Ҫ����
            if (subs <= 2000) {
                System.out.println("You need a loan!");
            } else {
                System.out.println("You income is enough!");
            }
        } finally {
            // �ر� Scanner �����ͷ���Դ
            if (input1 != null) {
                input1.close();
            }
        }
    }
}
