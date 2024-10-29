public class Car {
    String color;
    String type;
    String brand;
    int miles;
    int year;
    int price;


    public Car(String color) {
        this.color = color;
    }

    public Car(String color, String type, String brand, int miles, int year, int price) {
        this.color = color;
        this.type = type;
        this.brand = brand;
        this.miles = miles;
        this.year = year;
        this.price = price;
    }

    public int getPrice() {
        return price;
    }

    public void testDrive(){
        System.out.println("I am going on a test drive with " + color + " " + brand + " " + type);
    }

    public static void main(String[] args) {
        Car mycar = new Car("Blue", "Truck", "Ford", 34567, 2017, 15000);
        Car secondcar = new Car("Green", "Truck", "GM", 34567, 2014, 9000);

        System.out.println("mycar: " + mycar.getPrice());
        System.out.println("secondcar: " + secondcar.getPrice());

        mycar.testDrive();

    }
}

