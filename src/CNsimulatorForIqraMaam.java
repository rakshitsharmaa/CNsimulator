import java.util.*;


public class CNsimulatorForIqraMaam {

  public static class device {
    int mac;
    String data;
    public void setmac(int k) {
      this.mac = k;

    }
    public void setdata(String k) {
      this.data = k;
    }
  }

   public static class hub {
    String data;
    int mac;
    public device A, B, C, D, E;
    public hub() {
      data = "0";
      mac = 0;

    }

  hub(device A, device B, device C, device D, device E ) {
      data = "0";
      mac = 0;
      this.A = A;
      this.B = B;
      this.C = C;
      this.D = D;
      this.E = E;
    }
     public void store(int mac, String x, char s) {
      this.mac = mac;
      this.data = x;
      send(s);
    }


    private void send(char s) {
      if (s == 'A') {
        if (mac == B.mac && data == B.data)
          System.out.println("Mac Address matched with B and data send to it is " + data);
        else
          System.out.println("discard the data by B");
        if (mac == C.mac && data == C.data)
          System.out.println("Mac Address matched with C and data send to it is " + data);
        else
          System.out.println("discard the data by C");
        if (mac == D.mac && data == D.data)
          System.out.println("Mac Address matched with D and data send to it is " + data);
        else
          System.out.println("discard the data by D");
        if (mac == E.mac && data == E.data)
          System.out.println("Mac Address matched with E and data send to it is " + data);
        else
          System.out.println("discard the data by E");

      }
      if (s == 'B') {
        if (mac == A.mac && data == A.data)
          System.out.println("Mac Address matched with A and data send to it is " + data);
        else
          System.out.println("discard the data by A");
        if (mac == C.mac && data == C.data)
          System.out.println("Mac Address matched with C and data send to it is " + data);
        else
          System.out.println("discard the data by C");
        if (mac == D.mac && data == D.data)
          System.out.println("Mac Address matched with D and data send to it is " + data);
        else
          System.out.println("discard the data by D");
        if (mac == E.mac && data == E.data)
          System.out.println("Mac Address matched with E and data send to it is " + data);
        else
          System.out.println("discard the data by E");

      }
      if (s == 'C') {
        if (mac == B.mac && data == B.data)
          System.out.println("Mac Address matched with B and data send to it is " + data);
        else
          System.out.println("discard the data by B");
        if (mac == A.mac && data == A.data)
          System.out.println("Mac Address matched with A and data send to it is " + data);
        else
          System.out.println("discard the data by A");
        if (mac == D.mac && data == D.data)
          System.out.println("Mac Address matched with D and data send to it is " + data);
        else
          System.out.println("discard the data by D");
        if (mac == E.mac && data == E.data)
          System.out.println("Mac Address matched with E and data send to it is " + data);
        else
          System.out.println("discard the data by E");

      }
      if (s == 'D') {
        if (mac == B.mac && data == B.data)
          System.out.println("Mac Address matched with B and data send to it is " + data);
        else
          System.out.println("discard the data by B");
        if (mac == C.mac && data == C.data)
          System.out.println("Mac Address matched with C and data send to it is " + data);
        else
          System.out.println("discard the data by C");
        if (mac == A.mac && data == A.data)
          System.out.println("Mac Address matched with A and data send to it is " + data);
        else
          System.out.println("discard the data by A");
        if (mac == E.mac && data == E.data)
          System.out.println("Mac Address matched with E and data send to it is " + data);
        else
          System.out.println("discard the data by E");

      }
      if (s == 'E') {
        if (mac == B.mac && data == B.data)
          System.out.println("Mac Address matched with B and data send to it is " + data);
        else
          System.out.println("discard the data by B");
        if (mac == C.mac && data == C.data)
          System.out.println("Mac Address matched with C and data send to it is " + data);
        else
          System.out.println("discard the data by C");
        if (mac == A.mac && data == A.data)
          System.out.println("Mac Address matched with A and data send to it is " + data);
        else
          System.out.println("discard the data by A");
        if (mac == D.mac && data == D.data)
          System.out.println("Mac Address matched with D and data send to it is " + data);
        else
          System.out.println("discard the data by D");

      }

    }
  }

