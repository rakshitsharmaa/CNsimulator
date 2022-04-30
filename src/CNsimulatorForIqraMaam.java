import java.util.*;


public class CNsimulatorForIqraMaam {
   public static void main(String [] args) {
    @SuppressWarnings("resource")
    Scanner s = new Scanner(System.in);
    System.out.println("press 1 for physical layer \npress 2 for Data Link layer ");
    int choice = s.nextInt();
    device A = new device();
    device B = new device();
    device C = new device();
    device D = new device();
    device E = new device();

    switch (choice) {
    case 1:
      A.setmac(555);
      B.setmac(111);
      C.setmac(222);
      D.setmac(333);
      E.setmac(444);
      A.setdata("0");
      B.setdata("0");
      C.setdata("0");
      D.setdata("0");
      E.setdata("0");
      System.out.print("Intialise Mac Address and Data :\n");
      System.out.println("A : " + A.mac + ": " + A.data);
      System.out.println("B : " + B.mac + ": " + B.data);
      System.out.println("C : " + C.mac + ": " + C.data);
      System.out.println("D : " + D.mac + ": " + D.data);
      System.out.println("E : " + E.mac + ": " + E.data);

      System.out.println("Enter Sender :\n1.A\n2.B\n3.C\n4.D\n5.E");
      char se = s.next().charAt(0);
      System.out.println("Enter Reciever :\n1.A\n2.B\n3.C\n4.D\n5.E");
      char r = s.next().charAt(0);
      System.out.println("Enter Datar :");
      String d = s.next();
      System.out.println("Press 1 for dedicated or Press 2 for star topology" );
      int cn = s.nextInt();
      hub h = new hub(A, B, C, D, E);
      switch (cn) {
      case 1:
        if (r == 'A' || r == 'B' || r == 'C' || r == 'D' || r == 'E') {
          if (r == 'A')
            A.setdata(d);
          if (r == 'B')
            B.setdata(d);
          if (r == 'C')
            C.setdata(d);
          if (r == 'D')
            D.setdata(d);
          if (r == 'E')
            E.setdata(d);
          System.out.print("Now Mac Address and Data :\n");
          System.out.println("A : " + A.mac + ": " + A.data);
          System.out.println("B : " + B.mac + ": " + B.data);
          System.out.println("C : " + C.mac + ": " + C.data);
          System.out.println("D : " + D.mac + ": " + D.data);
          System.out.println("E : " + E.mac + ": " + E.data);

        }
        break;
      case 2:
        if (r == 'A' || r == 'B' || r == 'C' || r == 'D' || r == 'E') {
          if (r == 'A') {
            A.setdata(d);
            h.store(A.mac, d, se);
          }
          if (r == 'B') {
            B.setdata(d);
            h.store(B.mac, d, se);
          }
          if (r == 'C') {
            C.setdata(d);
            h.store(C.mac, d, se);
          }
          if (r == 'D') {
            D.setdata(d);
            h.store(D.mac, d, se);
          }
          if (r == 'E') {
            E.setdata(d);
            h.store(E.mac, d, se);
          }

        }
        huback(r, se, 5);

        break;
      default : System.out.println("Enter invalid chice");


      }
      break;
    case 2:
      int bridge = 0;
      System.out.println("Press 1 for Switch - End device configurtion \nPress 2 for Switch - Hub - End Device configuration ");
      int k = s.nextInt();
      switch (k) {
      case 1:
        System.out.println("Switch is created,Enter the number of Devices\n");
        int devices = s.nextInt();
        boolean t = true;
        while (t) {
          System.out.println("Enter the Sender(should be 1,2,3 etc) :");
          int  sender = s.nextInt();
          System.out.println("Enter the Receiver(should be 1,2,3 etc) :");
          int  receiver = s.nextInt();

          System.out.println("Enter the Data");
          d = s.next();
          bridge++;
          System.out.println("Go Back N protocol is used");
          transmission(sender, receiver, d, bridge, devices);
          System.out.println("want to sent again? y/n");
          char reply = s.next().charAt(0);
          if (reply != 'y')
            t = false;




        }
        break;
      case 2:
        System.out.println("\nEnter number of end Devices in 1st Hub\n");
        int h1 = s.nextInt();

        System.out.println("\nEnter number of end Devices in 2nd Hub\n");
        int h2 = s.nextInt();
        boolean flag2 = true ;
        bridge = 0;
        while (flag2) {
          System.out.println("Enter the Sender(should be 1,2,3 etc) :");
          int  sender = s.nextInt();
          System.out.println("Enter the Receiver(should be 1,2,3 etc) :");
          int  receiver = s.nextInt();

          System.out.println("Enter the Data");
          d = s.next();
          bridge++;
          System.out.println("Stop and wait protocol is used");
          transmission2(sender, receiver, d, bridge, h1 + h2, h1);
          System.out.println("want to sent again? y/n");
          char reply = s.next().charAt(0);
          if (reply != 'y')
            t = false;


        }

      }

    }
  }
}
