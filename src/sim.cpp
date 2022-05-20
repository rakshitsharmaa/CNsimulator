 #include<bits/stdc++.h>
 #define ll long long int
 using namespace std;

// int main()
// {
//     int a,n;
//     cout<<"press 1 for physical layer"<<endl;
//     cout<<"press 2 for data link layer"<<endl;
//     cin>>n;
//     if(n==1){
//         cout << "What type of connection do you want : ";
//         cout << endl << "1.Dedicated connection ";
//         cout << endl << "2.Star Topology ";
//           cin >> a;
//     if (a == 1) //Dedicated Connection
//     {
//         dedicatedConnection();
//     }
//     else if (a == 2)
//     {
//         starTopology();
        
//     }
//     }
//     if(n==2){
//          cout << "What type of connection do you want : ";
//         cout << endl << "1.Switch";
//          cout<<endl<<"2. Hub";
//          cout << endl << "3.Selective Repeat" << endl;
          
        
//      cin >> a;
//      if (a == 1)
//     {
//         switches();
//     }
//     if(a==2){
//         hub();
//     }
//     else if (a == 3)
//     {
//        selectiveRepeate();
//     }
    
//     else
//         cout << "Invalid choice.";
//     return 0;
//     }

class device {
    public:
    int mac;
    string data;
     void setmac(int k) {
      this->mac = k;

    }
     void setdata(string k) {
      this->data = k;
    }
  };

