import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("�������ַ����� ");
            String str = sc.nextLine();
            // ��Сдת��
            System.out.println("��Сдת������ַ���Ϊ�� " + exChange(str));
            // �ж��Ƿ�Ϊ����
            System.out.println("�Ƿ�Ϊ���ģ� " + ReverseStr(str));
            // ���������ַ������ӵ�һ���ַ�����ɾ���ڶ����ַ���������
            System.out.println("�������ַ���2�� ");
            String str2 = sc.nextLine();
            System.out.println("ɾ���󣬵�һ���ַ���Ϊ��" + DeleteString(str, str2));
            // ɾȥ�����ظ����ַ���ÿ���ַ�ֻ����һ��
            System.out.println("ɾȥ�����ظ����ַ�: " + DeleteRepeatChar(str));
            // ͳ��һ���ַ����и����ַ������ֵ�Ƶ��
            System.out.println("������һ���ַ�������" + str + "�У�");
            String str3 = sc.nextLine();
            System.out.println(str3 + "���ֵ�Ƶ��Ϊ: " + CharFrequency(str, str3));
            // ��һ����ʾʮ���������ַ���ת��Ϊ�Զ��ŷָ����ַ��������ұ߿�ʼÿ�������ֱ�һ������
            System.out.println("������һ�����֣� ");
            String str4 = sc.nextLine();
            System.out.println("�ָ��������Ϊ: " + AddComma(str4));
        }
    }

    // exChange����ת����Сд
    public static String exChange(String str) {
        StringBuffer sb = new StringBuffer();
        if (str != null) {
            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);
                if (Character.isUpperCase(c)) {
                    sb.append(Character.toLowerCase(c));
                } else if (Character.isLowerCase(c)) {
                    sb.append(Character.toUpperCase(c));
                }
            }
        }
        return sb.toString();
    }

    // ReverseStr�����ж��Ƿ�Ϊ����
    public static boolean ReverseStr(String str) {
        char[] arrayA = str.toCharArray();
        int top = 0;
        int end = arrayA.length - 1;
        if (str.equals("") || str.equals(null)) // �жϷǷ�����
            return false;
        while (top < end) {
            if (arrayA[top++] != arrayA[end--])
                return false;
        }
        return true;
    }

    // DeleteString������ɣ����������ַ������ӵ�һ���ַ�����ɾ���ڶ����ַ���������
    public static String DeleteString(String str, String str2) {
        str = str.replace("", "-"); // ��replace��ÿ���ַ���Ӹ�-
        String[] first = str.split("-");
        str2 = str2.replace("", "-"); // ͬ��
        String[] second = str2.split("-");

        for (int i = 0; i < first.length; i++) {
            for (int j = 0; j < second.length; j++) {
                if (first[i].equals(second[j])) {
                    str = str.replace(first[i], "");
                }
            }
        }
        // str=str.replace("-","");//ɾ��-
        return str.toString();
    }

    // DeleteRepeatChar����ɾ��str�е��ظ��ַ�
    public static String DeleteRepeatChar(String str) {
        StringBuilder sc = new StringBuilder(str);
        for (int i = 0; i < sc.length() - 1; i++) {
            for (int j = i + 1; j < sc.length(); j++) {
                if (sc.charAt(i) == sc.charAt(j)) {
                    sc.deleteCharAt(j);
                    j--;
                }
            }
        }
        return sc.toString();
    }

    // CharFrequency����ͳ��һ���ַ����и����ַ������ֵ�Ƶ��
    public static int CharFrequency(String str, String str3) {
        int count = 0;
        while (str.indexOf(str3) >= 0) {
            str = str.substring(str.indexOf(str3) + str3.length());
            count++;
        }
        return count;
    }

    // ��һ����ʾʮ���������ַ���ת��Ϊ�Զ��ŷָ����ַ��������ұ߿�ʼÿ�������ֱ�һ������
    public static String AddComma(String str) {
        StringBuffer ac = new StringBuffer(str);
        for (int i = str.length() - 3; i >= 0; i -= 3) {
            ac.insert(i, ",");
        }
        return ac.toString();
    }
}
