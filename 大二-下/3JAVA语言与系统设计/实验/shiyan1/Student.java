public class Student {
    private String sNO;  // ѧ��
    private String sName;  // ����
    private String sSex;  // �Ա�
    private int sAge;  // ����
    private double sJava;  // Java�γ̳ɼ�
    
    public Student(String no, String name, String sex, int age, double java) {
        this.sNO = no;
        this.sName = name;
        this.sSex = sex;
        this.sAge = age;
        this.sJava = java;
    }
    
    public String getNo() {
        return this.sNO;
    }
    
    public String getName() {
        return this.sName;
    }
    
    public String getSex() {
        return this.sSex;
    }
    
    public int getAge() {
        return this.sAge;
    }
    
    public double getJava() {
        return this.sJava;
    }
}