int errorControl(int k) {
    //Random p = new Random();
    int randm = (int)rand()%100;
    if (randm <= 80)
      return k + 1;
    else
      return k;

  }


 class hub {
     public:
    string data;
    int mac;
     device A, B, C, D, E;
     hub() {
      data = "0";
      mac = 0;

    }

  hub(device A, device B, device C, device D, device E ) {
      data = "0";
      mac = 0;
      this->A = A;
      this->B = B;
      this->C = C;
      this->D = D;
      this->E = E;
    }
      void store(int mac, string x, char s) {
      this->mac = mac;
      this->data = x;
      send(s);
    }


     void send(char s) {
      if (s == 'A') {
        if (mac == B.mac && data == B.data)
          cout<<"Mac Address matched with B and data send to it is "<< data<<endl;
        else
          cout<<"discard the data by B"<<endl;
        if (mac == C.mac && data == C.data)
          cout<<"Mac Address matched with C and data send to it is " << data<<endl;
        else
          cout<<"discard the data by C"<<endl;
        if (mac == D.mac && data == D.data)
          cout<<"Mac Address matched with D and data send to it is " << data<<endl;
        else
          cout<<"discard the data by D"<<endl;
        if (mac == E.mac && data == E.data)
          cout<<"Mac Address matched with E and data send to it is "<< data<<endl;
        else
          cout<<"discard the data by E"<<endl;

      }
      if (s == 'B') {
        if (mac == A.mac && data == A.data)
          cout<<"Mac Address matched with A and data send to it is " << data<<endl;
        else
          cout<<"discard the data by A"<<endl;
        if (mac == C.mac && data == C.data)
          cout<<"Mac Address matched with C and data send to it is " << data<<endl;
        else
          cout<<"discard the data by C"<<endl;
        if (mac == D.mac && data == D.data)
          cout<<"Mac Address matched with D and data send to it is " <<data<<endl;
        else
          cout<<"discard the data by D"<<endl;
        if (mac == E.mac && data == E.data)
         cout<<"Mac Address matched with E and data send to it is "<< data<<endl;
        else
          cout<<"discard the data by E"<<endl;

      }
      if (s == 'C') {
        if (mac == B.mac && data == B.data)
          cout<<"Mac Address matched with B and data send to it is " << data<<endl;
        else
          cout<<"discard the data by B"<<endl;
        if (mac == A.mac && data == A.data)
         cout<<"Mac Address matched with A and data send to it is " << data<<endl;
        else
          cout<<"discard the data by A"<<endl;
        if (mac == D.mac && data == D.data)
          cout<<"Mac Address matched with D and data send to it is " <<data<<endl;
        else
          cout<<"discard the data by D"<<endl;
        if (mac == E.mac && data == E.data)
          cout<<"Mac Address matched with E and data send to it is "<< data<<endl;
        else
          cout<<"discard the data by E"<<endl;

      }
      if (s == 'D') {
        if (mac == B.mac && data == B.data)
         cout<<"Mac Address matched with B and data send to it is " << data<<endl;
        else
          cout<<"discard the data by B"<<endl;
        if (mac == C.mac && data == C.data)
          cout<<"Mac Address matched with C and data send to it is " << data<<endl;
        else
          cout<<"discard the data by C"<<endl;
        if (mac == A.mac && data == A.data)
          cout<<"Mac Address matched with A and data send to it is " << data<<endl;
        else
        cout<<"discard the data by A"<<endl;
        if (mac == E.mac && data == E.data)
        cout<<"Mac Address matched with E and data send to it is " << data<<endl;
        else
        cout<<"discard the data by E"<<endl;

      }
      if (s == 'E') {
        if (mac == B.mac && data == B.data)
        cout<<"Mac Address matched with B and data send to it is "<< data<<endl;
        else
        cout<<"discard the data by B"<<endl;
        if (mac == C.mac && data == C.data)
        cout<<"Mac Address matched with C and data send to it is "<< data<<endl;
        else
        cout<<"discard the data by C"<<endl;
        if (mac == A.mac && data == A.data)
        cout<<"Mac Address matched with A and data send to it is "<< data<<endl;
        else
        cout<<"discard the data by A"<<endl;
        if (mac == D.mac && data == D.data)
        cout<<"Mac Address matched with D and data send to it is " << data<<endl;
        else
        cout<<"discard the data by D"<<endl;

      }

    }
  };

  void broadcast(int sender, int receiver, string d, device dev[], int devices) {
    for (int i = 0; i < devices; i++) {
      if (sender - 1 == i)
        continue;
      for (int j = 0; j < d.length(); j++) {
        long starttime = clock();
    cout<<"The sender " << sender << " sends frame no " << j + 1 << " to the receiver "<< i + 1<<endl;
        //dev[i] = new device();
        if (i == receiver - 1) {
          int k = errorControl(j);
          if (k == j) {
        cout<<"The receiver " << i + 1 << " discard frame no " << j + 1 << "and send an ack " << j + 1<<endl;
            j--;

          } else {
            dev[i].data += d[j];
        cout<<"The receiver " << i + 1 << " receives frame no " << j + 1 << " containing data " << d[j] << " successfully "
                               << "and send an ack " <<j + 2<<endl;
        cout<<"The sender " << sender << " receives the ack "<<endl;

          }
        } else {
        cout<<"The receiver "<< i + 1 << " discard the data"<<endl;

        }
        long endtime = (long)clock();
    cout<<"RoundTrip Time :" << (endtime - starttime) <<"ms \n";



      }

    }
cout<<"Broadcast domain = 1 \nCollision Domain = "<< devices<<endl;
  }



   void broadcast2(int sender, int receiver, string d, device dev[], int devices) {
    bool flag = false;
    int size = 4;
    int k = 1;
    int upto = 0;
    long start = clock();
    for (int i = 0; i < devices; i++) {
      if (sender - 1 == i)
        continue;

      for (int j = 0; j < d.length() || (i == receiver - 1 && upto < d.length()); j++) {
        long starttime = clock();
        if (k != size && j < d.length())
        cout<<"The sender " << sender << " sends frame no "<<j + 1 << " to the receiver " << i + 1<<endl;


        //dev[i] = new device();
        if (i == receiver - 1) {
          if (j < d.length() && flag && k < size) {
        cout<<"The receiver "<< i + 1 << " discard frame no " << j + 1 << "and send an ack " << upto<<endl;
        cout<<"The sender " << sender <<" receives the ack \n";
            k++;
          } else if (flag && ( k == size || j >= d.length())) {
            flag = false;
            j = upto;
            k = 1;
        cout<<"The sender " << sender << " sends frame no " << j + 1 << " to the receiver " << i + 1<<endl;
          }
          if (j == upto) {
            int k1 = errorControl(j);
            if (k1 == j) {
              if (!flag) {
                flag = true;
                k++;
                upto = k1;

              }
            cout<<"The receiver "<< i + 1 << " discard frame no " << j + 1<< " and send an ack " << upto<<endl;
            cout<<"The sender " << sender << " receives the ack \n";

            }
          }

          if (!flag) {
            dev[i].data += d[j];
        cout<<"The receiver "<< i + 1 << " receives frame no " <<j + 1 <<" containing data " << d[j] << " successfully "
                               <<"and send an ack " << ++upto<<endl;
        cout<<"The sender " << sender << " receives the ack "<<endl;

          }

        } else {
        cout<<"The receiver "<< i + 1 << " discard the data"<<endl;

        }
        long endtime = clock();
    cout<<"RoundTrip Time :" << (endtime - starttime) <<"ms \n";



      }
      if ((long)clock() - start > 50) {
    cout<<"time out occured please restart transmission"<<endl;
        break;
      }

    }
cout<<"Broadcast domain = 1 \nCollision Domain = " << devices<<endl;
  }




 void transmission(int sender, int receiver, string d, int bridge, int devices) {
    device dev[devices];
    bool flag = false;
    int size = 4;
    int k = 1;
    int upto = 0;
    if (bridge == 1) {
      for (int i = 0; i < devices; i++) {
       // dev[i] = new device();
        dev[i].setmac(i + 10);

      }
      broadcast2(sender, receiver, d, dev, devices);
    } else {


      for (int i = 0; i < devices; i++) {
        if (receiver - 1 == i) {
          long start = clock();
          for (int j = 0; j < d.length() || upto < d.length(); j++) {



            long starttime = clock();
            if (k != size && j < d.length())
            cout<<"The sender "<< sender << " sends frame no " << j + 1 << " to the receiver "<<i + 1<<endl;


           // dev[i] = new device();
            if (i == receiver - 1) {
              if (j < d.length() && flag && k < size) {
            cout<<"The receiver " << i + 1<< " discard frame no " <<j + 1<< "and send an ack " << upto<<endl;
            cout<<"The sender " << sender << " receives the ack \n";
                k++;
              } else if (flag && (k == size || j >= d.length())) {
                flag = false;
                j = upto;
                k = 1;
            cout<<"The sender " << sender << " sends frame no " << j + 1 << " to the receiver " << i + 1<<endl;
              }
              if (j == upto) {
                int k1 = errorControl(j);
                if (k1 == j) {
                  if (!flag) {
                    flag = true;
                    k++;
                    upto = k1;

                  }
                cout<<"The receiver "<< i + 1<< " discard frame no " << j + 1<< "and send an ack " <<upto<<endl;
                cout<<"The sender " << sender << " receives the ack \n";

                }
              }

              if (!flag) {
                dev[i].data += d[j];
            cout<<"The receiver "<< i + 1<< " receives frame no " << j + 1 << " containing data " << d[j] << " successfully "
                                   << "and send an ack " << ++upto<<endl;
            cout<<"The sender " <<sender << " receives the ack \n";

              }

            } else {
            cout<<"The receiver " << i + 1 << " discard the data"<<endl;


            }
            long endtime = clock();
        cout<<"RoundTrip Time :" << (endtime - starttime) <<"ms \n";


            if ((long)clock() - start > 50) {
            cout<<"time out occured please restart transmission";
              break;
            }
          }
        }
      }

    cout<<"Broadcast domain = 1 \nCollision Domain = " << devices;
    }
  }



     void transmission2(int sender, int receiver, string d, int bridge, int devices, int h1) {
    device dev[devices]; 
    if (bridge == 1) {
    cout<<"The Switch forwards the data 1st time "<<endl;
      for (int i = 0; i < devices; i++) {
       // dev[i] = new device();
        dev[i].setmac(i + 10);

      }
      broadcast(sender, receiver, d, dev, devices);
    } else {
      if (sender <= h1 && receiver <= h1) {
    cout<<"\nThe switch denied to pass the packet from Hub 1 to Hub 2"<<endl;
        for (int p = 0; p < h1; p++) {
          if (sender == p + 1) continue;



          for (int j = 0; j < d.length(); j++) {
            long startTime = clock();
        cout<<"\nThe Sender "<< sender << " sends frame no. " <<j + 1 << " to the receiver "<< p + 1<<endl;

            if (p == receiver - 1) {
              int k = errorControl(j);
              if (k == j) {
            cout<<"The receiver " << p + 1 <<" discard frame no " << j + 1 << "and send an ack "<<j + 1<<endl;
                j--;

              } else {
               // dev[p] = new device();
                dev[p].data += d[j];
            cout<<"\nThe Receiver "<< p + 1 << " receives frame no. " <<j + 1 << " containing the data " << d[j] << " and sends back ack " <<j + 2<<endl;
            cout<<"\n The sender "<< sender << " receives the ack \n\n\n"<<endl;
              }
            }

            else {
            cout<<"\nReceievr Discarded the info \n";

              long endTime = clock();
              long durationInNano = (endTime - startTime);
            cout<<"Roundtrip Time: " << durationInNano << " ms \n ";
            }
          }

        }
    cout<<"Broadcast domain = 1 \nCollision domain = 2"<<endl;
      } else if (sender > h1 && receiver > h1) {
    cout<<"\nThe switch denied to pass the packet from Hub 2 to Hub 1";
        for (int p = h1; p < devices; p++) {
          if (sender == p + 1) continue;

          //broadCast(data,sender,receiver,d,device);

          for (int i = 0; i < d.length(); i++) {
            long startTime = clock();

        cout<<"\nThe Sender " << sender <<" sends frame no. " << i + 1 << " to the receiver " << p + 1<<endl;

            if (p == receiver - 1) {
             // dev[p] = new device() ;
              dev[p].data += d[i];
            cout<<"\nThe Receiver " << p + 1<< " receives frame no. " << i + 1 << " containing the data " << d[i] << " and sends back ack "<<endl;
            cout<<"\n The sender "<< sender << " receives the ack \n\n\n";
            } else
            cout<<"Receiver Discarded the info"<<endl;

            long endTime = clock();
            long durationInNano = (endTime - startTime);
        cout<<"Roundtrip Time: "<< durationInNano << " ms \n";

          }

        }
    cout<<"Broadcast domain = 1 \nCollision domain = 2"<<endl;
      } else broadcast(sender, receiver, d, dev, devices);
    }
  }





  void huback(char se, char r, int device) {
    for (int i = 0; i < device; i++) {
      char k = (char)(65 + i);
      if (se == (65 + i))
        continue;

      else if (r == 65 + i)
    cout<<"ACK accepted by the receiver " << r<<endl;
      else
    cout<<"ACK discard by the receiver " << k<<endl;

    }
  }
 int main() {
    cout<<"press 1 for physical layer \npress 2 for Data Link layer "<<endl;
    int choice;
    cin>>choice;
    device A ,B,C,D,E;
   string d;
   bool tee=true;

    
    if(choice==1){
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
      cout<<"Intialise Mac Address and Data :\n"<<endl;
      cout<<"A : " << A.mac << ": " << A.data<<endl;
      cout<<"B : " << B.mac << ": " << B.data<<endl;
      cout<<"C : " << C.mac << ": " << C.data<<endl;
      cout<<"D : " << D.mac << ": " << D.data<<endl;
      cout<<"E : " << E.mac << ": " << E.data<<endl;

      cout<<"Enter Sender :\n1.A\n2.B\n3.C\n4.D\n5.E"<<endl;
      char se;
      cin>>se;
      cout<<"Enter Reciever :\n1.A\n2.B\n3.C\n4.D\n5.E"<<endl;
      char r;
      cin>>r;
      cout<<"Enter Data :"<<endl;
      //string d;
      cin>>d;
      cout<<"Press 1 for dedicated or Press 2 for star topology"<<endl;
      int cn;
      cin>>cn;
      hub h(A, B, C, D, E);
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
          cout<<"Now Mac Address and Data :\n";
          cout<<"A : " << A.mac << ": " << A.data<<endl;
          cout<<"B : " << B.mac << ": " << B.data<<endl;
          cout<<"C : " << C.mac << ": " << C.data<<endl;
          cout<<"D : " << D.mac << ": " << D.data<<endl;
          cout<<"E : " << E.mac << ": " << E.data<<endl;

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
      default : cout<<"Enter invalid chice"<<endl;


      }
        }
    
    if(choice==2){
        int bridge = 0;
      cout<<"Press 1 for Switch - End device configurtion \nPress 2 for Switch - Hub - End Device configuration "<<endl;
      int k;
      cin>>k;
      switch (k) {
      case 1:
        cout<<"Switch is created,Enter the number of Devices\n";
        int devices;
        cin>>devices;
        tee = true;
        while (tee) {
          cout<<"Enter the Sender(should be 1,2,3 etc) :"<<endl;
          int  sender;
          cin>>sender;
          cout<<"Enter the Receiver(should be 1,2,3 etc) :"<<endl;
          int  receiver;
          cin>>receiver;

          cout<<"Enter the Data"<<endl;
          string d;
          cin>>d;
          bridge++;
          cout<<"Go Back N protocol is used"<<endl;
          transmission(sender, receiver, d, bridge, devices);
          cout<<"want to sent again? y/n"<<endl;
          char reply;
          cin>>reply;
          if (reply != 'y')
            tee = false;




        }
        break;
      case 2:
        cout<<"Enter number of end Devices in 1st Hub\n";
        int h1;
        cin>>h1;

        cout<<"\nEnter number of end Devices in 2nd Hub\n"<<endl;
        int h2;
        cin>>h2;
        bool flag2 = true ;
        bridge = 0;
        while (flag2) {
          cout<<"Enter the Sender(should be 1,2,3 etc) :"<<endl;
          int  sender;
          cin>>sender;
          cout<<"Enter the Receiver(should be 1,2,3 etc) :"<<endl;
          int  receiver;
          cin>>receiver;

          cout<<"Enter the Data"<<endl;
          
          cin>>d;
          bridge++;
          cout<<"Stop and wait protocol is used"<<endl;
          transmission2(sender, receiver, d, bridge, h1 + h2, h1);
          cout<<"want to sent again? y/n"<<endl;
          char reply;
          cin>>reply;
          if (reply != 'y')
            tee = false;


        }
    }
    }
      
  }
