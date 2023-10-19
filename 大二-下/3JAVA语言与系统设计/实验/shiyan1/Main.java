public class Main {
    public static void main(String[] args) {
        Student student1 = new Student("001", "Tom", "Male", 18, 85.5);
        Student student2 = new Student("002", "Mary", "Female", 19, 91.0);
        
        System.out.println("Student 1 info:");
        System.out.println("NO: " + student1.getNo());
        System.out.println("Name: " + student1.getName());
        System.out.println("Sex: " + student1.getSex());
        System.out.println("Age: " + student1.getAge());
        System.out.println("Java score: " + student1.getJava());
        
        System.out.println("Student 2 info:");
        System.out.println("NO: " + student2.getNo());
        System.out.println("Name: " + student2.getName());
        System.out.println("Sex: " + student2.getSex());
        System.out.println("Age: " + student2.getAge());
        System.out.println("Java score: " + student2.getJava());
        
        double average = (student1.getJava() + student2.getJava()) / 2;
        System.out.println("Average Java score: " + average);

        Student s1 = new Student("001", "����", "��", 18, 89.5);
        Student s2 = new Student("002", "����", "Ů", 19, 92.0);
        Student s3 = new Student("003", "����", "��", 20, 85.5);
        Student s4 = new Student("004", "����", "Ů", 21, 95.0);
        Student s5 = new Student("005", "Ǯ��", "��", 22, 88.5);
        
        // ����Java���Գɼ������ֵ����Сֵ
        double max = Math.max(s1.getJava(), Math.max(s2.getJava(), Math.max(s3.getJava(), Math.max(s4.getJava(), s5.getJava()))));
        double min = Math.min(s1.getJava(), Math.min(s2.getJava(), Math.min(s3.getJava(), Math.min(s4.getJava(), s5.getJava()))));
        System.out.println("Java�ɼ����ֵΪ��" + max);
        System.out.println("Java�ɼ���СֵΪ��" + min);
    }
}