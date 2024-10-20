public class MacBook {
    String processor;
    int numUsbCPorts;


    public MacBook(int generation){
        if(generation == 1){
            processor = "Intel i5-8500k";
            numUsbCPorts = 0;
        }
        else if(generation == 2){
            processor = "Intel i7-8500k";
            numUsbCPorts = 2;
        }
        else{
            processor = "I'm not sure";
            numUsbCPorts = 0;
        }
    }


    public void runMe(){
        System.out.println(processor);
    }

}