   public static void broadcast(int sender, int receiver, String d, device[] dev, int devices) {
    for (int i = 0; i < devices; i++) {
      if (sender - 1 == i)
        continue;
      for (int j = 0; j < d.length(); j++) {
        long starttime = System.currentTimeMillis();
        System.out.println("The sender " + sender + " sends frame no " + (j + 1) + " to the receiver " + (i + 1));
        dev[i] = new device();
        if (i == receiver - 1) {
          int k = errorControl(j);
          if (k == j) {
            System.out.println("The receiver " + (i + 1) + " discard frame no " + (j + 1) + "and send an ack " + (j + 1));
            j--;

          } else {
            dev[i].data += d.charAt(j);
            System.out.println("The receiver " + (i + 1) + " receives frame no " + (j + 1) + " containing data " + d.charAt(j) + " successfully "
                               + "and send an ack " + (j + 2));
            System.out.println("The sender " + sender + " receives the ack ");

          }
        } else {
          System.out.println("The receiver " + (i + 1) + " discard the data");

        }
        long endtime = System.currentTimeMillis();
        System.out.println("RoundTrip Time :" + (endtime - starttime) + "ms \n");



      }

    }
    System.out.println("Broadcast domain = 1 \nCollision Domain = " + devices);
  }
  public static void broadcast2(int sender, int receiver, String d, device[] dev, int devices) {
    boolean flag = false;
    int size = 4;
    int k = 1;
    int upto = 0;
    long start = System.currentTimeMillis();
    for (int i = 0; i < devices; i++) {
      if (sender - 1 == i)
        continue;

      for (int j = 0; j < d.length() || (i == receiver - 1 && upto < d.length()); j++) {
        long starttime = System.currentTimeMillis();
        if (k != size && j < d.length())
          System.out.println("The sender " + sender + " sends frame no " + (j + 1) + " to the receiver " + (i + 1));


        dev[i] = new device();
        if (i == receiver - 1) {
          if (j < d.length() && flag && k < size) {
            System.out.println("The receiver " + (i + 1) + " discard frame no " + (j + 1) + "and send an ack " + upto);
            System.out.println("The sender " + sender + " receives the ack \n");
            k++;
          } else if (flag && ( k == size || j >= d.length())) {
            flag = false;
            j = upto;
            k = 1;
            System.out.println("The sender " + sender + " sends frame no " + (j + 1) + " to the receiver " + (i + 1));
          }
          if (j == upto) {
            int k1 = errorControl(j);
            if (k1 == j) {
              if (!flag) {
                flag = true;
                k++;
                upto = k1;

              }
              System.out.println("The receiver " + (i + 1) + " discard frame no " + (j + 1) + " and send an ack " + upto);
              System.out.println("The sender " + sender + " receives the ack \n");

            }
          }

          if (!flag) {
            dev[i].data += d.charAt(j);
            System.out.println("The receiver " + (i + 1) + " receives frame no " + (j + 1) + " containing data " + d.charAt(j) + " successfully "
                               + "and send an ack " + (++upto));
            System.out.println("The sender " + sender + " receives the ack ");

          }

        } else {
          System.out.println("The receiver " + (i + 1) + " discard the data");

        }
        long endtime = System.currentTimeMillis();
        System.out.println("RoundTrip Time :" + (endtime - starttime) + "ms \n");



      }
      if (System.currentTimeMillis() - start > 50) {
        System.out.println("time out occured please restart transmission");
        break;
      }

    }
    System.out.println("Broadcast domain = 1 \nCollision Domain = " + devices);
  }
  public  static int errorControl(int k) {
    Random p = new Random();
    int rand = p.nextInt(100);
    if (rand <= 80)
      return k + 1;
    else
      return k;

  }

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
