//LaBerge, Kaleena Ann
//COP-3530-01Z
//Project 6 (Queue Circle Elements)
//See output notes at the bottom

import java.util.Scanner;

public class CircleQueue {

    private class CircleNode {
        private double radius;
        private CircleNode next;

        public CircleNode(double radius) {
            this.radius = radius;
        }
    }

    private CircleNode front;
    private CircleNode rear;

    public CircleQueue() {
        front = null;
        rear = null;
    }

    public void enqueue(double radius) {
        CircleNode node = new CircleNode(radius);

        if (front == null) {
            front = node;
            rear = node;
        } else {
            rear.next = node;
            rear = node;
        }
    }

    public void dequeue() {
        if (front == null) {
            return;
        }

        CircleNode temp = front;
        front = front.next;

        if (front == null) {
            rear = null;
        }

        temp = null;
    }

    public void display() {
        CircleNode current = front;

        while (current != null) {
            System.out.println(current.radius);
            current = current.next;
        }
    }

    public static void main(String[] args) {
        CircleQueue queue = new CircleQueue();

        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("1. Enqueue");
            System.out.println("2. Dequeue");
            System.out.println("3. Display");
            System.out.println("4. Exit");

            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Enter the radius of the circle: ");
                    double radius = scanner.nextDouble();
                    queue.enqueue(radius);
                    break;
                case 2:
                    queue.dequeue();
                    break;
                case 3:
                    queue.display();
                    break;
                case 4:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice!");
            }
        } while (choice != 4);
    }
}

//I ran this in online Java compiler "programiz.com"
//Output and user entry as follows:
//java -cp /tmp/8nU7tk7KEp CircleQueue
//1. Enqueue
//2. Dequeue
//3. Display
//4. Exit
//1 entered by user
//Enter the radius of the circle:
//2 entered by user
//1. Enqueue
//2. Dequeue
//3. Display
//4. Exit
//3 entered by user
//1. Enqueue
//2. Dequeue
//3. Display
//4. Exit
//4 entered by user
//Exiting...
