// Circle.java

public class Circle {

    private double diameter = 10;

    public Circle() {
        this.diameter = 10.0; //this creates the object and gives it a default diameter.
    }

    public Circle(double diameter) {
        this.diameter = diameter;
    }

    public double getDiameter() {
        return diameter;
    }

    public void setDiameter(double diameter) {
        if (diameter > 0.0 && diameter < 20.0) {
            this.diameter = diameter;
        } else {
            throw new IllegalArgumentException("Diameter must be between 0.0 and 20.0");
        }
    }

    public double getArea() {
        return Math.PI * (this.diameter / 2) * (this.diameter / 2);
    }

    public double getPerimeter() {
        return 2 * Math.PI * (this.diameter / 2);
    }

    public void printAreaAndPerimeter() {
        System.out.println("Area: " + this.getArea());
        System.out.println("Perimeter: " + this.getPerimeter());
    }
}

// CircleTest.java

import java.util.Scanner;

public class CircleTest {

    public static void main(String[] args) {
        Circle circle = new Circle();
        System.out.println("Circle with default diameter:");
        circle.printAreaAndPerimeter();

        Circle starterCircle = new Circle(5);
        System.out.println("Circle with starter diameter:");
        starterCircle.printAreaAndPerimeter();

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a new diameter: ");
        double newDiameter = scanner.nextDouble();
        circle.setDiameter(newDiameter);
        System.out.println("Circle with new diameter:");
        circle.printAreaAndPerimeter();
    }
}