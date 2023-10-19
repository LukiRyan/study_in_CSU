abstract class Shape{
    public String getName(){
        return this.getClass().getName();//���Բ�ε�����
    }
    public abstract double getArea();
}
class Rectangle extends Shape {
    private double length;
    private double width;

    public Rectangle(double length,double width ) {
        this.length = length;
        this.width = width;
    }
    @Override
    public double getArea(){
        return length*width;
    }
}

class Circle extends Shape{
    private double radius;
    public Circle(double radius){
        this.radius=radius;
        }
        @Override
        public double getArea(){
        return Math.PI*Math.pow(radius,2);
        }
    }
public class Test{
    public static void main(String[] args){
        Circle circle =new Circle(1);
        System.out.println("Բ�ε�����Ϊ�� "+circle.getName());
        System.out.println("Բ�ε����Ϊ�� "+circle.getArea());
        Rectangle rectangle=new Rectangle(1,1);
        System.out.println("���ε�����Ϊ�� "+rectangle.getName());
        System.out.println("���ε������Ϊ�� "+rectangle.getArea());
    }
}