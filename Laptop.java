public class Laptop {
    

    public static void main(String[] args){




        MacBook myLaptop = new MacBook(1);
        // System.out.println(myLaptop.numUsbCPorts);

        MacBook lostLaptop = new MacBook(2);
        // System.out.println(lostLaptop.processor);
        // System.out.println(myLaptop.processor);

        myLaptop.runMe();
        lostLaptop.runMe();

        // runMe();

        System.out.println(myLaptop.processor);

    }
}
